#pragma once

#include "event.hpp"

using Node = TreeStructInfo::Default::Node;

class EventOptionsItemsBridge{
    using ItemsNode = Node;
public:
    EventOptionsItemsBridge(Node &options);
public:
    auto &all();
    const auto &all() const;
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