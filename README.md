# Student and Class Management System

This project provides a representation of students and classes in a university setting, with functionality for students to enroll, drop, and switch classes.

## Student

**Attributes**

* std::string name: The name of the student.
* std::string major: The major of the student.
* int maxCredits: The maximum number of credits the student can take.
* int currentCredits: The current number of credits the student is enrolled in.
* std::vector<Class*> classes: The list of classes the student is currently enrolled in.

**Functions**

* Getter and setter methods for name, major, maxCredits, and currentCredits.
* Getter method for classes.
* bool addClass: Adds a class to the student's schedule. Checks for class availability (if the class has reached its capacity) and student availability (if the student will exceed their max credits by adding this class, and if the student is eligible to take this class). Returns true if the class is successfully added, false otherwise.
* bool dropClass: Drops a class from the student's schedule. For the class, checks if a new student from the waitlist can enroll in this class after this student drops it. Returns true if the class is successfully dropped, false otherwise.
* bool switchClass: Switches one class for another in the student's schedule. The conditions checked are a combination of the conditions for adding and dropping classes. Returns true if the switch is successful, false otherwise.

## Class

**Attributes**

* std::string name: The name of the class.
* std::string major: The major associated with the class.
* int difficulty: The difficulty level of the class.
* int credit: The credit value of the class.
* std::vector<Student*> students: The list of students currently enrolled in the class.
* std::vector<Student*> waitlist: The waitlist of students for the class.
* int capacity: The maximum number of students that can be enrolled in the class.

**Functions**

* Getter and setter methods for name, major, difficulty, credit, students, waitlist, and capacity.
* bool addStudent: Adds a student to the class or to the waitlist, depending on class capacity. Checks if the student will exceed their max credits by adding this class, and if the student is eligible to take this class. Returns true if the student is successfully added to the class or waitlist, false otherwise.
* void dropStudent: Drops a student from the class. If a student is dropped, checks if a student from the waitlist can be moved to the class.
* int getDifficulty: Returns the difficulty level of the class.
* int getCredit: Returns the credit value of the class.
