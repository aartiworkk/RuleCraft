#ifndef THRESHOLDCONDITION_H
#define THRESHOLDCONDITION_H

#include <string>
#include <iostream>
#include "Condition.h"
#include "../Context.h"

class ThresholdCondition : public Condition {
private:
    int Context::*field;
    int threshold;
    std::string name;

public:

    ThresholdCondition(int Context::*f, int t, std::string n = "Field")
        : field(f), threshold(t), name(n) {}

    bool check(const Context& ctx) override {
        int value = ctx.*field;
        bool result = value > threshold;
        std::cout << "  → Checking: " << name << " (" << value
                  << ") > " << threshold << " ? "
                  << (result ? "YES" : "NO") << "\n";
        return result;
    }
};

#endif
