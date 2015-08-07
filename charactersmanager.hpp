#pragma once
#include "character.hpp"
#include <map>

class CharactersManager{
public:
    CharactersManager();
private:
    std::map<Character::Name, Character> characters;
};
