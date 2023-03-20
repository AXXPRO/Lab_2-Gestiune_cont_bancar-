#include <string.h>
#include "../Infrastructura/domain.h"
int tranzactie_valida(Tranzactie* tranz)
{
    int id = get_id(tranz);
    int suma = get_suma(tranz);
    int ziua = get_ziua(tranz);
    
    char descriere[50];
    strcpy(descriere, get_descriere(tranz));
 
    int ok =1;
    

    if(id < 0)
    ok=0;
    if (ziua <1 || ziua >31)
    ok=0;
    
    if(descriere[0]=='\0')
    ok=0;

    return ok;



}
