#include "class.h"
#include "student.h"
#include <iostream>

int main() {
    // Create some students
    Student s1("Alice", "Math", 20);
    Student s2("Bob", "Computer Science", 20);
    Student s3("Charlie", "Physics", 20);

    // Create some classes
    Class c1("Math101", 2, false); 
    Class c2("CS101", 2, true); 
    Class c3("Physics101", 2, true); 

    // Students add classes
    std::cout << "Alice adds Math101: " << (s1.addClass(&c1) ? "Success" : "Failed") << std::endl;
    std::cout << "Alice adds CS101: " << (s1.addClass(&c2) ? "Success" : "Failed") << std::endl;
    std::cout << "Bob adds Math101: " << (s2.addClass(&c1) ? "Success" : "Failed") << std::endl;
    std::cout << "Bob adds CS101: " << (s2.addClass(&c2) ? "Success" : "Failed") << std::endl;
    std::cout << "Charlie adds Physics101: " << (s3.addClass(&c3) ? "Success" : "Failed") << std::endl;

    // Students drop classes
    std::cout << "Alice drops Math101: " << (s1.dropClass(&c1) ? "Success" : "Failed") << std::endl;
    std::cout << "Bob drops CS101: " << (s2.dropClass(&c2) ? "Success" : "Failed") << std::endl;

    return 0;
}