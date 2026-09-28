#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "file.h"

int main()
{
    struct Addressbook addressbook;
    int choice;

    addressbook.count_contact = 0;
    loadContacts(&addressbook);

    do
    {
        printf("\n");

        printf("============================================================\n");
        printf("                       ADDRESS BOOK\n");

        printf("                         MAIN MENU\n");
        printf("============================================================\n");

        printf("S.No.        Operation\n");
        printf("------------------------------------------------------------\n");
        printf("1            Create Contact\n");
        printf("2            List Contacts\n");
        printf("3            Search Contact\n");
        printf("4            Edit Contact\n");
        printf("5            Delete Contact\n");
        printf("6            Save Contacts\n");
        printf("7            Exit\n");
        printf("------------------------------------------------------------\n");

        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("============================================================\n");
                printf("                    CREATE CONTACT\n");
                printf("============================================================\n\n");

                createContact(&addressbook);
                break;

            case 2:
                printf("============================================================\n");
                printf("                     CONTACT LIST\n");
                printf("============================================================\n\n");

                listContact(&addressbook);
                break;

            case 3:
                printf("============================================================\n");
                printf("                    SEARCH CONTACT\n");
                printf("============================================================\n\n");

                searchContact(&addressbook);
                break;

            case 4:
                printf("============================================================\n");
                printf("                     EDIT CONTACT\n");
                printf("============================================================\n\n");

                editContact(&addressbook);
                break;

            case 5:
                printf("============================================================\n");
                printf("                    DELETE CONTACT\n");
                printf("============================================================\n\n");

                deleteContact(&addressbook);
                break;

            case 6:
                printf("============================================================\n");
                printf("                     SAVE CONTACTS\n");
                printf("============================================================\n\n");

                saveContacts(&addressbook);
                break;

            case 7:
                printf("============================================================\n");
                printf("                     EXIT ADDRESS BOOK\n");
                printf("============================================================\n");

                printf("Exiting...\n");
                break;

            default:
                printf("------------------------------------------------------------\n");
                printf("Invalid choice! Please select a number from 1 to 7.\n");
                printf("------------------------------------------------------------\n");
        }

    } while (choice != 7);

    return 0;
}

