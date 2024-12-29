#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;

    // Test creating PresidentialPardonForm
    std::cout << "Creating PresidentialPardonForm:" << std::endl;
    AForm *form1 = intern.makeForm("PresidentialPardonForm", "White House");
    if (form1) {
        form1->beSigned(Bureaucrat("Alice", 20)); // Assuming Alice is a bureaucrat with sufficient grade
        Bureaucrat bureaucrat("Bob", 50); // Another bureaucrat
        bureaucrat.executeForm(*form1);
        delete form1;
    }
    std::cout << std::endl;

    // Test creating RobotomyRequestForm
    std::cout << "Creating RobotomyRequestForm:" << std::endl;
    AForm *form2 = intern.makeForm("RobotomyRequestForm", "John Doe");
    if (form2) {
        form2->beSigned(Bureaucrat("Charlie", 72)); // Assuming Charlie is a bureaucrat with sufficient grade
        Bureaucrat bureaucrat("David", 45); // Another bureaucrat
        bureaucrat.executeForm(*form2);
        delete form2;
    }
    std::cout << std::endl;

    // Test creating ShrubberyCreationForm
    std::cout << "Creating ShrubberyCreationForm:" << std::endl;
    AForm *form3 = intern.makeForm("ShrubberyCreationForm", "Home");
    if (form3) {
        form3->beSigned(Bureaucrat("Eve", 145)); // Assuming Eve is a bureaucrat with sufficient grade
        Bureaucrat bureaucrat("Frank", 137); // Another bureaucrat
        bureaucrat.executeForm(*form3);
        delete form3;
    }
    std::cout << std::endl;

    // Test creating an unknown form
    std::cout << "Creating an unknown form:" << std::endl;
    AForm *form4 = intern.makeForm("UnknownForm", "Target");
    if (form4) {
        delete form4; // Should not reach here, as form4 will be NULL
    }

    return 0;
}