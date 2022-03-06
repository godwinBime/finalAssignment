/**
Student: Godwin Bime
Course: CSC-402-001-2021-030
Due Date:04/05/2021
Assignment: #04
Instructor: Michael Clark Jr.
* **/

#include "GeneralPublic.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <map>
#include <random>
#include <ctime>
#include <unistd.h>
#include <sstream>

using namespace std;
GeneralPublic::GeneralPublic(){}

void GeneralPublic::setPatientId(int humanId){
    patientId = humanId;
}

int GeneralPublic::getPatientId() {
    return patientId;
}

int GeneralPublic::generateRandomNumber(int& len) {
    string temp;
    const char randomNumbers[] = "0123456789";
    srand((unsigned ) time(NULL)*getpid());
    temp.reserve(len);
    for(int i = 0; i < len; i++){
        temp = randomNumbers[rand() %(sizeof (randomNumbers) - 1)];
    }
    stringstream convertToInteger(temp);
    int newNumber = 0;
    convertToInteger >> newNumber;

    return newNumber;
}

string GeneralPublic::verifyDoctorName(const string& checkName) {
    string doctorName = "NONE";
    int nameSize = doctorsArray.size();
    for(int i = 0; i < nameSize; i++) {
        if (checkName == doctorsArray[i]) {
            doctorName = checkName;
        }
    }
    return doctorName;
}

void GeneralPublic::setPatientStatus(int& humanStatus) {
    status = humanStatus;
}

int GeneralPublic::getPatientStatus() {
    return status;
}

void GeneralPublic::setAssignedDoctor(string& humanPatientDoctor) {
    name = move(humanPatientDoctor);
}

string GeneralPublic::getDoctor() {
    return name;
}

int GeneralPublic::secondRandomNumber(int &len) {
    string temp;
    const char randomNumbers[] = "012345";
    srand((unsigned ) time(NULL)*getpid());
    temp.reserve(len);
    for(int i = 0; i < len; i++){
        temp = randomNumbers[rand() %(sizeof (randomNumbers) - 1)];
    }
    stringstream convertToInteger(temp);
    int newNumber = 0;
    convertToInteger >> newNumber;

    return newNumber;
}

void GeneralPublic::addPatient(int& number) {
    for(int i = 0; i < number; i++) {
        if (patientIDVector.empty()) {
            generatePatientID = 0;
            setPatientId(generatePatientID);
        } else if (patientIDVector.size() == 1 && patientIDVector[0] == 0){
            generatePatientID = patientIDVector.size();
            setPatientId(generatePatientID);
        } else{
            generatePatientID = patientIDVector.size();
            setPatientId(generatePatientID);
        }

        setIsTreated(false);
        setPriority(i);

        int randomValue = 5;

        patientIDVector.push_back(getPatientId());
        firstNameVector.push_back(firstNameArray.at(generateRandomNumber(randomValue)));
        middleNameVector.push_back(middleNameArray.at(generateRandomNumber(randomValue)));
        lastNameVector.push_back(lastNameArray.at(generateRandomNumber(randomValue)));
        suffixVector.push_back(patientSuffixArray.at(secondRandomNumber(randomValue)));
        ailmentVector.push_back(ailmentArray.at(secondRandomNumber(randomValue)));
        assignedDoctorVector.push_back(doctorsArray.at(secondRandomNumber(randomValue)));
        patientTreatmentStatusMap.insert(pair<int, int>(getPatientId(), verifyTreatmentStatus()));
        priorityVector.push_back(i);
    }
}

int GeneralPublic::convertStringToInteger(string& value) {
    stringstream getString(value);
    int convertToInteger = 0;
    getString >> convertToInteger;
    return convertToInteger;
}

void GeneralPublic::bulkAddPatients() {
    vector<string> vector;
    char fn = ':';
    string fileName;
    cout <<"Enter file name to read from: " << '\n';
    cin >> fileName;
    fstream file(fileName);
    string line;
    while (getline(file, line)){
        vector.push_back(line);
    }
    string patientDetails;
    string patientDescription;
    for(auto word : vector){
        string delimiter = ":";
        patientDetails = word.substr(word.find(delimiter) + 1, word.length());
        patientDescription = word.substr(0, word.find(delimiter));

        if ((patientDescription == "firstName")){
            setFirstName(patientDetails);
            firstNameVector.push_back(getFirstName());
        } else if (patientDescription == "middleName"){
            setMiddleName(patientDetails);
            middleNameVector.push_back(getMiddleName());
        } else if (patientDescription == "lastName"){
            setLastName(patientDetails);
            lastNameVector.push_back(getlastName());
        } else if (patientDescription == "suffix"){
            setSuffix(patientDetails);
            suffixVector.push_back(getSuffix());
        } else if (patientDescription == "ailment"){
            setAilment(patientDetails);
            ailmentVector.push_back(getAilment());
        } else if (patientDescription == "doctor"){
            setAssignedDoctor(patientDetails);
            assignedDoctorVector.push_back(getDoctor());
        } else if (patientDescription == "treated"){
            int treatmentStatus = convertStringToInteger(patientDetails);
            setPatientId(generatePatientID++);
            setPatientStatus(treatmentStatus);
            patientTreatmentStatusMap.insert(pair<int, int>(getPatientId(), getPatientStatus()));
        } else if (patientDescription == "priority"){
            int convertPriority = convertStringToInteger(patientDetails);
            setPriority(convertPriority);
            patientIDVector.push_back(generatePatientID);
            priorityVector.push_back(getPriority());
        }
    }
    file.close();
}

int GeneralPublic::randomSleepTime() {
    mt19937_64 engine{random_device{}()};
    uniform_int_distribution<> distribution{1000, 3000};
    return distribution(engine);
}

void GeneralPublic::treatPatientInTriagedOrder() {
    multimap<int, int>::iterator iterator;

    if (!patientTreatmentStatusMap.empty()){
        for(iterator = patientTreatmentStatusMap.begin(); iterator != patientTreatmentStatusMap.end(); iterator++){
            if (iterator->second == 0){
                iterator->second = 1;
                std::this_thread::sleep_for(std::chrono::microseconds(randomSleepTime()));
            }
        }
    } else{
        cout<<"No patients are registered in the database yet.\n";
    }
}

void GeneralPublic::treatAllPatients() {
   multimap<int, int>::iterator iterator;
    if (!patientTreatmentStatusMap.empty()){
        for(iterator = patientTreatmentStatusMap.begin(); iterator != patientTreatmentStatusMap.end(); iterator++){
            if (iterator->second == 0){
                iterator->second = 1;
                std::this_thread::sleep_for(std::chrono::microseconds(randomSleepTime()));
            }
        }
    } else{
        cout<<"No patients are registered in the database yet.\n";
    }
    cout<<"All patients have been treated!!!\n";
}

void GeneralPublic::nextPatient() {
    int i = 0;
    multimap<int, int>::iterator iterator;
    cout<<'\n';
    cout <<"Next patient in line is:" << '\n';
    if (!firstNameVector.empty()) {
        for(iterator = patientTreatmentStatusMap.begin(); iterator != patientTreatmentStatusMap.end(); iterator++) {
            i++;
            if (iterator -> second == 0) {
                cout << "firstName: " << firstNameVector.at(i) << '\n';
                cout << "middleName: " << middleNameVector.at(i) << '\n';
                cout << "lastName: " << lastNameVector.at(i) << '\n';
                cout << "suffix: " << suffixVector.at(i) << '\n';
                cout << "ailment: " << ailmentVector.at(i) << '\n';
                cout << "doctor: " << assignedDoctorVector.at(i) << '\n';
                cout << "Treated:" << iterator->second << '\n';
                cout << "Priority: " << priorityVector.at(i) << '\n' << '\n';
                break;
            }
        }
    } else{
        cout << "There is no patient in the database." << '\n';
    }
}

void GeneralPublic::logUserOperation(const string& logId, const string& action, const string& jobDescription) {
    time_t currentTime = time(0);
    ofstream logUserOperation("logFile.txt", ios::out | ios::app);
    logUserOperation <<"Operator-ID: " << logId << '\n';
    logUserOperation <<"Title: " << jobDescription << '\n';
    logUserOperation <<"Operation: " << action << '\n';
    logUserOperation <<"Time of operation: " << ctime(&currentTime) << '\n';
    logUserOperation.close();

    cout<<"===========Operations Logs================\n";
    cout <<"Operator-ID: " << logId << '\n';
    cout <<"Title: " << jobDescription << '\n';
    cout <<"Operation: " << action << '\n';
    cout <<"Time of operation: " << ctime(&currentTime) << '\n';
}

string GeneralPublic::verifyAction(const int titleNumber, const string& actionSelected) {
    string selectedAction;
    bool isInstructionFollowed = false;

    do {
        if ((titleNumber == 1) &&((actionSelected == "T") || (actionSelected == "N") || (actionSelected == "PD")
        || (actionSelected == "ATP"))){//Doctor
            selectedAction = actionSelected;
        } else if ((titleNumber == 2) && ((actionSelected == "PA") || (actionSelected == "TAP") ||
        (actionSelected == "MD"))){//Hospital admin
            selectedAction = actionSelected;
        } else if(titleNumber == 3 && (actionSelected == "F-L")){//Sys admin
            selectedAction = actionSelected;
        } else if (titleNumber == 4 && (actionSelected == "H")){//User
            isInstructionFollowed = true;
            selectedAction = actionSelected;
        }else if (actionSelected == "quit"){
            cout <<"Exiting the system...\n";
            exit(1);
        } else{
            cout <<"Please choose the right command to get started\n";
            cout <<"Enter the designated command: \n";
            cin >> selectedAction;
        }
        return selectedAction;
    } while (isInstructionFollowed);
}

int GeneralPublic::verifyID(int& userID) {
    int patientNumber = 0;
    if (patientIDVector.size() > userID) {
        for (int i : patientIDVector) {
            if (i == userID) {
                patientNumber = userID;
            }
        }
    }
    return patientNumber;
}

void GeneralPublic::printReportByDoctor(const string& doctorName) {
    if (!assignedDoctorVector.empty()){
        cout<<"Results of patients under Dr. " << doctorName <<".\n";
        for(int i = 0; i < assignedDoctorVector.size(); i++){
            if (assignedDoctorVector[i] == doctorName){
                cout << "firstName: " << firstNameVector.at(i) << '\n';
                cout << "middleName: " << middleNameVector.at(i) << '\n';
                cout << "lastName: " << lastNameVector.at(i) << '\n';
                cout << "suffix: " << suffixVector.at(i) << '\n';
                cout << "ailment: " << ailmentVector.at(i) << '\n';
                cout << "doctor: " << assignedDoctorVector.at(i) << '\n';
                for(auto& iterator : patientTreatmentStatusMap)
                    if (iterator.first == i)
                        cout << "Treated:" << iterator.second << '\n';
                cout << "Priority: " << priorityVector.at(i) << '\n' << '\n';
            }
        }
    } else{
        cout <<"No doctor has been assigned yet. Try again later.\n";
    }
}

void GeneralPublic::printReportByPatientByID(int& reportKey) {
    cout<<"Results of patient with ID #" << reportKey << "'\n";
    if (!patientIDVector.empty()){
        for(int i = 0; i < patientIDVector.size(); i++){
            if (patientIDVector[i] == reportKey){
                cout << "firstName: " << firstNameVector.at(i) << '\n';
                cout << "middleName: " << middleNameVector.at(i) << '\n';
                cout << "lastName: " << lastNameVector.at(i) << '\n';
                cout << "suffix: " << suffixVector.at(i) << '\n';
                cout << "ailment: " << ailmentVector.at(i) << '\n';
                cout << "doctor: " << assignedDoctorVector.at(i) << '\n';
                for(auto iterator = patientTreatmentStatusMap.begin(); iterator != patientTreatmentStatusMap.end();
                iterator++) {
                    if (iterator->first == i)
                        cout << "Treated:" << iterator->second << '\n';
                }
                cout << "Priority: " << priorityVector.at(i) << '\n' << '\n';
            }
        }
    } else{
        cout<<"No patient is registered yet. Try again later.\n";
    }
}

void GeneralPublic::printAllTreatedPatientReport() {
    int i = 0;
    if (!patientTreatmentStatusMap.empty()){
        for(auto & iterator : patientTreatmentStatusMap){
            i++;
            if (iterator.second == 1){
                cout << "firstName: " << firstNameVector.at(i) << '\n';
                cout << "middleName: " << middleNameVector.at(i) << '\n';
                cout << "lastName: " << lastNameVector.at(i) << '\n';
                cout << "suffix: " << suffixVector.at(i) << '\n';
                cout << "ailment: " << ailmentVector.at(i) << '\n';
                cout << "doctor: " << assignedDoctorVector.at(i) << '\n';
                cout << "Treated:" << iterator.second << '\n';
                cout << "Priority: " << priorityVector.at(i) << '\n' << '\n';
            }
        }
    } else{
        cout <<"There are no registered patients yet. Try again later\n";
    }
}

void GeneralPublic::printAllPatientsInTriage() {
    int i = 0;
    if (!patientTreatmentStatusMap.empty()){
        for(auto & iterator : patientTreatmentStatusMap){
            cout << "firstName: " << firstNameVector.at(i) << '\n';
            cout << "middleName: " << middleNameVector.at(i) << '\n';
            cout << "lastName: " << lastNameVector.at(i) << '\n';
            cout << "suffix: " << suffixVector.at(i) << '\n';
            cout << "ailment: " << ailmentVector.at(i) << '\n';
            cout << "doctor: " << assignedDoctorVector.at(i) << '\n';
            cout << "Treated:" << iterator.second << '\n';
            cout << "Priority: " << priorityVector.at(i) << '\n' << '\n';
            i++;
        }
    } else{
        cout <<"There are no registered patients yet. Try again later\n";
    }
}

void GeneralPublic::help() {
    cout<< "In the Administration Console App, a nurse, doctor, hospital admin, system admin\n can add patients into "
           "the system.\n- A system administrator is identified as \"sa\".\n"
           "- A hospital administrator is identified as \"hs\".\n"
           "- A nurse needs only to identify with the key word \"nurse\".\n"
           "- A doctor can enter letter \"T\" to treat patients in triaged order.\n"
           "- A doctor can enter \"ATP\" to view all treated patients.\n- A doctor can "
           "enter letter \"N\" to know the next "
           "patient to be treated.\n"
           "- A doctor can enter \"PD\" to view a patient information.\n"
           "- A hospital admin can input \"PA\" to get all patients printed in triage.\n- A "
           "hospital admin can enter \"TAP\" and get all patients treated.\n- A hospital admin can also type "
           " \"MD\" to view patients by assigned doctor.\n- A system administrator can type \"F-L\" to add patients "
           "from a "
           "text file.\n- A system administrator also have access to logs of all activities in the console and "
           "text file.\n- A user will type in \"H\" to print a guide on the various commands the system offers.\n"
           "- Finally, any one can type \"quit\" to exit the application."
           "\n\n **Thanks for using the Hospital Administration Console App.**\n";
}

void GeneralPublic::startHospitalAdministrationConsoleApp() {
    int firstNameID;
    if (patientIDVector.empty()){
        firstNameID = 0;
    } else {
         firstNameID = patientIDVector.front();
    }
    string choice;
    int addPatients;
    string registerTitle;
    string userID;
    string registerPatients;
    string activity;

    do {
        cout <<"Enter your job title: " << '\n';
        cin >> registerTitle;

        if (registerTitle == "quit"){
            cout <<"Exiting system..." << "\n";
            exit(1);
        }
        cout<<"Enter your badge ID: " << '\n';
        cin >> userID;

        if (userID == "quit"){
            cout <<"Exiting system..." << "\n";
            exit(1);
        }
        if ((registerTitle == "nurse") || (registerTitle == "Nurse") || (registerTitle == "nurse.") ||
            (registerTitle == "Nurse.") || (registerTitle == "NURSE") ||(registerTitle == "NURSE.")) {
            cout << "As a " << registerTitle << ", you can register a patient into the hospital.\n";
            cout <<"Are there patients to register? (y or n) \n";
            cin >> registerPatients;

            if ((registerPatients == "y") || (registerPatients == "Y")) {
                cout << "How many patients are available to be registered in?\n";
                cin >> addPatients;
                addPatient(addPatients);
                activity = "added patients.";
            } else if ((registerPatients == "n") || (registerPatients == "N")){
                cout<< "You are about to exit from the \"Hospital Administration Console App\"...";
                if (firstNameVector.empty()) {
                    activity = "NONE";
                }
                randomSleepTime();
                exit(1);
            }
        } else if ((registerTitle == "ha") || (registerTitle == "HA") ||
                   (registerTitle == "ha.")|| (registerTitle == "HA.")) {
            cout<<"Enter \"PA\" to get all patients printed in triage or\n Enter "
                  "\"TAP\" and get all patients treated or\n "
                  " Enter \"MD\" to enter a doctor's name.\n Or "
                  "Type \"quit\" to exit the system.\n";
            cin >> choice;
            verifyAction(2, choice);
            if (choice == "PA"){
                activity = "Hospital admin printed patients in triage order.";
                printAllPatientsInTriage();
            } else if (choice == "TAP"){
                activity = "Hospital admin treated all patience in a single command.";
                treatAllPatients();
            } else if (choice == "MD"){
                cout<<"Enter a doctor's name to view patient(s):" << '\n';
                cin >> choice;
                verifyDoctorName(choice);
                activity = "Hospital admin printed out patients by assigned Doctor's name.";
                printReportByDoctor(choice);
            }
        } else if ((registerTitle == "sa") || (registerTitle == "SA") ||
                   (registerTitle == "sa.") ||(registerTitle == "SA.")) {
            cout<<"Enter \"F-L\" to add patients from a text file.\n Or "
                  "Type \"quit\" to exit the system.\n";
            cin >> choice;
            verifyAction(3, choice);
            if (choice == "F-L"){
                activity = choice;
                bulkAddPatients();
            }
        } else if ((registerTitle == "doctor") || (registerTitle == "Doctor") || (registerTitle == "doctor.") ||
                   (registerTitle == "Doctor.") || (registerTitle == "DOCTOR") || (registerTitle == "DOCTOR.")) {
            cout <<"- Enter letter \"T\" to treat patients.\n- Enter letter \"N\" to know the next patient to be "
                   "treated.\n Or type \"ATP\" to view all treated patients.\n Or type \"PD\" to print a patient's "
                   "information.\n"
                   " Or Type \"quit\" to exit the system.\n";
            cin >> choice;
            verifyAction(1, choice);
            activity = choice;
            if (choice == "T"){
                activity = "Doctor treated a patient.";
                treatPatientInTriagedOrder();
            } else if (choice == "ATP"){
                activity = "Doctor viewed all patients in registry.";
                printAllTreatedPatientReport();
            } else if (choice == "PD"){
                int key = 0;
                string doctorName;
                activity = "Doctor printed patient's information.";
                if (!patientIDVector.empty()) {
                    int aSize = patientIDVector.size() - 1;
                    cout << "Enter patientID between " << firstNameID << " and " << aSize << " to print out:\n";
                    cin >> key;
                    if (key == verifyID(key)) {
                        printReportByPatientByID(key);
                    }
                } else{
                    cout<<"There is no patient registered yet. Try again later.\n" << "\n";
                }
            }else if (choice == "N"){
                activity = "Doctor looked up the next patient in triage order.";
                nextPatient();
            }
        } else if ((registerTitle == "user") || (registerTitle == "User") || (registerTitle == "user.") ||
                   (registerTitle == "User.") || (registerTitle == "USER") || (registerTitle == "USER.")) {
            cout <<"Enter letter \"H\" to get access to the user guide: \n "
                   "Or Type \"quit\" to exit the system.\n";
            cin >> choice;
            verifyAction(4, choice);
            activity = "User printed out the user manual for the \"Hospital Administration Console App.\"";

            cout << "As a " << registerTitle << ", you  will be given access to a guide on the features of the \n"
                                                "\"Hospital Administration Console App\".\n" << '\n';
            randomSleepTime();
            help();
        } else {
            cout<< "Unknown title. You must be either a nurse, system administrator, hospital administrator, \n"
                   "doctor or a verified \"user\" to access this system.\n";
            cout <<"Enter your job title one more time please: " << '\n';
        }
        logUserOperation(userID, activity, registerTitle);
    } while (true);
}