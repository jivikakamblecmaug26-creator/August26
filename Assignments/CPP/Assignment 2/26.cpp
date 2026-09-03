//Assignment 2
//Question 2 - Hospital patient registry
#include <iostream>
#include <string>
using namespace std;
class Patient{
private:
    int id;
    string name;
    int age;
    string ward;
    const string bloodGroup;
public:
    Patient(int i, const string& n, int a, const string& w, const string& b)
        : id(i), name(n), age(a), ward(w), bloodGroup(b)
    {
        cout << "[Constructor] Full admission: "<< name << endl;
    }
    Patient(int i, const string& n, int a, const string& b)
        : id(i), name(n), age(a), ward("Emergency"), bloodGroup(b)
    {
        cout << "[Constructor] Emergency: "<< name << endl;
    }
    Patient()
        : id(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }
    void displayRecord() const{
        cout << "\nPatient Record:" << endl;
        cout << "  ID        : " << id << endl;
        cout << "  Name      : " << name << endl;
        cout << "  Age       : " << age << endl;
        cout << "  Ward      : " << ward << endl;
        cout << "  Blood Grp : " << bloodGroup << endl;
    }
    void transferWard(const string& newWard){
        cout << "\nWard Transfer: " << name<< " -> " << newWard << endl;
        ward = newWard;
    }
    ~Patient(){
        cout << "[Destructor] Patient "<< name << " discharged." << endl;
    }
};
int main(){
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel", 58, "O+");
    Patient p3;
    Patient* patients = new Patient[4];
    for (int i = 0; i < 4; i++){
        patients[i].displayRecord();
    }
    p1.displayRecord();
    p2.displayRecord();
    p3.displayRecord();
    p2.transferWard("ICU");
    delete[] patients;
    cout << "\nDynamic patient array deleted." << endl;
    return 0;
}