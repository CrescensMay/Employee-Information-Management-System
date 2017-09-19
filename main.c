#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void add_employee();
void search_employee();
void display_employee_list();
void modify_employee();
void delete_employee();

struct employee
{
    char last_name[20];
    char first_name[20];
    char id[20];
    char phone_number[20];
    char designation[20];
   // char password[30];
    int year_of_service;
    float salary;
    int age;
    float salaryperyear;

};

struct employee emp;
int c,i=0;

void add_employee()
{
    FILE *addemployee;

    addemployee=fopen("list_employee.txt","a");
    printf("please enter the employee information.\n\n");
    c=1;
    while(c)
    {
        printf("first name:");
        scanf("%s",emp.first_name);

        printf("\nlast name:");
        scanf("%s",emp.last_name);

        printf("\nid number:");
        scanf("%s",emp.id);

        printf("\ndesignation:");
        scanf("%s",emp.designation);

        printf("\nage:");
        scanf("%d",&emp.age);

        printf("\nphone number:");
        scanf("%s",emp.phone_number);

        printf("\nyear of service:");
        scanf("%d",&emp.year_of_service);

        printf("\nsalary:");
        scanf("%f",&emp.salary);

        fwrite(&emp,sizeof(emp),1,addemployee);

        printf("\nWould you like to continue?(press 1 for yes or 0 for no).\n");
        scanf("%d",&c);
    }
    fclose(addemployee);

}

void search_employee()
{
    FILE *addemployee;
    int check_employee;
    char check_id[20];
    addemployee=fopen("list_employee.txt","r");

    printf("\nplease enter the employee id:");
   // fflush(stdin);
    scanf("%s",check_id);

   // c=1;
//while(c)
    while(fread(&emp,sizeof(emp),1,addemployee)==1)
    {
        check_employee=strcmp(check_id,emp.id);

        if(check_employee==0)
        {
            printf("\n\tThe record is available.\n");

            printf("\n  %c First Name:%s\n",4,emp.first_name);
            printf("\n  %c Last Name:%s\n",4,emp.last_name);
            printf("\n  %c Id:%s\n",4,emp.id);
            printf("\n  %c Designation:%s\n",4,emp.designation);
            printf("\n  %c Age:%d\n",4,emp.age);
            printf("\n  %c Phone Number:%s\n",4,emp.phone_number);
            printf("\n  %c Year of Service:%d\n",4,emp.year_of_service);
            printf("\n  %c Salary(RMB):%.2f\n",4,emp.salary);
           // printf("\n\n\twould you like to continue?(press 1 for yes or 0 for no).\n");
           // scanf("%d",&c);
           // return(search_employee());
             printf("\n\t%c Press any key to back to the menu.\n",4);
             getch();
             break;
        }
         //break;
    }
    //break;
       if (check_employee!=0)
        {
            printf("\n\tSorry the employee Id invalid.");
            printf("\n\t\tRecord not found.\n");
            printf("\n\t%c Press any key to back to the menu.\n",4);
            getch();
            //break;
        }



 fclose(addemployee);
}


void display_employee_list()
{
    FILE *addemployee;
    addemployee=fopen("list_employee.txt","r");

    int totalemployee=0;
    int i=0;
    float salaryperyear=0;

    printf("\n\n\t**********************ALL EMPLOYEES INFORMATION*********************\n\n");

    while((fread(&emp,sizeof(emp),1,addemployee)==1))
    {
          printf("\n\tEMPLOYEE[%d]\n",i+1);
         printf("\n%c First Name:%s\n",4,emp.first_name);
            printf("\n  %c Last Name:%s\n",4,emp.last_name);
            printf("\n  %c Id:%s\n",4,emp.id);
            printf("\n  %c Designation:%s\n",4,emp.designation);
            printf("\n  %c Age:%d years\n",4,emp.age);
            printf("\n  %c Phone Number:%s\n",4,emp.phone_number);
            printf("\n  %c Year of Service:%d year(s)\n",4,emp.year_of_service);
            printf("\n  %c Salary:%.2f RMB\n",4,emp.salary);

            emp.salaryperyear=emp.salary*12;

            printf("\n%c Salary per year:%.2f RMB\n\n",4,emp.salaryperyear);
            i++;
    }
    totalemployee+=i;

    printf("\n\nTOTAL EMPLOYEES: %d\n\n",totalemployee);
    printf("\n\t%c Press any key to back to the menu.\n",4);
        getch();

    fclose(addemployee);
}

void modify_employee()
{
    FILE *addemployee;
    addemployee=fopen("list_employee.txt","r+");

    char check_id[20];
    int check_employee;

    printf("\n\tPlease enter the employee id:");
    fflush(stdin);
    scanf("%s",check_id);
  // c=1;

    while((fread(&emp,sizeof(emp),1,addemployee)==1))
    {
        check_employee=strcmp(check_id,emp.id);
        if(check_employee==0)
        {
            printf("\n\tRecord found.\n");

            printf("\n  %c First Name:%s\n",4,emp.first_name);
            printf("\n  %c Last Name:%s\n",4,emp.last_name);
            printf("\n  %c Id:%s\n",4,emp.id);
            printf("\n  %c Designation:%s\n",4,emp.designation);
            printf("\n  %c Age:%d years\n",4,emp.age);
            printf("\n  %c Phone Number:%s\n",4,emp.phone_number);
            printf("\n  %c Year of Service:%d year(s)\n",4,emp.year_of_service);
            printf("\n  %c Salary:%f RMB\n\n",4,emp.salary);

            printf("***************enter the following information*****************\n\n");

               printf("first name:");
            scanf("%s",emp.first_name);

            printf("\nlast name:");
            scanf("%s",emp.last_name);

            printf("\nid number:");
            scanf("%s",emp.id);

            printf("\ndesignation:");
            scanf("%s",emp.designation);

            printf("\nage:");
            scanf("%d",&emp.age);

            printf("\nphone number:");
            scanf("%s",emp.phone_number);

            printf("\nyear of service:");
            scanf("%d",&emp.year_of_service);

            printf("\nsalary:");
            scanf("%f",&emp.salary);

        fseek(addemployee,-sizeof(emp),SEEK_CUR);
        fwrite(&emp,sizeof(emp),1,addemployee);

       printf("\n\t%c Press any key to back to the menu.\n",4);
        getch();

        }
        break;

    }

    if(check_employee!=0)
    {
        printf("\n\tSorry invalid Id record not found.\n");
        printf("\n\t%c Press any key to back to the menu.\n",4);
        getch();
    }

    fclose(addemployee);
}

void delete_employee()
{
    FILE *addemployee,*deleteemployee;
    char check_id[20];
    int check_employee;

    addemployee=fopen("list_employee.txt","r");
    deleteemployee=fopen("temp_list.txt","w");

    printf("\nPlease enter the employee id:");
    scanf("%s",check_id);

    while((fread(&emp,sizeof(emp),1,addemployee)==1))
    {
        check_employee=strcmp(check_id,emp.id);

        if(check_employee!=0)
        {



          /*  printf("\n%c First Name:%s\n",4,emp.first_name);
            printf("\n%c Last Name:%s\n",4,emp.last_name);
            printf("\n%c Id:%s\n",4,emp.id);
            printf("\n%c Designation:%s\n",4,emp.designation);
            printf("\n%c Age:%d years\n",4,emp.age);
            printf("\n%c Phone Number:%s\n",4,emp.phone_number);
            printf("\n%c Year of Service:%d year(s)\n",4,emp.year_of_service);
            printf("\n%c Salary:%f RMB\n\n",4,emp.salary);*/

            fwrite(&emp,sizeof(emp),1,deleteemployee);

        }
        else
        {
              printf("\n\tRecord found.\n");

             printf("\n %c First Name:%s\n",4,emp.first_name);
            printf("\n  %c Last Name:%s\n",4,emp.last_name);
            printf("\n  %c Id:%s\n",4,emp.id);
            printf("\n  %c Designation:%s\n",4,emp.designation);
            printf("\n  %c Age:%d years\n",4,emp.age);
            printf("\n  %c Phone Number:%s\n",4,emp.phone_number);
            printf("\n  %c Year of Service:%d year(s)\n",4,emp.year_of_service);
            printf("\n  %c Salary:%f RMB\n\n",4,emp.salary);
        }

    }

    fclose(addemployee);
    fclose(deleteemployee);

    remove("list_employee.txt");
    rename("temp_list.txt","list_employee.txt");

    addemployee=fopen("list_employee.txt","r");

    printf("\n\tRecord successfully deleted.\n\n");
    printf("\n\tPress any key to back to main menu.\n");
    getch();

}


int main()
{
   int choice;
   //int x=8;
   while(choice!=6)

{
     printf("\n\t\t\t WELCOME TO THE MAIN MENU \n\n");
      printf("\t\t\t 1-Add New employee record.\n\n");
       printf("\t\t\t 2-Show employee record.\n\n");
       printf("\t\t\t 3-Search employee record.\n\n");
       printf("\t\t\t 4-Modify employee record.\n\n");
       printf("\t\t\t 5-Delete employee record.\n\n");
      printf("\t\t\t 6-exit.\n");
       printf("\n\t****************************************************\n\n");
       printf("\t\tPlease enter your choice--->");
       scanf("%d",&choice);

       switch(choice)
       {
          case 1:
          add_employee();
          break;
          case 2:
          display_employee_list();
          break;
          case 3:
          search_employee();
          break;
          case 4:
          modify_employee();
          break;
          case 5:
          delete_employee();
          break;
          case 6:
          printf("\n\n\t\t*****END OF PROGRAM*****\n\t\t\t BYE BYE\n\n");
          break;
          default:
          printf("\n\t************* INVALID CHOICE,TRY AGAIN *************** \n\t\t PRESS ANY KEY TO BACK TO THE MENU.\n\n");
          getch();

    }
}

}
