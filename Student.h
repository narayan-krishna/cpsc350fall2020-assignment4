#include <iostream>
using namespace std;

//student class, holds arrival time and time needed.
//calculates amount of time spent waiting.
class Student{
  private:
    int arrivalTime;
    int timeNeeded;
    int waitTime;
    int windowTime;

  public:
    //default constructor
    Student(){
      timeNeeded = 0;
      arrivalTime = 0;
      windowTime = 0;
    }

    //overloaded constructor
    Student(int timeN, int arrivalT){
      timeNeeded = timeN;
      arrivalTime = arrivalT;
    }

    //increments time spent at windows
    void incrementWindowTime(){
      windowTime ++;
    }

    //increments time spent waiting
    void incrementWaitTime(){
      waitTime ++;
    }

    //calculates wait time
    int getWaitTime(int exitTime){
      return exitTime - arrivalTime;;
    }

    //for testing
    void print(){
      // cout << "tn " << timeNeeded << " at " << arrivalTime << endl;
    }

    //checks to see if student can leave window
    bool timeFulfilled(){
      if(timeNeeded == windowTime){
        return true;
      }else{
        return false;
      }
    }
};
