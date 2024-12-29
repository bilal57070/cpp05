#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string targ);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &cp);
        RobotomyRequestForm& operator=(RobotomyRequestForm const &cpi);

        void    execute(Bureaucrat const &executor) const;
};



#endif