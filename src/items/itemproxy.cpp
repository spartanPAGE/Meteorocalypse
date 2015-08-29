#include "items/itemproxy.hpp"

#include "CandiedTree.hpp"
using namespace TreeStructInfo;

ItemProxy::ItemProxy(Item &item): item(item){}

ItemProxy::Name &
ItemProxy::name(){ return item.name; }

const ItemProxy::Name &
ItemProxy::name() const{ return item.name; }

bool ItemProxy::is_spoilable() const{
    return makeCandied(item).readBool("is spoilable", false);
}

bool ItemProxy::is_stackable() const{
    return makeCandied(item).readBool("is stackable", false);
}