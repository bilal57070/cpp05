#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 20);
        Bureaucrat carol("Carol", 1);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << std::endl;

        alice.executeForm(shrubbery); // Should fail because form is not signed
        alice.executeForm(robotomy);  // Should fail because form is not signed
        alice.executeForm(pardon);    // Should fail because form is not signed

        std::cout << std::endl;

        shrubbery.beSigned(alice);
        robotomy.beSigned(alice);    // Should be successful
        pardon.beSigned(bob);        // Should be successful

        std::cout << std::endl;

        alice.executeForm(shrubbery); // Should be successful
        alice.executeForm(robotomy);  // Should fail because alice's grade is too low
        bob.executeForm(pardon);      // Should fail because Bob's grade is too low

        std::cout << std::endl;

        carol.executeForm(pardon);    // Should be successful

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}