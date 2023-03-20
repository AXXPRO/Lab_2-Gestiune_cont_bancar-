#include "../Infrastructura/repo.h"

int cmpfuncDescrescator(const void* el1, const void* el2);
int cmpfuncCrescator(const void* el1, const void* el2);
///
/// \param l -lista elementelor de tip tranzactie
/// \param criteriu - pentru a determina cum sortam. > 0 crescator,< 0 descrescator
/// \return
lista* ordonat_service(lista* l, int criteriu);
/// \param l -lista elementelor de tip tranzactie
/// \param suma -suma dupa care returnam o noua lista de elemente
/// \param comparatie -2 valori posibile >0 daca vrem mai >suma, si <0 daca vrem <suma
/// \return un pointer la o noua lista care contine doar elementele dupa criteriul ales
lista* criteriu_suma_service(lista* l, int suma, int comparatie);

///
/// \param l -lista elementelor de tip tranzactie
/// \param tip -tipul dupa care returnam o noua lista de elemente
/// \return un pointer la o noua lista care contine doar elementele cu tipul specificat
lista* criteriu_tip_service(lista* l, enum tip tip);
/*
 Functia returneaza un pointer la un string ce contine "descrerea" pentru fiecare functie
 */
char* afisare_service(lista* l);
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
int adaugare_service(int id, int suma, int ziua, enum tip tip, char* descriere, lista* l);

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

///
/// \param id_de_sters
/// \param l
/// \return
int stergere_service(int id_de_sters, lista* l);