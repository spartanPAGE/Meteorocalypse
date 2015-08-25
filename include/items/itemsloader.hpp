#pragma once

#include "objects/objectsloader.hpp"
#include "item.hpp"

namespace ItemsLoaderInfo{
    extern char dir[];
    extern char list_file[];
    extern char ext[];
}

Item load_item(const ListLoader::Path &path);

using ItemsLoader = ObjectsLoader<
    Item, 
    ItemsLoaderInfo::dir, 
    ItemsLoaderInfo::list_file, 
    ItemsLoaderInfo::ext
>;

ItemsLoader::Objects load_items(ItemsLoader &items_loader);