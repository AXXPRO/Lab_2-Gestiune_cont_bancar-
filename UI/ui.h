//
// Created by Gabi on 16.03.2023.
//

#include "../Infrastructura//repo.h"

///Va afisa functia sortata crescator/descrescator dupa suma
void ordonat(lista*);
///Va afisa doar elementele care au un anumit tip
void criteriu_tip(lista*);
///Va afisa doar elementele cu suma mai mare sau mai mica decat o suma data
void criteriu_suma(lista*);
///Functie de ui pentru optiunea criteriu. Aceasta va apela ori criteriu_tip, ori criteriu_suma
void criteriu(lista*);
///Functia de ui va afisa continutul din lista
void afisare(lista*);
///Functia de ui va cere date si va adauga elementul respectiv
void adaugare(lista*);
///Functia de ui va cere date si va modifica elementul respectiv
void modificare(lista*);
///Functia de ui va cere date si va sterge elementul respectiv
void stergere(lista*);
///Functia ce va rula aplicatia
void run_ui();



/*
Functia ia un sir de caractere si returneaza daca este sau nu numar
PreconditiiL s - sir de caractere cu \0 la sfarsit
Postconditii: 1 daca poate fi numar, 0 altfel
*/
int is_number(char* s);


