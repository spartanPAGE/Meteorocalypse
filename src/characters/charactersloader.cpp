#include "characters/charactersloader.hpp"
#include "tsimapper.hpp"
#include "tsiloader.hpp"

namespace CharactersLoaderInfo{
    char dir[] = "characters/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Character load_character(const ListLoader::Path &path){
    return TSIMapper::to_character(TSILoader::load_tree(path));
}

CharactersLoader::Objects load_characters(CharactersLoader &characters_loader){
    if(!characters_loader.test_paths())
        throw std::runtime_error("CharactersLoader::test_paths() failed");
    if(!characters_loader.load_list())
        throw std::runtime_error("CharactersLoader::load_list() failed");
    return characters_loader.load(load_character);
}