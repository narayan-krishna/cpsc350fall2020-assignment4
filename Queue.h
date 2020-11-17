#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"

//template queue class based on linked list. exists as an adt, all operations
//are references to DLL class
template <class T>
class Queue{
  private:
    DoublyLinkedList<T> *queueList;

  public:
    //constructo Queue
    Queue(){
      queueList = new DoublyLinkedList<T>();
    }

    //deletes queue
    ~Queue(){
      delete queueList;
    };

    //enqueues data by putting it at the back of queue
    void enQueue(T data){
      queueList->insertFront(data);
    }

    //dequeues and returns data at the front
    T deQueue(){
      queueList->removeBack();
    }

    //prints queue, for testing
    void printQueue(){
      queueList->printList();
    }

    //returns position of element in queue
    T returnPosition(int pos){
      queueList->returnPos((queueList->getSize()-pos)-1);
    }

    //returns size of queue
    unsigned int getSize(){
      queueList->getSize();
    }
};
#endif
