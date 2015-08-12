#include "listloader.hpp"
#include <exception>
#include <fstream>
using namespace std;

ListLoader::ListLoader(const Extension &ext,
                       const Path &dir,
                       const Path &list,
                       const Path &main, 
                       const Path &alter):
    files_ext(ext), location_dir(dir), list_path(list), main_path(main), alternative_path(alter){}

ListLoader::ListLoader(const Extension &ext, 
                       const Path &dir, 
                       const Path &list, 
                       Path &&main, 
                       Path &&alter):
    files_ext(ext), location_dir(dir), list_path(list), main_path(main), alternative_path(alter){}

ListLoader::PathInUse ListLoader::path_in_use() const{
    return used_path;
}

ListLoader::Path ListLoader::real_path() const{
    if(used_path == PathInUse::MAIN)
        return main_path;
    if(used_path == PathInUse::ALTERNATIVE)
        return alternative_path;

    throw runtime_error("Cannot access real_path when used_path == UNSPECIFIED");
    return "";
}

bool ListLoader::test_paths(){
    if(ifstream(main_path + location_dir + list_path))
        used_path = PathInUse::MAIN;
    else if(ifstream(alternative_path + location_dir + list_path))
            used_path = PathInUse::ALTERNATIVE;
    return used_path != PathInUse::UNSPECIFIED;
}

bool ListLoader::load_list(){
    Path real_path = this->real_path();

    ifstream in(real_path + location_dir + list_path);
    string line;
    while(getline(in, line))
        if(!line.empty())
            to_load.push_back(line + files_ext);
    return has_loaded_list();
}

bool ListLoader::has_loaded_list() const{
    return to_load.size() != 0;
}

ListLoader::ToLoadList ListLoader::list_to_load() const{
    return to_load;
}