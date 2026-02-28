#include "listhand.h"

#include <iostream>
#include <cstdlib>

ListHand::ListHand()
: m_list(nullptr)
{
   m_list = new List();
}

ListHand::~ListHand()
{
   delete m_list;
}

void
ListHand::run()
{
   Operation operation = Operation::PRINT;
   bool run = true;

   while(run)
   {
      printMenu();

      int choise;
      std::cin >> choise;
      operation = (Operation)choise;

      switch(operation)
      {
         case Operation::PRINT:
            printList();
            break;

         case Operation::ADD:
            add();
            break;

         case Operation::REMOVE:
            remove();
            break;

         case Operation::VISUALIZE:
            visualize();
            break;

         case Operation::QUIT:
            run = false;
            break;
      }
   }
}

void
ListHand::printMenu()
{
   using namespace std;
   system("cls");

   cout << "#### #### ####" << endl;
   cout << " [0] Print" << endl;
   cout << " [1] Add" << endl;
   cout << " [2] Remove" << endl;
   cout << " [3] Visualize" << endl;
   cout << " [4] Quit" << endl;
   cout << "#### #### ####" << endl;
   std::cout << "Enter value: ";
}

void
ListHand::add()
{
   int val;

   system("cls");
   std::cout << "--- Add ---" << std::endl;
   std::cout << "Enter value: ";
   std::cin >> val;

   m_list->add(val);
}

void
ListHand::remove()
{
   int val;

   system("cls");
   std::cout << "--- Remove ---" << std::endl;
   std::cout << "Enter value: ";
   std::cin >> val;

   m_list->remove(val);
}

void
ListHand::printList()
{
   int val;

   system("cls");
   std::cout << "Current list:" << std::endl;

   m_list->dump();

   std::cout << std::endl << "Press any key to continue" << std::endl;
   std::cin >> val;
   std::cout.flush();
}

void
ListHand::visualize()
{
   int val;
   system("cls");
      
   m_list->visualize();
   
   std::cout << std::endl << "Press any key to continue" << std::endl;
   std::cin >> val;
   std::cout.flush();
}
