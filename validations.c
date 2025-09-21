#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#include <stdio_ext.h>
extern int arr[MAX_CONTACTS];
extern int count;
// Function to validate the name.
void is_valid_name(AddressBook *addressBook, char *name)
{
    int i,flag;
    do
    {
        printf("Enter the name:");
        // __fpurge(stdin)--> it will remove all the content present in the stdin Buffer.
        __fpurge(stdin);
        scanf("%[^\n]",name);
        flag=0;
        for(i=0;name[i];i++)
        {
            // isalpha returns true for alphabet and returns false if it not alphabet.
            // we will pass character as a parameter.
            // it will check for alphabets.
            if(!(isalpha(name[i]) || name[i]==' '))
            {
                flag=1; 
                printf("---> Name should contain only Alphabets and Spaces <---\n");
                break;
            }
        }
    } while (flag!=0);
}

// Function to validate the mobile number.
void is_valid_number(AddressBook *addressBook, char *num)
{
    int i,flag;
    do
    {
        printf("Enter the Number:");
        scanf("%s",num);
        flag=0;
        // Strlen will return the length of the string.
        // we should pass the base address of the string as a parameter.
        int len=strlen(num);
        if(len!=10)
        {
            printf("---> Number of digits should be 10 <---\n");
            flag=1;
        }
        if(flag==0)
        {
            for(i=0;num[i];i++)
            {
                // isdigit will return true for digits....and return false for non digits.
                // we will pass a character as a parameter.
                // It will check whether the given character is digit or not.
                if(!isdigit(num[i]))
                {
                    printf("---> Numbers must be digits <---\n");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            for(i=0;i<addressBook->contactCount;i++)
            {
                // Strcmp will return 0 if both string are equal(or Same)
                // it will retrun the difference between the ASCII values of characters where the it fails to match.
                // we will pass base address of the strings or direct strings.
                if(!strcmp(num,addressBook->contacts[i].phone))
                {
                    printf("---> Please enter unique number <---\n");
                    flag=1;
                    break;
                }
            }
        }
    } while (flag!=0);
}

// Function to validate the email ID
void is_valid_mail(AddressBook *addressBook, char *mail)
{
    int i,flag;
    do
    {
        printf("Enter the mail:");
        scanf("%s",mail);
        flag=0;
        // Strchr will return the address of the character if the character is present in the sring
        // If the character is not present it will return the NULL.
        // It is used to check the wether the character is present in the string or not.
        char* ptr1 = strchr(mail,'@');
        if(!ptr1)
        {
            printf("---> @ is mandatory in the mail <---\n");
            flag=1;
        }
        // Strstr will return address of substring if the substring is present.
        // It will return NULL if not present.
        // it will check for the subString in the main string.
        char *ptr2 = strstr(mail,".com");
        if(flag==0)
        {
           if(!ptr2)
            {
                printf("---> Mail should contain .com <---\n");
                flag=1;
            } 
            if(flag==0 && *(ptr2+4)!='\0')
            {
                printf("---> .com should be at the end of the mail <---\n");
                flag=1;
            }
        }
        if(flag==0)
        {
            // isalnum will return true for alphabets and digits......it will return for special characters.
            // we will pass the character as a parameter.
            // It will check for digits and alphabets.
            if(!isalnum(*(--ptr1)))
            {
                printf("---> There should a character before @ <---\n");
                flag=1;
            }
        }
        if(flag==0)
        {
            // isalnum will return true for alphabets and digits......it will return for special characters.
            // we will pass the character as a parameter.
            // It will check for digits and alphabets.
            if(!isalnum(*(--ptr2)) )
            {
                printf("---> There should be a character between @ and .com <---\n");
                flag=1;
            }
        }
        if(flag==0)
        {
            for(i=0;i<addressBook->contactCount;i++)
            {
                // Strcasecmp will return 0 if both string are equal with respect to alphabet (whether it is lower case or upper case.)
                // it will retrun the difference between the ASCII values of characters where the it fails to match.
                // we will pass base address of the strings or direct strings.
                if(!strcasecmp(mail,addressBook->contacts[i].email))
                {
                    printf("---> Please enter unique mail <---\n");
                    flag=1;
                    break;
                }
            }
        }
    } while (flag!=0);
}

void search_by_name(AddressBook *addressBook)
{
    int i,j=1;
    char name[50];
    count=0;
    printf("enter the name:");
    __fpurge(stdin);
    scanf("%[^\n]",name);
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(!strcasecmp(addressBook->contacts[i].name,name))
        {
            printf("%-3d ",j++);
            printf("%-20s ",addressBook->contacts[i].name);
            printf("%-15s ",addressBook->contacts[i].phone);
            printf("%-20s\n",addressBook->contacts[i].email);
            arr[count++]=i;
        }
    }
    if(count==0)
    printf("---> Invalid Name❎❎ <---\n---> Entered Name not Found <---\n");
}

void search_by_number(AddressBook *addressBook)
{
    int i,j=1;
    char mobile[20];
    printf("enter the Mobile Number:");
    scanf("%s",mobile);
    count=0;
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(!strcmp(addressBook->contacts[i].phone,mobile))
        {
            printf("%-3d ",j++);
            printf("%-20s ",addressBook->contacts[i].name);
            printf("%-15s ",addressBook->contacts[i].phone);
            printf("%-20s\n",addressBook->contacts[i].email);
            arr[count++]=i;
        }
    }
    if(count==0)
    printf("---> Invalid mobile number❎❎ <---\n---> Entered Mobile number not Found <---\n");
}

void search_by_mail(AddressBook *addressBook)
{
    int i,j=1;
    char mail[50];
    printf("enter the Email:");
    scanf("%s",mail);
    count=0;
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(!strcasecmp(addressBook->contacts[i].email,mail))
        {
            printf("%-3d",j++);
            printf("%-20s ",addressBook->contacts[i].name);
            printf("%-15s ",addressBook->contacts[i].phone);
            printf("%-20s\n",addressBook->contacts[i].email);
            arr[count++]=i;
        }
    }
    if(count==0)
    printf("---> Invalid Email❎❎ <---\n---> Entered Email not Found <---\n");
}

