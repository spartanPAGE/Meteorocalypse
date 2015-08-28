#pragma once

#include "event.hpp"
#include <functional>
#include <list>

using Node = TreeStructInfo::Default::Node;

class EventOptionsPossibilitiesSingleBridge{
public:
    using PossibilityNode = Node;
    using Name = PossibilityNode::name_type;
    using Value = PossibilityNode::attribute_type::value_type;
    using Chance = double;
public:
    EventOptionsPossibilitiesSingleBridge(Node &possibilities, const Name &name);
public:
    Name &name();
    const Name &name() const;

    Chance chance() const;
    Value state() const;
private:
    PossibilityNode possibility;
};

class EventOptionsPossibilitiesBridge{
public:
    using PossibilitiesNode = Node;
    using Chance = EventOptionsPossibilitiesSingleBridge::Chance;
    using Number = unsigned;
    using ChancesList = std::list<Chance>;
public:
    EventOptionsPossibilitiesBridge(Node &base);
public:
    ChancesList collect_chances() const;
    template<typename ChancesListType>
    EventOptionsPossibilitiesSingleBridge random(const ChancesListType &chances) const{
        default_random_engine generator;
        discrete_distribution<Number> distribution(begin(chances), end(chances));
        return EventOptionsPossibilitiesSingleBridge(
            possibilities,
            std::to_string(distribution(generator)+1)
        );
    }
    EventOptionsPossibilitiesSingleBridge random() const;
private:
    PossibilitiesNode &possibilities;
};

class EventOptionsItemsSingleBridge{
    using ItemNode = Node;
    using Name = ItemNode::name_type;
public:
    EventOptionsItemsSingleBridge(Node &items, const Name &);
public:
    const auto &name() const;
    EventOptionsPossibilitiesBridge possibilities();
    const EventOptionsPossibilitiesBridge possibilities() const;
private:
    ItemNode &item;
};

class EventOptionsItemsBridge{
    using ItemsNode = Node;
    using ItemName = Node::name_type;
public:
    EventOptionsItemsBridge(Node &options);
public:
    auto &all();
    const auto &all() const;
    auto count() const;

    EventOptionsItemsSingleBridge at(const ItemName &);
    const EventOptionsItemsSingleBridge at(const ItemName &) const;
    bool exists(const ItemName &) const;

    EventOptionsItemsSingleBridge the(const ItemName &);
    const EventOptionsItemsSingleBridge the(const ItemName &) const;
private:
    ItemsNode &items;
};

class EventOptionsBridge{
public:
    using OptionsNode = Node;
public:
    EventOptionsBridge(Event &event);
public:
    bool has_items() const;

    EventOptionsItemsBridge &items();
    const EventOptionsItemsBridge &items() const;

    auto &all();
    const auto &all() const;
private:
    OptionsNode &options;
    EventOptionsItemsBridge items_bridge;
};

class EventBridge{
public:
    EventBridge(Event &event);
public:
    bool has_options() const;

    EventOptionsBridge &options();
    const EventOptionsBridge &options() const;
private:
    Event &event;
    EventOptionsBridge options_bridge;
};