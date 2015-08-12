#include "charactersloader.hpp"

#include "tsimapper.hpp"
#include "tsiloader.hpp"
#include <fstream>
#include <exception>

using namespace std;

CharactersLoader::CharactersLoader(const Path &main, const Path &alter):
    list_loader(ext, characters_dir, list_path, main, alter){}

CharactersLoader::CharactersLoader(Path &&main, Path &&alter) :
    list_loader(ext, characters_dir, list_path, main, alter){}

CharactersLoader::PathInUse CharactersLoader::path_in_use() const{
    return list_loader.path_in_use();
}

CharactersLoader::Path CharactersLoader::real_path() const{
    return list_loader.real_path();
}

bool CharactersLoader::test_paths(){
    return list_loader.test_paths();
}

bool CharactersLoader::load_list(){
    return list_loader.load_list();
}

bool CharactersLoader::has_loaded_list() const{
    return list_loader.has_loaded_list();
}

CharactersLoader::Characters CharactersLoader::load_characters() const{
    Characters characters;
    auto real_path = this->real_path();
    auto to_load = list_loader.list_to_load();
    for(const auto &character_path : to_load){
        auto &&path = real_path + characters_dir + character_path;
        characters.push_back(TSIMapper::to_character(TSILoader::load_tree(path)));
    }
    return characters;
}