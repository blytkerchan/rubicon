#ifndef vlinder_rubicon_compiler_statemachine_hpp
#define vlinder_rubicon_compiler_statemachine_hpp

#include <deque>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct StateMachine
{
        struct State
        {
                unsigned int state_;
                unsigned int type_class_;
                unsigned int tag_;
                int next_state_;
        };

        std::deque< State > states_;
        unsigned int state_count_ = 0;
};
}}}

#endif
