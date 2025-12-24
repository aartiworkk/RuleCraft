#ifndef POLICYRULE_H
#define POLICYRULE_H

#include "../engine/Rule.h"
#include "../conditions/Condition.h"
#include "../actions/Action.h"
#include <string>
#include <iostream>

/**
 * PolicyRule: A complete rule with a name, condition, and action
 * This is the GLUE that connects everything together
 * 
 * Structure:
 * - Name: "Excessive Reports Policy"
 * - Condition: "userReports > 3"
 * - Action: "Warn User"
 * 
 * Logic: IF (condition is true) THEN (perform action)
 */
class PolicyRule : public Rule {
private:
    std::string name;       // Human-readable rule name
    Condition* condition;   // The "IF" part
    Action* action;         // The "THEN" part

public:
    /**
     * Constructor
     * @param n Rule name
     * @param c Condition to check
     * @param a Action to perform
     */
    PolicyRule(std::string n, Condition* c, Action* a)
        : name(n), condition(c), action(a) {}

    /**
     * Evaluate: Check if this rule should trigger
     * @param ctx The current context
     * @return true if condition is met
     */
    bool evaluate(const Context& ctx) override {
        std::cout << "📋 Evaluating Rule: \"" << name << "\"\n";
        return condition->check(ctx);
    }

    /**
     * Execute: Perform the action
     * @param ctx The current context
     */
    void execute(const Context& ctx) override {
        std::cout << "✔ Rule Triggered!\n";
        action->perform(ctx);
    }

    /**
     * Destructor: Clean up condition and action
     */
    ~PolicyRule() {
        delete condition;
        delete action;
    }
};

#endif