#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(){
    target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ): AForm(targ, 145, 137){
    std::cout << "presidentialpardon form constructor called" << std::endl;
    target = targ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Presidentialpardon form destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cp): AForm(cp){
    std::cout << "special presidentialpardon form constructor called" << std::endl;
    *this = cp;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpi){
    std::cout << "presidential overloaded operator called" << std::endl;
    target = cpi.target;
    return *this;
    }

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > 137)
        throw Bureaucrat::GradetoolowException();
    if (this->getsign() == 0)
        throw AForm::FormnotsignedException();
    std::string file;
    file = this->target + "_shrubbery";
    std::ofstream of(file.c_str());
    of << "    *    " << std::endl;
    of << "   ***   " << std::endl;
    of << "  *****  " << std::endl;
    of << " ******* " << std::endl;
    of << "*********" << std::endl;
    of << "   |||   " << std::endl;
    of << "   |||   " << std::endl;

    of.close();
}