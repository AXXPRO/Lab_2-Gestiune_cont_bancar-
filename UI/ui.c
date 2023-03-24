
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Service/service.h"
#include "ui.h"
//#include <stdlib.h>


/*
Functia ia un sir de caractere si returneaza daca este sau nu numar
PreconditiiL s - sir de caractere cu \0 la sfarsit
Postconditii: 1 daca poate fi numar, 0 altfel
*/
int is_number(char* s)
{
    if (strlen(s)==0)
        return 0;
    int i=0;
    if(s[0]=='-')
        i=1;



    for(; i<(int)strlen(s); i++)
    {
        if(s[i] - '0' < 0 || s[i]- '0' > 9)
            if(!(i == (int) strlen(s)-1 && s[i]=='\n'))
                return 0;
    }

    return 1;
}

void interface()
{ //system("cls");
  printf("Alegeti optiunea pe care o doriti. Optiunile sunt urmatoarele:\n");
  printf("1.Adaugare de tranzactii.\n");
  printf("2.Modificare tranzactie existenta.\n");
  printf("3.Stergere tranzactie existenta.\n");
  printf("4.Vizualizare tranzactii dupa un criteriu.\n");
  printf("5.Vizualizare tranzactii ordonat dupa suma\n");
  printf("6.Afisarea tranzactiilor din aplicatie.\n");
  printf("7.Inchidere aplicatie.\n");
  printf(">>>");

}



char* strtol_pointer;

void run_ui()
{   lista* lista_tranzactii = creaza_lista(tranzactii);


    char choice[20];
    int program_running = 1;
    int number_choice;
    while(program_running)
    {
        interface();
        //scanf("%s", choice);
        strtol_pointer= fgets(choice,20, stdin);
       // printf("%d", (int)strlen(choice));
       // getchar();
        if(strlen(choice)==2)
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
                    criteriu(lista_tranzactii);
                    break;
                    case 5:
                        ordonat(lista_tranzactii);
                    break;
                    case 6:
                   afisare(lista_tranzactii);

                    break;
                    case 7:
                    program_running = 0;
                        distruge_lista_tranzactii(lista_tranzactii);
                    break;
                default:
                {
                printf("Varianta inexistenta!\n");
                    strtol_pointer=   fgets(choice,20, stdin);
                }
                    break;
                }


            
          
        }
        else{printf("Varianta inexistenta!\n");
            strtol_pointer=  fgets(choice,20, stdin);}



    }
    

}

//This pointer is requiered to call the strtol function

void ordonat(lista* l)
{
    char alegere[50];
    printf("Cum doriti sa sortam lista?\n1. Crescator\n2. Descrescator\n");
    strtol_pointer= fgets(alegere,50, stdin);


    if(is_number(alegere))
    {
        int numar = (int)strtol(alegere,&strtol_pointer,10);
        if(numar <1 || numar >2)
        {
            printf("Varianta inexistenta!");
            getchar();
        }
        else

        {
            lista* lista_ordonata;
            if(numar == 1)
            lista_ordonata = ordonat_service(l,1);
            else
                lista_ordonata = ordonat_service(l,-1);


            afisare(lista_ordonata);
            distruge_lista_tranzactii(lista_ordonata);


        }

    }
    else

    {
        printf("Varianta inexistenta!");
        getchar();
    }
}
void criteriu_suma(lista* l)
{
    char alegere[50];
    char suma[50];
    printf("Cum doriti sa filtram dupa suma?\n1. Mai mari decat o suma data\n2. Mai mici decat o suma data\n");
    strtol_pointer= fgets(alegere,50, stdin);

    if(is_number(alegere))
    {
        int numar = (int)strtol(alegere,&strtol_pointer,10);
        if(numar <1 || numar >2)
        {
            printf("Varianta inexistenta!");
            getchar();
        }
        else

        {
            printf("Dati suma cu care comparam\n");
            strtol_pointer=  fgets(suma,50, stdin);
            if(is_number(suma))
            {
                int suma_numar = (int)strtol(suma,&strtol_pointer,10);
                lista* l_temporara;
                if(numar == 1)
                {
                     l_temporara= criteriu_suma_service(l,suma_numar,1);
                }
                else
                {
                   l_temporara= criteriu_suma_service(l,suma_numar,-1);
                }
                afisare(l_temporara);
                distruge_lista_tranzactii(l_temporara);
            }
            else{
                printf("Suma invalida!");
                getchar();
            }
        }

    }
    else

    {
        printf("Varianta inexistenta!");
        getchar();
    }

}
void criteriu_tip(lista* l)
{char alegere[50];
    printf("Tranzactiile cu ce tip doriti sa le vedeti?\n1. Intrare\n2. Iesire");
    strtol_pointer= fgets(alegere,50, stdin);
    if(is_number(alegere))
    {
        int numar = (int)strtol(alegere,&strtol_pointer,10);
        if(numar <1 || numar >2)
        {
            printf("Varianta inexistenta!");
            getchar();
        }
        else

        {
            enum tip tipul;
            if(numar == 1)
                tipul = intrare;
            else
             tipul = iesire;
            lista* l_temporara;
            l_temporara = criteriu_tip_service(l, tipul);
            afisare(l_temporara);

            distruge_lista_tranzactii(l_temporara);

        }

    }
    else

    {
        printf("Varianta inexistenta!");
        getchar();
    }


}
void criteriu(lista* l)
{
    char alegere[50];
  printf("Ce criteriu de sortare doriti?\n 1. Dupa tip\n 2. Dupa suma\n");
    strtol_pointer= fgets(alegere,50, stdin);
  if(is_number(alegere))
  {
int numar = (int)strtol(alegere,&strtol_pointer,10);

switch(numar)

{
    case 1:
         criteriu_tip(l);
        break;
    case 2:
        criteriu_suma(l);
        break;
    default:{
        printf("Varianta inexistenta!");
        getchar();
    }

}

  }

  else

  {
      printf("Varianta inexistenta!");
      getchar();
  }


}

void afisare(lista* l)
{
    char *de_afisat;
    de_afisat= afisare_service(l);
    printf("%s", de_afisat);
    getchar();
    free (de_afisat);

}

void adaugare(lista* l)
{   
    char params[100];
    char true_params[5][50];
    char* cuvant;
    //printf
    printf("Dati id-ul, ziua, suma, tipul, si descrierea tranzactiei, separate prin ; :\n");
     //getchar();
    strtol_pointer= fgets(params,100, stdin);
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


    for(i =0; i<3; i++)
    {
        if(!is_number(true_params[i]))
        ok = 0;
    }

  
 if(ok)
    {
    char* descriere=(char*)malloc(sizeof(char)*50);
    strcpy(descriere, true_params[4]);
    int id = (int)strtol(true_params[0],&strtol_pointer,10);
    int ziua = (int)strtol(true_params[1],&strtol_pointer,10);
    int suma =(int)strtol(true_params[2],&strtol_pointer,10);

      if( adaugare_service(id,suma,ziua,tip,descriere,l)==0)
      {
          printf("Paramtetrii invalizi!");
          getchar();
      }
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
{char params[5];
int ok = 1;
    printf("Dati id-ul tranzactiei pe care dorim sa o stergem: \n");
    strtol_pointer= fgets(params,5, stdin);

     if(!is_number(params))
        ok = 0;
    
    if(!ok)
    {
        printf("Id invalid!\n");
        getchar();

    }
    else
    {       int id = (int)strtol(params,&strtol_pointer,10);
            if(!stergere_service(id, l))
            {
                printf("Stergere neefectuata!");
                 getchar();  
            }

    }
    
}
/*
Functia din ui responsabila pentru a modifica o tranzactie existenta
Anunta utilziatorul daca id-ul nu exista
Preconditii: l este o lista
Postconditii: se va schimba tranzactia cu un id dat cu alta
*/
void modificare(lista* l)
{
char params[100];
    char true_params[5][50];
    char* cuvant;
    //printf
    printf("Dati id-ul tranzactiei pe care doriti sa o modificam, ziua, suma, tipul, si descrierea tranzactiei, separate prin ; :\n");
     //getchar();
    strtol_pointer=  fgets(params,100, stdin);
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


    for( i =0; i<3; i++)
    {
        if(!is_number(true_params[i]))
        ok = 0;
    }

  
 if(ok)
    {
    char* descriere=(char*)malloc(sizeof(char)*50);
    strcpy(descriere, true_params[4]);
    int id = (int)strtol(true_params[0],&strtol_pointer,10);
    int ziua = (int)strtol(true_params[1],&strtol_pointer,10);
    int suma = (int)strtol(true_params[2],&strtol_pointer,10);
    ///MODIFICARE SERVICE

        
        if( !modificare_service(id,suma,ziua,tip,descriere,l))
       {
    free(descriere);
    printf("Modificare neefectuata!");
    getchar();
       }
           // free(descriere);
    }
 else
    {
printf("Paramtetrii invalizi!");
getchar();
    }
    }

}