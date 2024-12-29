#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(){
    name = "pnj";
    gradetosign = 150;
    gradetoexec = 150;
    sign = false;
    std::cout << "default Form constructor called" << std::endl;
}

Form::~Form(){
    std::cout << "default Form destructor called" << std::endl;
}

Form::Form(std::string nm, int gsign, int gexec){
    if (gsign < 1 || gexec < 1)
        throw Form::GradetoohighException();
    if (gsign > 150 || gexec > 150)
        throw Form::GradetoolowException();
    name = nm;
    gradetosign = gsign;
    gradetoexec = gexec;
    sign = false;
}

Form::Form(Form const &cpi){
    std::cout << "copy Form constructor called" << std::endl;
    *this = cpi;
}

Form    &Form::operator=(Form const &cp){
    std::cout << "overloaded Form copy operator called" << std::endl;
    name = cp.name;
    gradetosign = cp.gradetosign;
    gradetoexec = cp.gradetoexec;
    sign = cp.sign;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Form& Form){
    out << Form.getname();
    out << Form.getgtosign();
    out << Form.getgtoexec();
    out << Form.getsign();
    return (out);
}

std::string Form::getname(){
    return (name);
}

bool    Form::getsign(){
    return (sign);
}

int     Form::getgtosign(){
    return (gradetosign);
}

int     Form::getgtoexec(){
    return (gradetoexec);
}

const char *Form::GradetoohighException::what() const throw(){
    return ("grade too high");
}

const char *Form::GradetoolowException::what() const throw(){
    return ("grade too low");
}

void    Form::beSigned(Bureaucrat& h){
    if (h.getGrade() > this->getgtosign())
        throw Form::GradetoolowException();
    else
        this->sign = true;
}