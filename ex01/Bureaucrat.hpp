#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Bureaucrat{
    private:
        std::string name;
        int grade;
    
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string nm, int r);
        Bureaucrat(Bureaucrat const &cpi);
        Bureaucrat& operator=(Bureaucrat const &cp);
        std::string getName()const;
        int getGrade();
        void upgrade();
        void downgrade();

        class GradetoolowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradetoohighException : public std::exception {
            public:
                const char *what() const throw();
        };

        void    signForm(Form &form);
};

#endif