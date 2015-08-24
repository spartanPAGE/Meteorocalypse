#include "items/Radio.hpp"
#include <exception>
using namespace std;
namespace Items{
    Radio::State radio_state_from_string(const string &val){
        if(val == "WORKING")
            return Radio::State::WORKING;
        if(val != "BROKEN")
            throw runtime_error("Cannot convert from string to radio state; Reason: Bad string;" + val);
        return Radio::State::BROKEN;
    }
}