#include "Catch.hpp"

#include "events/eventoptionsrecognizer.hpp"
#include "events/eventsmanager.hpp"

SCENARIO("Testing event options recognizing", "[EventOptionsRecognizer]"){
    GIVEN("Loaded items"){
        auto items_manager = create_items_manager({
            "resources/test/", 
            "../Meteorocalypse/resources/test/"
        });
        items_manager.load_all();
        GIVEN("Loaded event"){
            auto events_manager = create_events_manager({
                "resources/test/", 
                "../Meteorocalypse/resources/test/"
            });
            events_manager.load_all();
            GIVEN("recognizer"){
                events_manager.for_exact("Rats", [&](auto &event){
                    EventOptionsRecognizer event_options_recognizer(event);
                    WHEN("Checking avaiable items"){
                        REQUIRE(event_options_recognizer.any_items());
                        auto items = event_options_recognizer.select().available_items();
                        REQUIRE(items.size() == 3);
                    }
                });
            }
        }
    }
}