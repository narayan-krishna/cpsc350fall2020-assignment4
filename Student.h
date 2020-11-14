#include <iostream>
using namespace std;

class Student{
  private:
    int arrivalTime;
    int timeNeeded;
    int waitTime;
    int windowTime;

  public:
    Student(){
      timeNeeded = 0;
      arrivalTime = 0;
      windowTime = 0;
    }

    Student(int timeN, int arrivalT){
      timeNeeded = timeN;
      arrivalTime = arrivalT;
    }

    void incrementWindowTime(){
      windowTime ++;
    }

    void incrementWaitTime(){
      waitTime ++;
    }

    int getWaitTime(int exitTime){
      return exitTime - arrivalTime;;
    }

    void print(){
      // cout << "tn " << timeNeeded << " at " << arrivalTime << endl;
    }

    bool timeFulfilled(){
      if(timeNeeded == windowTime){
        return true;
      }else{
        return false;
      }
    }
};
