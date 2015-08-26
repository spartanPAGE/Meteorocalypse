#include "items/itemsmanager.hpp"

ItemsManager create_items_manager(ItemsLoader &&loader){
    return ItemsManager(std::move(loader), load_items);
}