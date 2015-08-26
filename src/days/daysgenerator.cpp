#include "days/DaysGenerator.hpp"

DaysGenerator::DaysGenerator(CharactersManager &cm):
    characters_manager(cm){}

Day DaysGenerator::fetch_next(){
    //Todo
    return Day(++past_days, characters_manager);
}
