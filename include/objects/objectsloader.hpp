#pragma once

#pragma once

#include "listloader.hpp"

#include <functional>
#include <list>
template<
    typename T,
    const char *dir_val, 
    const char *list_path_val,
    const char *ext_val
>
class ObjectsLoader{
public:
    using Path = ListLoader::Path;
    using PathInUse = ListLoader::PathInUse;
    using Extension = ListLoader::Extension;
    using Object = T;
    using Objects = std::list<T>;
public:
    ObjectsLoader(const Path &main, const Path &alter):
        list_loader(ext, dir, list_path, main, alter){}
    ObjectsLoader(Path &&main = "resources/",
                  Path &&alter = "../Meteorocalypse/resources/"):
        list_loader(ext, dir, list_path, main, alter){}
public:
    PathInUse path_in_use() const{
        return list_loader.path_in_use();
    }
    Path real_path() const{
        return list_loader.real_path();
    }
    bool test_paths(){
        return list_loader.test_paths();
    }
    bool load_list(){
        return list_loader.load_list();
    }
    bool has_loaded_list() const{
        return list_loader.has_loaded_list();
    }

    template<typename Mapper>
    Objects load(Mapper mapper) const{
        Objects objects;
        auto real_path = this->real_path();
        auto to_load = list_loader.list_to_load();
        for(const auto &single_path : to_load){
            auto &&path = real_path + dir + single_path;
            objects.push_back(mapper(path));
        }
        return objects;
    }
private:
    const Path dir = dir_val;
    const Path list_path = list_path_val;
    const Extension ext = ext_val;
    ListLoader list_loader;
};