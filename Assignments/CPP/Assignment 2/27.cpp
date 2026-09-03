//Assignment 2
//Question 1 - Inventory management system
//Part B - Function overloading
#include <iostream>
using namespace std;
double reorderCost(int qty, double unitPrice){
    return qty * unitPrice;
}
double reorderCost(double qty, double unitPrice){
    return qty * unitPrice;
}
double reorderCost(int qty, double unitPrice, double taxRate){
    double cost = qty * unitPrice;
    double tax = cost * taxRate / 100;
    return cost + tax;
}
double applyDiscount(double price, double discountPercent = 10.0){
    return price - (price * discountPercent / 100);
}
int main(){
    cout << "Integer reorder cost: "<< reorderCost(10, 50.0) << endl;
    cout << "Double reorder cost: "<< reorderCost(5.5, 50.0) << endl;
    cout << "Reorder cost with tax: "<< reorderCost(10, 50.0, 18.0) << endl;
    cout << "Price after default discount: "<< applyDiscount(1000) << endl;
    cout << "Price after 20% discount: "<< applyDiscount(1000, 20) << endl;
    return 0;
}