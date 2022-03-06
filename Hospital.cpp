/**
Student: Godwin Bime
Course: CSC-402-001-2021-030
Due Date:04/05/2021
Assignment: #04
Instructor: Michael Clark Jr.
* **/

#include "Hospital.h"
using namespace std;

Hospital::Hospital(){}

Hospital::~Hospital() = default;

void Hospital::setFirstName(string& humanFirstName) {
    firstName = move(humanFirstName);
}

string Hospital::getFirstName() {
    return firstName;
}

void Hospital::setMiddleName(string &humanMiddleName) {
    middleName = move(humanMiddleName);
}

string Hospital::getMiddleName() {
    return middleName;
}

void Hospital::setLastName(string &humanLastName) {
    lastName = move(humanLastName);
}

string Hospital::getlastName() {
    return lastName;
}

void Hospital::setAilment(string& humanAilment) {
    ailment = move(humanAilment);
}

string Hospital::getAilment() {
    return ailment;
}

void Hospital::setIsTreated(bool isHumanTreated){
    isTreated = isHumanTreated;
}

bool Hospital::getIsTreated() const {
    return isTreated;
}

int Hospital::verifyTreatmentStatus() const {
    bool isTheyTreated = getIsTreated();
    if (isTheyTreated)
        return 1;
    else
        return 0;
}

void Hospital::setPriority(int& patientPriority) {
    priority = patientPriority;
}

int Hospital::getPriority() const {
    return priority;
}

void Hospital::setSuffix(string &humanSuffix) {
    aSuffix = move(humanSuffix);
}

string Hospital::getSuffix() {
    return aSuffix;
}