#include <stdlib.h>
#include <stdio.h>
#include "repo.h"
#include <string.h>
lista* creaza_lista()
{
    lista* v = (lista*)malloc(sizeof(lista));
    v->lungime_actuala=0;
    v->capacitate_maxima=2;
    v->elemente = (Tranzactie**)malloc(sizeof(Tranzactie*)*v->capacitate_maxima);
    return v;
}

int sterge_tranzactie(lista* l, int id)
{ int ok =0;
    for(int i=0; i<l->lungime_actuala; i++)
    {
        if(get_id(l->elemente[i]) == id)
        {
                ok = 1;
            free(l->elemente[i]);

            for(int j=i; j<l->lungime_actuala-1; j++)
            {
                l->elemente[j] = l->elemente[j+1];
            }

            l->lungime_actuala--;


        }
    }
    return ok;

}
void adaugare_tranzactie(lista* l, Tranzactie* tranz)
{
for (int i =0; i<l->lungime_actuala; i++)
{
    if(get_id(tranz)==get_id(l->elemente[i]))
    return;
}

if(l->lungime_actuala == l->capacitate_maxima)
resize(l);

l->elemente[l->lungime_actuala] = tranz;
l->lungime_actuala++;


}
void resize(lista* l)
{
     int capacitate_noua = 2*l->capacitate_maxima;
 Tranzactie** elemente_noi=(Tranzactie**)malloc(sizeof(Tranzactie*)*capacitate_noua);
//copiez din vectorul existent
 int i;
 for (i = 0; i < l->lungime_actuala; i++) {
elemente_noi[i] = l->elemente[i];
 }
 //dealocam memoria ocupata de vector
 free(l->elemente);
 l->elemente= elemente_noi;
 l->capacitate_maxima = capacitate_noua;

}

Tranzactie* get_tranzactie(lista* l, int id)
{
    for(int i=0; i<l->lungime_actuala; i++)
    {
      if(get_id(l->elemente[i])==id)
      return l->elemente[i];
    }
    return (Tranzactie*)NULL;
}

void modificare_tranzactie(lista* l, Tranzactie* tranz_noua, int id)
{
    for(int i=0; i<l->lungime_actuala; i++)
    {
        if(get_id(l->elemente[i]) == id)
        {   set_suma(l->elemente[i],get_suma(tranz_noua));
            set_ziua(l->elemente[i],get_ziua(tranz_noua));
            set_tip(l->elemente[i],get_tip(tranz_noua));

            free(l->elemente[i]->descriere);
            set_descriere(l->elemente[i],get_descriere(tranz_noua));
        }
    }
}

int numar_elemente(lista* l)
{
    return l->lungime_actuala;
}

void distruge(lista* l)
{
    int i;
for (i = 0; i < l->lungime_actuala; i++) 
{
free(l->elemente[i]->descriere);
free(l->elemente[i]);
}

free(l->elemente);
free(l);
}

/*
void afisare_tranzactii(lista* l)
{char* text;
    for(int i=0; i<l->lungime_actuala; i++)
    {
       text =string_tranzactie(l->elemente[i]);
        printf("%s\n", text);
        free(text);

    }
}
*/

Tranzactie ** get_all(lista* l)
{
    Tranzactie ** vector_tranzactii = (Tranzactie**)malloc(sizeof(Tranzactie*)*l->lungime_actuala);

    //Tranzactie* tranzactie_copie = (Tranzactie*) malloc(sizeof(Tranzactie));
    char* descriere_copie;


    for(int i=0; i<l->lungime_actuala; i++)
    {descriere_copie = (char*)malloc(sizeof(char)*50);
        strcpy(descriere_copie, get_descriere(l->elemente[i]));
        vector_tranzactii[i] = (Tranzactie*) malloc(sizeof (Tranzactie));
        set_descriere(vector_tranzactii[i], descriere_copie);
        set_suma(vector_tranzactii[i], get_suma(l->elemente[i]))  ;
        set_tip(vector_tranzactii[i], get_tip(l->elemente[i]));
        set_ziua(vector_tranzactii[i], get_ziua(l->elemente[i]));
        set_id(vector_tranzactii[i], get_id(l->elemente[i]));

    }

    return vector_tranzactii;

}