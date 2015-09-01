#pragma once
#include "items/item.hpp"
#include "characters/character.hpp"
#include <list>

template<typename EventProxyT>
class EventOptionsSelectProxyTemplate{
    using EventProxy = EventProxyT;
    template<typename T>
    using List = std::list<T>;

    using ItemsList = List<Item::name_type>;
    using CharactersList = List<Character::Name>;
public:
    EventOptionsSelectProxyTemplate(EventProxy event): event_proxy(event){}
public:
    ItemsList available_items() const{
        const auto &all_items = event_proxy.options().items().all();
        ItemsList result(all_items.size());
        transform(begin(all_items), end(all_items), begin(result), [](const auto &pair){
            return pair.first;
        });
        return result;
    }

    CharactersList available_characters() const{
        throw "unimplemented yet";
        return CharactersList{};
    }
private:
    EventProxy event_proxy;
};