#ifndef CONTACT_H
#define CONTACT_H

struct contact
{
    char name[30];
    char phone_number[11];
    char mail[30];
};
struct Addressbook
{
    struct contact contacts[100];
    int count_contact;
};

void createContact(struct Addressbook *addressbook);
void listContact(struct Addressbook *addressbook);
void searchContact(struct Addressbook *addressbook);
void editContact(struct Addressbook *addressbook);
void deleteContact(struct Addressbook *addressbook);

#endif
