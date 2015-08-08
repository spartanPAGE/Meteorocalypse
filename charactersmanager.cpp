#include "charactersmanager.hpp"
#include <fstream>

CharactersLoader::CharactersLoader(const Path &main, const Path &alter):
    main_path(main), alternative_path(alter){}

CharactersLoader::CharactersLoader(Path &&main, Path &&alter):
    main_path(main), alternative_path(alter){}

CharactersLoader::PathInUse CharactersLoader::path_in_use() const{
    return used_path;
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



CharactersManager::CharactersManager(CharactersLoader &&loader):
    characters_loader(loader){}
