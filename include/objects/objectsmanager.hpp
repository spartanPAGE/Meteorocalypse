#pragma once

#pragma once

#include <map>
#include <functional>

template<typename T, typename Loader, typename TName = typename T::Name>
class ObjectsManager{
public:
    using Object = T;
    using ObjectName = TName;
    using ObjectsLoader = Loader;
    using LoadingFunc = std::function<typename ObjectsLoader::Objects(ObjectsLoader &)>;
public:
    ObjectsManager(ObjectsLoader &&loader, LoadingFunc func):
        objects_loader(loader), loading_func(func){}
public:
    void load_all(){
        auto objects = loading_func(objects_loader);
        for(const auto &object : objects){
            this->objects[object.name] = object;
        }
    }

    void for_each(std::function<void(Object &)> func){
        for(auto &name_obj_pair : objects){
            func(name_obj_pair.second);
        }
    }

    void for_each(std::function<void(const Object &)>) const{
        for(const auto &name_obj_pair : objects){
            func(name_obj_pair.second);
        }
    }

    void for_exact(const ObjectName &name, std::function<void(Object &)> func){
        func(objects.at(name));
    }

    void for_exact(const ObjectName &name, std::function<void(const Object &)> func) const{
        func(objects.at(name));
    }
private:
    ObjectsLoader objects_loader;
    LoadingFunc loading_func;
    std::map<ObjectName, Object> objects;
};
