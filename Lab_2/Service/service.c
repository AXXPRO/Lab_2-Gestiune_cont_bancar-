#pragma once
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Validation\valid.h"

int modificare_service(int id_de_schimbat, int suma, int ziua, enum tip tip, char* descriere, lista* l)
{
Tranzactie* tranz = creaza_tranzactie(id_de_schimbat,suma,ziua,tip,descriere);

Tranzactie* tranz_cautata = get_tranzactie(l,id_de_schimbat);
if(tranz_cautata == (Tranzactie*)NULL || !tranzactie_valida(tranz))
    return 0;

modificare_tranzactie(l,tranz, id_de_schimbat);
free(tranz);
return 1;


}
int stergere_service(int id_de_sters, lista* l)
{

    return sterge_tranzactie(l, id_de_sters);
}

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