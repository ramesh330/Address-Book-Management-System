/*  
Project Name : Addressbook
Name : Ramesh Pandhare
Date : 18/06/26

Description : Addressbook is a reference of Telephone Directory. to overcome some drawback of telephone directory we build this project.
              in this project we have used following functions:
              1.void create_contact(AddressBook *) -> in create_contact() funtion we are going to create the name,mobile number and mail id. after 
                cheacking all the condition for validation we store successfully in addressbook contact details.

              2.void list_contacts(AddressBook *)-> list_contact() is used to display all the contact details whatever we stored. we can see the list
                sorted by name,sorted by mobile and sorted by mail id.

              3.void search_contacts(AddressBook *)->in this function we can search a contact. it also contain 3 options which are search by name,
                search by number and search by mail. we can search any contact details using these options.

              4.void edit_contact(AddressBook *)-> In edit_contact() we can modify the contact details. first we have to search a conctact to modify
                so the same logic of search_contact() we are going to use here also. once contact is found after it contains 4 options of edit menu-
                name,number,mail and all fields which fields do you want to edit, you can just enter the option.

              5.void delete_contact(AddressBook *)->If user want to delete the contact,just user can enter the delete_contact() option no. here also 
                we have first called search_contact() to search the contact to delet. once contact found it will show 3 options-name,mobile and mail
                by using those option user can delete the contact.

              6.void save_contact(Addressbook*)-> In this function first we are going to open the file that is .csv file. if file is not found it will 
                create the new file and contacts which we have taken it will store in .csv file. so that if once we terminate from the program data will 
                not be deleted we can retain the data anytime.

              7.void load_contacts(Addressbook*)-> Using this function we can read the contacts which we have stored. if contacts are not found 
                it will shows only zero contacts count. if contacts are available then it showes number of contacts count and that number of contacts
                details in .csv file.
*/

#include "contact.h"


int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    load_contacts(&addressbook);

    while (1)
    {
        printf("\nAddress Book Menu\n"); /* Give a prompt message for a user */
        printf("1. Add contact\n2. search contact\n3. Edit contact\n4. Delete contact\n5. Display contact\n6. Save contacts\n7. Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            //calling craeat_contact function
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            search_contacts(&addressbook);
            break;
        }
        case 3:
        {
            edit_contact(&addressbook);
            break;
        }
        case 4:
        {
            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("List contacts:\n");
            list_contacts(&addressbook);
            break;
        }
        case 6:
        {
            save_contacts(&addressbook);

        }
        case 7:
            return 0;

        default:
            printf("Invalid option \n");
            break;
        }
    }
    return 0;
}
