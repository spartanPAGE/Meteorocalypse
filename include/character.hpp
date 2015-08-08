#pragma once
#include <string>

struct Character{
    using Name = std::string;
    using Path = std::string;

    Name name;
    Path image_path;

    enum class Personality{
        FRIENDLY, UNFRIENDLY
    } personality;

    struct Health{
        unsigned max;
        unsigned actual;
        double loss_ratio;
        double gain_ratio;
    } health;

    struct Hunger{
        unsigned max;
        unsigned actual;
    } hunger;

    struct Thirst{
        unsigned max;
        unsigned actual;
    } thirst;

    struct SusceptibilityFor{
        double exhaustion;
        double fatique;
    } susceptibilityFor;

    struct Daily{
        struct Strength{
            unsigned max;
            unsigned avail;
        } strength;

        struct Time{
            unsigned max;
            unsigned avail;
        } time;

        struct Hunger{
            unsigned value;
        } hunger;

        struct Thirst{
            unsigned value;
        } thirst;
    };
};

Character::Personality character_personality_from_string(const std::string &);
