#include "Catch.hpp"

#include "items/itemsloader.hpp"
#include "items/itemproxy.hpp"

using namespace std;

SCENARIO("Loading items", "[ItemsLoader]"){
    GIVEN("New instance of ItemsLoader with paths set on resources->test->items"){
        ItemsLoader loader("resources/test/", "../Meteorocalypse/resources/test/");
        WHEN("Loading items"){
            loader.test_paths();
            loader.load_list();
            GIVEN("Loaded list of items"){
                auto items = loader.load(load_item);
                WHEN("Validating size"){
                    THEN("items.size() must be eq 3"){
                        REQUIRE(items.size() == 3);
                    }
                }

                WHEN("Validating items"){
                    THEN("First item is radio and the second is axe"){
                        ItemProxy radio(items.front());
                        REQUIRE(radio.name() == "radio");

                        REQUIRE(radio.is_spoilable());
                        REQUIRE_FALSE(radio.is_stackable());

                        ItemProxy axe(*next(items.begin()));
                        REQUIRE(axe.name() == "axe");

                        REQUIRE(radio.is_spoilable());
                        REQUIRE_FALSE(radio.is_stackable());

                        ItemProxy rats_poison(*next(items.begin(), 2));
                        REQUIRE(rats_poison.name() == "Rats poison");

                        REQUIRE_FALSE(rats_poison.is_spoilable());
                        REQUIRE(rats_poison.is_stackable());
                    }
                }
            }
        }
    }
}