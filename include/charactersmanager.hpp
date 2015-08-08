#pragma once
#include "character.hpp"
#include <map>
#include <string>
#include <list>

class CharactersLoader{
public:
    using Path = std::string;
public:
    enum class PathInUse{
        MAIN, ALTERNATIVE, UNSPECIFIED
    };
public:
    CharactersLoader(const Path &main_path, const Path &alternative_path);
    CharactersLoader(Path &&main_path        = "resources/characters/",
                     Path &&alternative_path = "../Meteorocalypse/resources/characters/");
public:
    PathInUse path_in_use() const;
    Path real_path() const;
    bool test_paths();
    void load_list();
    bool has_loaded_list() const;
private:
    const Path main_path;
    const Path alternative_path;
    const Path characters_list = "list.txt";

    PathInUse used_path = PathInUse::UNSPECIFIED;

    std::list<Path> to_load;
};

class CharactersManager{
public:
    CharactersManager(CharactersLoader &&);
private:
    CharactersLoader characters_loader;
    std::map<Character::Name, Character> characters;
};