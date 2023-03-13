#pragma once
#include <string.h>
#include <stdio.h>
#include "C:\Users\Gabi\Desktop\Lab_2-Gestiune_cont_bancar-\Lab_2\Service\service.h"
//#include <stdlib.h>
void adaugare(lista*);
void modificare(lista*);
void stergere(lista*);

/*
Functia ia un sir de caractere si returneaza daca este sau nu numar
PreconditiiL s - sir de caractere cu \0 la sfarsit
Postconditii: 1 daca poate fi numar, 0 altfel
*/
int is_number(char* s)
{   

    if (strlen(s)==0)
    return 0;
    if(s[0]=='-')
    return is_number(s+1);
    for(int i = 0; i<strlen(s); i++)
    {
        if(s[i] - '0' < 0 || s[i]- '0' > 9)
        return 0;
    }

    return 1;
}

/*
Functia responsabila pentru afisarea optiunilor utilizatorului
*/
void interface()
{ system("cls");
  printf("Alegeti optiunea pe care o doriti. Optiunile sunt urmatoarele:\n");
  printf("1.Adaugare de tranzactii.\n");
  printf("2.Modificare tranzactie existenta.\n");
  printf("3.Stergere tranzactie existenta.\n");
  printf("6.Afisarea tranzactiilor din aplicatie.\n");
  printf("7.Inchidere aplicatie.\n");
  printf(">>>");

}



/*
Functia ce va rula interfata de utilizator
*/


void run_ui()
{   lista* lista_tranzactii = creaza_lista();
    
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
                    afisare_tranzactii(lista_tranzactii);
                    getchar();

                    break;
                    case 7:
                    program_running = 0;
                    distruge(lista_tranzactii);
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
    {
        

    enum tip tip;
    int ok = 0;
    char tipul[50];
    strcpy(tipul, true_params[3]);
    if(strstr("intrare", tipul)!=NULL)
      {tip = intrare; ok =1;}
    if(strstr("iesire", tipul)!=NULL)
      {tip = iesire; ok=1;}


    for(int i =0; i<3; i++)
    {
        if(!is_number(true_params[i]))
        ok = 0;
    }

  
 if(ok)
    {
    char* descriere=(char*)malloc(sizeof(char)*50);
    strcpy(descriere, true_params[4]);
    int id = atoi(true_params[0]);
    int ziua = atoi(true_params[1]);
    int suma = atoi(true_params[2]);
        adaugare_service(id,suma,ziua,tip,descriere,l);
           // free(descriere);
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