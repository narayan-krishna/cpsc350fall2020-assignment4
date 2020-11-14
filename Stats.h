#include <iostream>
using namespace std;

class Stats{
  private:
    int *waitTimes;
    int maxSize;
    int added;

    float meanWait;
    int medianWait;
    int longestWait;
    int studentsOver10;

    float meanIdleWindow; //done
    int longestIdleWindow; //done
    int windowsOver5; //done

  public:
    Stats(){
      maxSize = 1;
      waitTimes = new int[maxSize];
      meanWait = 0;
      medianWait = 0;
      longestWait = 0;
      studentsOver10 = 0;
      meanIdleWindow = 0;
      longestIdleWindow = 0;
      windowsOver5 = 0;
    }

    ~Stats(){
      delete waitTimes;
    }

    void updateWindowStats(float meanIdleWindowTime, int longestIdleWindowTime, int windowsOver5time){
      meanIdleWindow = meanIdleWindowTime;
      longestIdleWindow = longestIdleWindowTime;
      windowsOver5 = windowsOver5time;
    }

    void addWaitTime(int waitTime){
      // cout << "added " << added << endl;
      // cout << "max size " << maxSize << endl;
      if(added == maxSize){
        resize();
      }
      waitTimes[added] = waitTime;
      added ++;
    }

    void resize(){
      int *temp = new int[maxSize];
      for(int i = 0; i < maxSize; ++i){
        temp[i] = waitTimes[i];
      }
      delete waitTimes;
      waitTimes = new int[maxSize+1];
      for(int i = 0; i < maxSize; ++ i){
        waitTimes[i] = temp[i];
      }
      delete temp;
      maxSize = maxSize+1;
    }

    void printWaitTimes(){
      cout << "[";
      for(int i = 0; i < maxSize; ++i){
        cout << waitTimes[i];
      }
      cout << "]" << endl;
    }

    void updateStudentStats(){
      float sum = 0;
      int longest = 0;
      int over10 = 0;
      for(int i = 0; i < maxSize; ++i){
        sum += waitTimes[i];
        longest = waitTimes[i];
        if(waitTimes[i] > 10){
          over10 ++;
        }
      }
      meanWait = sum/maxSize;
      longestWait = longest;
      studentsOver10 = over10;
    }


    void printStats(){
      cout << "------------------------------------" << endl;
      cout << "STATISTICS REPORT: " << endl;
      cout << "mean wait time: " << meanWait << endl;
      cout << "median wait time: " << medianWait << endl;
      cout << "longest wait time: " << longestWait << endl;
      cout << "students waiting over 10 minutes: " << studentsOver10 << endl;
      cout << "mean window idle time: " <<  meanIdleWindow<< endl;
      cout << "longest window idle time: " << longestIdleWindow << endl;
      cout << "windows idle over 5 minutes: " << windowsOver5 << endl;
      cout << "------------------------------------" << endl;
    }


};
