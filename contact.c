#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#include <stdio_ext.h>
int arr[MAX_CONTACTS];
int count;
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("%-20s %-15s %-20s\n","NAME","MOBILE NUMBER","MAIL ID");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-20s ",addressBook->contacts[i].name);
        printf("%-15s ",addressBook->contacts[i].phone);
        printf("%-20s\n",addressBook->contacts[i].email);
    }
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void createContact(AddressBook *addressBook)
{
    char name[20];
    is_valid_name(addressBook, name);
    // Strcpy will copy the whole content to destination string  from the source string.
    // First parameter is the destinaton string base Address and second patameter is  source string.
    // It will return the base address of the destination string.
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    char num[20];
    is_valid_number(addressBook, num);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,num);
    char mail[50];
    is_valid_mail(addressBook, mail);
    strcpy(addressBook->contacts[addressBook->contactCount].email,mail);
    printf("---> Contact Added Sucessfully✅✅ <---");
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    printf("1.Search by Name\n");
    printf("2.Search by Mobile Number\n");
    printf("3.Search by Mail\n");
    int num=0;
    __fpurge(stdin);
    printf("Enter the Choice:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
            search_by_name(addressBook);
            break;
        case 2:
            search_by_number(addressBook);
            break;
        case 3:
            search_by_mail(addressBook);
            break;
        default:
            printf("---> INVALID CHOICE <---\n");
            count=0;
    } 

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    searchContact(addressBook);
    if(count==0)
    return;
    int S_No=1;
    if(count!=1)
    {
        printf("There are more matches with single name.\nPlease enter the Serial Number that you want to edit:");
        scanf("%d",&S_No);
    }
    printf("1.Edit the Name.\n");
    printf("2.Edit the Mobile Number.\n");
    printf("3.Edit the Email.\n");
    int num;
    printf("Enter the choice:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
            char name[50];
            is_valid_name(addressBook, name);
            if(count!=1)
            strcpy(addressBook->contacts[arr[S_No-1]].name,name);
            else
            strcpy(addressBook->contacts[arr[0]].name,name);
            break;
        case 2:
            char mobile[20];
            is_valid_number(addressBook, mobile);
            if(count!=1)
            strcpy(addressBook->contacts[arr[S_No-1]].phone,mobile);
            else
            strcpy(addressBook->contacts[arr[0]].phone,mobile);
            break;
        case 3:
            char mail[50];
            is_valid_mail(addressBook, mail);
            if(count!=1)
            strcpy(addressBook->contacts[arr[S_No-1]].email,mail);
            else
            strcpy(addressBook->contacts[arr[0]].email,mail);
            break;
        default:
            printf("---> INVALID CHOICE <---\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    if (addressBook->contactCount==0)
    {
        printf("---> No contacts are created till now <---\n");
        return;
    }
    searchContact(addressBook);
    if(count==0)
    return;
    int S_No=1;
    if(count!=1)
    {
        printf("There are more matches with single name.\nPlease enter the Serial Number that you want to edit:");
        scanf("%d",&S_No);
    }
    for(int i=arr[S_No-1];i<addressBook->contactCount-1;i++)
    {
        strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
        strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
        strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
    }
    addressBook->contactCount--;
    printf("---> Contact Deleted Sucessfully✅✅ <---\n");
}
