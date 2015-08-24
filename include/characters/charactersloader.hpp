#pragma once

#include "objectloader.hpp"
#include "character.hpp"

namespace CharactersLoaderInfo{
    extern char dir[];
    extern char list_file[];
    extern char ext[];
}

Character load_character(const ListLoader::Path &path);

using CharactersLoader = ObjectsLoader<
    Character, 
    CharactersLoaderInfo::dir, 
    CharactersLoaderInfo::list_file, 
    CharactersLoaderInfo::ext
>;

CharactersLoader::Objects load_characters(CharactersLoader &characters_loader);