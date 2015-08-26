#include "events/eventsmanager.hpp"

EventsManager create_events_manager(EventsLoader &&loader){
    return EventsManager(std::move(loader), load_events);
}