#ifndef THRESHOLDCONDITION_H
#define THRESHOLDCONDITION_H

#include "Condition.h"

/**
 * ThresholdCondition: Checks if a value exceeds a threshold
 * This is a CONCRETE implementation of Condition
 * 
 * Example: "Is userReports > 3?"
 * - field points to ctx.userReports
 * - threshold is 3
 * - Returns true if userReports > 3
 */
class ThresholdCondition : public Condition {
private:
    int* field;        // Pointer to the field to check
    int threshold;     // The limit value
    std::string name;  // Description of what we're checking

public:
    /**
     * Constructor
     * @param f Pointer to the integer field in Context
     * @param t Threshold value
     * @param n Description (e.g., "User Reports")
     */
    ThresholdCondition(int* f, int t, std::string n = "Field")
        : field(f), threshold(t), name(n) {}

    /**
     * Check if the field value exceeds the threshold
     * @param ctx Context (not used directly since we have pointer)
     * @return true if *field > threshold
     */
    bool check(const Context& ctx) override {
        bool result = (*field) > threshold;
        std::cout << "  → Checking: " << name << " (" << *field 
                  << ") > " << threshold << " ? " 
                  << (result ? "YES" : "NO") << "\n";
        return result;
    }
};

#endif