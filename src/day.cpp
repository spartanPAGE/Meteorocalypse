#include "day.hpp"

Day::Day(Number num): id(num){}

Day::Number Day::number() const{
    return id;
}
