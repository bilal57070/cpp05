#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

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
        friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& o);
        std::string getName()const;
        int getGrade()const;
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

        void    signForm(AForm &form);

        void    executeForm(AForm const &form);
};

#endif