#include "statemachinebuilder.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
void StateMachineBuilder::reset()
{
        *this = StateMachineBuilder();
}
void StateMachineBuilder::addState(unsigned int type_class, unsigned int tag, int offs/* = 0*/)
{
        commit();
        addToState(type_class, tag, offs);
}
void StateMachineBuilder::addToState(unsigned int type_class, unsigned int tag, int offs/* = 0*/)
{
        cache_.push_back({0, type_class, tag, offs});
        committed_ = false;
}
void StateMachineBuilder::commit()
{
        if (!committed_)
        {
                for (auto new_state : cache_)
                {
                        new_state.state_ = next_state_;
                        new_state.next_state_ += next_state_ + 1;
                        states_.push_back(new_state);
                }
                cache_.clear();
                committed_ = true;
                ++next_state_;
                state_count_ = next_state_;
        }
        else
        { /* already committed */ }
}
}}}
