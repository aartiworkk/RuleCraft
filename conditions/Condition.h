#ifndef CONDITION_H
#define CONDITION_H

#include "../Context.h"

/**
 * Condition: Abstract base class for all conditions
 * A condition is a "checker" - it answers: "Should this rule trigger?"
 * 
 * Examples:
 * - "Are reports > 3?"
 * - "Is account age < 30 days?"
 * - "Is user on probation?"
 */
class Condition {
public:
    /**
     * Check if the condition is met
     * @param ctx The context to check against
     * @return true if condition passes, false otherwise
     */
    virtual bool check(const Context& ctx) = 0;
    
    // Virtual destructor
    virtual ~Condition() {}
};

#endif