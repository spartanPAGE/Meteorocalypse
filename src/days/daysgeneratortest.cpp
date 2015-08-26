#include "Catch.hpp"

#include "days/DaysGenerator.hpp"

#include <utility>
using namespace std;

SCENARIO("Day incrementation", "[DaysGenerator]"){
    GIVEN("New instance of DaysGenerator"){
        CharactersLoader characters_loader;
        auto characters_manager = create_characters_manager(move(characters_loader));
        DaysGenerator days_manager(characters_manager);
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
