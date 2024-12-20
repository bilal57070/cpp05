#include "Bureaucrat.hpp"

int main() {
    try {
        // Test du constructeur par défaut
        Bureaucrat b1;
        std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;

        // Test du constructeur avec paramètres
        Bureaucrat b2("John", 100);
        std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;

        // Test du constructeur par copie
        Bureaucrat b3(b2);
        std::cout << b3.getName() << " has grade " << b3.getGrade() << std::endl;

        // Test de l'opérateur d'affectation
        Bureaucrat b4;
        b4 = b2;
        std::cout << b4.getName() << " has grade " << b4.getGrade() << std::endl;

        // Test de l'incrémentation du grade
        b2.upgrade();
        std::cout << b2.getName() << " after increment has grade " << b2.getGrade() << std::endl;

        // Test de la décrémentation du grade
        b2.downgrade();
        std::cout << b2.getName() << " after decrement has grade " << b2.getGrade() << std::endl;

        // Test des exceptions
        try {
            Bureaucrat b5("TooHigh", 0);
        } catch (const Bureaucrat::GradetoohighException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Bureaucrat b6("TooLow", 151);
        } catch (const Bureaucrat::GradetoolowException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            b2.upgrade();
            b2.upgrade();
            // Assuming initial grade was 150
        } catch (const Bureaucrat::GradetoolowException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            b2.downgrade();
            b2.downgrade();
            // Assuming initial grade was 1
        } catch (const Bureaucrat::GradetoohighException &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}