#pragma once

#include "event.hpp"
#include "objects/objectsloader.hpp"

namespace EventsLoaderInfo{
    extern char dir[];
    extern char list_file[];
    extern char ext[];
}

Event load_event(const ListLoader::Path &path);

using EventsLoader = ObjectsLoader<
    Event,
    EventsLoaderInfo::dir,
    EventsLoaderInfo::list_file,
    EventsLoaderInfo::ext
>;

EventsLoader::Objects load_events(EventsLoader &loader);