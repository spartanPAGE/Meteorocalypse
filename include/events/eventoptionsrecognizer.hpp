#pragma once
#include "items/itemsmanager.hpp"
#include "characters/charactersmanager.hpp"
#include "eventproxy.hpp"
#include <list>

class EventOptionsRecognizerSelectProxy{
    template<typename T>
    using List = std::list<T>;

    using ItemsList = List<Item::name_type>;
    using CharactersList = List<Character::Name>;
public:
    EventOptionsRecognizerSelectProxy(EventProxy event);
public:
    ItemsList available_items() const;

    CharactersList available_characters() const;
private:
    EventProxy event_proxy;
};

class EventOptionsRecognizer{
public:
    using Select = EventOptionsRecognizerSelectProxy;
public:
    EventOptionsRecognizer(Event &event);
public:
    bool any_options() const;

    bool any_items() const;
    bool any_characters() const;

    const Select select() const;
private:
    EventProxy event_proxy;
};