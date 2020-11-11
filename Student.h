#include <iostream>
using namespace std;

class Student{
  public:
    int arrivalTime;
    int timeNeeded;
    int waitTime;
    int windowTime;

    void incrementWindowTime();
    void incrementWaitTime();
    void printStudentInfo();

}
