#include "tsiloader.hpp"
#include <fstream>

namespace TSILoader{
    tree_type load_tree(const path_type &path){
        parser_type parser;
        std::ifstream in(path);
        if(!in.good()) throw std::runtime_error("Invalid path");
        return parser.loadTreeFromTextStream(in);
    }
}
