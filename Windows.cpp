#include "Windows.h"

Windows::Windows(int count){
  size = count;
  windowArray = new Student *[count];
  idleTimes = new int *[count];
}

bool Windows::windowIsEmpty(int window){
  if(windowArray[i] == NULL){
    return true;
  }else{
    return false;
  }
}

bool windowsFull(){
  int fullCount = 0;
  for(int i = 0; i < size; ++i){
    if(!windowIsEmpty[i]){
      fullCount += 1;
    }
  }
  if(fullCount == size + 1){
    return true;
  }else{
    return false;
  }
}

void Windows::addStudent(Student s){
  for(int i = 0; i < size; ++i){
    if(windowIsEmpty[i]){
      windowArray[i] = s;
  }
}
