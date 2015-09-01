#include "events/eventProxy.hpp"
#include "CandiedTree.hpp"
#include <random>

using namespace std;

EventOptionsPossibilitiesSingleProxy
::EventOptionsPossibilitiesSingleProxy(Node &possibilities, const Name &name):
    possibility(possibilities.findNode(name)){}

EventOptionsPossibilitiesSingleProxy::Name &
EventOptionsPossibilitiesSingleProxy::name()
{ return possibility.name; }
const EventOptionsPossibilitiesSingleProxy::Name &
EventOptionsPossibilitiesSingleProxy::name() const
{ return possibility.name; }

EventOptionsPossibilitiesSingleProxy::Chance
EventOptionsPossibilitiesSingleProxy::chance() const{
    auto sweet_possibility = TreeStructInfo::makeCandied(possibility);
    return sweet_possibility.readReal("chance", 0.0);
}

EventOptionsPossibilitiesSingleProxy::Value &
EventOptionsPossibilitiesSingleProxy::state(){
    auto sweet_possibility = TreeStructInfo::makeCandied(possibility);
    return sweet_possibility.readValue("state");
}
const EventOptionsPossibilitiesSingleProxy::Value &
EventOptionsPossibilitiesSingleProxy::state() const{
    auto sweet_possibility = TreeStructInfo::makeCandied(possibility);
    return sweet_possibility.readValue("state");
}

EventOptionsPossibilitiesProxy::EventOptionsPossibilitiesProxy(Node &base):
    possibilities(base.findNode("Possibilities")){}

EventOptionsPossibilitiesProxy::ChancesList 
EventOptionsPossibilitiesProxy::collect_chances() const{
    ChancesList chances;
    for(const auto &possibilityPair : possibilities.nodes){
        const auto &possibility = TreeStructInfo::makeCandied(possibilityPair.second);
        chances.push_back(possibility.readReal("chance", 0.0));
    }
    return chances;
}

EventOptionsPossibilitiesSingleProxy
EventOptionsPossibilitiesProxy::random() const{
    return random(collect_chances());
}

EventOptionsItemsSingleProxy::EventOptionsItemsSingleProxy(Node &items, const Name &name):
    item(items.findNode(name)){}

const auto &EventOptionsItemsSingleProxy::name() const
{ return item.name; }

EventOptionsPossibilitiesProxy EventOptionsItemsSingleProxy::possibilities()
{ return EventOptionsPossibilitiesProxy(item); }
const EventOptionsPossibilitiesProxy EventOptionsItemsSingleProxy::possibilities() const
{ return EventOptionsPossibilitiesProxy(item); }

EventOptionsItemsProxy::EventOptionsItemsProxy(Node &options):
    items(options.findNode("Items")){}

EventOptionsItemsProxy::AllItemsMap &EventOptionsItemsProxy::all()
{ return items.nodes; }
const EventOptionsItemsProxy::AllItemsMap &EventOptionsItemsProxy::all() const
{ return items.nodes; }

auto EventOptionsItemsProxy::count() const
{ return items.nodes.size(); }

EventOptionsItemsSingleProxy EventOptionsItemsProxy::at(const ItemName &name)
{ return EventOptionsItemsSingleProxy(items, name); }
const EventOptionsItemsSingleProxy EventOptionsItemsProxy::at(const ItemName &name) const
{ return EventOptionsItemsSingleProxy(items, name); }

bool EventOptionsItemsProxy::exists(const ItemName &name) const
{ return items.nodes.count(name) != 0; }

EventOptionsItemsSingleProxy EventOptionsItemsProxy::the(const ItemName &name)
{ return at(name); }
const EventOptionsItemsSingleProxy EventOptionsItemsProxy::the(const ItemName &name) const
{ return at(name); }


EventOptionsProxy::EventOptionsProxy(Event &event):
    options(event.findNode("Options")),
    items_proxy(options){}

bool EventOptionsProxy::has_items() const{ return !items().all().empty(); }

EventOptionsItemsProxy &EventOptionsProxy::items(){ return items_proxy; }
const EventOptionsItemsProxy &EventOptionsProxy::items() const{ return items_proxy; }

auto &EventOptionsProxy::all(){ return options.nodes; }
const auto &EventOptionsProxy::all() const{ return options.nodes; }

EventProxy::EventProxy(Event &event):
    event(event),
    options_proxy(event){}

bool EventProxy::has_options() const{ return !options().all().empty(); }

EventOptionsProxy &EventProxy::options(){ return options_proxy; }
const EventOptionsProxy &EventProxy::options() const{ return options_proxy; }

EventProxy::EventOptionsSelectProxy EventProxy::select(){
    return EventOptionsSelectProxy(*this);
}

const EventProxy::EventOptionsSelectProxy EventProxy::select() const{
    return EventOptionsSelectProxy(const_cast<EventProxy &>(*this));
}