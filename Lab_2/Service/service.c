#pragma once
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Validation\valid.h"


void adaugare_service(int id, int suma, int ziua, enum tip tip, char* descriere, lista* l)
{

    Tranzactie* tranz = creaza_tranzactie(id,suma,ziua,tip,descriere);

    if(tranzactie_valida(tranz))
    {
        adaugare_tranzactie(l,tranz);
        
    }
    else 
    {
        printf("Parametrii invalizi!\n");
        getchar();
    }

}