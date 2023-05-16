#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <pthread.h>
#include "class.h"

class Class;

class Student {
private:
    std::string name;
    std::string major;
    int maxCredits;
    int currentCredits;
    std::vector<Class*> classes;
    pthread_mutex_t studentLock; // Mutex for thread-safety

public:
    Student(std::string name, std::string major, int maxCredits);
    ~Student();
    
    std::string getName();
    std::string getMajor();
    int getMaxCredits();
    int getCurrentCredits();
    std::vector<Class*> getClasses();
    void setCurrentCredits(int newCredits);
    bool addClass(Class* newClass);
    bool dropClass(Class* oldClass);
    bool switchClass(Class* oldClass, Class* newClass);
};

#endif
