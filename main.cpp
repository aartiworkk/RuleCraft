#include <iostream>
#include "Context.h"
#include "engine/RuleEngine.h"
#include "rules/PolicyRule.h"
#include "conditions/ThresholdCondition.h"
#include "actions/WarnUserAction.h"
#include "actions/RestrictAccountAction.h"

int main() {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║  PLATFORM MODERATION POLICY ENGINE    ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";

    RuleEngine engine;
    engine.addRule(new PolicyRule(
        "Excessive Reports Policy",
        new ThresholdCondition(&Context::userReports, 3, "User Reports"),
        new WarnUserAction()
    ));
    engine.addRule(new PolicyRule(
        "Content Violation Policy",
        new ThresholdCondition(&Context::contentViolations, 2, "Content Violations"),
        new RestrictAccountAction()
    ));
    engine.addRule(new PolicyRule(
        "Login Failure Policy",
        new ThresholdCondition(&Context::loginFailures, 5, "Login Failures"),
        new WarnUserAction()
    ));

    Context ctx{5, 3, 1};
    std::cout << " User Profile Created:\n";
    std::cout << "   - User Reports: " << ctx.userReports << "\n";
    std::cout << "   - Content Violations: " << ctx.contentViolations << "\n";
    std::cout << "   - Login Failures: " << ctx.loginFailures << "\n";
    engine.run(ctx);

    std::cout << "\n\n";
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║  TESTING WITH DIFFERENT CONTEXT       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";

    Context ctx2{2, 1, 10};
    std::cout << " User Profile Created:\n";
    std::cout << "   - User Reports: " << ctx2.userReports << "\n";
    std::cout << "   - Content Violations: " << ctx2.contentViolations << "\n";
    std::cout << "   - Login Failures: " << ctx2.loginFailures << "\n";
    engine.run(ctx2);

    std::cout << "\n Program completed successfully!\n\n";
    return 0;
}
