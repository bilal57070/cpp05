#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(){
    name = "default";
    gradetosign = 150;
    gradetoexec = 150;
    sign = false;
    std::cout << "default AForm constructor called" << std::endl;
}

AForm::~AForm(){
    std::cout << "default AForm destructor called" << std::endl;
}

AForm::AForm(std::string nm, int gsign, int gexec){
    std::cout << "special AFORm constructor called" << std::endl;
    if (gsign < 1 || gexec < 1)
        throw AForm::GradetoohighException();
    if (gsign > 150 || gexec > 150)
        throw AForm::GradetoolowException();
    name = nm;
    gradetosign = gsign;
    gradetoexec = gexec;
    sign = false;
}

AForm::AForm(AForm const &cpi){
    std::cout << "copy AForm constructor called" << std::endl;
    *this = cpi;
}

AForm    &AForm::operator=(AForm const &cp){
    std::cout << "overloaded AForm copy operator called" << std::endl;
    name = cp.name;
    gradetosign = cp.gradetosign;
    gradetoexec = cp.gradetoexec;
    sign = cp.sign;
    return *this;
}

std::ostream& operator<<(std::ostream& out, AForm& AForm){
    out << AForm.getname();
    out << AForm.getgtosign();
    out << AForm.getgtoexec();
    out << AForm.getsign();
    return (out);
}

std::string AForm::getname() const{
    return (name);
}

bool    AForm::getsign() const{
    return (sign);
}

int     AForm::getgtosign(){
    return (gradetosign);
}

int     AForm::getgtoexec(){
    return (gradetoexec);
}

const char *AForm::GradetoohighException::what() const throw(){
    return ("grade too high");
}

const char *AForm::GradetoolowException::what() const throw(){
    return ("grade too low");
}

const char *AForm::FormnotsignedException::what() const throw(){
    return ("form not signed");
}

void    AForm::beSigned(Bureaucrat const &h){
    if (h.getGrade() > this->getgtosign())
        throw AForm::GradetoolowException();
    else{
        std::cout << "signed" << std::endl;
        this->sign = true;
    }
}