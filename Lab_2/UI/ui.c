#pragma once
#include <string.h>
#include <stdio.h>
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Service\service.h"
//#include <stdlib.h>
void adaugare(lista*);
void modificare(lista*);
void stergere(lista*);

char null_var;

/*
Functia responsabila pentru afisarea optiunilor utilizatorului
*/
void interface()
{ system("cls");
  printf("Alegeti optiunea pe care o doriti. Optiunile sunt urmatoarele:\n");
  printf("1.Adaugare de tranzactii.\n");
  printf("2.Modificare tranzactie existenta.\n");
  printf("3.Stergere tranzactie existenta.\n");
  printf("6.Inchidere aplicatie.\n");
  printf(">>>");

}



/*
Functia ce va rula interfata de utilizator
*/


void run_ui()
{   lista* lista_tranzactii = creaza_lista();
    char choices[]="123456";
    char choice[20];
    int program_running = 1;
    int number_choice;
    while(program_running)
    {
        interface();
        //scanf("%s", choice);
        gets(choice);
        if(strlen(choice)==1)
        {
           
            //Run program
                number_choice = choice[0]-'0';
                switch (number_choice)
                {
                    case 1:
                    adaugare(lista_tranzactii);
                    break;
                    case 2:
                    modificare(lista_tranzactii);
                    break;
                    case 3:
                    stergere(lista_tranzactii);
                    break;
                    case 4:
                    /* code */
                    break;
                    case 5:
                    /* code */
                    break;
                    case 6:
                    program_running = 0;
                    break;
                default:
                {
                printf("Varianta inexistenta!\n");
                gets(choice);
                }
                    break;
                }


            
          
        }
        else{printf("Varianta inexistenta!\n");
                gets(choice);}



    }
    

}

void adaugare(lista* l)
{   
    char params[100];
    char true_params[5][50];
    char* cuvant;
    //printf
    printf("Dati id-ul, ziua, suma, tipul, si descrierea tranzactiei, separate prin ; :\n");
     //getchar();
    gets(params);
    //scanf("%s",params);
    cuvant = strtok(params, ";");
    int i;

    for(i=0;cuvant != NULL; i++)
     {strcpy(true_params[i], cuvant);   
     cuvant = strtok(NULL, ";");
     }

    if(i!=5)
    {
printf("Paramtetrii invalizi!");
getchar();
    }
    else 
    { int id = atoi(true_params[0]);
    int ziua = atoi(true_params[1]);
    int suma = atoi(true_params[2]);



    enum tip tip;
    int ok = 0;
    char tipul[50];
    strcpy(tipul, true_params[3]);
    if(strstr("intrare", tipul)!=NULL)
      {tip = intrare; ok =1;}
    if(strstr("iesire", tipul)!=NULL)
      {tip = iesire; ok=1;}



    char descriere[50];
    strcpy(descriere, true_params[4]);

    if(ok)
    {
        adaugare_service(id,suma,ziua,tip,descriere,l);
    }
    else 
    {
printf("Paramtetrii invalizi!");
getchar();

    }

    }

   


}
void stergere(lista* l)
{

}
void modificare(lista* l)
{

}