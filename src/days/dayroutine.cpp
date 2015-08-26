#include "days/dayroutine.hpp"

using namespace std;

DayRoutine::DayRoutine(){
    on_morning = bind(&DayRoutine::produce_morning_results, ref(*this), placeholders::_1);
}

void DayRoutine::set_morning_results_consumer(ResultsConsumer &&consumer){
    on_morning_results = consumer;
}

void DayRoutine::set_inventory_distribution_producer(ResultsProducer &&producer){
    on_inventory_distribution = producer;
}

void DayRoutine::set_inventory_distribution_consumer(ResultsConsumer &&consumer){
    on_inventory_distribution_results = consumer;
}

void DayRoutine::for_next(const Day &day){
      on_morning_results(on_morning(day));
      on_inventory_distribution_results(on_inventory_distribution(day));
}

DayRoutine::Results DayRoutine::produce_morning_results(const Day &){
    //TODO;
    return Results{};
}
