#include "Catch.hpp"

#include "daysmanager.hpp"

SCENARIO("Day incrementation", "[DaysManager]"){
    GIVEN("New instance of DaysManager"){
        DaysManager daysManager;
        WHEN("Fetching day for the first time"){
            auto day = daysManager.fetch_next();
            THEN("The day number is 1"){
                REQUIRE(day.number() == 1);
            }
            WHEN("Fetching day for the second time"){
                day = daysManager.fetch_next();
                THEN("The day number is 2"){
                    REQUIRE(day.number() == 2);
                }
            }
        }
    }
}
