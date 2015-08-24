#pragma once
#include <string>

namespace Items{
    struct Radio{
        enum class State{
            WORKING, BROKEN
        } state;
    };

    Radio::State radio_state_from_string(const std::string &);
}