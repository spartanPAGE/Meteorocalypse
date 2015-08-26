#include "characters/charactersloader.hpp"
#include "mapper/tsimapper.hpp"
#include "mapper/tsiloader.hpp"

namespace CharactersLoaderInfo{
    char dir[] = "characters/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Character load_character(const ListLoader::Path &path){
    return TSIMapper::to_character(TSILoader::load_tree(path));
}

CharactersLoader::Objects load_characters(CharactersLoader &characters_loader){
    return load_objects(characters_loader, load_character);
}