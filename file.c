#include<stdio.h>
#include"contact.h"
#include"file.h"

void saveContacts(struct Addressbook *addressbook)
{
    FILE *fp;

    fp = fopen("contacts.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < addressbook->count_contact; i++)
    {
        fprintf(fp, "%s\n", addressbook->contacts[i].name);
        fprintf(fp, "%s\n", addressbook->contacts[i].phone_number);
        fprintf(fp, "%s\n", addressbook->contacts[i].mail);
    }

    fclose(fp);

    printf("Contacts saved successfully\n");
}

void loadContacts(struct Addressbook *addressbook)
{
    FILE *fp = fopen("contacts.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp, " %[^\n]", addressbook->contacts[addressbook->count_contact].name) == 1)
    {
        fscanf(fp, " %[^\n]", addressbook->contacts[addressbook->count_contact].phone_number);
        fscanf(fp, " %[^\n]", addressbook->contacts[addressbook->count_contact].mail);

        addressbook->count_contact++;

        if (addressbook->count_contact >= 100)
        {
            break;
        }
    }

    fclose(fp);
}
