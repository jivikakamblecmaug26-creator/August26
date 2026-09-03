//Assignment 2
//Question 1 - Inventory management system
//Part A - Product class with array of objects
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Product{
private:
    int productId;
    string name;
    double price;
    int quantity;
public:
    void acceptDetails(){
        cout << "Enter Product ID: ";
        cin >> productId;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }
    void displayDetails() const{
        cout << left << setw(8) << productId<< setw(15) << name<< setw(10) << fixed << setprecision(2) << price<< setw(8) << quantity<< setw(12) << totalValue();
        if (quantity < 10)
            cout << "  LOW STOCK";
        cout<<endl;
    }
    double totalValue() const{
        return price * quantity;
    }
    bool isLowStock(int threshold) const{
        return quantity < threshold;
    }
    string getName() const{
        return name;
    }
};
int main(){
    Product products[5];
    cout << "===== ENTER PRODUCT DETAILS =====" << endl;
    for (int i = 0; i < 5; i++){
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }
    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << left << setw(8) << "ID"<< setw(15) << "Name"<< setw(10) << "Price"<< setw(8) << "Qty"<< setw(12) << "Total Value"<< endl;
    for (int i = 0; i < 5; i++){
        products[i].displayDetails();
    }
    int highestIndex = 0;
    for (int i = 1; i < 5; i++){
        if (products[i].totalValue() > products[highestIndex].totalValue()){
            highestIndex = i;
        }
    }
    cout << "\nHighest Value Product : "<< products[highestIndex].getName()<< " (Rs. "<< products[highestIndex].totalValue()<< ")" << endl;
    int threshold;
    cout << "\nEnter low stock threshold: ";
    cin >> threshold;
    cout << "\nLow Stock Products: ";
    for (int i = 0; i < 5; i++){
        if (products[i].isLowStock(threshold)){
            cout << products[i].getName() << endl;
        }
    }
    return 0;
}