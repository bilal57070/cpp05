#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int luck = 0;

RobotomyRequestForm::RobotomyRequestForm(){
    target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string targ): AForm(targ, 72, 45){
    std::cout << "presidentialpardon form constructor called" << std::endl;
    target = targ;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Presidentialpardon form destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cp): AForm(cp){
    std::cout << "special presidentialpardon form constructor called" << std::endl;
    *this = cp;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpi){
    std::cout << "presidential overloaded operator called" << std::endl;
    target = cpi.target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > 45)
        throw Bureaucrat::GradetoolowException();
    if (this->getsign() == 0)
        throw AForm::FormnotsignedException();
    std::cout << "drilling noise" << std::endl;
    if (luck == 0){
        std::cout << target << " has been successfully robotomized" << std::endl;
        luck++;
    }
    else if (luck == 1){
        std::cout << target << " robotomy failed" << std::endl;
        luck--;
    }
}