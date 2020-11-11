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
      delete queueList();
    };

    void enQueue(T data){
      queueList->insertFront(data);
    }

    void deQueue(){
      queueList->removeBack();
    }

    void printQueue(){
      queueList->printList();
    }
};
#endif
