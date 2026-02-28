#ifndef LISTHAND_H
#define LISTHAND_H

#include "list.h"

class ListHand
{
   public:
      ListHand();
      ~ListHand();

      void run();

   private:
      List* m_list;


      enum class Operation
      {
         PRINT,
         ADD,
         REMOVE,
         QUIT,
      };

      void printMenu();

      void add();
      void remove();
      void printList();
};

#endif
