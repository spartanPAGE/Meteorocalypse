#pragma once
#include "character.hpp"
#include <map>
#include <string>
#include <list>
#include <functional>

class CharactersLoader{
public:
    using Path = std::string;
    using Characters = std::list<Character>;
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
    bool load_list();
    bool has_loaded_list() const;

    Characters load_characters() const;
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
