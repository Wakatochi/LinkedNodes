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
      void add(int value);
      void remove(int value);
      int size();

      void dump();

   private:
      Node* m_first;
      Node* m_last;

      /// <summary>
      /// Search the list for the node with the desired value.
      /// </summary>
      /// <param name="value">Node value</param>
      /// <returns>The predecessor node</returns>
      Node* traverse(int value);

      /// <summary>
      /// Remove all nodes.
      /// </summary>
      void deleteAll();
};

#endif
