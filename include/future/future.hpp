#pragma once
#include "days/day.hpp"
#include "events/event.hpp"

#include <unordered_map>

class Future{
private:
    using Container = std::multimap<Day::Number, Event::name_type>;
public:
    using EventsRange = std::pair<Container::const_iterator, Container::const_iterator>;
public:
    void store_event(Day::Number day_id, Event::name_type event_name);
    EventsRange events_of(const Day &day) const;
private:
    Container associated_events;
};