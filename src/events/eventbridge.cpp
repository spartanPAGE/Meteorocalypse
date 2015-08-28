#include "events/eventbridge.hpp"
#include "CandiedTree.hpp"
#include <random>

using namespace std;

EventOptionsPossibilitiesSingleBridge
::EventOptionsPossibilitiesSingleBridge(Node &possibilities, const Name &name):
    possibility(possibilities.findNode(name)){}

EventOptionsPossibilitiesSingleBridge::Name &
EventOptionsPossibilitiesSingleBridge::name()
{ return possibility.name; }
const EventOptionsPossibilitiesSingleBridge::Name &
EventOptionsPossibilitiesSingleBridge::name() const
{ return possibility.name; }

EventOptionsPossibilitiesSingleBridge::Chance
EventOptionsPossibilitiesSingleBridge::chance() const{
    auto sweet_possibility = TreeStructInfo::makeCandied(possibility);
    return sweet_possibility.readReal("chance", 0.0);
}

EventOptionsPossibilitiesSingleBridge::Value
EventOptionsPossibilitiesSingleBridge::state() const{
    auto sweet_possibility = TreeStructInfo::makeCandied(possibility);
    return sweet_possibility.readValue("state");
}

EventOptionsPossibilitiesBridge::EventOptionsPossibilitiesBridge(Node &base):
    possibilities(base.findNode("Possibilities")){}

EventOptionsPossibilitiesBridge::ChancesList 
EventOptionsPossibilitiesBridge::collect_chances() const{
    ChancesList chances;
    for(const auto &possibilityPair : possibilities.nodes){
        const auto &possibility = TreeStructInfo::makeCandied(possibilityPair.second);
        chances.push_back(possibility.readReal("chance", 0.0));
    }
    return chances;
}

EventOptionsPossibilitiesSingleBridge
EventOptionsPossibilitiesBridge::random() const{
    return random(collect_chances());
}

EventOptionsItemsSingleBridge::EventOptionsItemsSingleBridge(Node &items, const Name &name):
    item(items.findNode(name)){}

const auto &EventOptionsItemsSingleBridge::name() const
{ return item.name; }

EventOptionsPossibilitiesBridge EventOptionsItemsSingleBridge::possibilities()
{ return EventOptionsPossibilitiesBridge(item); }
const EventOptionsPossibilitiesBridge EventOptionsItemsSingleBridge::possibilities() const
{ return EventOptionsPossibilitiesBridge(item); }

EventOptionsItemsBridge::EventOptionsItemsBridge(Node &options):
    items(options.findNode("Items")){}

auto &EventOptionsItemsBridge::all()
{ return items.nodes; }
const auto &EventOptionsItemsBridge::all() const
{ return items.nodes; }

auto EventOptionsItemsBridge::count() const
{ return items.nodes.size(); }

EventOptionsItemsSingleBridge EventOptionsItemsBridge::at(const ItemName &name)
{ return EventOptionsItemsSingleBridge(items, name); }
const EventOptionsItemsSingleBridge EventOptionsItemsBridge::at(const ItemName &name) const
{ return EventOptionsItemsSingleBridge(items, name); }

bool EventOptionsItemsBridge::exists(const ItemName &name) const
{ return items.nodes.count(name) != 0; }

EventOptionsItemsSingleBridge EventOptionsItemsBridge::the(const ItemName &name)
{ return at(name); }
const EventOptionsItemsSingleBridge EventOptionsItemsBridge::the(const ItemName &name) const
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