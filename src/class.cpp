#include "class.h"

// constructor
Class::Class(std::string name, int capacity, bool labOrNot) : name(name), capacity(capacity), labOrNot(labOrNot) {
    size_t i = 0;
    while (i < name.size() && !isdigit(name[i])) {
        i++;
    }
    this->major = name.substr(0, i);
    this->difficulty = name[i] - '0';

    if(labOrNot) {
        this->credit = 4;
    }else{
        this->credit = 3;
    }

    pthread_mutex_init(&classLock, NULL); // Initialize the mutex
}

Class::~Class() {
    pthread_mutex_destroy(&classLock); // Destroy the mutex
}


// get/set
std::string Class::getName() const {
    return name;
}

std::string Class::getMajor() const {
    return major;
}

int Class::getDifficulty() const {
    return difficulty;
}

int Class::getCredit() const {
    return credit;
}

std::vector<Student*> Class::getStudents(){
    return students;
}

int Class::getCapacity(){
    return capacity;
}

std::vector<Student*> Class::getWaitlist(){
    return waitlist;
}

// add/drop
bool Class::addStudent(Student* student) {
    pthread_mutex_lock(&classLock);

    if (student->getCurrentCredits() + credit > student->getMaxCredits() || (student->getMajor() != major && difficulty > 2)) {
        pthread_mutex_unlock(&classLock);
        return false;
    }

    if (students.size() < capacity) {
        students.push_back(student);
        student->setCurrentCredits(student->getCurrentCredits() + credit); 
        pthread_mutex_unlock(&classLock);
        return true;
    } else {
        waitlist.push_back(student);
        pthread_mutex_unlock(&classLock);
        return false;
    }
}

bool Class::dropStudent(Student* student) {
    pthread_mutex_lock(&classLock);
    bool result = false;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i] == student) {
            students.erase(students.begin() + i);
            student->setCurrentCredits(student->getCurrentCredits() - credit);
            result = true;

            for (size_t j = 0; j < waitlist.size(); j++) {
                if (waitlist[j]->getCurrentCredits() + credit <= waitlist[j]->getMaxCredits()) {
                    students.push_back(waitlist[j]);
                    waitlist[j]->setCurrentCredits(waitlist[j]->getCurrentCredits() + credit);
                    waitlist.erase(waitlist.begin() + j);
                    break;
                }
            }
            pthread_mutex_unlock(&classLock);
            return result;
        }
    }

    pthread_mutex_unlock(&classLock);
    return result;
}