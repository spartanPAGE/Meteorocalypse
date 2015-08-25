#pragma once

#include "objects/objectsmanager.hpp"
#include "characters/character.hpp"
#include "characters/charactersloader.hpp"

using CharactersManager = ObjectsManager<Character, CharactersLoader>;

CharactersManager create_characters_manager(CharactersLoader &&);