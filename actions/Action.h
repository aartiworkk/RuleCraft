#ifndef ACTION_H
#define ACTION_H

#include "../Context.h"
#include <iostream>

/**
 * Action: Abstract base class for all actions
 * An action is what happens when a rule triggers
 * 
 * Examples:
 * - Send a warning email
 * - Restrict account access
 * - Ban user permanently
 * - Log the incident
 */
class Action {
public:
    /**
     * Perform the action
     * @param ctx The context (might contain user info, etc.)
     */
    virtual void perform(const Context& ctx) = 0;
    
    // Virtual destructor
    virtual ~Action() {}
};

#endif