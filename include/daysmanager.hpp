#pragma once
#include "day.hpp"

class DaysManager{
public:
    DaysManager();
public:
    Day fetch_next();
private:
    unsigned past_days;
};
