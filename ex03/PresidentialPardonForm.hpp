#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string targ);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &cp);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &cpi);
        
        void    execute(Bureaucrat const &executor) const;
};


#endif