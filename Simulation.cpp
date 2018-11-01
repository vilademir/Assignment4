#include <iostream>
#include "Simulation.h"

#include <fstream>

using namespace std;

Simulation::Simulation()
{
  queue = new Queue<Students>();
  lineCounter = 0;

}

Simulation::~Simulation()
{

}

void Simulation::makeStudentObjects(string nameOfFile)
{
  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
  {
    string fileLine;
    overallLines = 1;

    getline(fileReader, fileLine);
    int windows = stoi(fileLine);

    getline(fileReader, fileLine);
    newTimer = stoi(fileLine);

    getline(fileReader, fileLine);
    students = stoi(fileLine);

    while(fileLine != "")
    {
      for (int i = 0; i < students; i++)
      {
        windows--;
        Students newStudents;
        queue->insert(newStudents);

        getline(fileReader, fileLine);
        if (fileLine != "") {
          int newRequiredTime = stoi(fileLine);
          if (windows == 0)
          {
            minuteCount += newRequiredTime;
            lineCounter++;
            if(newRequiredTime > longestWaitTime)
            {
              longestWaitTime = newRequiredTime;
            }
            if(newRequiredTime > 10)
            {
              overTenWait++;
            }
          }
        }
      }
    }
  }
  fileReader.close();
}


int Simulation::getMeanWait()
{
  return minuteCount/lineCounter;
}

int Simulation::getMedianWait()
{
  return ((minuteCount + 1)/2);
}

int Simulation::longestWait()
{
  return longestWaitTime;
}

int Simulation::waitOverTen()
{
  return overTenWait;
}
