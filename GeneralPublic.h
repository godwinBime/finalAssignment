/**
Student: Godwin Bime
Course: CSC-402-001-2021-030
Due Date:04/05/2021
Assignment: #04
Instructor: Michael Clark Jr.
* **/

#ifndef HOSPITALADMINISTRATIONCONSOLEAPP_GENERALPUBLIC_H
#define HOSPITALADMINISTRATIONCONSOLEAPP_GENERALPUBLIC_H

#include "Hospital.h"
#include <string>
#include <map>
#include <vector>

using namespace std;
class GeneralPublic: public Hospital{
public:
    explicit GeneralPublic();

    void setPatientId(int id) override;
    int getPatientId() override;

    static void help();
    void addPatient(int &number);

    void setAssignedDoctor(string &patientDoctor);
    string getDoctor();

    void setPatientStatus(int &status);
    int getPatientStatus();
    void treatAllPatients();

    string verifyDoctorName(const string& name);
    int verifyID(int &userID);

    void logUserOperation(const string& id, const string& action, const string& jobDescription);
    void treatPatientInTriagedOrder();

    void bulkAddPatients();
    void nextPatient();

    void printReportByDoctor(const string& doctorName);
    void printReportByPatientByID(int& keyID);

    void printAllTreatedPatientReport();
    void printAllPatientsInTriage();

    int generateRandomNumber(int& len);
    void startHospitalAdministrationConsoleApp();

    string verifyAction(const int titleNumber, const string& actionSelected);
    int randomSleepTime();

    int convertStringToInteger(string &value);
    int secondRandomNumber(int& len);

private:
    string name;
    int patientId;
    int status;
    int generatePatientID = 0;
    vector<int> patientIDVector;
    vector<string> firstNameVector;
    vector<string> middleNameVector;
    vector<string> lastNameVector;
    vector<string> suffixVector;
    vector<string> ailmentVector;
    vector<string> assignedDoctorVector;
    vector<int> priorityVector;
    multimap<int, int> patientTreatmentStatusMap;

    vector<string> firstNameArray{"Wright", "Kala", "White", "Sunday", "Berry", "Kendall", "Drew", "Kennedy",
                                 "Addison", "Adrian"};
    vector<string> middleNameArray {"K", "P", "S,", "M", "A", "Z", "D", "L", "X", "u"};
    vector<string> lastNameArray {"Alex", "Jordan", "Taylor", "Kyle", "Drew", "Ali", "Nani","Evra", "Promise",
                                   "Fallon"};
    vector<string> patientSuffixArray {"Jr", "Sr", "II", "I", "IV", "III"};
    vector<string> ailmentArray{"Gastric", "Fever", "Cough", "Back Pain", "Headache", "Stomach ache"};
    vector<string> doctorsArray {"Paul", "Mary", "Phil", "John", "Berry", "Amory"};
};


#endif //HOSPITALADMINISTRATIONCONSOLEAPP_GENERALPUBLIC_H
