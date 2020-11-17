#include "Windows.h"
#include "Stats.h"
#include "Queue.h"
#include <fstream>
#include <string>
#include <math.h>
#include <thread>
#include <chrono>

//simulation class. creates windows, a queue and then uses a giant while loop
//to process the file.  
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

    //counts the lines per file, so that number of commands is known
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

    //processes the file for commands, puts them into an array
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

    //main program simulation
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
      //keep running while either the q has people in it, the windows have people,
      //or there are more commands to follow.
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
    }
};
