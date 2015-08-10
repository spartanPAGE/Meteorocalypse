#include "charactersmanager.hpp"
#include "tsimapper.hpp"
#include "tsiloader.hpp"
#include <fstream>
#include <exception>

using namespace std;

CharactersLoader::CharactersLoader(const Path &main, const Path &alter):
    list_loader(ext, characters_dir, list_path, main, alter){}

CharactersLoader::CharactersLoader(Path &&main, Path &&alter):
    list_loader(ext, characters_dir, list_path, main, alter){}

CharactersLoader::PathInUse CharactersLoader::path_in_use() const{
    return list_loader.path_in_use();
}

CharactersLoader::Path CharactersLoader::real_path() const{
    return list_loader.real_path();
}

bool CharactersLoader::test_paths(){
    return list_loader.test_paths();
}

bool CharactersLoader::load_list(){
    return list_loader.load_list();
}

bool CharactersLoader::has_loaded_list() const{
    return list_loader.has_loaded_list();
}

CharactersLoader::Characters CharactersLoader::load_characters() const{
    Characters characters;
    auto real_path = this->real_path();
    auto to_load = list_loader.list_to_load();
    for(const auto &character_path : to_load){
        auto &&path = real_path + characters_dir + character_path;
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

void CharactersManager::for_exact(
        const Character::Name &name,
        function<void (Character &)> func
){
    func(characters.at(name));
}

void CharactersManager::for_exact(
        const Character::Name &name,
        function<void (const Character &)> func
) const{
    func(characters.at(name));
}
