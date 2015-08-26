#include "Catch.hpp"
#include "events/event.hpp"
#include "events/eventsloader.hpp"

SCENARIO("Testing events loading", "[EventsLoader]"){
    GIVEN("list of events loaded with EventsLoader"){
        EventsLoader loader("resources/test/", "../Meteorocalypse/resources/test/");
        auto events = load_events(loader);
        WHEN("Validating events existence"){
            THEN("events list is not empty"){
                REQUIRE(!events.empty());
                //TODO: add events options possibility checking
            }
        }
    }
}