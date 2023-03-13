#pragma once
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
int tranzactie_valida(Tranzactie* tranz)
{
    int id = get_id(tranz);
    int suma = get_suma(tranz);
    int ziua = get_ziua(tranz);
    
    char descriere[50];
    strcpy(descriere, get_descriere(tranz));
 

    

    if(id < 0)
    return 0;
    if (ziua <1 || ziua >31)
    return 0;
    
    if(descriere[0]=='\0')
    return 0;

    return 1;



}
