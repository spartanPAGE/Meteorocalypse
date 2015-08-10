#pragma once
#include "character.hpp"
#include "listloader.hpp"
#include <map>
#include <string>
#include <list>
#include <functional>

class CharactersLoader{
public:
    using Path = ListLoader::Path;
    using PathInUse = ListLoader::PathInUse;
    using Extension = ListLoader::Extension;
    using Characters = std::list<Character>;    
public:
    CharactersLoader(const Path &main_path, const Path &alternative_path);
    CharactersLoader(Path &&main_path        = "resources/",
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

class CharactersManager{
public:
    CharactersManager(CharactersLoader &&);
public:
    void load_all();
    void for_each(std::function<void(Character &)>);
    void for_each(std::function<void(const Character &)>) const;
    void for_exact(const Character::Name &, std::function<void(Character &)>);
    void for_exact(const Character::Name &, std::function<void(const Character &)>) const;
private:
    CharactersLoader characters_loader;
    std::map<Character::Name, Character> characters;
};
