#include "charactersmanager.hpp"

CharactersLoader::CharactersLoader(const Path &main, const Path &alter):
    main_path(main), alternative_path(alter){}

CharactersLoader::CharactersLoader(Path &&main, Path &&alter):
    main_path(main), alternative_path(alter){}

CharactersManager::CharactersManager(CharactersLoader &&loader):
    characters_loader(loader){}
