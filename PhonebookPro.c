#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<conio.h>
#define max_size 200

typedef struct{
char firstname[100];
char lastname[50];
char mobilenumber[40];
char telephone[40];
}pb;

int current_size=0;
pb contacts[max_size];

void strtolow(char arr[])
{
    int n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        arr[i]=tolower(arr[i]);
    }
}

void addentry()
{
   system("cls");
   if(current_size==max_size)
   {
       printf("Phonebook memory is full. Please delete some contacts before adding new contact.\n");
       return;
   }
   printf("You are now saving a new contact.\n\n");
   pb x;
   printf("Please enter first name: ");
   gets(x.firstname);
   printf("Please enter last name: ");
   gets(x.lastname);
   printf("Please enter mobile number: ");
   gets(x.mobilenumber);
   printf("Please enter telephone number (press 'Enter' if you don't want to add): ");
   gets(x.telephone);
   contacts[current_size]=x;
   current_size++;
   printf("\nYour contact has been saved. Press 'Enter' to return to main menu.\n");
   getchar();
   system("cls");
}

void display(int index)
{
 pb c=contacts[index];
 printf("First name of the contact: %s\n",c.firstname);
 printf("Last name of the contact: %s\n",c.lastname);
 printf("Mobile number: %s\n",c.mobilenumber);
 if(strlen(c.telephone)!=0)
 {
     printf("Telephone number: %s\n",c.telephone);
 }
}
void search(char src[],int type)
{
    int found=0;
    strtolow(src);
    char temp[100];
    if(type==3)
    {
        for(int i=0;i<current_size;i++)
        {
            strcpy(temp,contacts[i].firstname);
            strtolow(temp);
            if(strcmp(src,temp)==0)
            {
                display(i);
                printf("\n");
                found=1;
            }
        }
    }
    else if(type==4)
    {
        for(int i=0;i<current_size;i++)
        {
            strcpy(temp,contacts[i].lastname);
            strtolow(temp);
            if(strcmp(src,temp)==0)
            {
                display(i);
                printf("\n");
                found=1;
            }
        }
    }
    else if(type==5)
    {
        for(int i=0;i<current_size;i++)
        {
            if(strcmp(src,contacts[i].mobilenumber)==0)
            {
                display(i);
                printf("\n");
                found=1;
            }
        }
    }
    else if(type==6)
    {
        for(int i=0;i<current_size;i++)
        {
            if(strcmp(src,contacts[i].telephone)==0)
            {
                display(i);
                printf("\n");
                found=1;
            }
        }
    }
    if(found==0)
    {
        printf("Contact not found in phone book.\n");
    }
}
int main()
{
    system("color 4f");
    while(1)
    {
    int choice;
    char selection[10];
    char content[150];
    printf("**Phone book application main menu**\n\n");
    printf("Your options:\n");
    printf("1. Add new contact\n");
    printf("2. Show all contacts\n");
    printf("3. Search for a contact by first name\n");
    printf("4. Search for a contact by last name\n");
    printf("5. Search for a contact by mobile number\n");
    printf("6. Search for a contact by telephone number\n");
    printf("7. Exit application\n\n");
    printf("Please select an option: ");
    gets(selection);
    choice=atoi(selection);
    if(choice==7)
    {
        system("cls");
        printf("Thank You For Using The Program.....\nHelping you For All Time. Always.....");
        sleep(2);
        system("cls");
        return 0;

    }
    switch(choice)
    {
        case 1:
        addentry();
        break;
        case 2:
        system("cls");
        if(current_size==0)
        {
            printf("You haven't saved any contact yet. Please save a contact first.\n\n");
            printf("Press 'Enter' to return to main menu.\n");
            getchar();
            system("cls");
        }
        else{
        printf("You are now seeing all contacts.\n\n");
        for(int i=0;i<current_size;i++)
        {
            display(i);
            printf("\n");
        }
        printf("Press 'Enter' to return to main menu.\n");
        getchar();
        system("cls");
        }
        break;
        case 3:
        system("cls");
        if(current_size==0)
        {
            printf("Unable to search for contact(s) as you haven't saved any contacts yet. Please save a contact first.\n\n");
            printf("Press 'Enter' to return to main menu.\n");
            getchar();
            system("cls");
        }
        else
        {
        printf("You are now searching for a contact by first name.\n\n");
        printf("Please enter first name to search: ");
        gets(content);
        system("cls");
        printf("Showing your search result(s):\n\n");
        search(content,3);
        printf("\nPress 'Enter' to return to main menu.\n");
        getchar();
        system("cls");
        }
        break;
        case 4:
        system("cls");
        if(current_size==0)
        {
            printf("Unable to search for contact(s) as you haven't saved any contacts yet. Please save a contact first.\n\n");
            printf("Press 'Enter' to return to main menu.\n");
            getchar();
            system("cls");
        }
        else
        {
        printf("You are now searching for a contact by last name.\n\n");
        printf("Please enter last name to search: ");
        gets(content);
        system("cls");
        printf("Showing your search result(s):\n\n");
        search(content,4);
        printf("\nPress 'Enter' to return to main menu.\n");
        getchar();
        system("cls");
        }
        break;
        case 5:
        system("cls");
        if(current_size==0)
        {
            printf("Unable to search for contact(s) as you haven't saved any contacts yet. Please save a contact first.\n\n");
            printf("Press 'Enter' to return to main menu.\n");
            getchar();
            system("cls");
        }
        else
        {
        printf("You are now searching for a contact by mobile number.\n\n");
        printf("Please enter mobile number to search: ");
        gets(content);
        system("cls");
        printf("Showing your search result(s):\n\n");
        search(content,5);
        printf("\nPress 'Enter' key to return to main menu.\n");
        getchar();
        system("cls");
        }
        break;
        case 6:
        system("cls");
        if(current_size==0)
        {
            printf("Unable to search for contact(s) as you haven't saved any contacts yet. Please save a contact first.\n\n");
            printf("Press 'Enter' to return to main menu.\n");
            getchar();
            system("cls");
        }
        else
        {
        printf("You are now searching for a contact by telephone number.\n\n");
        printf("Please enter telephone to search: ");
        gets(content);
        system("cls");
        printf("Showing your search result(s):\n\n");
        search(content,6);
        printf("\nPress 'Enter' to return to main menu.\n");
        getchar();
        system("cls");
        }
        break;
        default:
        system("cls");
        printf("Invalid input. Please read the menu and try again.\n\n");
        printf("Press 'Enter' to return to main menu.\n");
        getchar();
        system("cls");
        break;
    }

    }

    return 0;
}