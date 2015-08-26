#pragma once

#include "objects/objectsmanager.hpp"
#include "events/event.hpp"
#include "events/eventsloader.hpp"

using EventsManager = ObjectsManager<Event, EventsLoader, Event::name_type>;

EventsManager create_events_manager(EventsLoader &&);