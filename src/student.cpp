#include "student.h"

// constructor
Student::Student(std::string name, std::string major, int maxCredits) {
    this->name = name;
    this->major = major;
    this->maxCredits = maxCredits;
    this->currentCredits = 0;
    pthread_mutex_init(&studentLock, NULL);
}

Student::~Student() {
    pthread_mutex_destroy(&studentLock);
}

// getters and setters
std::string Student::getName() {
    return name;
}

std::string Student::getMajor() {
    return major;
}

int Student::getMaxCredits() {
    return maxCredits;
}

int Student::getCurrentCredits() {
    return currentCredits;
}

std::vector<Class*> Student::getClasses() {
    return classes;
}

void Student::setCurrentCredits(int newCredits) {
    pthread_mutex_lock(&studentLock);
    this->currentCredits = newCredits;
    pthread_mutex_unlock(&studentLock);
}

// add/drop/switch
bool Student::addClass(Class* newClass) {
    pthread_mutex_lock(&studentLock); // Lock the mutex
    if (newClass->getCredit() + currentCredits <= maxCredits) {
        if (newClass->addStudent(this)) {
            classes.push_back(newClass);
            currentCredits += newClass->getCredit();
            pthread_mutex_unlock(&studentLock); // Unlock the mutex
            return true;
        }
    }
    pthread_mutex_unlock(&studentLock); // Unlock the mutex
    return false;
}

bool Student::dropClass(Class* oldClass) {
    pthread_mutex_lock(&studentLock); // Lock the mutex
    
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i] == oldClass) {
            if (oldClass->dropStudent(this)) {
                classes.erase(classes.begin() + i);
                currentCredits -= oldClass->getCredit();
                pthread_mutex_unlock(&studentLock); // Unlock the mutex
                return true;
            }
        }
    }

    pthread_mutex_unlock(&studentLock); // Unlock the mutex
    return false;
}

bool Student::switchClass(Class* oldClass, Class* newClass) {
    pthread_mutex_lock(&studentLock); // Lock the mutex

    if (dropClass(oldClass)) {
        if (addClass(newClass)) {
            pthread_mutex_unlock(&studentLock); // Unlock the mutex
            return true;
        } else {
            addClass(oldClass); // Re-enroll in the old class if cannot switch
        }
    }

    pthread_mutex_unlock(&studentLock); // Unlock the mutex
    return false;
}