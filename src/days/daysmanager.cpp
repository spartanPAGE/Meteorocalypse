#include "days/daysmanager.hpp"

DaysManager::DaysManager(CharactersManager &cm):
    characters_manager(cm){}

Day DaysManager::fetch_next(){
    //Todo
    return Day(++past_days, characters_manager);
}
