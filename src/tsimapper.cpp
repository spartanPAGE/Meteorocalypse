#include "tsimapper.hpp"
#include "CandiedTree.hpp"
using namespace std;
using TreeStructInfo::makeCandied;

Character TSIMapper::to_character(const TreeStructInfo::Default::Tree &tree){
    Character character;
    auto candied = makeCandied(tree);

    character.name       = candied.name();
    character.image_path = candied.readValue("image path");
    character.personality = character_personality_from_string(candied.readValue("personality"));

    character.health.max        = candied.readUnsigned  ("Health/max",        0);
    character.health.loss_ratio = candied.readReal      ("Health/loss ratio", 0.0);
    character.health.gain_ratio = candied.readReal      ("Health/gain ratio", 0.0);

    character.hunger.max = candied.readUnsigned("Hunger/max", 0);
    character.thirst.max = candied.readUnsigned("Thirst/max", 0);

    character.susceptibilityFor.exhaustion = candied.readReal("Susceptibility For/exhaustion", 0.0);
    character.susceptibilityFor.fatique    = candied.readReal("Susceptibility For/fatique",    0.0);

    character.strength.max = candied.readUnsigned("Strength/max", 0);
    character.time.max     = candied.readUnsigned("Time/max", 0);

    return character;
}
