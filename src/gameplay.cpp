#include "gameplay.hpp"

Gameplay::Gameplay():
    characters_manager(CharactersLoader()),
    days_manager(characters_manager)
{
    //Todo: fill day_routine with producers/consumers
    day_routine.set_morning_results_consumer([](DayRoutine::Results const &){});
    day_routine.set_inventory_distribution_consumer([](DayRoutine::Results const &){});
    day_routine.set_inventory_distribution_producer([](const Day &){ return DayRoutine::Results{}; });
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
