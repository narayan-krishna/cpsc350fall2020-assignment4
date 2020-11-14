#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"

template <class T>
class Queue{
  private:
    DoublyLinkedList<T> *queueList;

  public:
    Queue(){
      queueList = new DoublyLinkedList<T>();
    }

    ~Queue(){
      delete queueList;
    };

    void enQueue(T data){
      queueList->insertFront(data);
    }

    T deQueue(){
      queueList->removeBack();
    }

    void printQueue(){
      queueList->printList();
    }

    T returnPosition(int pos){
      queueList->returnPos((queueList->getSize()-pos)-1);
    }

    unsigned int getSize(){
      queueList->getSize();
    }
};
#endif
