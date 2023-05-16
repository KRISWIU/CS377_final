#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include <pthread.h>
#include "student.h"

class Student;

class Class {
    private:
        std::string name;
        std::string major;
        int difficulty;
        int credit;
        std::vector<Student*> students;
        std::vector<Student*> waitlist;
        int capacity;
        bool labOrNot;
        pthread_mutex_t classLock;
        
    public:
        // constructor
        Class(std::string name, int capacity = 20, bool labOrNot = false);
        ~Class();

        // get/set
        std::string getName() const;
        std::string getMajor() const;
        int getDifficulty() const;
        int getCredit() const;  // New getter for credit
        std::vector<Student*> getStudents();
        int getCapacity();
        std::vector<Student*> getWaitlist();
        
        // add/drop student
        bool addStudent(Student* student);
        bool dropStudent(Student* student);  // corrected the return type
};

#endif
