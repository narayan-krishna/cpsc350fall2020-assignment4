// #include "Windows.h"
//
// Windows::Windows(int count){
//   arrSize = count;
//   windowArray = new Student[count];
//   spaceArray = new bool[count];
//   idleTimes = new int[count];
// }
//
// bool Windows::windowIsEmpty(int i){
//   if(spaceArray[i] == true){
//     return false;
//   }else{
//     return true;
//   }
// }
//
// bool windowsFull(){
//   int fullCount = 0;
//   for(int i = 0; i < arrSize; ++i){
//     if(spaceArray[i] == true){
//       fullCount += 1;
//     }
//   }
//   if(fullCount == arrSize + 1){
//     return true;
//   }else{
//     return false;
//   }
// }
//
// void Windows::addStudent(Student s){
//   for(int i = 0; i < arrSize; ++i){
//     if(spaceArray[i] == false){
//       windowArray[i] = s;
//       spaceArray[i] = true;
//     }
//   }
// }
//
// void Windows::removeStudents(int time){
//   for(int i = 0; i < arrSize; ++i){
//     if(spaceArray(i) == true){
//       if(windowArray[i].timeFulfilled()){
//         spaceArray[i] = false;
//       }
//     }
//   }
// }
