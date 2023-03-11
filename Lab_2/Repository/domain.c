
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"

Tranzactie* creaza_tranzactie(int id, int suma, int ziua, enum tip tip, char* descriere)
{
    Tranzactie* tranz =  (Tranzactie*)malloc(sizeof(Tranzactie));
    tranz->id = id;
    tranz->suma = suma;
    tranz->ziua = ziua;
    tranz->tip = tip;
    tranz->descriere = descriere;

    return tranz;
}

int get_id(Tranzactie* tranzactie)
{
    return tranzactie->id;
}
int get_suma(Tranzactie* tranzactie)
{
    return tranzactie->suma;
}
void set_suma(Tranzactie* tranzactie, int suma)
{
    tranzactie->suma = suma;

}

enum tip get_tip(Tranzactie* tranzactie)
{
    return tranzactie->tip;
}
void set_tip(Tranzactie* tranzactie, enum tip tip)
{
  tranzactie->tip = tip;
}

int get_ziua(Tranzactie* tranzactie)
{
    return tranzactie->ziua;
}

void set_ziua(Tranzactie* tranzactie, int ziua)
{
    tranzactie->ziua = ziua;
}

char* get_descriere(Tranzactie* tranzactie)
{
   return tranzactie->descriere;
}

void set_descriere(Tranzactie* tranzactie, char* descriere)
{
    tranzactie->descriere = descriere;
}