#pragma once
#include "characters/charactersmanager.hpp"

class Day{
public:
    using Number = unsigned;
public:
    Day(Number, CharactersManager &);
public:
    Number number() const;
private:
    Number id;
    CharactersManager characters_manager;
};

