//Assignment 2
//Question 3 - Game engine
//Part B - Namespaces
#include <iostream>
using namespace std;
namespace Physics{
    double clamp(double val, double min, double max){
        if (val < min)
            return min;
        if (val > max)
            return max;
        return val;
    }
    double lerp(double a, double b, double t){
        return a + (b - a) * t;
    }
}
namespace GameMath{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;
        if (val > max)
            return max;
        return val;
    }
    double lerp(double a, double b, double t){
        return a + (b - a) * t;
    }
}
int main(){
    double velocity = 150.5;
    cout << "Physics clamp: "<< Physics::clamp(velocity, 0.0, 100.0)<< endl;
    cout << "Physics lerp: "<< Physics::lerp(0, 100, 0.5)<< endl;
    cout << "GameMath clamp: "<< GameMath::clamp(120, 0, 100)<< endl;
    cout << "GameMath lerp: "<< GameMath::lerp(0, 100, 0.25)<< endl;
    {
        using namespace Physics;
        cout << "Inside block: "<< clamp(150.0, 0.0, 100.0)<< endl;
    }
    return 0;
} 