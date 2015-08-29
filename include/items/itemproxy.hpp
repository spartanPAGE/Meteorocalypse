#pragma once
#include "item.hpp"

class ItemProxy{
    using Name = Item::name_type;
public:
    ItemProxy(Item &item);
public:
    Name &name();
    const Name &name() const;

    bool is_spoilable() const;

    bool is_stackable() const;
private:
    Item &item;
};