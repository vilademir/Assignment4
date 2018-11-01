#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;

template <class q>
class Queue
{
public:
  Queue();
  Queue(int maxSize);
  ~Queue();
  void insert(q data);
  q remove();
  int getSize();

  DoublyLinkedList<q> *newQueue;

private:
  int front;
  int rear;
  int numElements;
  int size;

};


template <class q>
Queue<q>::Queue()
{
    newQueue = new DoublyLinkedList<q>();
}

template <class q>
Queue<q>::Queue(int maxSize)
{

}

template <class q>
Queue<q>::~Queue()
{

}

template <class q>
void Queue<q>::insert(q data)
{
  newQueue->insertBack(data);
  size++;
}


template <class q>
q Queue<q>::remove()
{
  newQueue->removeFront();
}

template <class q>
int Queue<q>::getSize()
{
  return newQueue->getSize();
}
