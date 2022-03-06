/**
Student: Godwin Bime
Course: CSC-402-001-2021-030
Due Date:04/05/2021
Assignment: #04
Instructor: Michael Clark Jr.
* **/

#ifndef HOSPITALADMINISTRATIONCONSOLEAPP_HOSPITAL_H
#define HOSPITALADMINISTRATIONCONSOLEAPP_HOSPITAL_H
#include <string>

using namespace std;
class Hospital {
public:
    explicit Hospital();

    virtual ~Hospital();

    virtual void setPatientId(int id) = 0;
    virtual int getPatientId() = 0;

    void setFirstName(string& patientFirstName);
    string getFirstName();

    void setMiddleName(string& patientMiddleName);
    string getMiddleName();

    void setLastName(string& patientLastName);
    string getlastName();

    void setSuffix(string &patientSuffix);
    string getSuffix();

    void setAilment(string &ailment);
    string getAilment();

    int verifyTreatmentStatus() const;

    void setPriority(int &priority);
    int getPriority() const;

    void setIsTreated(bool isTreated);
    bool getIsTreated() const;

private:
    string lastName;
    string middleName;
    string firstName;
    string ailment;
    int priority;
    bool isTreated;
    string aSuffix;
};


#endif //HOSPITALADMINISTRATIONCONSOLEAPP_HOSPITAL_H
