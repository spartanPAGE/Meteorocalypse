#include "Catch.hpp"
#include "events/event.hpp"
#include "events/eventbridge.hpp"
#include "events/eventsloader.hpp"

#include <algorithm>
using namespace std;

SCENARIO("Testing events loading", "[EventsLoader]"){
    GIVEN("list of events loaded with EventsLoader"){
        EventsLoader loader("resources/test/", "../Meteorocalypse/resources/test/");
        auto events = load_events(loader);
        WHEN("Validating events existence"){
            THEN("events list is not empty"){
                REQUIRE(!events.empty());
            }
        }
        GIVEN("New event bridge for fancy nodes handling"){
            EventBridge event(events.front());
            WHEN("Validating existence of options"){
                THEN("Options are present"){
                    REQUIRE(event.has_options());
                }
            }
            WHEN("Validating existence of options->items"){
                THEN("options->items are present"){
                    REQUIRE(event.options().has_items());
                }
            }
            WHEN("Validating items"){
                THEN("options->items->{Axe, Rifle, Rat poison} are present"){
                    REQUIRE(event.options().items().exists("Axe"));
                    REQUIRE(event.options().items().exists("Rifle"));
                    REQUIRE(event.options().items().exists("Rat poison"));
                }
            }
            WHEN("Validating chance of possibilities in Axe item"){
                auto chances = event.options().items().the("Axe").possibilities().collect_chances();
                bool found_zero = find(begin(chances), end(chances), 0.0) != end(chances);
                REQUIRE_FALSE(chances.empty());
                REQUIRE_FALSE(found_zero);
            }
            WHEN("Validating randomly picked possibility"){
                auto possibility = event.options().items().the("Axe").possibilities().random();
                THEN("Possibility is not empty"){
                    REQUIRE(possibility.name() != "");
                    REQUIRE(possibility.state() != "");
                    REQUIRE(possibility.chance() != 0.0);
                }
            }
        }
    }
}