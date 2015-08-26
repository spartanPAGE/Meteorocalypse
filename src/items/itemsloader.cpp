#include "items/itemsloader.hpp"
#include "mapper/tsiloader.hpp"

namespace ItemsLoaderInfo{
    char dir[] = "items/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Item load_item(const ListLoader::Path &path){
    return TSILoader::load_tree(path);
}

ItemsLoader::Objects load_items(ItemsLoader &items_loader){
    return load_objects(items_loader, load_item);
}