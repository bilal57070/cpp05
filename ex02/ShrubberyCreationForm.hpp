#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string targ);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &cp);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &cpi);

        void    execute(Bureaucrat const &executor) const;
};



#endif