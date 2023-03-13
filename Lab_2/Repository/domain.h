#pragma once
/*
Structura de "tip" care poate avea doar 2 posibilitati, intrare sau iesire
*/
enum tip{intrare,iesire};
/*
Structura unui obiect de tipul Tranzactie, cu campurile specificate
*/
typedef struct
{
    int suma;
    int ziua;
    enum tip tip;
    char *descriere;
    int id;
}Tranzactie;

/*
Functia returneaza un pointer la un string ce contine datele tranz
Preconditii: tranz este tranzactie
Postconditii: returneaza pointer la char
*/
char* string_tranzactie(Tranzactie* tranz);
/*
Constructorul unei tranzactii. Functia returneaza un pointer catre un obiect de tip tranzactie
Preconditii: - ziua apartine intervalului {1,...,31}
             - suma este un numar intreg
             - tip este fie intrare, fie iesire
             - descriere este un pointer catre o descriere, OBLIGATORIU avand \0 pe ultima pozitie
             - id numar natural
Postconditii: Functia returneaza un pointer catre un obiect de tip tranzactie ,cu specificarile date
*/
Tranzactie* creaza_tranzactie(int id, int suma, int ziua, enum tip tip, char* descriere);

/*
Functia returneaza id-ul unei tranzactii
Preconditii: tranzactie este un pointer catre o structura de tip tranzactie
Postconditii: Functia returneaza id-ul lui tranzactie
*/
int get_id(Tranzactie* tranzactie);
/*
Functia returneaza suma-ul unei tranzactii
Preconditii: tranzactie este un pointer catre o structura de tip tranzactie
Postconditii: Functia returneaza suma lui tranzactie
*/
int get_suma(Tranzactie* tranzactie);
/*
Functia schimba suma pentru o tranzactie
Preconditii: suma - numar intreg
             tranzactie - pointer catre o structura de tip tranzactie
Postconditii: Se va schimba campul suma din tranzactie in suma specificata  
*/
void set_suma(Tranzactie* tranzactie, int suma);
/*
Functia returneaza ziua unei tranzactii
Preconditii: tranzactie este un pointer catre o structura de tip tranzactie
Postconditii: Functia returneaza ziua lui tranzactie
*/
int get_ziua(Tranzactie* tranzactie);

/*
Functia schimba ziua pentru o tranzactie
Preconditii: ziua - numar intreg din {1,...,31}
             tranzactie - pointer catre o structura de tip tranzactie
Postconditii: Se va schimba campul ziua din tranzactie in ziua specificata  
*/
void set_ziua(Tranzactie* tranzactie, int ziua);
/*
Functia returneaza tipul unei tranzactii
Preconditii: tranzactie este un pointer catre o structura de tip tranzactie
Postconditii: Functia returneaza tipul lui tranzactie
*/
enum tip get_tip(Tranzactie* tranzactie);
/*
Functia schimba tipul pentru o tranzactie
Preconditii: tip - intrare/iesire
             tranzactie - pointer catre o structura de tip tranzactie
Postconditii: Se va schimba campul tip din tranzactie in tipul specificata  
*/
void set_tip(Tranzactie* tranzactie, enum tip tip);


/*
Functia returneaza un pointer de tip char, descrierea unei tranzactii
Preconditii: tranzactie este un pointer catre o structura de tip tranzactie
Postconditii: Functia returneaza descrierea unei tranzactii
*/
char* get_descriere(Tranzactie* tranzactie);
/*
Functia schimba descrierea pentru o tranzactie
Preconditii: descriere - sir de caractere cu \0 pe ultima pozitie
             tranzactie - pointer catre o structura de tip tranzactie
Postconditii: Se va schimba campul descriere din tranzactie in descrierea specificata  
*/
void set_descriere(Tranzactie* tranzactie, char* descriere);
