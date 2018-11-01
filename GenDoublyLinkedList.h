#include <iostream>
#include "ListNode.h"

using namespace std;


template <class list>
class DoublyLinkedList
{

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(list d);
  int removeFront();
  void insertBack(list d);
  int removeBack();

  void printList();
  int find(list value);

  unsigned int getSize();
  int deletePos(list pos);
  ListNode<list>* remove(list key);

  ListNode<list> *front;
  ListNode<list> *back;
  unsigned int size;

};



template <class list>
DoublyLinkedList<list>::DoublyLinkedList()
{
  front = NULL;
  size = 0;
}

template <class list>
DoublyLinkedList<list>::~DoublyLinkedList()
{
  //research
}

template <class list>
unsigned int DoublyLinkedList<list>::getSize()
{
  return size;
}

template <class list>
void DoublyLinkedList<list>::printList()
{
  ListNode<list> *curr = front;

  while(curr)
  {
    std::cout << curr -> data << endl;
    curr = curr -> next;
  }
}

template <class list>
void DoublyLinkedList<list>::insertBack(list d)
{
  ListNode<list> *node = new ListNode<list>(d);

  if(size == 0)
  {
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class list>
int DoublyLinkedList<list>::removeFront()
{
  ListNode<list> *temp = front;
  if(front->next == NULL) //only node in list
  {
    back = NULL;
  }else{
    front->next->prev = NULL;
  }

 front->next = front;
 temp->next = NULL;
 int val = temp->data;

 delete temp;
 size--;

 return val;
}

template <class list>
int DoublyLinkedList<list>::find(list value)
{
  int idx = -1;
  ListNode<list> *curr = front;

  while(curr != NULL)
  {
    ++idx;
    if(curr -> data == value)
    {
      break;
    }else{
      curr = curr -> next;
    }
  }
  if (curr == NULL)
  {
    idx = -1;
  }

  return idx;

}

template <class list>
int DoublyLinkedList<list>::deletePos(list pos)
{
  int idx = 0;
  ListNode<list> *prev = front;
  ListNode<list> *curr = front;

  while (idx != pos)
  {
    prev = curr;
    curr = curr -> next;
    ++idx;
  }
  //when it finds the position, add logic to verify value was found

  prev -> next = curr -> next;
  curr -> next = NULL;
  int d = curr -> data;
  size--;

  delete curr;

  return d;
}
