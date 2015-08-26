#include "Catch.hpp"

#include "items/itemsloader.hpp"

SCENARIO("Loading items", "[ItemsLoader]"){
    GIVEN("New instance of ItemsLoader with paths set on resources->test->items"){
        ItemsLoader loader("resources/test/", "../Meteorocalypse/resources/test/");
        WHEN("Loading items"){
            loader.test_paths();
            loader.load_list();
            GIVEN("Loaded list of items"){
                auto items = loader.load(load_item);
                WHEN("Validating size"){
                    THEN("items.size() must be eq 2"){
                        REQUIRE(items.size() == 2);
                    }
                }

                WHEN("Validating items"){
                    THEN("First item is radio and the second is axe"){
                        auto radio = items.front();
                        REQUIRE(radio.name == "radio");

                        auto axe = items.back();
                        REQUIRE(axe.name == "axe");
                    }
                }
            }
        }
    }
}