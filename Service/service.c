#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Infrastructura\domain.h"
#include "..\Infrastructura\repo.h"
#include "..\Validation\valid.h"


lista* criteriu_tip_service(lista* l, enum tip tip)
{
    lista* lista_returnat = creaza_lista();

    Tranzactie** lista_tranzactii = get_all(l);

    for(int i=0; i< numar_elemente(l); i++)
    {
        if(get_tip(lista_tranzactii[i])==tip)
        {
            adaugare_tranzactie(lista_returnat,lista_tranzactii[i]);

        }
    }


    /*for(int i =0; i< numar_elemente(l); i++)
    {
        free(lista_tranzactii[i]);
    }
     */
    free(lista_tranzactii);
    return lista_returnat;
}

int modificare_service(int id_de_schimbat, int suma, int ziua, enum tip tip, char* descriere, lista* l)
{
Tranzactie* tranz = creaza_tranzactie(id_de_schimbat,suma,ziua,tip,descriere);

Tranzactie* tranz_cautata = get_tranzactie(l,id_de_schimbat);
if(tranz_cautata == (Tranzactie*)NULL || !tranzactie_valida(tranz))
{ free(tranz);
    return 0;
}


modificare_tranzactie(l,tranz, id_de_schimbat);
free(tranz);
return 1;


}
char* afisare_service(lista* l)
{
    char* descriere_returnat = (char*)malloc(sizeof (char)*500* numar_elemente(l));

    descriere_returnat[0] = '\0';
    if(numar_elemente(l) == 0)
        return descriere_returnat;
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

    for(int i =0; i< numar_elemente(l); i++)
    {
        free(lista_tranzactii[i]);
    }
    free(lista_tranzactii);

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
    { free(tranz);
        return 0;
    }

}