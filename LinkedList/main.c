/********************************************************************************
code written by : MOHAMED TAREK (TEKO)
data : Friday 22/3 4:06 AM
coded with Tears
********************************************************************************/

#include "LinkedList.h"
node *P1 = NULL;
dnode *P2 = NULL;
int main()
{
    InsertAtBeg_sl(&P1,6);
    InsertAtBeg_sl(&P1,7);
    InsertAtBeg_sl(&P1,9);
    Insertbet_sl(P1,2,8);
    InsertAtEnd_sl(P1,5);
    print(P1);
    printf("\n");
    /***********************************/
    InsertAtBeg_dl(&P2,2);
    InsertAtBeg_dl(&P2,3);
    InsertAtBeg_dl(&P2,5);
    Insertbet_dl(P2,2,4);
    InsertAtEnd_dl(P2,1);
    dprint(P2);
    return 0;
}
