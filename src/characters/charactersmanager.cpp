#include "characters/charactersmanager.hpp"
#include <exception>
using namespace std;

CharactersManager::CharactersManager(CharactersLoader &&loader):
    characters_loader(loader){}

void CharactersManager::load_all(){
    auto characters = load_characters(characters_loader);
    for(const auto &character : characters){
        this->characters[character.name] = character;
    }
}

void CharactersManager::for_each(function<void (Character &)> func){
    for(auto &name_obj_pair : characters){
        func(name_obj_pair.second);
    }
}

void CharactersManager::for_each(function<void (const Character &)> func) const{
    for(const auto &name_obj_pair : characters){
        func(name_obj_pair.second);
    }
}

void CharactersManager::for_exact(
        const Character::Name &name,
        function<void (Character &)> func
){
    func(characters.at(name));
}

void CharactersManager::for_exact(
        const Character::Name &name,
        function<void (const Character &)> func
) const{
    func(characters.at(name));
}
