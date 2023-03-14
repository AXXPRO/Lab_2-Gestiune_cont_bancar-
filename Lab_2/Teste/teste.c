#include <assert.h>
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\domain.h"
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Repository\repo.h"
#include <string.h>

void teste_domain();
void teste_repository();
void teste_service();
/*
    Functia de rulare a tuturor testelor
*/
void run_all_tests()
{
    teste_domain();
    printf("Teste domain trecute!\n");
    teste_repository();
    printf("Teste repository trecute!\n");
    teste_service();
    printf("Teste service trecute!\n");


}
/*
Teste pentru functiile legate de service
*/
void teste_service()
{       
    int id_1 = 0;
    int suma_1  =50;
    int ziua_1 = 23;
    enum tip tip_1 = intrare;
    char* descriere = (char*)malloc(sizeof(char));
    strcpy(descriere, "Lemne");

    lista* lista_test = creaza_lista();


    adaugare_service(id_1,  suma_1, ziua_1,  tip_1, descriere, lista_test);

    assert(get_tranzactie(lista_test, 0) != (Tranzactie*)NULL);

   assert(modificare_service(1,suma_1+1, ziua_1,  tip_1, descriere, lista_test) == 0 );
    assert(modificare_service(0,suma_1+1, ziua_1,  tip_1, descriere, lista_test) == 1 );

    Tranzactie* tranz_modificata = get_tranzactie(lista_test, 0);
    assert(get_suma(tranz_modificata)==51);

    assert(sterge_tranzactie(lista_test,2) == 0);
    assert(sterge_tranzactie(lista_test,0) == 1);
  tranz_modificata = get_tranzactie(lista_test, 0);
    assert(tranz_modificata == (Tranzactie*)NULL);
   
    free(lista_test);

}

/*
Teste pentru functiile legate de repository
*/
void teste_repository()
{ 
    lista* l = creaza_lista();
    assert(numar_elemente(l) == 0);
    Tranzactie *tranz,*tranz1,*tranz2,*tranz3, *tranz_noua;
    char *d1,*d2,*d3, *d4;
    d1 = (char*)malloc(sizeof(char)*10); d1[0] = '\n';
    d2 = (char*)malloc(sizeof(char)*10); d2[0] = '\n';
    d3 = (char*)malloc(sizeof(char)*10); d3[0] = '\n';

    strcpy(d1,"cadou");
    strcpy(d2,"cerere");
    strcpy(d3,"imprumut");
    tranz1 = creaza_tranzactie(0,13,5,iesire,d1);
    tranz2 = creaza_tranzactie(1,15,2,iesire,d2);
    tranz3 = creaza_tranzactie(2,177,6,intrare,d3);

    adaugare_tranzactie(l,tranz1);
    assert(numar_elemente(l) == 1);
    adaugare_tranzactie(l,tranz2);
    adaugare_tranzactie(l,tranz3);
    assert(numar_elemente(l) == 3);

    adaugare_tranzactie(l,tranz3);
    assert(numar_elemente(l) == 3);
    
    tranz = get_tranzactie(l, 1);
    assert(get_suma(tranz)==get_suma(tranz2));

    tranz = get_tranzactie(l, 3);
    assert(tranz==NULL);
   

    d4 = (char*)malloc(sizeof(char)*10); d4[0] = '\n';
    strcpy(d4,"taxe");


    tranz_noua = creaza_tranzactie(2,900,30,iesire,d4);
    modificare_tranzactie(l, tranz_noua, get_id(tranz3));

    Tranzactie* tranzactie_cautata_invalida = get_tranzactie(l,7);
    assert(tranzactie_cautata_invalida == (Tranzactie*)NULL);

    Tranzactie* tranzactie_cautata = get_tranzactie(l,0);
    assert(tranzactie_cautata ==tranz1);


    sterge_tranzactie(l, 2);
    tranzactie_cautata_invalida =get_tranzactie(l,2);
    assert(tranzactie_cautata_invalida == (Tranzactie*)NULL);

    assert(numar_elemente(l) == 2);
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
    
    char* string_tranz = (char*)malloc(sizeof(char));

   string_tranz = string_tranzactie(tranz);
   // printf("%s\n", string_tranz);
    assert(strcmp(string_tranz,"Tranzactia cu id-ul 1 si suma 100 din ziua 9 de tipul iesire are descrierea cerere" ) == 0);

   
    free(string_tranz);
    free(tranz);

}