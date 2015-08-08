#include "charactersmanager.hpp"
#include <fstream>
#include <exception>

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

    throw std::runtime_error("Cannot access real_path when used_path == UNSPECIFIED");
    return "";
}

bool CharactersLoader::test_paths(){
    if(std::ifstream(main_path+characters_list)){
        used_path = PathInUse::MAIN;
    } else
    if(std::ifstream(alternative_path+characters_list)){
        used_path = PathInUse::ALTERNATIVE;
    }
    return used_path != PathInUse::UNSPECIFIED;
}

void CharactersLoader::load_list(){
    Path list_path = real_path();

    std::ifstream in(list_path+characters_list);
    std::string line;
    while(std::getline(in, line))
        if(!line.empty())
            to_load.push_back(line);
}

bool CharactersLoader::has_loaded_list() const{
    return to_load.size() != 0;
}


CharactersManager::CharactersManager(CharactersLoader &&loader):
    characters_loader(loader){}
