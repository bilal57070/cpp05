#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &cp);
        Intern& operator=(Intern const &cpi);

        AForm* makeForm(std::string name, std::string target);
};




#endif