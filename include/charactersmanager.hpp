#pragma once

#include "charactersloader.hpp"
#include "character.hpp"
#include <map>
#include <functional>

class CharactersManager{
public:
    CharactersManager(CharactersLoader &&);
public:
    void load_all();
    void for_each(std::function<void(Character &)>);
    void for_each(std::function<void(const Character &)>) const;
    void for_exact(const Character::Name &, std::function<void(Character &)>);
    void for_exact(const Character::Name &, std::function<void(const Character &)>) const;
private:
    CharactersLoader characters_loader;
    std::map<Character::Name, Character> characters;
};
