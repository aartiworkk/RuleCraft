#ifndef RULEENGINE_H
#define RULEENGINE_H

#include "Rule.h"
#include <vector>
#include <iostream>

/**
 * RuleEngine: The brain of the system
 * It stores all rules and runs them against a context
 * 
 * This is like a moderator who checks every rule in the rulebook
 */
class RuleEngine {
private:
    std::vector<Rule*> rules;  // Collection of all policy rules

public:
    /**
     * Add a new rule to the engine
     * @param rule Pointer to a Rule object
     */
    void addRule(Rule* rule) {
        rules.push_back(rule);
    }

    /**
     * Run all rules against the given context
     * @param ctx The current situation to evaluate
     */
    void run(const Context& ctx) {
        std::cout << "\n========== POLICY ENGINE STARTED ==========\n";
        std::cout << "Context: Reports=" << ctx.userReports 
                  << ", Violations=" << ctx.contentViolations 
                  << ", Login Failures=" << ctx.loginFailures << "\n\n";
        
        // Check each rule one by one
        for (Rule* rule : rules) {
            if (rule->evaluate(ctx)) {
                rule->execute(ctx);
            } else {
                std::cout << "✘ Not Triggered\n";
            }
            std::cout << "\n";
        }
        
        std::cout << "========== ENGINE EXECUTION COMPLETE ==========\n";
    }

    /**
     * Destructor: Clean up allocated memory
     * Important: Prevents memory leaks
     */
    ~RuleEngine() {
        for (Rule* rule : rules) {
            delete rule;
        }
    }
};

#endif