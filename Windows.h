#include "Student.h"

class Windows{
  private:
    Student *windowArray;
    int *idleTimes;
    bool *spaceArray;
    int arrSize;

  public:
    Windows(int count){
      arrSize = count;
      windowArray = new Student[count];
      spaceArray = new bool[count]{false};
      idleTimes = new int[count]{};
    }

    ~Windows(){
      delete windowArray;
      delete spaceArray;
      delete idleTimes;
    }

    bool windowIsEmpty(int i){
      if(spaceArray[i] == true){
        return false;
      }else{
        return true;
      }
    }

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

    void incrementIdle(){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == false){
          idleTimes[i] += 1;
        }
      }
    }

    void updateWindowTimes(){
      for(int i = 0; i < arrSize; ++i){
        if(spaceArray[i] == true){
          windowArray[i].incrementWindowTime();
        }
      }
    }

    float meanIdle(){
      float sum = 0;
      for(int i = 0; i < arrSize; ++i){
        sum += idleTimes[i];
      }
      float mean = sum/arrSize;
      return mean;
    }

    int longestIdleWindow(){
      int longest = 0;
      for(int i = 0; i < arrSize; ++i){
        if(idleTimes[i] > longest){
          longest = idleTimes[i];
        }
      }
      return longest;
    }

    int windowsOver5(){
      int over5 = 0;
      for(int i = 0; i < arrSize; ++i){
        if(idleTimes[i] >= 5){
          over5 ++;
        }
      }
      return over5;
    }
};
