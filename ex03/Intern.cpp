#include "Intern.hpp"

Intern::Intern(){
    std::cout << "intern constructor called" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &cp){
    std::cout << "Intern copy constructor called" << std::endl;
    *this = cp;
}

Intern& Intern::operator=(Intern const &cpi){
    std::cout << "overloaded Intern operator called" << std::endl;
    if (this == &cpi){
        return *this;
    }
    return *this;
}

AForm* President(const std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Robot(const std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Shrubbery(const std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target){
    AForm* (*all_form[])(const std::string targ) = {&President, &Robot, &Shrubbery};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (int i = 0; i < 3; i++){
        if (forms[i] == name){
            std::cout << "intern creates " << name << std::endl;
            return (all_form[i](target));
        }
    }
    std::cout << "intern cant creates " << name << std::endl;
    return (NULL);
}