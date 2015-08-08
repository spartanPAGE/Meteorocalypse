#pragma once

#include "Parser/ParserHelper.hpp"

#include "Parser/Collector.hpp"
#include "Parser/CollectedMemory.hpp"
#include "Parser/InterpretStrategiesResponsibilityChain.hpp"
#include "Parser/Parser.hpp"
#include "Util/StreamTools.hpp"

#include "InterpretStrategies/All.hpp"
#include "InterpretStrategies/TagsMapped.hpp"

#include "Parser/StateMachine.hpp"

#include "Default.hpp"
#include "DefaultTree.hpp"

#include <array>
#include <stack>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <functional>



namespace TSILoader{
    using namespace TreeStructInfo;
    using TreeStructInfo::Default::String;

    template<typename MemT>
    using collector_template_type = Collector<MemT>;
    template<typename T>
    using stack_template_type = Default::Stack<T>;
    template<typename T>
    using deque_template_type = Default::Deque<T>;
    using tree_type = Default::Tree;
    using attribute_type = Default::Attribute;

    using memory_type = CollectedMemory<stack_template_type, deque_template_type, tree_type, attribute_type>;
    using collector_type = Collector<memory_type>;

    using string_type = Default::String;
    using chain_type = InterpretStrategiesResponsibilityChain<collector_type, string_type>;
    using machine_type = StateMachine<chain_type>;
    using parser_type = Parser<machine_type>;
    using strategy_type = chain_type::line_handle_strategy_type;
    using dict_type = Default::Map<StrategyTag, strategy_type>;

    using path_type = String;
    tree_type load_tree(const path_type &);
}
