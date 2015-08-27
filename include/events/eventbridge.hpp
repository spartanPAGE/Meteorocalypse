#pragma once

#include "event.hpp"
#include <functional>

using Node = TreeStructInfo::Default::Node;

class EventOptionsItemsSingleBridge{
    using Item = Node;
    using Name = Item::name_type;
public:
    EventOptionsItemsSingleBridge(Node &items, const Name &);
public:
    const auto &name() const;
private:
    Item &item;
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
    auto at(const ItemName &);
    const auto at(const ItemName &) const;
    bool exists(const ItemName &) const;

    auto the(const ItemName &);
    const auto the(const ItemName &) const;
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