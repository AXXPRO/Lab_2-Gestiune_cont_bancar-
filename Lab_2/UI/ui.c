#pragma once
#include <string.h>
/*
Functia responsabila pentru afisarea optiunilor utilizatorului
*/
void interface()
{ system("cls");
  printf("Alegeti optiunea pe care o doriti. Optiunile sunt urmatoarele:\n");
  printf("1.Adaugare de tranzactii.\n");
  printf("2.Modificare tranzactie existenta.\n");
  printf("3.Stergere  tranzactie existenta.\n");
  printf("6.Inchidere aplicatie.\n");
  printf(">>>");

}



/*
Functia ce va rula interfata de utilizator
*/
void run_ui()
{
    char choices[]="123456";
    char choice[20];
    int program_running = 1;
    int number_choice;
    while(program_running)
    {
        interface();
        scanf("%s", choice);
        if(strlen(choice)==1)
        {
           
            //Run program
                number_choice = choice[0]-'0';
                switch (number_choice)
                {
                    case 1:
                    /* code */
                    break;
                    case 2:
                    /* code */
                    break;
                    case 3:
                    /* code */
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
                scanf("%s", choice);
                }
                    break;
                }


            
          
        }
        else{printf("Varianta inexistenta!\n");
                scanf("%s", choice);}



    }
    

}

