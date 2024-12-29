#ifndef AForm_HPP
#define AForm_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm{
    private:
        std::string name;
        bool        sign;
        int         gradetosign;
        int         gradetoexec;

    public:
        AForm();
        ~AForm();
        AForm(std::string nm, int gtosign, int gtoexec);
        AForm(AForm const &cpi);
        AForm& operator=(AForm const &cp);
        friend std::ostream& operator<<(std::ostream& out, AForm& AForm);

        virtual std::string getname() const;
        virtual bool getsign() const;
        virtual int getgtosign();
        virtual int getgtoexec();

        class GradetoolowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradetoohighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormnotsignedException : public std::exception {
            public:
                const char *what() const throw();
        };
        void    beSigned(Bureaucrat& h);

        virtual void    execute(Bureaucrat const &executor) const = 0;
};

#endif