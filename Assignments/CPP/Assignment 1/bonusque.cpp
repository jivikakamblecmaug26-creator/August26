//Assignment 1
//Struct padding
#include <iostream>
using namespace std;
struct Layout1{
    char c1;
    int i;
    char c2;
};
struct Layout2{
    int i;
    char c1;
    char c2;
};
int main(){
    cout << "Size of Layout1 : "<< sizeof(Layout1)<< " bytes" << endl;
    cout << "Size of Layout2 : "<< sizeof(Layout2)<< " bytes" << endl;
    return 0;
}
