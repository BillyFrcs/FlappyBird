#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace BillyEngine
{
    typedef std::unique_ptr<State> StatePtr;

    class StateMachine
    {
    public:
        StateMachine();
        ~StateMachine();

        // States machine methods
        void addState(StatePtr newStatePtr, bool isReplacing = true);
        void removeState();

        void processStateChanges();

        StatePtr &getActiveState()
        {
            return this->_states.top();
        }

    private:
        std::stack<StatePtr> _states;
        StatePtr _newState;

        bool _isAdding;
        bool _isReplacing;
        bool _isRemoving;
    };
}