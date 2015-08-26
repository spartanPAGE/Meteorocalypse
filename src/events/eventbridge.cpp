#include "events/eventbridge.hpp"

EventOptionsItemsBridge::EventOptionsItemsBridge(Node &options):
    items(options.findNode("Items")){}

auto &EventOptionsItemsBridge::all()
{ return items.nodes; }
const auto &EventOptionsItemsBridge::all() const
{ return items.nodes; }


EventOptionsBridge::EventOptionsBridge(Event &event):
    options(event.findNode("Options")),
    items_bridge(options){}

bool EventOptionsBridge::has_items() const{ return !items().all().empty(); }

EventOptionsItemsBridge &EventOptionsBridge::items(){ return items_bridge; }
const EventOptionsItemsBridge &EventOptionsBridge::items() const{ return items_bridge; }

auto &EventOptionsBridge::all(){ return options.nodes; }
const auto &EventOptionsBridge::all() const{ return options.nodes; }

EventBridge::EventBridge(Event &event):
    event(event),
    options_bridge(event){}

bool EventBridge::has_options() const{ return !options().all().empty(); }

EventOptionsBridge &EventBridge::options(){ return options_bridge; }
const EventOptionsBridge &EventBridge::options() const{ return options_bridge; }