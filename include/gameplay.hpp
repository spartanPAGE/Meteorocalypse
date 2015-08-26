#pragma once
#include "days/daysmanager.hpp"
#include "days/dayroutine.hpp"
#include "characters/charactersmanager.hpp"

class Gameplay{
public:
    Gameplay();
public:
    void start();
    bool is_running() const;
    bool has_finished() const;

private:
    void load_all();

private:
    bool running = true;

    CharactersManager characters_manager;
    DaysManager days_manager;
    DayRoutine day_routine;
};
