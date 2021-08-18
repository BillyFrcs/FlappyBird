#pragma once

#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

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
	void AddState(StatePtr newStatePtr, bool isReplacing = true);
	void RemoveState();

	void ProcessStateChanges();

	StatePtr& GetActiveState();

private:
	std::stack<StatePtr> _states;
	StatePtr _newState;

	bool _isAdding;
	bool _isReplacing;
	bool _isRemoving;
};
}

#endif // STATE_MACHINE_HPP