#ifndef RESTRICTACCOUNTACTION_H
#define RESTRICTACCOUNTACTION_H

#include "Action.h"

/**
 * RestrictAccountAction: Temporarily restricts user access
 * This is a moderate action - limits what user can do
 * 
 * In a real system, this might:
 * - Disable posting for 24 hours
 * - Hide user's content
 * - Prevent messaging
 */
class RestrictAccountAction : public Action {
public:
    void perform(const Context& ctx) override {
        std::cout << "  [ACTION] 🚫 Account Restricted\n";
        std::cout << "           → Posting disabled for 24 hours\n";
        std::cout << "           → User notified of restriction\n";
        std::cout << "           → Case logged for review\n";
    }
};

#endif