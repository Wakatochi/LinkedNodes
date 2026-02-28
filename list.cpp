#include "list.h"
#include "node.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <ios>

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

void
List::visualize()
{
   // Collect nodes first
   std::vector<Node*> nodes;
   Node* cur = m_first;
   while(cur != nullptr)
   {
      nodes.push_back(cur);
      cur = cur->getNext();
   }

   if(nodes.empty())
   {
      std::cout << "List empty" << std::endl;
      return;
   }

   const int boxWidth = 8;
   const std::string sep = "+" + std::string(boxWidth, '-') + "+";
   const std::string spacer = "    "; // space between node columns

   std::string sepLine;
   std::string prevLine;
   std::string valLine;
   std::string nextLine;

   for(size_t i = 0; i < nodes.size(); ++i)
   {
      std::string prevVal = nodes[i]->getPrev() ? std::to_string(nodes[i]->getPrev()->getValue()) : "NULL";
      std::string val = std::to_string(nodes[i]->getValue());
      std::string nextVal = nodes[i]->getNext() ? std::to_string(nodes[i]->getNext()->getValue()) : "NULL";

      // separator blocks
      sepLine += sep;
      if(i + 1 < nodes.size()) sepLine += spacer;

      // prev box
      std::ostringstream tp;
      tp << "|p:" << std::left << std::setw(boxWidth - 2) << prevVal << "|";
      prevLine += tp.str();
      if(i + 1 < nodes.size())
      {
         // if next node's prev points to this node, show left arrow between boxes
         if(nodes[i + 1]->getPrev() == nodes[i]) prevLine += " <- "; else prevLine += "    ";
      }

      // value box
      std::ostringstream vm;
      vm << "|v:" << std::left << std::setw(boxWidth - 2) << val << "|";
      valLine += vm.str();
      if(i + 1 < nodes.size())
      {
         // remove middle arrow: just add spacer between value boxes
         valLine += spacer;
      }

      // next box
      std::ostringstream nt;
      nt << "|n:" << std::left << std::setw(boxWidth - 2) << nextVal << "|";
      nextLine += nt.str();
      if(i + 1 < nodes.size())
      {
         if(nodes[i]->getNext() == nodes[i + 1]) nextLine += " -> "; else nextLine += spacer;
      }
   }

   // Print assembled lines
   std::cout << sepLine << std::endl;
   std::cout << prevLine << std::endl;
   std::cout << sepLine << std::endl;
   std::cout << valLine << std::endl;
   std::cout << sepLine << std::endl;
   std::cout << nextLine << std::endl;
   std::cout << sepLine << std::endl;
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
