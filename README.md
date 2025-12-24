# Rulecraft – Rule-Based Policy Execution Engine (OOPS Project)

## Overview
Rulecraft is a rule-based policy execution engine developed using C++. The project demonstrates the practical application of Object-Oriented Programming (OOPS) principles by evaluating predefined rules and executing corresponding actions based on condition–action logic. It simulates real-world systems such as platform moderation, access control, and policy enforcement engines.

---

## Project Objectives
- Design a scalable rule execution engine using OOPS principles
- Implement condition–action based policy evaluation
- Build a modular and extensible system architecture
- Demonstrate real-world use cases of rule-based systems

---

## Key Features
- Rule definition and execution using condition–action logic
- Modular and extensible architecture
- Dynamic rule evaluation at runtime
- Clear separation of concerns across components

---

## OOPS Concepts Used
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

---

## Technologies Used
- C++
- Standard Template Library (STL)
- VS Code

---

## System Design
The system is centered around a Rule Engine that manages multiple rule objects. Each rule evaluates a condition and triggers an action when the condition is satisfied. The design allows new rules to be added without modifying existing code, ensuring scalability and maintainability.

---

## How to Run the Project

### 1. Compile the Source Code
```bash
g++ main.cpp Rule.cpp RuleEngine.cpp -o rulecraft
```
### 2. Execute the Program
```bash
./rulecraft
```
## Learning Outcomes
- Strong understanding of Object-Oriented Programming concepts
- Experience designing modular and extensible systems
- Ability to model real-world policy logic in C++
- Improved software design and problem-solving skills

---

## Future Enhancements
- File-based or database-driven rule configuration
- Priority-based rule execution
- Logging and audit trail support
- Graphical or web-based user interface

---

## Conclusion
Rulecraft demonstrates how Object-Oriented Programming principles can be used to design scalable rule-based systems. The project emphasizes clean architecture, modularity, and extensibility, making it suitable for real-world policy-driven applications.
