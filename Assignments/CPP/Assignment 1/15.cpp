//Assignment 1
//Question 1 - Iot sensor dashboard
//Problem 2 - Sensor log buffer
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cout << "Enter number of readings: ";
    cin >> n;
    if (n < 1 || n > 100){
        cout << "Invalid number of readings." << endl;
        return 1;
    }
    double readings[100];
    for (int i = 0; i < n; i++){
        cout << "Enter reading " << i << ": ";
        cin >> readings[i];
    }
    int skipped = 0;
    double minimum = 0;
    double maximum = 0;
    double sum = 0;
    int validCount = 0;
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;
    cout << "\nValid readings : ";   
    for (int i = 0; i < n; i++){
        if (readings[i] < 0){
            skipped++;
            continue;
        }
        cout << readings[i] << " ";
        if (validCount == 0){
            minimum = readings[i];
            maximum = readings[i];
        }
        else{
            if (readings[i] < minimum)
                minimum = readings[i];
            if (readings[i] > maximum)
                maximum = readings[i];
        }
        sum += readings[i];
        validCount++;
        if (readings[i] < 30)
            normal++;
        else if (readings[i] < 45)
            warning++;
        else if (readings[i] < 60)
            critical++;
        else
            shutdown++;
    }
    cout << endl;
    bool foundCritical = false;
    for (int i = 0; i < n; i++){
        if (readings[i] >= 45){
            cout << "First CRITICAL : Index "<< i << " → " << readings[i] << "°C" << endl;
            foundCritical = true;
            break;
        }
    }
    if (!foundCritical){
        cout << "First CRITICAL : None" << endl;
    }
    double average = 0;
    if (validCount > 0)
        average = sum / validCount;
    cout << fixed << setprecision(2);
    cout << "Readings entered : " << n << endl;
    cout << "Skipped (errors) : " << skipped << endl;
    if (validCount > 0){
        cout << "Min : " << minimum << "°C" << endl;
        cout << "Max : " << maximum << "°C" << endl;
        cout << "Avg : " << average << "°C" << endl;
    }
    cout << "Normal:" << normal<< " Warning:" << warning<< " Critical:" << critical<< " Shutdown:" << shutdown << endl;
    return 0;
}