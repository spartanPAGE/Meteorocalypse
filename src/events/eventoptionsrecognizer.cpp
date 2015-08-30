#pragma once
#include "events/eventoptionsrecognizer.hpp"

#include <algorithm>
using namespace std;

EventOptionsRecognizerSelectProxy::
EventOptionsRecognizerSelectProxy(EventProxy event): event_proxy(event){}

EventOptionsRecognizerSelectProxy::ItemsList 
EventOptionsRecognizerSelectProxy::available_items() const{
    const auto &all_items = event_proxy.options().items().all();
    ItemsList result(all_items.size());
    transform(begin(all_items), end(all_items), begin(result), [](const auto &pair){
        return pair.first;
    });
    return result;
}

EventOptionsRecognizerSelectProxy::CharactersList 
EventOptionsRecognizerSelectProxy::available_characters() const{
    throw "unimplemented yet";
    return CharactersList{};
}

EventOptionsRecognizer::EventOptionsRecognizer(Event &event): event_proxy(event){}

bool EventOptionsRecognizer::any_options() const{
    return event_proxy.has_options();
}

bool EventOptionsRecognizer::any_items() const{
    return event_proxy.options().has_items();
}
bool EventOptionsRecognizer::any_characters() const{
    throw "unimplemented yet";
    return false;
}

const EventOptionsRecognizer::Select EventOptionsRecognizer::select() const{
    return event_proxy;
}