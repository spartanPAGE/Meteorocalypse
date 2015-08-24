#include "characters/character.hpp"
#include <exception>

Character::Personality character_personality_from_string(const std::string &str){
    if(str == "FRIENDLY")
        return Character::Personality::FRIENDLY;
    if(str != "UNFRIENDLY")
        throw std::runtime_error("Cannot convert string to character personality; Reason: bad string;" + str);
    return Character::Personality::UNFRIENDLY;
}
