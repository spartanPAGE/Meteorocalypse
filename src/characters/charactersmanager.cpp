#include "characters/charactersmanager.hpp"

CharactersManager create_characters_manager(CharactersLoader &&loader){
    return CharactersManager(std::move(loader), load_characters);
}