#pragma once

#include "objectloader.hpp"
#include "character.hpp"

extern char dir[];
extern char list_file[];
extern char ext[];

Character load_character(const ListLoader::Path &path);

using CharactersLoader = ObjectsLoader<Character, dir, list_file, ext>;

CharactersLoader::Objects load_characters(CharactersLoader &characters_loader);