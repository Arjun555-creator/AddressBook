#include<stdio.h>
#include<string.h>
#include "contact.h"

void createContact(struct Addressbook *addressbook)
{
    int i, valid = 1;
//NAME
do 
{
        valid = 1;
        printf("Enter the name: ");
        scanf(" %[^\n]", addressbook -> contacts[addressbook -> count_contact].name);
    for (i = 0; addressbook -> contacts[addressbook -> count_contact].name[i] != '\0'; i++)
    {
        if (addressbook -> contacts[addressbook -> count_contact].name[i] >= 'a' && addressbook -> contacts[addressbook -> count_contact].name[i] <= 'z')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].name[i] >= 'A' && addressbook -> contacts[addressbook -> count_contact].name[i] <= 'Z')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].name[i] == '.')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].name[i] == ' ')
        {
        }
        else
        {
            valid = 0;
        }
    }
}while(valid == 0);

//PHONE-NUMBER 
do
{
    valid = 1;
    printf("Enter the phone number: ");
    scanf(" %[^\n]", addressbook -> contacts[addressbook -> count_contact].phone_number);
    for (i = 0; addressbook -> contacts[addressbook -> count_contact].phone_number[i] != '\0'; i++)
    {
        if (addressbook -> contacts[addressbook -> count_contact].phone_number[i] >= '0' && addressbook -> contacts[addressbook -> count_contact].phone_number[i] <= '9')
        {
        }
        else
        {
            valid = 0;
        }
        
    }
       if(i != 10)
        {
            valid = 0;
        }

}while(valid == 0);

       
//E-MAIL
do
{
    valid = 1;
    printf("Enter the mail: ");
    scanf(" %[^\n]", addressbook -> contacts[addressbook -> count_contact].mail);
    for (i = 0; addressbook -> contacts[addressbook -> count_contact].mail[i] != '\0'; i++)
    {
        if (addressbook -> contacts[addressbook -> count_contact].mail[i] >= '0' && addressbook -> contacts[addressbook -> count_contact].mail[i] <= '9')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].mail[i] >= 'a' && addressbook -> contacts[addressbook -> count_contact].mail[i] <= 'z')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].mail[i] == '.')
        {
        }
        else if (addressbook -> contacts[addressbook -> count_contact].mail[i] == '@')
        {
        }
        else
        {
            valid = 0;
        }
    }
}while(valid == 0);
addressbook -> count_contact++;
}

//LIST FUNCTION

void listContact(struct Addressbook *addressbook)
{
    int i;

    if (addressbook->count_contact == 0)
    {
        printf("No contacts available.\n");
        printf("============================================================\n");
        return;
    }

    printf("%-6s %-20s %-15s %-30s\n", "S.No.", "Name", "Phone Number", "Mail");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < addressbook->count_contact; i++)
    {
        printf("%-6d %-20s %-15s %-30s\n",
               i + 1,
               addressbook->contacts[i].name,
               addressbook->contacts[i].phone_number,
               addressbook->contacts[i].mail);
    }

    printf("------------------------------------------------------------\n");
    printf("Total Contacts: %d\n", addressbook->count_contact);
    printf("============================================================\n");
}

// SEARCH FUNCTION

void searchContact(struct Addressbook *addressbook)
{
    int flag;
    char search[100];
    int category, i;

    do
    {
        flag = 0;
        printf("Choose the category to search\n");
        printf("------------------------------------------------------------\n");
        printf("1. Name\n");
        printf("2. Phone Number\n");
        printf("3. Mail\n");
        printf("------------------------------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &category) != 1)
{
    printf("Invalid input! Please enter 1, 2 or 3.\n");

    while (getchar() != '\n')
        ;

    continue;
}

        if (category == 1)
        {
            printf("Enter the Name: ");
            scanf(" %[^\n]", search);
        }
        else if (category == 2)
        {
            printf("Enter the Phone Number: ");
            scanf(" %[^\n]", search);
        }
        else if (category == 3)
        {
            printf("Enter the Mail: ");
            scanf(" %[^\n]", search);
        }
        else
        {
            printf("\nInvalid category! Please choose 1, 2 or 3.\n");
            continue;
        }

        printf("\n------------------------------------------------------------\n");

        for (i = 0; i < addressbook->count_contact; i++)
        {
            if (category == 1)
            {
                if (strstr(addressbook->contacts[i].name, search))
                {
                    printf("Contact Found\n");
                    printf("------------------------------------------------------------\n");
                    printf("Name  : %s\n", addressbook->contacts[i].name);
                    printf("Phone : %s\n", addressbook->contacts[i].phone_number);
                    printf("Mail  : %s\n", addressbook->contacts[i].mail);
                    printf("------------------------------------------------------------\n");

                    flag = 1;
                }
            }
            else if (category == 2)
            {
                if (strcmp(addressbook->contacts[i].phone_number, search) == 0)
                {
                    printf("Contact Found\n");
                    printf("------------------------------------------------------------\n");
                    printf("Name  : %s\n", addressbook->contacts[i].name);
                    printf("Phone : %s\n", addressbook->contacts[i].phone_number);
                    printf("Mail  : %s\n", addressbook->contacts[i].mail);
                    printf("------------------------------------------------------------\n");

                    flag = 1;
                }
            }
            else if (category == 3)
            {
                if (strcmp(addressbook->contacts[i].mail, search) == 0)
                {
                    printf("Contact Found\n");
                    printf("------------------------------------------------------------\n");
                    printf("Name  : %s\n", addressbook->contacts[i].name);
                    printf("Phone : %s\n", addressbook->contacts[i].phone_number);
                    printf("Mail  : %s\n", addressbook->contacts[i].mail);
                    printf("------------------------------------------------------------\n");

                    flag = 1;
                }
            }
        }

        if (flag == 0)
        {
            printf("Contact not found!\n");
            printf("Please try again.\n");
        }

    } while (flag == 0);
}

// EDIT FUNCTION

void editContact(struct Addressbook *addressbook)
{
    int i;
    int index = -1;
    int edit_choice;
    char edit[100];
    printf("Find a contact using:\n");
    printf("------------------------------------------------------------\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Mail\n");
    printf("------------------------------------------------------------\n");
    printf("Enter your choice: ");

    if (scanf("%d", &edit_choice) != 1)
    {
        printf("Invalid input! Please enter 1, 2 or 3.\n");

        while (getchar() != '\n')
            ;

        return;
    }

    if (edit_choice == 1)
    {
        printf("Enter the name: ");
        scanf(" %[^\n]", edit);
    }
    else if (edit_choice == 2)
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", edit);
    }
    else if (edit_choice == 3)
    {
        printf("Enter the mail: ");
        scanf(" %[^\n]", edit);
    }
    else
    {
        printf("Invalid choice! Please select 1, 2 or 3.\n");
        return;
    }

    for (i = 0; i < addressbook->count_contact; i++)
    {
        if (edit_choice == 1)
        {
            if (strstr(addressbook->contacts[i].name, edit))
            {
                index = i;
                break;
            }
        }
        else if (edit_choice == 2)
        {
            if (strcmp(addressbook->contacts[i].phone_number, edit) == 0)
            {
                index = i;
                break;
            }
        }
        else if (edit_choice == 3)
        {
            if (strcmp(addressbook->contacts[i].mail, edit) == 0)
            {
                index = i;
                break;
            }
        }
    }

    if (index == -1)
    {
        printf("\n------------------------------------------------------------\n");
        printf("Contact not found!\n");
        printf("------------------------------------------------------------\n");
        return;
    }

    printf("\nContact found!\n");
    printf("------------------------------------------------------------\n");
    printf("Name  : %s\n", addressbook->contacts[index].name);
    printf("Phone : %s\n", addressbook->contacts[index].phone_number);
    printf("Mail  : %s\n", addressbook->contacts[index].mail);
    printf("------------------------------------------------------------\n");

    int edit_field;
    char new_value[100];

    printf("\nWhat do you want to edit?\n");
    printf("------------------------------------------------------------\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Mail\n");
    printf("------------------------------------------------------------\n");
    printf("Enter your choice: ");

    if (scanf("%d", &edit_field) != 1)
    {
        printf("Invalid input! Please enter 1, 2 or 3.\n");

        while (getchar() != '\n')
            ;

        return;
    }

    if (edit_field == 1)
    {
        printf("Enter new Name: ");
        scanf(" %[^\n]", new_value);
        strcpy(addressbook->contacts[index].name, new_value);
    }
    else if (edit_field == 2)
    {
        printf("Enter new Phone Number: ");
        scanf(" %[^\n]", new_value);
        strcpy(addressbook->contacts[index].phone_number, new_value);
    }
    else if (edit_field == 3)
    {
        printf("Enter new Mail: ");
        scanf(" %[^\n]", new_value);
        strcpy(addressbook->contacts[index].mail, new_value);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("\n============================================================\n");
    printf("                 CONTACT UPDATED SUCCESSFULLY\n");
    printf("============================================================\n");
    printf("Name  : %s\n", addressbook->contacts[index].name);
    printf("Phone : %s\n", addressbook->contacts[index].phone_number);
    printf("Mail  : %s\n", addressbook->contacts[index].mail);
    printf("============================================================\n");
}
// DELETE FUNCTION

void deleteContact(struct Addressbook *addressbook)
{
    int category, i, index = -1;
    char search[100];
    printf("Find a contact using:\n");
    printf("------------------------------------------------------------\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Mail\n");
    printf("------------------------------------------------------------\n");
    printf("Enter your choice: ");

    if (scanf("%d", &category) != 1)
    {
        printf("Invalid input! Please enter 1, 2 or 3.\n");

        while (getchar() != '\n')
            ;

        return;
    }

    if (category == 1)
    {
        printf("Enter the name: ");
        scanf(" %[^\n]", search);
    }
    else if (category == 2)
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", search);
    }
    else if (category == 3)
    {
        printf("Enter the mail: ");
        scanf(" %[^\n]", search);
    }
    else
    {
        printf("Invalid choice! Please select 1, 2 or 3.\n");
        return;
    }

    for (i = 0; i < addressbook->count_contact; i++)
    {
        if (category == 1)
        {
            if (strstr(addressbook->contacts[i].name, search))
            {
                index = i;
                break;
            }
        }
        else if (category == 2)
        {
            if (strcmp(addressbook->contacts[i].phone_number, search) == 0)
            {
                index = i;
                break;
            }
        }
        else if (category == 3)
        {
            if (strcmp(addressbook->contacts[i].mail, search) == 0)
            {
                index = i;
                break;
            }
        }
    }

    if (index == -1)
    {
        printf("\n------------------------------------------------------------\n");
        printf("Contact not found!\n");
        printf("------------------------------------------------------------\n");
        return;
    }

    printf("\nContact found:\n");
    printf("------------------------------------------------------------\n");
    printf("Name  : %s\n", addressbook->contacts[index].name);
    printf("Phone : %s\n", addressbook->contacts[index].phone_number);
    printf("Mail  : %s\n", addressbook->contacts[index].mail);
    printf("------------------------------------------------------------\n");

    for (i = index; i < addressbook->count_contact - 1; i++)
    {
        addressbook->contacts[i] = addressbook->contacts[i + 1];
    }

    addressbook->count_contact--;

    printf("\n============================================================\n");
    printf("                 CONTACT DELETED SUCCESSFULLY\n");
    printf("============================================================\n");
}
