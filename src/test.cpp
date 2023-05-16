#include "class.h"
#include "student.h"
#include <iostream>

void testAddClass() {
    Student s("Student1", "MATH", 15);
    Class c("MATH101", 50, false);

    if (!s.addClass(&c)) {
        std::cout << "testAddClass failed: Expected to add class successfully." << std::endl;
    }
}

void testDropClass() {
    Student s("Student1", "MATH", 15);
    Class c("MATH101", 50, false);

    s.addClass(&c);

    if (!s.dropClass(&c)) {
        std::cout << "testDropClass failed: Expected to drop class successfully." << std::endl;
    }else {
        std::cout << "testDropClass drops class successfully." << std::endl;
    }
}

void testSwitchClass() {
    Student s("Student1", "MATH", 15);
    Class c1("MATH101", 50, false);
    Class c2("MATH102", 50, false);

    s.addClass(&c1);

    if (!s.switchClass(&c1, &c2)) {
        std::cout << "testSwitchClass failed: Expected to switch class successfully." << std::endl;
    } else {
        std::cout << "testSwitchClass switchs class successfully." << std::endl;
    }
}

void testClassCapacity() {
    Student s1("Student1", "MATH", 15);
    Student s2("Student2", "MATH", 15);
    Class c("MATH101", 1, false);

    s1.addClass(&c);

    if (s2.addClass(&c)) {
        std::cout << "testClassCapacity failed: Expected class to be full." << std::endl;
    } else {
        std::cout << "testClassCapacity success, class is full already." << std::endl;
    }
}

int main() {
    testAddClass();
    testDropClass();
    testSwitchClass();
    testClassCapacity();
    return 0;
}
