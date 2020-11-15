#include "Windows.h"
#include "Stats.h"
#include "Queue.h"
#include <fstream>
#include <string>
#include <math.h>
#include <thread>
#include <chrono>

class Simulation{
  private:
    string file;
    Queue<Student> *queue;
    Windows *wind;
    int *commands;
    int commandsLength;
    Stats *stati;

  public:
    Simulation(string fileName){
      queue = new Queue<Student>();
      stati = new Stats();
      file = fileName;
    }

    ~Simulation(){
      delete queue;
      delete wind;
      delete commands;
      delete stati;
    }

    int countFileLines(){
      int numLine = 0;
      ifstream myfile (file);
      string line;
      if(myfile.is_open()){
        while(getline(myfile, line)){
          numLine += 1;
        }
        myfile.close();
      }
      return numLine;
    }

    void processFile(){
      commandsLength = countFileLines();
      commands = new int[commandsLength];
      ifstream myfile (file);
      if(myfile.fail()){
        cout << "your file wasn't found. please enter a valid file name." << endl;
        exit(EXIT_FAILURE);
      }
      string line;
      if(myfile.is_open()){
        int curr = 0;
        while(getline(myfile, line)){
          commands[curr] =  stoi(line);
          curr ++;
        }
        myfile.close();
      }
    }

    // 5 <-- windows
    // 1 <-- time of students arriving
    // 2 <-- number of students arriving
    // 5 <-- student 1
    // 10 <-- student 2
    // 3 <-- time of students arriving
    // 1 <-- number of students
    // 4 <-- student 3
    //
    // 2 <-- windows
    // 5 <-- time
    // 5 <-- num students
    // 5 <-- 1
    // 5 <-- 2
    // 10 <-- 3
    // 10 <-- 4
    // 5 <-- 5


    //510, 5104

    void mainSim(){
      int clockTick = 0;
      int currCommand = 0;
      wind = new Windows(commands[currCommand]);
      currCommand ++;
      //while the queue is not empty
      // wind->printWind();
      // while(clockTick <= 8){
      // cout << wind->windowsAllEmpty() << endl;
      cout << "RUNNING SIMULATION ... " << endl;
      while(queue->getSize() != 0 || !wind->windowsAllEmpty() || currCommand < commandsLength){
        // cout << "clock: " << clockTick << endl;
        //if the time matches the time students arrive
        if(commands[currCommand] == clockTick){
          currCommand ++;
          //number of students shown up
          int studentNum = commands[currCommand];
          //add them to the queue
          for(int i = 0; i < studentNum; ++i){
            currCommand ++;
            Student s(commands[currCommand], clockTick);
            queue->enQueue(s);
          }
          // queue->returnPosition(0).print();
          currCommand ++;
        }
        //remove finished students from windows
        wind->removeStudents(clockTick);
        //add students to empty windows
        while(!wind->windowsAllFull() && queue->getSize() != 0){
          queue->returnPosition(0).print();
          Student k = queue->deQueue();
          int kWaitTime = k.getWaitTime(clockTick);
          if(kWaitTime != 0){
            stati->addWaitTime(kWaitTime);
            // cout << "here" << endl;
          }

          wind->addStudent(k, clockTick);
        }
        wind->updateWindowTimes();
        // wind->printWind();
        if(queue->getSize() != 0 || !wind->windowsAllEmpty() || currCommand < commandsLength){
          wind->incrementIdle();
        }


        //update times spent in windows
        clockTick ++;
        // cout << "current cmnd" << currCommand << " < " << commandsLength << endl;
        // cout << "queueSize " << queue->getSize() << endl;
        // cout << "windows empty? " << wind->windowsAllEmpty() << endl;
        // cout << "------------" << endl;

        this_thread::sleep_for(chrono::milliseconds(100));
      }
      stati->updateWindowStats(wind->meanIdle(), wind->longestIdleWindow(), wind->windowsOver5());
      stati->updateStudentStats();
      stati->printStats();
      // stati->printWaitTimes();
      // stati->findMedian();
    }
};
