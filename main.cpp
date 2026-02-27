// --- Memory Leak detection --- //
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free
// ------------------------------//

#include "list.h"

int main()
{
   // Calls "_CrtDumpMemoryLeaks" at exit point
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   List list(9);

   list.add(17);
   list.add(26);
   list.add(22);
   list.add(20);
   list.add(34);

   list.dump();

   return 0;
}
