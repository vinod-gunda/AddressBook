#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

void is_valid_name(AddressBook *addressBook, char *name);
void is_valid_number(AddressBook *addressBook, char *num);
void is_valid_mail(AddressBook *addressbook, char *mail);
void search_by_name(AddressBook *addressBook);
void search_by_number(AddressBook *addressBook);
void search_by_mail(AddressBook *addressBook);
void sort_criteria(AddressBook *addressBook);


#endif

