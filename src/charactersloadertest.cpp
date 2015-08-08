#include "Catch.hpp"
#include "charactersmanager.hpp"

SCENARIO("Can load characters", "[CharactersLoader]"){
    GIVEN("New instance of CharactersLoader"){
        CharactersLoader loader;
        WHEN("Trying to load list of characters"){
            THEN("At the begining, path is unspecified"){
                REQUIRE(loader.path_in_use() == CharactersLoader::PathInUse::UNSPECIFIED);
            }
            WHEN("Testing paths"){
                loader.test_paths();
                THEN("Path is no longer unspecified"){
                    REQUIRE(loader.path_in_use() != CharactersLoader::PathInUse::UNSPECIFIED);
                }
                WHEN("Loading characters list"){
                    loader.load_list();
                    THEN("the loaded_list is not empty"){
                        REQUIRE(loader.has_loaded_list());
                    }
                }
            }
        }
    }
}
