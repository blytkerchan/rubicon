#ifndef vlinder_rubicon_compiler_statemachinebuilder_hpp
#define vlinder_rubicon_compiler_statemachinebuilder_hpp

#include "statemachine.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class StateMachineBuilder : private StateMachine
{
public :
        void reset();

        void addState(unsigned int type_class, unsigned int tag, int offs = 0);
        void addToState(unsigned int type_class, unsigned int tag, int offs = 0);
        void commit();

        StateMachine const &get() { return *this; }
private :
        std::deque< State > cache_;
        unsigned int next_state_ = 0;
        bool committed_ = true;
};
}}}

#endif
