#pragma once
#include <string>
#include <list>

class ListLoader{
public:
    using Path = std::string;
    using Extension = std::string;
    using ToLoadList = std::list<Path>;
public:
    enum class PathInUse{
        MAIN, ALTERNATIVE, UNSPECIFIED
    };
public:
    ListLoader(const Extension &files_ext, 
               const Path &location_dir,
               const Path &list_path, 
               const Path &main_path, 
               const Path &alternative_path);

    ListLoader(const Extension &files_ext, 
               const Path &location_dir,
               const Path &list_path,
               Path &&main_path = "resources/",
               Path &&alternative_path = "../Meteorocalypse/resources/");
public:
    PathInUse path_in_use() const;
    Path real_path() const;
    bool test_paths();
    bool load_list();
    bool has_loaded_list() const;
    ToLoadList list_to_load() const;
private:
    const Path main_path;
    const Path alternative_path;
    const Path list_path;

    PathInUse used_path = PathInUse::UNSPECIFIED;
    const Extension files_ext;
    const Path location_dir;

    ToLoadList to_load;
};