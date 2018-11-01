#include <iostream>
#include "Students.h"
#include "Queue.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();

  void makeStudentObjects(string nameOfFile);

  int getMeanWait();
  int getMedianWait();
  int longestWait();
  int waitOverTen();
  int meanIdle(string nameOfFile);
  int longestIdle(string nameOfFile);
  int numWindowsOverFive(string nameOfFile);

  int lineCounter;
  int minuteCount;
  int overallLines;
  int newTimer;
  int students;
  int longestWaitTime;
  int overTenWait;
  int numberOnLine;
  Queue<Students> *queue;
};
