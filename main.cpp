#include <iostream>
#include <fstream>

#include "Simulation.h"
//#include "Queue.h"
using namespace std;

int main(int argc, char ** argv)
{
  if(argc > 1)
  {
    string fileName = argv[1];

    ifstream doesFileExist(fileName);

    if(doesFileExist.good())
    {
      Simulation* execute;
      execute = new Simulation();
      execute->makeStudentObjects(fileName);
      cout << "Mean of Wait Time: " << execute->getMeanWait() << '\n';
      cout << "Longest Wait Time: " << execute->longestWait() << '\n';
      cout << "Number of students waiting over 10 mins: " << execute->waitOverTen() << '\n';
    }else{
      std::cout << "File doesn't exist. Please try again." << '\n';
    }
  return 0;
  }
}
