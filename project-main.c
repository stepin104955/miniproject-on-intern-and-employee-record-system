#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

COORD coord = {0,0};

void gotoxy(int x, int y)
{
coord.X=x;
coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
    FILE *fp1,*ft1,*fp2,*ft2;
    char another,another1,choice,choice1;

    struct emp{
        char name[50];
        int age;
        int ID;
        float salary;
        char mailID[50];
        char organization[50];
        };struct emp e;

    struct intern{
        char name[50];
        int age;
        int ID;
        float stipend;
        char mailID[50];
        char organization[50];
        };struct intern i;

    int empID,interID;

    long int recsize1;
    long int recsize2;

    fp1=fopen("EMP1.DAT","rb+");
    if(fp1==NULL)
    {
    fp1 = fopen("EMP1.DAT","wb+");
        if(fp1 == NULL)
            {
                printf("the file cannot be opened");
                exit(1);
            }
    }

    fp2=fopen("EMP2.DAT","rb+");
    if(fp2==NULL)
    {
    fp2 = fopen("EMP2.DAT","wb+");
        if(fp2 == NULL)
            {
                printf("the file cannot be opened");
                exit(1);
            }
    }

    recsize1=sizeof(e);
    recsize2=sizeof(i);

    while(1)
        {
            system("cls");
            gotoxy(30,1);
            printf("1. Employee Data");
            gotoxy(30,3);
            printf("2. Intern Data");
            gotoxy(30,5);
            printf("3. Exit");
            gotoxy(30,7);
            printf("Your Choice: ");
            fflush(stdin);
            choice  = getche();

            switch(choice)
            {
            case '1':
                system("cls");
                fseek(fp1,0,SEEK_END);

                system("cls");
                gotoxy(30,10);
                printf("1. Add Record");
                gotoxy(30,12);
                printf("2. List Records");
                gotoxy(30,14);
                printf("3. Modify Records");
                gotoxy(30,16);
                printf("4. Delete Records");
                gotoxy(30,18);
                printf("5. Exit");
                gotoxy(30,20);
                printf("Your Choice: ");
                fflush(stdin);
                choice1=getche();

                    switch(choice1)
                    {
                    case '1':
                        system("cls");
                    another = 'y';
                        while(another == 'y')
                        {
                        printf("\nEnter name: ");
                        scanf("%[^\n]s",e.name);
                        fflush(stdin);
                        printf("\nEnter age: ");
                        scanf("%d",&e.age);
                        printf("\nEnter ID: ");
                        scanf("%d", &e.ID);
                        printf("\nEnter salary:");
                        scanf("%f",&e.salary);
                        fflush(stdin);
                        printf("\nEnter mail ID:");
                        scanf("%[^\n]s",e.mailID);
                        fflush(stdin);
                        printf("\nEnter organiztaion:");
                        scanf("%[^\n]s",e.organization);

                        fwrite(&e,recsize1,1,fp1);

                        printf("\nAdd another record(y/n) ");
                        fflush(stdin);
                        another = getche();
                        }break;

                        case '2':
                                system("cls");
                                rewind(fp1);
                                while(fread(&e,recsize1,1,fp1)==1)
                                {
                                printf("\n%s |%d |%d |%f| %s| %s",e.name,e.age,e.ID,e.salary,e.mailID,e.organization);
                                }
                                getch();
                                break;

                        case '3':
                        system("cls");
                        another = 'y';
                        while(another == 'y')
                        {
                            printf("Enter the employee ID to modify: ");
                            scanf("%d", &empID);
                            rewind(fp1);
                            while(fread(&e,recsize1,1,fp1)==1)
                                {
                                    if(empID==e.ID)
                                    {
                                                            printf("\nEnter name: ");
                                                            scanf("%[^\n]s",e.name);
                                                            fflush(stdin);
                                                            printf("\nEnter age: ");
                                                            scanf("%d",&e.age);
                                                            printf("\nEnter ID: ");
                                                            scanf("%d", &e.ID);
                                                            printf("\nEnter salary:");
                                                            scanf("%f",&e.salary);
                                                            fflush(stdin);
                                                            printf("\nEnter mail ID:");
                                                            scanf("%[^\n]s",e.mailID);
                                                            fflush(stdin);
                                                            printf("\nEnter organiztaion:");
                                                            scanf("%[^\n]s",e.organization);
                                    fseek(fp1,-recsize1,SEEK_CUR);
                                    fwrite(&e,recsize1,1,fp1);
                                    break;
                                    }
                                }
                                printf("\nModify another record(y/n)");
                                fflush(stdin);
                                another = getche();
                                }
                                break;

                        case '4':
                        system("cls");
                        another = 'y';
                        while(another == 'y')
                        {
                        printf("\nEnter ID of employee to delete: ");
                        scanf("%d",&empID);
                        ft1 = fopen("Temp2.dat","wb+");
                        rewind(fp1);
                                        while(fread(&e,recsize1,1,fp1) == 1)
                                            {
                                                if(e.ID==empID)
                                                {
                                                fwrite(&e,recsize1,1,ft1); /// move all records except the one that is to be deleted to temp file
                                                }
                                            }
                                        fclose(fp1);
                                        fclose(ft1);
                                        remove("EMP1.DAT"); /// remove the orginal file
                                        rename("Temp1.dat","EMP1.DAT"); /// rename the temp file to original file name
                                        fp1 = fopen("EMP1.DAT", "rb+");
                                        printf("Delete another record(y/n)");
                                        fflush(stdin);
                                        another = getche();
                                        }
                                        break;

                        case '5':
                        fclose(fp1);  /// close the file
                        exit(0);
                        }




   case '2':

                system("cls");
                fseek(fp2,0,SEEK_END);

                system("cls");
                gotoxy(30,10);
                printf("1. Add Record");
                gotoxy(30,12);
                printf("2. List Records");
                gotoxy(30,14);
                printf("3. Modify Records");
                gotoxy(30,16);
                printf("4. Delete Records");
                gotoxy(30,18);
                printf("5. Exit");
                gotoxy(30,20);
                printf("Your Choice: ");
                fflush(stdin);
                choice1=getche();

                    switch(choice1)
                    {
                    case '1':
                    another1 = 'y';
                        while(another1 == 'y')
                        {
                        printf("\nEnter name: ");
                        scanf("%[^\n]s",i.name);
                        fflush(stdin);
                        printf("\nEnter age: ");
                        scanf("%d",&i.age);
                        fflush(stdin);
                        printf("\nEnter ID: ");
                        scanf("%d", &i.ID);
                        fflush(stdin);
                        printf("\nEnter salary:");
                        scanf("%f",&i.stipend);
                        fflush(stdin);
                        printf("\nEnter mail ID:");
                        scanf("%[^\n]s",i.mailID);
                        fflush(stdin);
                        printf("\nEnter organiztaion:");
                        scanf("%s[^\n]",i.organization);

                        fwrite(&i,recsize2,1,fp2);

                        printf("\nAdd another record(y/n) ");
                        fflush(stdin);
                        another1 = getche();
                        }break;

                        case '2':
                                system("cls");
                                rewind(fp2);
                                while(fread(&i,recsize2,1,fp2)==1)
                                {
                                printf("\n%s |%d |%d |%f| %s| %s",i.name,i.age,i.ID,i.stipend,i.mailID,i.organization);
                                }
                                getch();
                                break;

                        case '3':
                        system("cls");
                        another = 'y';
                        while(another == 'y')
                        {
                            printf("Enter the employee ID to modify: ");
                            scanf("%d", &interID);
                            rewind(fp2);
                            while(fread(&i,recsize2,1,fp2)==1)
                                {
                                    if((i.ID==interID)==1)
                                    {
                                    printf("\nEnter new name,age,ID,salary,mailID,organization\n ");
                                    scanf("%s %d %d %f %s %s",i.name,&i.age,&i.ID,&i.stipend,i.mailID,i.organization);
                                    fseek(fp2,-recsize2,SEEK_CUR);
                                    fwrite(&i,recsize2,1,fp2);
                                    break;
                                    }
                                }
                                printf("\nModify another record(y/n)");
                                fflush(stdin);
                                another1 = getche();
                                }
                                break;

                        case '4':
                        system("cls");
                        another1 = 'y';
                        while(another1 == 'y')
                        {
                        printf("\nEnter ID of employee to delete: ");
                        scanf("%d",&interID);
                        ft2 = fopen("Temp2.dat","wb");
                        rewind(fp2);
                                        while(fread(&i,recsize2,1,fp2) == 1)
                                            {
                                                if((i.ID==interID)==1)
                                                {
                                                fwrite(&i,recsize2,1,ft2);
                                                }
                                            }
                                        fclose(fp2);
                                        fclose(ft2);
                                        remove("EMP2.DAT");
                                        rename("Temp2.dat","EMP2.DAT");
                                        fp2 = fopen("EMP2.DAT", "rb+");
                                        printf("Delete another record(y/n)");
                                        fflush(stdin);
                                        another1 = getche();
                                        }
                                        break;

                        case '5':
                        fclose(fp2);
                        exit(0);
                        }

                case '3':

                fclose(fp1);
                fclose(fp2);
                exit(0);
        }
}}
