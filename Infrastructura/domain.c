
#include "..\Infrastructura\domain.h"
#include <stdlib.h>
#include <string.h>
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
void set_id(Tranzactie* tranzactie, int id)
{
    tranzactie->id = id;
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

char* string_tranzactie(Tranzactie* tranz)
{ 

    char* string = (char*)malloc(sizeof(char)*100);
    string[0]='\0';
    strcat(string,"Tranzactia cu id-ul ");

   // char id[100], suma[100], ziua[100]
   char id[10] ,suma[10],ziua[10];
     itoa(get_id(tranz),id,10);
    strcat(string,id);
    strcat(string," si suma ");
     itoa(get_suma(tranz),suma,10);
    strcat(string,suma);

    strcat(string," din ziua ");
     itoa(get_ziua(tranz),ziua,10);
    strcat(string,ziua);

    strcat(string," de tipul ");

    enum tip tip = get_tip(tranz);
    if(tip == intrare)
    strcat(string,"intrare");
    else
    strcat(string,"iesire"); 

     strcat(string," are descrierea ");

     char *p = get_descriere(tranz);
     strcat(string, p);

     return string;

    
}