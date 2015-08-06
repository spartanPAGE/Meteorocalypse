#pragma once
#include "daysmanager.hpp"
#include "dayroutine.hpp"

class Gameplay{
public:
    Gameplay();
public:
    void start();
    bool is_running() const;
    bool has_finished() const;

private:
    bool running;

    DaysManager daysManager;
    DayRoutine dayRoutine;
};
