#pragma once
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"


/*
Functia de service de adaugare a unei tranzactii in repository
Preconditii: int - natural
             suma - intreg
             ziua - natural {1,...,31}
             tip - intrare/iesire
             descriere - sir de caractere ce se termina cu \0
postconditii: tranzactia e adaugata in repo
*/
void adaugare_service(int id, int suma, int ziua, enum tip tip, char* descriere, lista* l);