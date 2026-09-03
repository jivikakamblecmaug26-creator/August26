//Assignment 2
//Question 3 - Game engine
//Part C - Dynamic 2D game map
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int R, C;
    cout << "Enter number of rows: ";
    cin >> R;
    cout << "Enter number of columns: ";
    cin >> C;
    int** map = new int*[R];
    for (int i = 0; i < R; i++){
        map[i] = new int[C];
    }
    srand(time(0));
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            map[i][j] = rand() % 5;
        }
    }
    cout << "\n===== GAME MAP =====" << endl;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nLegend:"<< "\n0 = Grass"<< "\n1 = Water"<< "\n2 = Mountain"<< "\n3 = Forest"<< "\n4 = Dungeon"<< endl;
    int count[5] = {0};
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            count[map[i][j]]++;
        }
    }
    cout << "\nTile Count:" << endl;
    cout << "Grass    : " << count[0] << endl;
    cout << "Water    : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest   : " << count[3] << endl;
    cout << "Dungeon  : " << count[4] << endl;
    for (int i = 0; i < R; i++){
        delete[] map[i];
    }
    delete[] map;
    return 0;
} 
 