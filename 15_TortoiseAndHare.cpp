// 8.12 (Simulation: The Tortoise and the Hare)
// Author: Daniel C. Watkins 09/26/21

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void moveHare(int *);
void moveTortoise(int *);
void printTrack(int *, int *, const int);

int main(){
    int tortoisePos = 1;
    int harePos = 1;
    const int raceLength = 70;
    srand(time(0)); // initialize random seed
  
    // START THE RACE
    cout << "BANG !!!!\nAND THEY'RE OFF!!!" << endl;
    while (tortoisePos < raceLength && harePos < raceLength){
        moveHare(&harePos);
        if (harePos > raceLength)
            harePos = raceLength;
        if (harePos < 1)
            harePos = 1;
        moveTortoise(&tortoisePos);
        if (tortoisePos > raceLength)
            tortoisePos = raceLength; 
        if (tortoisePos < 1)
            tortoisePos = 1;
        printTrack(&harePos, &tortoisePos, raceLength);
    }

} // end main

void moveHare(int *position){
    int move = 0;
    int roll = 1 + rand() % 10;
    if (roll == 3 || roll == 4)
        move = 9; // big hop
    else if (roll == 5)
        move = -12; // big slip
    else if (roll > 5 && roll < 9)
        move = 1; // small hop
    else if (roll > 8)
        move = -2; // small slip

    *position = *position + move;
}

void moveTortoise(int *position){
    int move = 0;
    int roll = 1 + rand() % 11;
    if (roll <= 5)
        move = 3; // fast plod
    else if (roll > 5 && roll < 8)
        move = -6; // slip
    else
        move = 1; // slow plod

    *position = *position + move;
}

void printTrack(int *harePos, int *tortPos, const int raceLength){
    // print a track starting with S, then blank until
    // we reach an animal, and blank until the F for finish line
    bool collision = false;
    for (int i = 0; i < raceLength+1; ++i){
        if (i == *harePos && i == *tortPos){
            if (i < raceLength){
                collision = true;
                cout << "*";
            }
            else
                cout << " IT'S A TIE!!!";   
        }
        else if (i == *harePos){
            cout << "H";
            if (i == raceLength)
                cout << " HARE WINS!!!";
        }
        else if (i == *tortPos){
            cout << 'T';
            if (i == raceLength)
                cout << " TORTOISE WINS!!!";
        }
        else if (i==0){
            cout << ">";
        }
        else{
            if (i < raceLength)
                cout << "-";
            else
                cout << "|";
        }
    }
    if (collision)
        cout << " OUCH!!!";
    cout << endl;
}