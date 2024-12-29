#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string targ): AForm(targ, 25, 5){
    std::cout << "presidentialpardon form constructor called" << std::endl;
    target = targ;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidentialpardon form destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cp): AForm(cp){
    std::cout << "special presidentialpardon form constructor called" << std::endl;
    *this = cp;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpi){
    std::cout << "presidential overloaded operator called" << std::endl;
    target = cpi.target;
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > 5)
        throw Bureaucrat::GradetoolowException();
    if (this->getsign() == 0)
        throw AForm::FormnotsignedException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}