#include "class.h"
#include "student.h"
#include <iostream>

int main() {
    // Create some students
    Student s1("Davis", "MATH", 15);
    Student s2("Walker", "COMPSCI", 15);
    Student s3("Rivers", "COMPSCI", 15);

    // Create some classes
    Class c1("MATH131", 50, false); 
    Class c2("COMPSCI377", 50, true); 
    Class c3("ECON103", 1, true);
    Class c4("COMPSCI121", 100, true);

    // Students add classes
    s1.addClass(&c1);
    s2.addClass(&c2);
    s3.addClass(&c3);
    s3.addClass(&c4);

    // Students drop classes
    s2.dropClass(&c2);

    // Students switch classes
    s1.switchClass(&c1, &c4);

    // Output classes' student names
    std::cout << "Students in " << c1.getName() << ": ";
    for(auto student : c1.getStudents()) {
        std::cout << student->getName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Students in " << c2.getName() << ": ";
    for(auto student : c2.getStudents()) {
        std::cout << student->getName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Students in " << c3.getName() << ": ";
    for(auto student : c3.getStudents()) {
        std::cout << student->getName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Students in " << c4.getName() << ": ";
    for(auto student : c4.getStudents()) {
        std::cout << student->getName() << " ";
    }
    std::cout << std::endl;

    return 0;
}