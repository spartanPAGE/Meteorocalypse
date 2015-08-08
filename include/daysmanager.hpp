#pragma once
#include "day.hpp"
#include "charactersmanager.hpp"

class DaysManager{
public:
    DaysManager(CharactersManager &);
public:
    Day fetch_next();
private:
    unsigned past_days = 0;
    CharactersManager &characters_manager;
};
