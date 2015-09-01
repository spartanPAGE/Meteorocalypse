#include "Catch.hpp"

#include "items/itemsmanager.hpp"
#include "events/eventsmanager.hpp"

#include "events/eventproxy.hpp"

SCENARIO("Testing event options recognizing", "[EventOptionsSelectionProxy]"){
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
                    EventProxy proxy(event);
                    WHEN("Checking avaiable items"){
                        REQUIRE(proxy.options().has_items());
                        auto items = proxy.select().available_items();
                        REQUIRE(items.size() == 3);
                    }
                });
            }
        }
    }
}