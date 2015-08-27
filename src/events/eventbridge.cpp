#include "events/eventbridge.hpp"

EventOptionsItemsSingleBridge::EventOptionsItemsSingleBridge(Node &items, const Name &name):
    item(items.findNode(name)){}

const auto &EventOptionsItemsSingleBridge::name() const
{ return item.name; }

EventOptionsItemsBridge::EventOptionsItemsBridge(Node &options):
    items(options.findNode("Items")){}

auto &EventOptionsItemsBridge::all()
{ return items.nodes; }
const auto &EventOptionsItemsBridge::all() const
{ return items.nodes; }

auto EventOptionsItemsBridge::count() const
{ return items.nodes.size(); }

auto EventOptionsItemsBridge::at(const ItemName &name)
{ return EventOptionsItemsSingleBridge(items, name); }
const auto EventOptionsItemsBridge::at(const ItemName &name) const
{ return EventOptionsItemsSingleBridge(items, name); }

bool EventOptionsItemsBridge::exists(const ItemName &name) const
{ return items.nodes.count(name); }

auto EventOptionsItemsBridge::the(const ItemName &name)
{ return at(name); }
const auto EventOptionsItemsBridge::the(const ItemName &name) const
{ return at(name); }


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