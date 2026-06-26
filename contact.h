#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <unistd.h>

// Structures for the Fields
typedef struct Contact_data
{
    char Name[20];
    char Mobile_number[11];
    char Mail_ID[30];

} Contacts;

// Structures foe the Contact deatils
typedef struct AddressBook_Data
{
    // Array of structures for the Fields sturucture
    Contacts contact_details[100];
    // To keep the track no of contact count
    int contact_count;
} AddressBook;

/* Function declarations */

void create_contact(AddressBook *);
void list_contacts(AddressBook *);
void search_contacts(AddressBook *);
void edit_contact(AddressBook *);
void delete_contact(AddressBook *);
void save_contacts(AddressBook *);
void load_contacts(AddressBook*);

void valid_name(char *);
void valid_number(char *,AddressBook *);
void valid_mail(char *,AddressBook *);

int search_name(AddressBook *);
int search_number(AddressBook *);
int search_mail(AddressBook *);

void delet_loader();
void save_loader();


#endif

