#include "list.h"

#include <iostream>

List::List()
 : m_first(nullptr)
{

}

List::List(int value) 
{
   Node* node = new Node(value);
   m_first = node;
}

List::~List()
{
   if(m_first != nullptr)
   {
      delete m_first;
   }
}

bool
List::empty()
{
   return m_first == nullptr;
}

Node*
List::traverse(int value)
{
   Node* ptr = m_first;
   while(ptr->getNext() != nullptr && ptr->getValue() < value)
   {
      if(value >= ptr->getNext()->getValue())
      {
         ptr = ptr->getNext();
      }
      else
      {
         return ptr;
      }
   }

   // Last
   return ptr;
}

void
List::add(int value)
{
   Node* node = new Node(value);
   if(m_first == nullptr)
   {
      m_first = node;
   }
   else
   {
      Node* predptr = traverse(value);
      node->setNext(predptr->getNext());

      predptr->setNext(node);
   }
}

void
List::remove()
{

}

int
List::size()
{
   int size = 0;
   Node* ptr = m_first;
   
   while(ptr != nullptr)
   {
      ptr = ptr->getNext();
      size++;
   }

   return size;
}

void
List::dump()
{
   std::cout << "Size: " << size() << std::endl;
   Node* ptr = m_first;

   while(ptr != nullptr)
   {
      std::cout << ptr->getValue() << " ";
      ptr = ptr->getNext();
   }
   std::cout << std::endl;
}
