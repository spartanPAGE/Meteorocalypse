#pragma once

struct Character{
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
};
