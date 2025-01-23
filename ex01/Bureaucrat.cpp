#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    name = "pnj";
    grade = 150;
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string nm, int g){
    name = nm;
    if (g < 1)
        throw Bureaucrat::GradetoohighException();
    if (g > 150)
        throw Bureaucrat::GradetoolowException();
    grade = g;
    std::cout << "special Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cp){
    *this = cp;
    std::cout << "Bureaucrat copie constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cp){
    name = cp.name;
    grade = cp.grade;
    std::cout << "overloaded copy operator called" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat &o){
    out << o.getName() << std::endl;
    out << o.getGrade() << std::endl;
    return (out);
}

std::string Bureaucrat::getName()const{
    return name;
} 

int Bureaucrat::getGrade(){
    return grade;
}

void Bureaucrat::upgrade(){
    grade--;
    if (grade < 1)
        throw Bureaucrat::GradetoohighException();
    std::cout << "successful upgrade !!" << std::endl;
}

void Bureaucrat::downgrade(){
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradetoolowException();
    std::cout << "successful downgrade !!" << std::endl;
}

const char *Bureaucrat::GradetoohighException::what() const throw(){
    return ("grade too high");
}

const char *Bureaucrat::GradetoolowException::what() const throw(){
    return ("grade too low");
}

void    Bureaucrat::signForm(Form &form){
    if (form.getsign() == true)
        std::cout << name << " signed " << form.getname() << std::endl;
    else
        std::cout << name << " couldn't sign " << form.getname() << " because grade too low" << std::endl;
}