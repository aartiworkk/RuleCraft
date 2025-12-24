#ifndef RULE_H
#define RULE_H

#include "../Context.h"

/**
 * Rule: Abstract base class (interface) for all rules
 * This is pure OOP - any specific rule MUST implement these methods
 * 
 * Think of this as a "contract" - every rule must:
 * 1. Check if it applies (evaluate)
 * 2. Do something if it applies (execute)
 */
class Rule {
public:
    // Check if this rule should trigger
    virtual bool evaluate(const Context& ctx) = 0;
    
    // Execute the action associated with this rule
    virtual void execute(const Context& ctx) = 0;
    
    // Virtual destructor for proper cleanup
    virtual ~Rule() {}
};

#endif