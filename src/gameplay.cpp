#include "gameplay.hpp"

Gameplay::Gameplay():
    characters_manager(CharactersLoader()),
    days_manager(characters_manager)
{
    //Todo: fill dayRoutine with producers/consumers
}

void Gameplay::start(){
    load_all();
    while(is_running()){
        auto day = days_manager.fetch_next();
        day_routine.for_next(day);
    }
}

bool Gameplay::is_running() const{
    return running;
}

bool Gameplay::has_finished() const{
    return !running;
}

void Gameplay::load_all(){
    characters_manager.load_all();
}
