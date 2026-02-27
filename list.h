#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
   public:
      List();
      List(int value);
      ~List();

      bool empty();
      Node* traverse(int value);
      void add(int value);
      void remove();
      int size();

      void dump();

   private:
      Node* m_first;
};

#endif