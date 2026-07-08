#include "contact.h"

//Function definations for contact menu

void create_contact(AddressBook *addressbook)
{
    while(1)
    {
    //Creating a contact name and store to addressbook
    char name[20];
    printf("Enter contact name: ");
    scanf(" %[^\n]",name);
    valid_name(name);
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);
   
    // Creating a mobile number and store to addressbook
    char mob_number[11];
    printf("Enter contact number: ");
    scanf(" %s",mob_number);
    valid_number(mob_number,addressbook);
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mob_number);

    // Creating a mail id and store to addressbook
    char mail_id[50];
    printf("Enter mail id: ");
    scanf(" %s",mail_id);
    valid_mail(mail_id,addressbook);
    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail_id);

    // counting the no. of contacts
    addressbook->contact_count++;

    //once adding the contact it will ask the user that for do you want to add one more contact
    printf("\nDo you want to add one more contact?\nY/N\n");
    char ch;
    int flag=0;
    while(1)
    {
        scanf(" %c",&ch);
        //If user enter the Y/y,flag will be update 1 and terminate from this loop 
        if(ch == 'Y' || ch == 'y'){
            flag=1;
            break;
        }
        //If user enter the N/n,flag will be update to 2 and terminate from this loop 
        else if(ch == 'N'|| ch == 'n'){
            flag=2;
            break;
        }
        //If input is neither Y nor N then loop will be run again and ask once again to enter between y/n.
        else
        {
            printf("You can only enter either Y or N: ");
            continue;
        }
    }
    //Enterd input is Y.outer loop run one more time and to add the contact details.
    if(flag==1)
    continue;
    //Enterd input is N.outer loop will terminate and return to main where function called.
    else if(flag==2)
    {
        save_contacts(addressbook);
        break;
    }

    }
}

void list_contacts(AddressBook *addressbook)
{

    char temp_name[30];
    char temp_number[30];
    char temp_mail[30];
    //If contacts are not there it will print no number is saved and return to main
    if(addressbook->contact_count == 0)
    {
        printf("Contacts not found.\n");
        return;
    }
    else
    {
        printf("Select sort criteria:\n1. sort by name\n2. sort by mobile number\n3. sort by mail\nEnter the option\n");
        int option;
        scanf("%d",&option);

        switch(option) //Based on options 
        {
        case 1:
        {
            //Sorting the contacts based on name using qsort function and ascending_name function is used to compare the names.
            qsort(addressbook->contact_details, addressbook->contact_count, sizeof(Contacts), ascending_name);
            printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
            printf("------------------------------------------------------------------------------\n");
            for(int i=0; i<addressbook->contact_count; i++)
            {
                printf("%-5d ",i+1);
                printf("%-20s ",addressbook->contact_details[i].Name);
                printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                printf("%-30s\n",addressbook->contact_details[i].Mail_ID);

            }
            printf("------------------------------------------------------------------------------\n");
            printf("\n");
            break;
        }

        case 2:
        {
            //Sorting the contacts based on mobile number using qsort function and ascending_number function is used to compare the numbers.
            qsort(addressbook->contact_details, addressbook->contact_count, sizeof(Contacts), ascending_number);
            printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
            printf("------------------------------------------------------------------------------\n");
            for(int i=0; i<addressbook->contact_count; i++)
            {
                printf("%-5d ",i+1);
                printf("%-20s ",addressbook->contact_details[i].Name);
                printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                printf("%-30s\n",addressbook->contact_details[i].Mail_ID);

            }
            printf("------------------------------------------------------------------------------\n");
            printf("\n");
            break;
        }

        case 3:
        {
            //Sorting the contacts based on mail id using qsort function and ascending_mail function is used to compare the mail ids.
            qsort(addressbook->contact_details, addressbook->contact_count, sizeof(Contacts), ascending_mail);
            printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
            printf("------------------------------------------------------------------------------\n");
            for(int i=0; i<addressbook->contact_count; i++)
            {
                printf("%-5d ",i+1);
                printf("%-20s ",addressbook->contact_details[i].Name);
                printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                printf("%-30s\n",addressbook->contact_details[i].Mail_ID);

            }
            printf("------------------------------------------------------------------------------\n");
            printf("\n");
            break;
        }

        }
    }

}

// Function definations for sorting the contacts based on name,number and mail id
int ascending_name(const void *a, const void *b)
{
    const Contacts *A = (const Contacts *)a;
    const Contacts *B = (const Contacts *)b;
    return strcmp(A->Name, B->Name);
}
int ascending_number(const void *a, const void *b)
{
    const Contacts *A = (const Contacts *)a;
    const Contacts *B = (const Contacts *)b;
    return strcmp(A->Mobile_number, B->Mobile_number);
}
int ascending_mail(const void *a, const void *b)
{
    const Contacts *A = (const Contacts *)a;
    const Contacts *B = (const Contacts *)b;
    return strcmp(A->Mail_ID, B->Mail_ID);
}

void search_contacts(AddressBook *addressbook)
{
    while(1)
    {
        printf("Search Contact menu : \n1. Name \n2. Mobile number\n3. Mail ID\n4. Exit\nEnter the option : ");

        int option,found=0;
        scanf("%d",&option);
        switch(option)
        {
            case 1 :
            {
                
                char name[20];
                printf("Enter a name\n");
                scanf(" %[^\n]",name);
                printf("\n");
                int i,found=0;
                printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
                printf("------------------------------------------------------------------------------\n");
                for(i=0; i<addressbook->contact_count; i++)
                {
                    //strstr function return base address of the string if string is found. if string is not found it will return NULL
                    char *ptr = strstr(addressbook->contact_details[i].Name,name);
                    if(ptr!=NULL)
                    {
                        printf("%-5d ",i+1);
                        printf("%-20s ",addressbook->contact_details[i].Name);
                        printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                        printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
                        found=1;
                    }
                }
                printf("------------------------------------------------------------------------------\n");
                if(found == 0)
                printf("contact not found\n");
                break;
            }

            case 2 :
            {
                char mob_number[11];
                printf("Enter a number\n");
                scanf(" %s",mob_number);
                int i,found=0;
                printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
                printf("------------------------------------------------------------------------------\n");
                for(i=0; i<addressbook->contact_count; i++)
                {
                //strstr function return base address of the string if string is found. if string is not found it will return NULL
                    char *ptr = strstr(addressbook->contact_details[i].Mobile_number,mob_number);
                    if(ptr != NULL)
                    {
                        printf("%-5d ",i+1);
                        printf("%-20s ",addressbook->contact_details[i].Name);
                        printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                        printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
                        found=1;
                    }
                }
                printf("------------------------------------------------------------------------------\n");
                if(found==0)
                printf("contact not found\n");
                break;
            }

            case 3 :
            {
                char mail_id[30];
                printf("Enter a mail ID\n");
                scanf(" %s",mail_id);
                int i,found=0;
                printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
                printf("------------------------------------------------------------------------------\n");
                for(int i=0; i<addressbook->contact_count; i++)
                {
                    //strstr function return base address of the string if string is found. if string is not found it will return NULL
                    char *ptr = strstr(addressbook->contact_details[i].Mail_ID,mail_id);
                    if(ptr != NULL)
                    {
                        printf("%-5d ",i+1);
                        printf("%-20s ",addressbook->contact_details[i].Name);
                        printf("%-15s ",addressbook->contact_details[i].Mobile_number);
                        printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
                        found=1;
                    }
                }
                printf("------------------------------------------------------------------------------\n");
                if(found == 0)
                printf("contact not found\n");
                break;
            }

            case 4 :
            {
                //It will return to main function
                return;
            }
        }
    }
}

void edit_contact(AddressBook *addressbook)
{
    while(1)
    {
        printf("Edit Contact menu : \n1.Search by Name \n2.Search by Mobile number\n3.Search by Mail ID\n4.Exit\nEnter the option : ");
        int option,update=0;
        scanf("%d",&option);
        switch(option)
        {
            case 1 :
            {
                int ind=search_name(addressbook);

                if(ind == -1)
                break;
                else if(ind == -2)
                break;
                else
                {
                    //if contact is found it will show the options which fields do you want to edit
                    int op;
                    printf("\nWhich field do you want to edit?\n");
                    printf("1.Name\n2.Phone number\n3.Mail id\n4.All fields\n5.Exit\nEnter the option: ");
                    scanf("%d",&op);

                    switch(op) //Based on conditions
                    {
                        case 1 :
                        {
                            //Modify the name and copy to original name using strcpy function
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[ind].Name,update_name);
                            printf("Name is updated.\n");
                            break;
                        }
                        case 2 :
                        {
                            //Modify the number and copy to original number using strcpy function
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[ind].Mobile_number,update_number);
                            printf("Number is updated.\n");
                            break;
                        }
                        case 3 :
                        {
                            //Modify the mail and copy to original mail using strcpy function
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[ind].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }
                        case 4 :
                        {
                            //Modify all the fields and copy to there resepective fields
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[ind].Name,update_name);
                            printf("Name is updated.\n");

                            
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[ind].Mobile_number,update_number);
                            printf("Number is updated.\n");

                            
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[ind].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }

                        case 5 :
                        {
                            //It will terminate from the switch loop
                            break;
                        }
                    }
                    //It will terminate from the while loop
                    break;
                }
            }

            case 2 :
            {
                int indx=search_number(addressbook);
                if(indx == -1)
                break;
                else
                {
                    //if contact is found it will display the edit menu
                    int op;
                    printf("Which field do you want to edit?\n");
                    printf("1.Name\n2.Phone number\n3.Mail id\n4.All fields\n5.Exit\nEnter the option: ");
                    scanf("%d",&op);

                    switch(op)
                    {
                        case 1 :
                        {
                             //Modify the name and copy to original name using strcpy function
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[indx].Name,update_name);
                            printf("Name is updated.\n");
                            break;
                        }
                        case 2 :
                        {
                             //Modify the number and copy to original number using strcpy function
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[indx].Mobile_number,update_number);
                            printf("Number is updated.\n");
                            break;
                        }
                        case 3 :
                        {
                             //Modify the mail and copy to original mail using strcpy function
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[indx].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }
                        case 4 :
                        {
                             //Modify the name and copy to original name using strcpy function
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[indx].Name,update_name);
                            printf("Name is updated.\n");

                             //Modify the number and copy to original number using strcpy function
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[indx].Mobile_number,update_number);
                            printf("Number is updated.\n");

                             //Modify the mail and copy to original mail using strcpy function
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[indx].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }
                        case 5 :
                        {
                            break;
                        }
                    }
                    break;
                }
            }

            case 3 :
            {
                int indx=search_mail(addressbook);
                if(indx == -1)
                break;
                else
                {
                    int op;
                    printf("Which field do you want to edit?\n");
                    printf("1.Name\n2.Phone number\n3.Mail id\n4.All fields\n5.Exit\nEnter the option: ");
                    scanf("%d",&op);

                    switch(op)
                    {
                        case 1 :
                        {
                             //Modify the name and copy to original name using strcpy function
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[indx].Name,update_name);
                            printf("Name is updated.\n");
                            break;
                        }
                        case 2 :
                        {
                             //Modify the number and copy to original number using strcpy function
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[indx].Mobile_number,update_number);
                            printf("Number is updated.\n");
                            break;
                        }
                        case 3 :
                        {
                             //Modify the mail and copy to original mail using strcpy function
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[indx].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }
                        case 4 :
                        {
                            char update_name[20];
                            printf("Enter a name: ");
                            scanf(" %[^\n]",update_name);
                            valid_name(update_name);
                            strcpy(addressbook->contact_details[indx].Name,update_name);
                            printf("Name is updated.\n");

                            
                            char update_number[11];
                            printf("Enter a number: ");
                            scanf(" %s",update_number);
                            valid_number(update_number,addressbook);
                            strcpy(addressbook->contact_details[indx].Mobile_number,update_number);
                            printf("Number is updated.\n");

                            
                            char update_mail[20];
                            printf("Enter mail id: ");
                            scanf(" %s",update_mail);
                            valid_mail(update_mail,addressbook);
                            strcpy(addressbook->contact_details[indx].Mail_ID,update_mail);
                            printf("Mail is updated.\n");
                            break;
                        }
                        case 5 :
                        {
                            break;
                        }
                    }
                    break;
                }
            }

            case 4 :
            {
                //it will return to main function
                return ;
            }
        }
    }

}

void save_contacts(AddressBook *addressbook)
{
    //Declare the file pointer
    FILE *fp;
    //open the file. if file is not there it will create the new file
    fp = fopen("contacts.csv","w+");
    //if file is not crated it wil retun
    if(fp==NULL)
    {
        printf("file not created.\n");
        return;
    }

    fprintf(fp,"#%d\n",addressbook->contact_count);

    //take the contacts
    for(int i=0; i<addressbook->contact_count; i++)
    {
        fprintf(fp,"%s,",addressbook->contact_details[i].Name);
        fprintf(fp,"%s,",addressbook->contact_details[i].Mobile_number);
        fprintf(fp,"%s\n",addressbook->contact_details[i].Mail_ID);
    }
    //file will be closed
    fclose(fp);
    //printing the loading animation
    save_loader();

}

void load_contacts(AddressBook *addressbook)
{
    //Declaration of file pointer
    FILE *fp;
    //open the file if file is there in read mode
    fp = fopen("contacts.csv","r");
    if(fp==NULL)
    {
        printf("file not found.\n");
        addressbook->contact_count = 0;
        return;
    }

    //if no contacts details is available in file it should be show the contact count 0
    fscanf(fp,"#%d\n",&addressbook->contact_count);
    
    //reading the contacts details
    for(int i=0; i<addressbook->contact_count; i++)
    {
        fscanf(fp," %[^,],%[^,],%s\n",
            addressbook->contact_details[i].Name,
            addressbook->contact_details[i].Mobile_number,
            addressbook->contact_details[i].Mail_ID);
    }
    //close the file
    fclose(fp);
}

void delete_contact(AddressBook *addressbook)
{

    while(1)
    {
        int option;
        //Display the delet menu
        printf("Delete Contact menu : \n1. Name \n2. Mobile number\n3. Mail ID\n4. Exit\nEnter the option : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1 :
            {
                int indx=search_name(addressbook);
                if(indx==-1)
                break;
                else if(indx == -2)
                break;
                else
                {
                    //if contact found it will display the option for y/n
                    char ch;
                    printf("Do you want to delete this contact ?\nY / N\n");
                    scanf(" %c",&ch);
                    //based on user input.if input is N/n then it will break from the switch loop
                    if(ch == 'N' || ch == 'n')
                    {
                        break;
                    }
                    //if input is Y/y then contact will be deleted.
                    else if(ch == 'Y' || ch == 'y')
                    {
                        for(int i=indx; i<addressbook->contact_count-1; i++)
                        {
                            //shifting the contacts from last index to the index value of delete
                            addressbook->contact_details[i] = addressbook->contact_details[i+1];
                        }
                        //decremening of count after removing contact
                        addressbook->contact_count--;
                    }

                }
                delet_loader();
                printf("\nContact deleted successfully\n");
                break;
            }

            case 2 :
            {

                int indx=search_number(addressbook);
                if(indx==-1)
                break;
                else
                {
                    //if contact found it will display the option for y/n
                    printf("Do you want to delete this contact?\nY / N\n");
                    char ch;
                    scanf(" %c",&ch);
                    if(ch =='N' || ch=='n')
                    {
                        break;
                    }
                    else if(ch == 'Y' || ch == 'y')
                    {
                        for(int i=indx; i<addressbook->contact_count-1; i++)
                        {
                            //shifting the contacts from last index upto the index value of delete
                            addressbook->contact_details[i] = addressbook->contact_details[i+1];
                        }
                         //decremening of count after removing contact
                        addressbook->contact_count--;
                    }
                }
                delet_loader();
                printf("\nContact deleted successfully\n");
                break;
            }

            case 3 :
            {

                int indx=search_mail(addressbook);
                if(indx==-1)
                break;
                else
                {
                    printf("Do you want to delete this contact?\nY / N\n");
                    char ch;
                    scanf(" %c",&ch);
                    if(ch =='N' || ch=='n')
                    {
                        break;
                    }
                    else if(ch == 'Y' || ch == 'y')
                    {
                        for(int i=indx; i<addressbook->contact_count-1; i++)
                        {
                            //shifting the contacts from last index to the index value of delete
                            addressbook->contact_details[i] = addressbook->contact_details[i+1];
                        }
                        //decremening of count after removing contact
                        addressbook->contact_count--;
                    }
                }
                delet_loader();
                printf("\nContact deleted successfully\n");
                break;
            }

            case 4 :
            {
                //return to main function
                return;
            }
        }
    }
}


// Function definations To cheak the validations

void valid_name(char *name)
{
    while(1)
    {
        int valid=1;
        int i=0;
        while(name[i])
        {
            //Cheaking for all charcters are alphabets or not
            if(isalpha(name[i]) != 0 || name[i]==' ')
            i++;
            else
            {
                valid=0;
                break;
            }
        }
        //if valid=1,returns to the where function is called
        //else it will print enter a valid name
        if(valid)
        break;
        else
        printf("Please enter a valid name.\n");
        printf("Enter contact name: ");
        scanf(" %[^\n]",name);
    }
    return;
}

void valid_number(char *mob_number,AddressBook *addressbook)
{
    
    while(1)
    {
        int valid=1;
        //Count the lenght of the number.
        int count=strlen(mob_number);

        for(int i=0; i<10; i++)
        {
            //To check whether no is starting from 6 or greater than 6.
            if(mob_number[0]<'6')
            {
                printf("Starting number should be greater than 6.\n");
                valid=0;
                break;
            }
            //To check whether number contains any character other than digit.
            else if(!isdigit(mob_number[i]))
            {
                printf("Number must be in digits\n");
                valid =0;
                break;
            }
            //To cheack whether number contains 10 digits or not.
            else if(mob_number[i] == ' ' || count!=10)
            {
                printf("Number should be of 10 digits.\n");
                valid=0;
                break; 
            }
        }
        //To cheak the number is already exist or not
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mobile_number,mob_number)== 0)
            {
                printf("Number is already exist.\n");
                valid=0;
                break;
            }
        }
    
        if(valid)
        break;
        else{
        printf("Enter a number: ");
        scanf("%s",mob_number);
        }
    }
    return;
}

void valid_mail(char *mail_id,AddressBook *addressbook)
{
    while(1)
    {
        int valid=1;
        
        char *at = strstr(mail_id, "@");
        char *dot = strstr(mail_id, ".com");

        // Check @ and .com
        if(at == NULL || dot == NULL)
        {
            printf("Mail id must contain @ and .com\n");
            valid = 0;
        }

        // Check characters between @ and .com
        else if(dot - at <= 1)
        {
            printf("Please enter a valid mail\n");
            valid = 0;
        }

        // Check only alphabets between @ and .com
        else
        {
            char *p = at + 1;

            while(p < dot)
            {
                if(!isalpha(*p))
                {
                    printf("Mail id should contain alphabets between @ and .com\n");
                    valid = 0;
                    break;
                }
                p++;
            }
        }

        if(!valid)
        {
            printf("Enter mail ID: ");
            scanf("%s",mail_id);
            continue;
        }

        // Count @
        int at_count = 0;

        for(int i = 0; mail_id[i] != '\0'; i++)
        {
            if(mail_id[i] == '@')
                at_count++;
        }

        // Count .com
        int com_count = 0;
        char *q = mail_id;

        while((q = strstr(q, ".com")) != NULL)
        {
            com_count++;
            q += 4;
        }

        if(at_count != 1 || com_count != 1)
        {
            printf("Mail id should contain only one @ and one .com\n");
            printf("Enter mail id: ");
            scanf("%s", mail_id);
            continue;
        }

        // First character should be lowercase
        if(!islower(mail_id[0]))
        {
            printf("Mail id should start with a lowercase letter\n");
            printf("Enter mail id: ");
            scanf("%s", mail_id);
            continue;
        }

        // Check all letters are lowercase
        int found = 0;

        for(int i = 0; mail_id[i] != '\0'; i++)
        {
            if(isalpha(mail_id[i]) && !islower(mail_id[i]))
            {
                found = 1;
                break;
            }
        }
        if(found)
        {
            printf("All letters must be lowercase\n");
            printf("Enter mail id: ");
            scanf("%s", mail_id);
            continue;
        }
        //Check the mail id is already exists or not
        for(int i=0; i<addressbook->contact_count; i++)
        {
            if(strcmp(addressbook->contact_details[i].Mail_ID,mail_id) == 0)
            {
                printf("Mail id is already exist.\n");
                valid=0;
                break;
            }
        }
        if(valid)
        break;
        else
        {
            printf("Enter mail id: ");
            scanf("%s", mail_id);
        }
    }
}

// Funciton definations to search the contacts

int search_name(AddressBook *addressbook)
{
    char name[20];
    printf("Enter a name\n");
    scanf(" %[^\n]",name);
    printf("\n");
    int i,count=0;
    int j = -1;
    printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
    printf("------------------------------------------------------------------------------\n");
    for(i=0; i<addressbook->contact_count; i++)
    {
        //strstr function return base address of the string if string is found. if string is not found it will return NULL
        char *ptr = strstr(addressbook->contact_details[i].Name,name);
        if(ptr!=NULL)
        {
            printf("%-5d ",i+1);
            printf("%-20s ",addressbook->contact_details[i].Name);
            printf("%-15s ",addressbook->contact_details[i].Mobile_number);
            printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
            j=i;
            count++;
        }
    }
    printf("------------------------------------------------------------------------------\n");
    // return -1 if contact not found
    if(count==0)
    {
        printf("\ncontact not found\n");
        return j;
    }
    //return -2 if more than one contact found
    else if(count>1)
    {
        printf("Multiple matches found. search by either phone or mail\n");
        return -2;
    }
    //return index value of found contact
    else
    return j; 
}

int search_number(AddressBook *addressbook)
{
    char mob_number[11];
    printf("Enter a number\n");
    scanf(" %s",mob_number);
    int i,found=0,ret=-1;
    printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
    printf("------------------------------------------------------------------------------\n");
    for(i=0; i<addressbook->contact_count; i++)
    {
        //strcmp function will return 0 if string is present
        int res = strcmp(addressbook->contact_details[i].Mobile_number,mob_number);
        if(res==0)
        {
            printf("%-5d ",i+1);
            printf("%-20s ",addressbook->contact_details[i].Name);
            printf("%-15s ",addressbook->contact_details[i].Mobile_number);
            printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
            ret=i;
            break;
        }
    }
    printf("------------------------------------------------------------------------------\n");
    // return -1 if contact not found
    if(ret==-1)
    {
        printf("\ncontact not found\n");
        return ret;
    }
    else
    return ret; 
}

int search_mail(AddressBook *addressbook)
{
    char mail_id[30];
    printf("Enter a mail ID\n");
    scanf(" %s",mail_id);
    int i,ret=-1;
    printf("\n%-5s %-20s %-15s %-30s\n","NO.","NAME","MOBILE","MAIL ID");
    printf("------------------------------------------------------------------------------\n");
    for(int i=0; i<addressbook->contact_count; i++)
    {
        //strcmp function return 0 if string is present.
        int res = strcmp(addressbook->contact_details[i].Mail_ID,mail_id);
        if(res==0)
        {
            printf("%-5d ",i+1);
            printf("%-20s ",addressbook->contact_details[i].Name);
            printf("%-15s ",addressbook->contact_details[i].Mobile_number);
            printf("%-30s\n",addressbook->contact_details[i].Mail_ID);
            ret=i;
            break;
        }
    }
    printf("------------------------------------------------------------------------------\n");
    // return -1 if contact not found
    if(ret==-1)
    {
        printf("\ncontact not found\n");
        return ret;
    }
    else
    return ret; 
}

//Function definations to show the loading animation

void save_loader()
{
    printf("Loading... ");
    for(int i = 0; i <= 100; i++)
    {
        printf("\rLoading... %3d%%", i);
        fflush(stdout);
        usleep(20000);
    }
    printf("\nContact saved successfully\n");
    return;
}

void delet_loader()
{
    printf("Deleting... ");
    for(int i = 0; i <= 100; i++)
    {
        printf("\rDeleting... %3d%%", i);
        fflush(stdout);
        usleep(20000);
    }
    printf("\nContact deleted successfully\n");
    return;
}