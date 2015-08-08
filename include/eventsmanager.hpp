#pragma once
#include <map>

#include "day.hpp"

struct Event{

};

class EventsManager{
public:
    EventsManager();
private:
    std::multimap<Day::Number, Event> events;
};
