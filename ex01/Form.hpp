#ifndef Form_HPP
#define Form_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form{
    private:
        std::string name;
        bool        sign;
        int         gradetosign;
        int         gradetoexec;

    public:
        Form();
        ~Form();
        Form(std::string nm, int gtosign, int gtoexec);
        Form(Form const &cpi);
        Form& operator=(Form const &cp);
        friend std::ostream& operator<<(std::ostream& out, Form& Form);

        std::string getname();
        bool getsign();
        int getgtosign();
        int getgtoexec();

        class GradetoolowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradetoohighException : public std::exception {
            public:
                const char *what() const throw();
        };

        void    beSigned(Bureaucrat& h);
};

#endif