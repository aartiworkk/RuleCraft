#ifndef CONTEXT_H
#define CONTEXT_H

/**
 * Context: Represents the current state of a user/situation
 * This is like a "snapshot" of what's happening right now
 * 
 * Example: A user has 5 reports, 3 content violations, 1 login failure
 */
struct Context {
    int userReports;        // How many times this user was reported
    int contentViolations;  // How many times they posted bad content
    int loginFailures;      // How many failed login attempts
    
    // You can add more fields like:
    // int accountAge;
    // bool isPremiumUser;
    // std::string userType;
};

#endif