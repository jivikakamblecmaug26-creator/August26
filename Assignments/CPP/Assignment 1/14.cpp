//Assignment 1
//Question 1 - Iot sensor dashboard
//Problem 1 - Sensor reading classifier
#include <iostream>
using namespace std;
int main(){
    double temperature;
    int statusCode;
    cout << "Enter temperature: ";
    cin >> temperature;
    if (temperature < 0){
        statusCode = -1;
    }
    else if (temperature < 30){
        statusCode = 0;
    }
    else if (temperature < 45){
        statusCode = 1;
    }
    else if (temperature < 60){
        statusCode = 2;
    }
    else{
        statusCode = 3;
    }
    double fahrenheit = (temperature * 9 / 5) + 32;
    cout << "Temperature : " << temperature<< "°C / " << fahrenheit << "°F" << endl;
    switch (statusCode){
        case -1:
            cout << "Status : SENSOR_ERROR" << endl;
            cout << "Action : Sensor fault — check wiring" << endl;
            break;
        case 0:
            cout << "Status : NORMAL" << endl;
            cout << "Action : No action required" << endl;
            break;
        case 1:
            cout << "Status : WARNING" << endl;
            cout << "Action : Alert sent to supervisor" << endl;
            break;
        case 2:
            cout << "Status : CRITICAL" << endl;
            cout << "Action : Cooling system triggered" << endl;
            break;
        case 3:
            cout << "Status : SHUTDOWN" << endl;
            cout << "Action : Emergency shutdown initiated" << endl;
            break;
    }
    cout << "Reading : "<< (temperature >= 25 ? "Above Average" : "Below Average")<< endl;
    return 0;
}