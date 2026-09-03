//Assignment 1
//Question 2 - Embedded memory manager
//Problem 2 - Signal processing pipeline
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double computeRMS(double* signal, int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += (*(signal + i)) * (*(signal + i));
    }
    return sqrt(sum / n);
}
void normalise(double* signal, int n){
    double maxValue = fabs(*signal);
    for (int i = 1; i < n; i++){
        if (fabs(*(signal + i)) > maxValue){
            maxValue = fabs(*(signal + i));
        }
    }
    if (maxValue == 0)
        return;
    for (int i = 0; i < n; i++){
        *(signal + i) = *(signal + i) / maxValue;
    }
}
int countZeroCrossings(double* signal, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if ((*(signal + i) < 0 && *(signal + i + 1) > 0) || (*(signal + i) > 0 && *(signal + i + 1) < 0)){
            count++;
        }
    }
    return count;
}
void applyGain(double* signal, int n, double gainFactor){
    for (int i = 0; i < n; i++){
        *(signal + i) = *(signal + i) * gainFactor;
    }
}
void printSignal(double* signal, int n){
    for (int i = 0; i < n; i++){
        cout << fixed << setprecision(2)<< *(signal + i) << " ";
    }
    cout << endl;
}
int main(){
    double signal[] ={
        0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1
    };
    int n = 7;
    cout << "Original signal : ";
    printSignal(signal, n);
    double rms = computeRMS(signal, n);
    int crossings = countZeroCrossings(signal, n);
    cout << "RMS : " << rms << endl;
    cout << "Zero Crossings : " << crossings << endl;
    normalise(signal, n);
    cout << "After normalise : ";
    printSignal(signal, n);
    applyGain(signal, n, 2.0);
    cout << "After gain : ";
    printSignal(signal, n);
    return 0;
}
