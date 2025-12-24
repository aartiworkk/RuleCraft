#ifndef WARNUSERACTION_H
#define WARNUSERACTION_H

#include "Action.h"

/**
 * WarnUserAction: Sends a warning to the user
 * This is a lightweight action - just a notification
 * 
 * In a real system, this might:
 * - Send an email
 * - Show an in-app notification
 * - Log to database
 */
class WarnUserAction : public Action {
public:
    void perform(const Context& ctx) override {
        std::cout << "  [ACTION] ⚠️  User Warning Issued\n";
        std::cout << "           → Email sent to user\n";
        std::cout << "           → Warning logged to database\n";
    }
};

#endif