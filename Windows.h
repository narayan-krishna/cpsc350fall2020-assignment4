#include "Student.h"

//window class, has an array of windows, an array of idle times and
//booleans to match window status
class Windows{
  private:
    Student *windowArray;
    int *idleTimes;
    bool *spaceArray;
    int arrSize;

  public:
    //window constructor, takes number of windows as input
    Windows(int count){
      arrSize = count;
      windowArray = new Student[count];
      spaceArray = new bool[count]{false};
      idleTimes = new int[count]{};
    }

    //destructor
    ~Windows(){
      delete windowArray;
      delete spaceArray;
      delete idleTimes;
    }

    //checks if a given window empty
    bool windowIsEmpty(int i){
      if(spaceArray[i] == true){
        return false;
      }else{
        return true;
      }
    }

    //checks if all windows are full (if so dont add student)
    bool windowsAllFull(){
      int fullCount = 0;
      // cout << "arr " << arrSize << endl;
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == true){
          fullCount += 1;
        }
      }
      // cout << "full " << fullCount << endl;
      if(fullCount == arrSize){
        return true;
      }else{
        return false;
      }
    }

    //checks if all windows are empty
    bool windowsAllEmpty(){
      int emptyCount = 0;
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == false){
          emptyCount += 1;
        }
      }
      if(emptyCount == arrSize){
        return true;
      }else{
        return false;
      }
    }

    //add a student to windows
    void addStudent(Student s, int time){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == false){
          cout << " ... adding student @" << time << endl;
          windowArray[i] = s;
          spaceArray[i] = true;
          break;
        }
      }
    }

    //remove student from windows
    void removeStudents(int time){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == true){
          if(windowArray[i].timeFulfilled()){
            cout << " ... removing student @" << time <<  endl;
            spaceArray[i] = false;
          }
        }
      }
    }

    //print windows (full or not, and for how long they might be idle)
    void printWind(){
      for(int i = 0; i < arrSize; ++i){
        cout << "[" << spaceArray[i] << "] ";
      }
      cout << endl;
      for(int i = 0; i < arrSize; ++i){
        cout << "[" << idleTimes[i] << "] ";
      }
      cout << endl;
    }

    //increments idle time of window
    void incrementIdle(){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == false){
          idleTimes[i] += 1;
        }
      }
    }

    //increments the window time of a student
    void updateWindowTimes(){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == true){
          windowArray[i].incrementWindowTime();
        }
      }
    }

    //average window time
    float meanIdle(){
      float sum = 0;
      for(int i = 0; i < arrSize; ++i){
        sum += idleTimes[i];
      }
      float mean = sum/arrSize;
      return mean;
    }

    //finds the window idle for longest
    int longestIdleWindow(){
      int longest = 0;
      for(int i = 0; i < arrSize; ++i){
        if(idleTimes[i] > longest){
          longest = idleTimes[i];
        }
      }
      return longest;
    }

    //finds number of windows over 5 minutes
    int windowsOver5(){
      int over5 = 0;
      for(int i = 0; i < arrSize; ++i){
        if(idleTimes[i] > 5){
          over5 ++;
        }
      }
      return over5;
    }
};
