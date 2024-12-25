#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Test du constructeur par défaut de Form
        Form f1;
        std::cout << f1.getname() << " form, sign grade: " << f1.getgtosign()
                  << ", exec grade: " << f1.getgtoexec() << ", is signed: " << f1.getsign() << std::endl;

        // Test du constructeur avec paramètres de Form
        Form f2("TopSecret", 50, 25);
        std::cout << f2.getname() << " form, sign grade: " << f2.getgtosign()
                  << ", exec grade: " << f2.getgtoexec() << ", is signed: " << f2.getsign() << std::endl;

        // Test du constructeur par copie de Form
        Form f3(f2);
        std::cout << f3.getname() << " form, sign grade: " << f3.getgtosign()
                  << ", exec grade: " << f3.getgtoexec() << ", is signed: " << f3.getsign() << std::endl;

        // Test de l'opérateur d'affectation de Form
        Form f4;
        f4 = f2;
        std::cout << f4.getname() << " form, sign grade: " << f4.getgtosign()
                  << ", exec grade: " << f4.getgtoexec() << ", is signed: " << f4.getsign() << std::endl;

        // Création de bureaucrates
        Bureaucrat b1("Alice", 45);
        Bureaucrat b2("Bob", 55);

        // Test de la signature de formulaires
        std::cout << "Trying to sign form " << f2.getname() << " with " << b1.getName() << std::endl;
        f2.beSigned(b1);
        std::cout << f2.getname() << " is signed: " << f2.getsign() << std::endl;
        b1.signForm(f2);

        std::cout << "Trying to sign form " << f4.getname() << " with " << b2.getName() << std::endl;
        f4.beSigned(b2);
        std::cout << f4.getname() << " is signed: " << f4.getsign() << std::endl;
        b2.signForm(f4);

        // Test des exceptions
        try {
            Form f5("TooHigh", 0, 25);
        } catch (const Form::GradetoohighException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Form f6("TooLow", 151, 25);
        } catch (const Form::GradetoolowException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            f1.beSigned(b2);
        } catch (const Form::GradetoolowException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
