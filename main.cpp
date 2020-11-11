#include "Queue.h"

int main(int argc, char **argv){
  // DoublyLinkedList<char> *testList = new DoublyLinkedList<char>();
  // testList->insertFront('a');
  // testList->insertBack('b');
  // testList->insertBack('c');
  // testList->insertFront('a');
  // testList->printList();
  // testList->deletePos(2);
  // cout << testList->removeBack() << endl;
  // // testList->removeNode('a');
  // // cout << testList->find('b') << endl;
  // testList->printList();

  Queue<char> *testQueue = new Queue<char>();
  testQueue->enQueue('a');
  testQueue->printQueue();
  cout << "-------" << endl;
  testQueue->enQueue('b');
  testQueue->printQueue();
  cout << "-------" << endl;
  testQueue->deQueue();
  testQueue->printQueue();
  cout << "-------" << endl;
  testQueue->enQueue('d');
  testQueue->printQueue();
  cout << "-------" << endl;
  testQueue->deQueue();
  testQueue->printQueue();
  cout << "-------" << endl;
}


//deletePos