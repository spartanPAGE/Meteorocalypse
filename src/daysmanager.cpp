#include "daysmanager.hpp"

DaysManager::DaysManager(){
    past_days = 0;
}

Day DaysManager::fetch_next(){
    //Todo
    return Day(++past_days);
}
