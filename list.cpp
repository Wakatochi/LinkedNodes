#include "list.h"

#include <iostream>

List::List()
 : m_first(nullptr)
 , m_last(nullptr)
{

}

List::List(int value) 
{
   Node* node = new Node(value);
   m_first = node;
   m_last = node;
}

List::~List()
{
   deleteAll();
}

bool
List::empty()
{
   return m_first == nullptr;
}

void
List::add(int value)
{
   Node* node = new Node(value);
   if(m_first == nullptr)
   {
      // First node
      m_first = node;
      m_last = node;
   }
   else if(value <= m_first->getValue())
   {
      // Put first
      node->setNext(m_first);
      m_first = node;
   }
   else
   {
      // Middle to last
      Node* predptr = traverse(value);

      node->setPrev(predptr);
      node->setNext(predptr->getNext());

      if(node->getNext() != nullptr)
      {
         // New node is between first and last.
         predptr->getNext()->setPrev(node);
      }
      else
      {
         // New node is last
         m_last = node;
      }

      predptr->setNext(node);
   }
}

void
List::remove(int value)
{
   Node* ptr;

   if(value == m_first->getValue())
   {
      ptr = m_first;
      m_first = ptr->getNext();
      m_first->setPrev(nullptr);

      delete ptr;
   }
   else
   {
      Node* predptr = traverse(value);
      ptr = predptr->getNext(); // Point out the node.

      ptr->getNext()->setPrev(ptr->getPrev());
      ptr->getPrev()->setNext(ptr->getNext());
      
      delete ptr;
   }
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
   std::cout << "Empty: ";
   if(empty())
   {
      std::cout << "YES";
   }
   else
   {
      std::cout << "NO";
   }

   std::cout << std::endl << "Size: " << size() << std::endl;
   Node* ptr = m_first;

   while(ptr != nullptr)
   {
      std::cout << ptr->getValue() << " ";
      ptr = ptr->getNext();
   }
   std::cout << std::endl;
}

Node*
List::traverse(int value)
{
   Node* ptr = m_first;
   while(ptr->getNext() != nullptr && ptr->getNext()->getValue() < value)
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
List::deleteAll()
{
   if(m_first != nullptr)
   {
      while(m_first->getNext() != nullptr)
      {
         Node* del = m_first;
         m_first = del->getNext();
         delete del;
      }

      delete m_first;
   }
}
