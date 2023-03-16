#include <stdio.h>
#include <stdlib.h>
#include "..\Repository\domain.h"
#include "..\Repository\repo.h"
#include "..\Validation\valid.h"

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

int adaugare_service(int id, int suma, int ziua, enum tip tip, char* descriere, lista* l)
{

    Tranzactie* tranz = creaza_tranzactie(id,suma,ziua,tip,descriere);

    if(tranzactie_valida(tranz))
    {
        adaugare_tranzactie(l,tranz);
        return 1;
    }
    else 
    {
        return 0;
    }

}