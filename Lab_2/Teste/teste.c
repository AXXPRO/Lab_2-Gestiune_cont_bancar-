#include <assert.h>
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include <string.h>

void teste_repository();
/*
    Functia de rulare a tuturor testelor
*/
void run_all_tests()
{
    teste_repository();
    printf("Teste repository trecute!\n");
}

/*
Teste pentru functiile legate de repository
*/
void teste_repository()
{
    Tranzactie* tranz = (Tranzactie*)malloc(sizeof(Tranzactie));
    int id=1;
    int suma=50;
    int ziua=4;
    enum tip tip = intrare;
    char descriere[] = "cadou";

    tranz = creaza_tranzactie(id,suma,ziua,tip,descriere);
    assert(id==get_id(tranz));
    assert(suma==get_suma(tranz));
    assert(ziua==get_ziua(tranz));
    assert(strcmp(descriere, get_descriere(tranz))==0);
   
   //int id_nou = 7;
   int suma_nou = 100;
   int ziua_nou=9;
   enum tip tip_nou = iesire;
   char descriere_nou[] = "cerere";

   set_suma(tranz,suma_nou);
   set_ziua(tranz,ziua_nou);
   set_tip(tranz,tip_nou);
   set_descriere(tranz,descriere_nou);

   assert(id==get_id(tranz));
    assert(suma_nou==get_suma(tranz));
    assert(ziua_nou==get_ziua(tranz));
    assert(strcmp(descriere_nou, get_descriere(tranz))==0);
    free(tranz);

}