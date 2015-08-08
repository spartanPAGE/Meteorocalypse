#include "charactersmanager.hpp"
#include "tsimapper.hpp"
#include "tsiloader.hpp"
#include <fstream>
#include <exception>

using namespace std;

CharactersLoader::CharactersLoader(const Path &main, const Path &alter):
    main_path(main), alternative_path(alter){}

CharactersLoader::CharactersLoader(Path &&main, Path &&alter):
    main_path(main), alternative_path(alter){}

CharactersLoader::PathInUse CharactersLoader::path_in_use() const{
    return used_path;
}

CharactersLoader::Path CharactersLoader::real_path() const{
    if(used_path == PathInUse::MAIN)
        return main_path;
    if(used_path == PathInUse::ALTERNATIVE)
        return alternative_path;

    throw runtime_error("Cannot access real_path when used_path == UNSPECIFIED");
    return "";
}

bool CharactersLoader::test_paths(){
    if(ifstream(main_path+characters_list)){
        used_path = PathInUse::MAIN;
    } else
    if(ifstream(alternative_path+characters_list)){
        used_path = PathInUse::ALTERNATIVE;
    }
    return used_path != PathInUse::UNSPECIFIED;
}

bool CharactersLoader::load_list(){
    Path list_path = real_path();

    ifstream in(list_path+characters_list);
    string line;
    while(getline(in, line))
        if(!line.empty())
            to_load.push_back(line+".tsinfo");
    return has_loaded_list();
}

bool CharactersLoader::has_loaded_list() const{
    return to_load.size() != 0;
}

CharactersLoader::Characters CharactersLoader::load_characters() const{
    Characters characters;
    auto real_path = this->real_path();
    for(const auto &character_path : to_load){
        auto &&path = real_path + character_path;
        characters.push_back(TSIMapper::to_character(TSILoader::load_tree(path)));
    }
    return characters;
}


CharactersManager::CharactersManager(CharactersLoader &&loader):
    characters_loader(loader){}

void CharactersManager::load_all(){
    if(!characters_loader.test_paths())
        throw runtime_error("CharactersLoader::test_paths() failed");
    if(!characters_loader.load_list())
        throw runtime_error("CharactersLoader::load_list() failed");
    auto characters = characters_loader.load_characters();
    for(const auto &character : characters){
        this->characters[character.name] = character;
    }
}

void CharactersManager::for_each(function<void (Character &)> func){
    for(auto &name_obj_pair : characters){
        func(name_obj_pair.second);
    }
}

void CharactersManager::for_each(function<void (const Character &)> func) const{
    for(const auto &name_obj_pair : characters){
        func(name_obj_pair.second);
    }
}
