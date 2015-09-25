#include "future/future.hpp"

void Future::store_event(Day::Number day_id, Event::name_type event_name){
    associated_events.emplace(day_id, event_name);
}

auto Future::events_of(const Day &day) const -> EventsRange{
    return associated_events.equal_range(day.number());
}