#include "gameplay.hpp"

Gameplay::Gameplay(): running(true), charactersManager(CharactersLoader()){
    //Todo: fill dayRoutine with producers/consumers
}

void Gameplay::start(){
    load_all();
    while(is_running()){
        auto day = daysManager.fetch_next();
        dayRoutine.for_next(day);
    }
}

bool Gameplay::is_running() const{
    return running;
}

bool Gameplay::has_finished() const{
    return !running;
}

void Gameplay::load_all(){
    charactersManager.load_all();
}
