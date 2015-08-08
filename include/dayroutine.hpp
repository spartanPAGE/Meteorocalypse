#pragma once
#include "day.hpp"

#include <functional>
#include <map>
#include <string>

class DayRoutine{
public:
    using Results = std::map<std::string, std::string>;
    using ResultsHandler = std::function<void(const Results &)>;

    using ResultsConsumer = ResultsHandler;
    using ResultsProducer = std::function<Results(const Day &)>;
public:
    DayRoutine();
public:
    void set_morning_results_consumer(ResultsConsumer &&);

    void set_inventory_distribution_producer(ResultsProducer &&);
    void set_inventory_distribution_consumer(ResultsConsumer &&);

    void for_next(const Day &);
private:
    Results produce_morning_results(const Day &);
private:
    ResultsProducer onMorning;
    ResultsConsumer onMorningResults;

    ResultsProducer onInventoryDistribution;
    ResultsConsumer onInventoryDistributionResults;
};
