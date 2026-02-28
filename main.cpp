// --- Memory Leak detection --- //
#define _CRTDBG_MAP_ALLOC //to get more details
#include <crtdbg.h>   //for malloc and free
// ------------------------------//

#include "listhand.h"

int main()
{
   // Calls "_CrtDumpMemoryLeaks" at exit point
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   ListHand* list = new ListHand();
   list->run();

   delete list;

   return 0;
}
