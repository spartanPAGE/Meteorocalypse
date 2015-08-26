#include "Catch.hpp"

#include "days/daysmanager.hpp"

#include <utility>
using namespace std;

SCENARIO("Day incrementation", "[DaysManager]"){
    GIVEN("New instance of DaysManager"){
        CharactersLoader characters_loader;
        auto characters_manager = create_characters_manager(move(characters_loader));
        DaysManager days_manager(characters_manager);
        WHEN("Fetching day for the first time"){
            auto day1 = days_manager.fetch_next();
            THEN("The day number is 1"){
                REQUIRE(day1.number() == 1);
            }
            WHEN("Fetching day for the second time"){
                auto day2 = days_manager.fetch_next();
                THEN("The day number is 2"){
                    REQUIRE(day2.number() == 2);
                }
            }
        }
    }
}
