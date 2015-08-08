#pragma once
#include "daysmanager.hpp"
#include "dayroutine.hpp"
#include "charactersmanager.hpp"

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
    bool running;

    DaysManager daysManager;
    DayRoutine dayRoutine;
    CharactersManager characters_manager;
};
