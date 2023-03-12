#pragma once
#include "domain.h"

/*
Vectorul dinamic ce va fi practic o lista
*/
typedef struct {
Tranzactie** elemente;
int lungime_actuala;
int capacitate_maxima;
}lista;

/*
Constructorul unei liste, va returna un pointer catre o lista
Preconditii: Nimic
Postconditii: returneaza o lista goala
*/
lista* creaza_lista();

/*
Va adauga tranzactia tranz in lista l
Preconditii: l este o lista iar tranz este o tranzactie
Postconditii: l are un element in plus, tranz
*/
void adaugare_tranzactie(lista* l, Tranzactie* tranz);

/*
Va returna numarul de elemente din lista l
Preconditii: l este lista
Postconditii: Functia returneaza numarul de elemente din lista
*/
int numar_elemente(lista* l);

/*
Va modifica tranzactia cu id-ul dat in parametrii lui tranz_noua
Daca nu exista id, nu se schimba nimic
Preconditii: l este o lista
             tranz_noua este tranzactia cu care vom modifica
             id este id-ul tranzactiei pe care o modificam
Postconditii: tranzactia cu id-ul dat devine modificata
*/
void modificare_tranzactie(lista* l, Tranzactie* tranz_noua, int id);
/*
Functia va returna un pointer catre un element de tip tranzactie cu id-ul specificat, sau NULL daca nu exista
Preconditii: l este o lista
             id este numar natural
Postconditii: adresa unei structuri de tip Tranzactie, sau NULL daca nu exista
*/
Tranzactie* get_tranzactie(lista* l, int id);
/*
Va sterge tranzitia cu id-ul dat din lista l
Daca nu exista, nu se schibma nimic
Preconditii: l este lista
             id este un numar natural
Postconditii: din lista l dispare elementul cu id-ul dat
*/
void sterge_tranzactie(lista* l, int id);
/*
Operatie necesara pentru vectori dinamici. Dubleaza capacitatea acestuia de stocare
Preconditii: l este o lista
Postconditii: capacitatea maxima lui l este dublata
*/
void resize(lista* l);
/*
Operatie necesara pentru vectori dinamici. Elibereaza memoria ocupata de lista
Preconditii: l este o lista
Postconditii: l nu mai este o lista si memoria este eliberata
*/
void distruge(lista* l);

