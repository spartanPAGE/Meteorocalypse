#include "items/itemsloader.hpp"
#include "tsimapper.hpp"
#include "tsiloader.hpp"

namespace ItemsLoaderInfo{
    char dir[] = "characters/";
    char list_file[] = "list.txt";
    char ext[] = ".tsinfo";
}

Item load_item(const ListLoader::Path &path){
    return TSILoader::load_tree(path);
}

ItemsLoader::Objects load_items(ItemsLoader &items_loader){
    if(!items_loader.test_paths())
        throw std::runtime_error("ItemsLoader::test_paths() failed");
    if(!items_loader.load_list())
        throw std::runtime_error("ItemsLoader::load_list() failed");
    return items_loader.load(load_item);
}