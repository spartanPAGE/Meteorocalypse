#include "days/day.hpp"

Day::Day(Number num, CharactersManager &manager):
    id(num), characters_manager(manager){}

Day::Number Day::number() const{
    return id;
}
