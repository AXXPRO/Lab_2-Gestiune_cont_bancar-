#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Infrastructura\domain.h"
#include "..\Infrastructura\repo.h"
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
char* afisare_service(lista* l)
{
    char* descriere_returnat = (char*)malloc(sizeof (char)*500* numar_elemente(l));

    descriere_returnat[0] = '\n';

    Tranzactie** lista_tranzactii = get_all(l);

    char* temp_char;
    temp_char  =string_tranzactie(lista_tranzactii[0]);
    strcpy(descriere_returnat,temp_char);

    free(temp_char);
   // free(descriere_returnat);
    strcat(descriere_returnat, "\n");


    for(int i =1; i< numar_elemente(l); i++)
    {
        temp_char  =string_tranzactie(lista_tranzactii[i]);
        strcat(descriere_returnat, temp_char);
        free(temp_char);
        strcat(descriere_returnat, "\n");
    }


    return descriere_returnat;

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