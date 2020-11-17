#include "Simulation.h"

//main file runs a simulation upon valid input
int main(int argc, char **argv){
  if(argc != 2){
    cout << "command line requires a file input" << endl;
    cout << "example: " << endl;
    cout << "'./assignment4.exe sequences.txt'" << endl;
  }
  else{
    Simulation *s = new Simulation(argv[1]);
    s->processFile();
    s->mainSim();
    delete s;
  }
}
