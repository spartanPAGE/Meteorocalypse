#pragma once

#include "objects/objectsmanager.hpp"
#include "items/item.hpp"
#include "items/itemsloader.hpp"

using ItemsManager = ObjectsManager<Item, ItemsLoader, Item::name_type>;

ItemsManager create_items_manager(ItemsLoader &&);