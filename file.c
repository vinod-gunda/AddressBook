#include <stdio.h>
#include<stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contacts.csv","w");
    fprintf(fptr,"%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr1=fopen("contacts.csv","r");
    // int num;
    // fscanf(fptr1,"%d\n",&num);
    // addressBook->contactCount=atoi(&num);
    fscanf(fptr1,"%d\n",&addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr1,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr1);
}
