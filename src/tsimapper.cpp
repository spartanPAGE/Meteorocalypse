#include "tsimapper.hpp"
using namespace std;

Character TSIMapper::to_character(const TreeStructInfo::Default::Tree &tree){
    Character character;

    character.name = tree.name;
    character.image_path = tree.findAttribute("image path");
    character.personality = character_personality_from_string(tree.findAttribute("personality"));

    const auto &health_node = tree.findNode("Health");
    character.health.max        = stoul(health_node.findAttribute("max"));
    character.health.loss_ratio = stod(health_node.findAttribute("loss ratio"));
    character.health.gain_ratio = stod(health_node.findAttribute("gain ratio"));

    const auto &hunger_node = tree.findNode("Hunger");
    character.hunger.max = stoul(hunger_node.findAttribute("max"));

    const auto &thirst_node = tree.findNode("Thirst");
    character.thirst.max = stoul(thirst_node.findAttribute("max"));

    const auto &susceptibility_for_node = tree.findNode("Susceptibility For");
    character.susceptibilityFor.exhaustion = stod(susceptibility_for_node.findAttribute("exhaustion"));
    character.susceptibilityFor.fatique    = stod(susceptibility_for_node.findAttribute("fatique"));

    const auto &strength_node = tree.findNode("Strength");
    character.strength.max = stoul(strength_node.findAttribute("max"));

    const auto &time_node = tree.findNode("Time");
    character.time.max = stoul(time_node.findAttribute("max"));
    return character;
}
