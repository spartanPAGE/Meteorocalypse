#pragma once

#include "event.hpp"
#include "items/itemsmanager.hpp"
#include "characters/charactersmanager.hpp"
#include "events/eventoptionsselectproxy.hpp"

#include <list>
#include <functional>

using Node = TreeStructInfo::Default::Node;

class EventOptionsPossibilitiesSingleProxy{
public:
    using PossibilityNode = Node;
    using Name = PossibilityNode::name_type;
    using Value = PossibilityNode::attribute_type::value_type;
    using Chance = double;
public:
    EventOptionsPossibilitiesSingleProxy(Node &possibilities, const Name &name);
public:
    Name &name();
    const Name &name() const;

    Chance chance() const;

    Value &state();
    const Value &state() const;
private:
    PossibilityNode possibility;
};

class EventOptionsPossibilitiesProxy{
public:
    using PossibilitiesNode = Node;
    using Chance = EventOptionsPossibilitiesSingleProxy::Chance;
    using Number = unsigned;
    using ChancesList = std::list<Chance>;
public:
    EventOptionsPossibilitiesProxy(Node &base);
public:
    ChancesList collect_chances() const;
    template<typename ChancesListType>
    EventOptionsPossibilitiesSingleProxy random(const ChancesListType &chances) const{
        default_random_engine generator;
        discrete_distribution<Number> distribution(begin(chances), end(chances));
        return EventOptionsPossibilitiesSingleProxy(
            possibilities,
            std::to_string(distribution(generator)+1)
        );
    }
    EventOptionsPossibilitiesSingleProxy random() const;
private:
    PossibilitiesNode &possibilities;
};

class EventOptionsItemsSingleProxy{
    using ItemNode = Node;
    using Name = ItemNode::name_type;
public:
    EventOptionsItemsSingleProxy(Node &items, const Name &);
public:
    const auto &name() const;
    EventOptionsPossibilitiesProxy possibilities();
    const EventOptionsPossibilitiesProxy possibilities() const;
private:
    ItemNode &item;
};

class EventOptionsItemsProxy{
    using ItemsNode = Node;
    using AllItemsMap = Node::nodes_map_type;
    using ItemName = Node::name_type;
public:
    EventOptionsItemsProxy(Node &options);
public:
    AllItemsMap &all();
    const AllItemsMap &all() const;
    auto count() const;

    EventOptionsItemsSingleProxy at(const ItemName &);
    const EventOptionsItemsSingleProxy at(const ItemName &) const;
    bool exists(const ItemName &) const;

    EventOptionsItemsSingleProxy the(const ItemName &);
    const EventOptionsItemsSingleProxy the(const ItemName &) const;
private:
    ItemsNode &items;
};

class EventOptionsProxy{
public:
    using OptionsNode = Node;
public:
    EventOptionsProxy(Event &event);
public:
    bool has_items() const;

    EventOptionsItemsProxy &items();
    const EventOptionsItemsProxy &items() const;

    auto &all();
    const auto &all() const;
private:
    OptionsNode &options;
    EventOptionsItemsProxy items_proxy;
};

class EventProxy{
public:
    using EventOptionsSelectProxy = EventOptionsSelectProxyTemplate<EventProxy>;
public:
    EventProxy(Event &event);
public:
    bool has_options() const;

    EventOptionsProxy &options();
    const EventOptionsProxy &options() const;

    EventOptionsSelectProxy select();
    const EventOptionsSelectProxy select() const;
private:
    Event &event;
    EventOptionsProxy options_proxy;
};