#include "events/eventsloader.hpp"
#include "tsiloader.hpp"

namespace EventsLoaderInfo{
    char dir[] = "events/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Event load_event(const ListLoader::Path &path){
    return TSILoader::load_tree(path);
}

EventsLoader::Objects load_events(EventsLoader &events_loader){
    if(!events_loader.test_paths())
        throw std::runtime_error("EventsLoader::test_paths() failed");
    if(!events_loader.load_list())
        throw std::runtime_error("EventsLoader::load_list() failed");
    return events_loader.load(load_event);
}