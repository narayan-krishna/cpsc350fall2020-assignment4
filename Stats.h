#include <iostream>
using namespace std;

class Stats{
  public:
    int meanWait;
    int medianWait;
    int longestWait;
    int studentsOver10;
    int meanIdleWindow;
    int longestIdleWindow;
    int windowsOver5;

    void printStats();
}
