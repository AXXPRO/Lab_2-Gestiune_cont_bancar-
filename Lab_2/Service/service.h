#pragma once
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"


/*
MODIFY TO INT
Functia de service de adaugare a unei tranzactii in repository
Preconditii: int - natural
             suma - intreg
             ziua - natural {1,...,31}
             tip - intrare/iesire
             descriere - sir de caractere ce se termina cu \0
postconditii: tranzactia e adaugata in repo
*/
void adaugare_service(int id, int suma, int ziua, enum tip tip, char* descriere, lista* l);

/*
Functia de service de modificare a unei tranzactii
Preconditii: int - natural
             suma - intreg
             ziua - natural {1,...,31}
             tip - intrare/iesire
             descriere - sir de caractere ce se termina cu \0
Postconditii: se modifica Tranzactia, daca s-a modificat se returneaza 1, 0 altfel
*/
int modificare_service(int id_de_schimbat, int suma, int ziua, enum tip tip, char* descriere, lista* l);

/*
Functia de service de stergere a unei
Preconditii: id - natural
Postconditii: se sterge Tranzactia cu id-ul dat, daca s-a sters se returneaza 1, 0 altfel
*/
int stergere_service(int id_de_sters, lista* l);