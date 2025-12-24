#include <iostream>
#include "Context.h"
#include "engine/RuleEngine.h"
#include "rules/PolicyRule.h"
#include "conditions/ThresholdCondition.h"
#include "actions/WarnUserAction.h"
#include "actions/RestrictAccountAction.h"

/**
 * ============================================
 * PLATFORM MODERATION & POLICY ENGINE
 * ============================================
 * 
 * This system automatically enforces platform rules.
 * 
 * HOW IT WORKS:
 * 1. Context = Current situation (user stats)
 * 2. Rules = IF (condition) THEN (action)
 * 3. Engine = Runs all rules against context
 * 
 * KEY OOP CONCEPTS DEMONSTRATED:
 * ✓ Abstraction (Rule, Condition, Action interfaces)
 * ✓ Inheritance (PolicyRule extends Rule)
 * ✓ Polymorphism (Different conditions and actions)
 * ✓ Encapsulation (Each class has specific responsibility)
 * ============================================
 */

int main() {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║  PLATFORM MODERATION POLICY ENGINE    ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";

    // ========================================
    // STEP 1: Create a Context (user situation)
    // ========================================
    Context ctx{5, 3, 1};  // userReports=5, contentViolations=3, loginFailures=1
    
    std::cout << "📊 User Profile Created:\n";
    std::cout << "   - User Reports: " << ctx.userReports << "\n";
    std::cout << "   - Content Violations: " << ctx.contentViolations << "\n";
    std::cout << "   - Login Failures: " << ctx.loginFailures << "\n";

    // ========================================
    // STEP 2: Create the Rule Engine
    // ========================================
    RuleEngine engine;

    // ========================================
    // STEP 3: Define Policy Rules
    // ========================================
    
    // RULE 1: Too many user reports → Warn user
    engine.addRule(new PolicyRule(
        "Excessive Reports Policy",
        new ThresholdCondition(&ctx.userReports, 3, "User Reports"),
        new WarnUserAction()
    ));

    // RULE 2: Too many content violations → Restrict account
    engine.addRule(new PolicyRule(
        "Content Violation Policy",
        new ThresholdCondition(&ctx.contentViolations, 2, "Content Violations"),
        new RestrictAccountAction()
    ));

    // RULE 3: Failed login attempts → Warn (security concern)
    engine.addRule(new PolicyRule(
        "Login Failure Policy",
        new ThresholdCondition(&ctx.loginFailures, 5, "Login Failures"),
        new WarnUserAction()
    ));

    // ========================================
    // STEP 4: Run the Engine
    // ========================================
    engine.run(ctx);

    // ========================================
    // DEMO: Change context and run again
    // ========================================
    std::cout << "\n\n";
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║  TESTING WITH DIFFERENT CONTEXT       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    Context ctx2{2, 1, 10};  // Low reports, low violations, HIGH login failures
    
    RuleEngine engine2;
    engine2.addRule(new PolicyRule(
        "Excessive Reports Policy",
        new ThresholdCondition(&ctx2.userReports, 3, "User Reports"),
        new WarnUserAction()
    ));
    engine2.addRule(new PolicyRule(
        "Content Violation Policy",
        new ThresholdCondition(&ctx2.contentViolations, 2, "Content Violations"),
        new RestrictAccountAction()
    ));
    engine2.addRule(new PolicyRule(
        "Login Failure Policy",
        new ThresholdCondition(&ctx2.loginFailures, 5, "Login Failures"),
        new WarnUserAction()
    ));
    
    engine2.run(ctx2);

    std::cout << "\n✅ Program completed successfully!\n\n";

    return 0;
}