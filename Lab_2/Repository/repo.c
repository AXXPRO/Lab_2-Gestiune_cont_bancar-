#pragma once
#include "repo.h"

lista* creaza_lista()
{
    lista* v = (lista*)malloc(sizeof(lista));
    v->lungime_actuala=0;
    v->capacitate_maxima=2;
    v->elemente = (Tranzactie**)malloc(sizeof(Tranzactie*)*v->capacitate_maxima);
    return v;
}


void adaugare_tranzactie(lista* l, Tranzactie* tranz)
{
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

int numar_elemente(lista* l)
{
    return l->lungime_actuala;
}

void distruge(lista* l)
{
    int i;
for (i = 0; i < l->lungime_actuala; i++) 
free(l->elemente[i]);

free(l->elemente);
free(l);
}