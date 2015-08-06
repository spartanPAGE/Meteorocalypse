#include "dayroutine.hpp"

using namespace std;

DayRoutine::DayRoutine(){
    onMorning = bind(&DayRoutine::produce_morning_results, ref(*this), placeholders::_1);
}

void DayRoutine::set_morning_results_consumer(ResultsConsumer &&consumer){
    onMorningResults = consumer;
}

void DayRoutine::set_inventory_distribution_producer(ResultsProducer &&producer){
    onInventoryDistribution = producer;
}

void DayRoutine::set_inventory_distribution_consumer(ResultsConsumer &&consumer){
    onInventoryDistributionResults = consumer;
}

void DayRoutine::for_next(const Day &day){
      onMorningResults(onMorning(day));
      onInventoryDistributionResults(onInventoryDistribution(day));
}

DayRoutine::Results DayRoutine::produce_morning_results(const Day &){
    //TODO;
    return Results{};
}
