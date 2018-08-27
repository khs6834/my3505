#include <iostream>
#include <math.h>
#include <string>
using namespace std;
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void plotCharacterAtPosition(int number, char letter);
void plotPopulations(int numRabbits, int numFoxes, double scale);
void incrementCounter(int* counter);

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes) {
  double deltaRabbit = g*numRabbits*(1-numRabbits/K) - p*numRabbits*numFoxes;
  double deltaFoxes = c*p*numRabbits*numFoxes - m*numFoxes;
  //cout << "deltaR = " <<deltaRabbit <<"  deltaF = " <<deltaFoxes;
  numRabbits = (int) (numRabbits + deltaRabbit);
  numFoxes = (int) (numFoxes + deltaFoxes);
}


void plotCharacterAtPosition(int number, char letter) {
  if(number < 1) {
    cout << letter ;
  }
  else{
    for (int i = 0; i<number-1; i++) {
      cout << " " ;
    }
    cout << letter ;
  }
}


void plotPopulations(int numRabbits, int numFoxes, double scale) {
  int foxPos = floor(numFoxes*scale) + 1;
  int rabPos = floor(numRabbits * scale) + 1;
  if(foxPos == rabPos) {
    plotCharacterAtPosition(foxPos,'*');
  }
  else {
    plotCharacterAtPosition(foxPos,'F');
    plotCharacterAtPosition(rabPos,'r');
  }
  cout << endl;
}


void incrementCounter(int* counter) {
  //create a new int object with the new counter vlaue.
  int newCounter = (*counter) --;
  //set the old pointer to point towards the new object
  counter = &newCounter;
}

int main () {
  double g = 0.2;
  double p = 0.002;
  double c = 0.6;
  double m = 0.2;
  double K = 1000;
  double numFoxes = 0;
  double numRabbits = 0;
  string temp;

  cout << "Please enter the number of Foxes: ";
  try {
    cin >> temp;
    numFoxes = stod(temp);
  }
  catch (...)
  {
    cout << "Invalid input. Exitting the program." << endl;
    exit(0);
  }

  cout << "Please enter the number of Rabbits: ";
  try {
    cin >> temp;
    numRabbits = stod(temp);
  }
  catch (...)
  {
    cout << "Invalid input. Exitting the program." << endl;
    exit(0);
  }

  int counter = 500;
  while (counter > 0 && numFoxes > 0 && numRabbits > 0)
  {
    updatePopulations(g,p,c,m,K,numRabbits,numFoxes);
    plotPopulations(numRabbits,numFoxes,0.1);
  }
}
