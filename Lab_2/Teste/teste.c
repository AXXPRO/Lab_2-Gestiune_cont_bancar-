#include <assert.h>
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"
#include <string.h>

void teste_domain();
void teste_repository();
/*
    Functia de rulare a tuturor testelor
*/
void run_all_tests()
{
    teste_domain();
    printf("Teste domain trecute!\n");
    teste_repository();
    printf("Teste repository trecute!\n");


}

/*
Teste pentru functiile legate de repository
*/
void teste_repository()
{ 
    lista* l = creaza_lista();
    assert(numar_elemente(l) == 0);
    Tranzactie *tranz1,*tranz2,*tranz3;
    tranz1 = creaza_tranzactie(0,13,5,iesire,"cadou");
    tranz2 = creaza_tranzactie(1,15,2,iesire,"cerere");
    tranz3 = creaza_tranzactie(2,177,6,intrare,"imprumut");

    adaugare_tranzactie(l,tranz1);
    assert(numar_elemente(l) == 1);
    adaugare_tranzactie(l,tranz2);
    adaugare_tranzactie(l,tranz3);
    assert(numar_elemente(l) == 3);

    distruge(l);

    

}
/*
Teste pentru functiile legate de domain
*/
void teste_domain()
{
    Tranzactie* tranz;
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