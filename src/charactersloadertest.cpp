#include "Catch.hpp"
#include "charactersmanager.hpp"

SCENARIO("Can load characters", "[CharactersLoader]"){
    GIVEN("New instance of CharactersLoader with paths set on resources->test->characters"){
        CharactersLoader loader("resources/test/characters/", "../Meteorocalypse/resources/test/characters/");
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
                    WHEN("loading characters"){
                        auto characters = loader.load_characters();
                        THEN("the characters size is eq to 2 (count of characters in test->characters)"){
                            REQUIRE(characters.size() == 2);
                        }
                        WHEN("Checking first character (named Tomasz)"){
                            auto &tomasz = characters.front();
                            THEN("Tomasz should match the .tsinfo representation"){
                                REQUIRE(tomasz.name == "Tomasz");
                                REQUIRE(tomasz.personality == Character::Personality::FRIENDLY);
                            }
                        }
                    }
                }
            }
        }
    }
}
