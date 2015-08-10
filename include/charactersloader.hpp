#pragma once

#include "listloader.hpp"
#include "character.hpp"

#include <list>
class CharactersLoader{
public:
    using Path = ListLoader::Path;
    using PathInUse = ListLoader::PathInUse;
    using Extension = ListLoader::Extension;
    using Characters = std::list<Character>;
public:
    CharactersLoader(const Path &main_path, const Path &alternative_path);
    CharactersLoader(Path &&main_path = "resources/",
                     Path &&alternative_path = "../Meteorocalypse/resources/");
public:
    PathInUse path_in_use() const;
    Path real_path() const;
    bool test_paths();
    bool load_list();
    bool has_loaded_list() const;

    Characters load_characters() const;
private:
    const Path characters_dir = "characters/";
    const Path list_path = "list.txt";
    const Extension ext = ".tsinfo";
    ListLoader list_loader;
};