#include "events/eventsloader.hpp"
#include "mapper/tsiloader.hpp"

namespace EventsLoaderInfo{
    char dir[] = "events/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Event load_event(const ListLoader::Path &path){
    return TSILoader::load_tree(path);
}

EventsLoader::Objects load_events(EventsLoader &events_loader){
    return load_objects(events_loader, load_event);
}