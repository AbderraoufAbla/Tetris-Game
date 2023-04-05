#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// struct to represent a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    // initialize an array to store contacts
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    // display welcome message and menu
    printf("Welcome to MyContacts\n");
    printf("Please select an option:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Update Contact\n");
    printf("4. View Contact\n");
    printf("5. Exit\n");

    // process user input
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // add contact
                if (num_contacts >= MAX_CONTACTS) {
                    printf("\nContact list is full. Cannot add more contacts.\n");
                } else {
                    struct Contact new_contact;
                    printf("\nEnter contact name: ");
                    scanf("%s", new_contact.name);
                    printf("Enter contact phone: ");
                    scanf("%s", new_contact.phone);
                    printf("Enter contact email: ");
                    scanf("%s", new_contact.email);
                    contacts[num_contacts] = new_contact;
                    num_contacts++;
                    printf("\nContact added successfully.\n");
                }
                break;
            case 2:
                // delete contact
                if (num_contacts == 0) {
                    printf("\nContact list is empty. Cannot delete contacts.\n");
                } else {
                    int delete_index;
                    printf("\nEnter index of contact to delete (0-%d): ", num_contacts-1);
                    scanf("%d", &delete_index);
                    if (delete_index < 0 || delete_index >= num_contacts) {
                        printf("\nInvalid index. Please try again.\n");
                    } else {
                        for (int i = delete_index; i < num_contacts-1; i++) {
                            contacts[i] = contacts[i+1];
                        }
                        num_contacts--;
                        printf("\nContact deleted successfully.\n");
                    }
                }
                break;
            case 3:
                // update contact
                if (num_contacts == 0) {
                    printf("\nContact list is empty. Cannot update contacts.\n");
                } else {
                    int update_index;
                    printf("\nEnter index of contact to update (0-%d): ", num_contacts-1);
                    scanf("%d", &update_index);
                    if (update_index < 0 || update_index >= num_contacts) {
                        printf("\nInvalid index. Please try again.\n");
                    } else {
                        struct Contact updated_contact;
                        printf("\nEnter new contact name (or press enter to keep current value '%s'): ", contacts[update_index].name);
                        fgets(updated_contact.name, 50, stdin);
                        updated_contact.name[strcspn(updated_contact.name, "\n")] = 0; // remove newline character
                        if (strlen(updated_contact.name) == 0) {
                            strcpy(updated_contact.name, contacts[update_index].name);
                        }
                        printf("Enter new contact phone (or press enter to keep current value '%s'): ", contacts[update_index].phone);
                        fgets(updated_contact.phone, 15, stdin);
                        updated_contact.phone[strcspn(updated_contact.phone, "\n")] = 0; // remove newline character
                        if (strlen(updated_contact.phone) == 0) {
                            strcpy(updated_contact.phone, contacts

                                   contacts[update_index].phone);
}
printf("Enter new contact email (or press enter to keep current value '%s'): ", contacts[update_index].email);
fgets(updated_contact.email, 50, stdin);
updated_contact.email[strcspn(updated_contact.email, "\n")] = 0; // remove newline character
if (strlen(updated_contact.email) == 0) {
strcpy(updated_contact.email, contacts[update_index].email);
}
contacts[update_index] = updated_contact;
printf("\nContact updated successfully.\n");
}
}
break;
case 4:
// view contact
if (num_contacts == 0) {
printf("\nContact list is empty. Cannot view contacts.\n");
} else {
int view_index;
printf("\nEnter index of contact to view (0-%d): ", num_contacts-1);
scanf("%d", &view_index);
if (view_index < 0 || view_index >= num_contacts) {
printf("\nInvalid index. Please try again.\n");
} else {
printf("\nContact Details:\n");
printf("Name: %s\n", contacts[view_index].name);
printf("Phone: %s\n", contacts[view_index].phone);
printf("Email: %s\n", contacts[view_index].email);
}
}
break;
case 5:
// exit program
printf("\nGoodbye!\n");
break;
default:
// invalid choice
printf("\nInvalid choice. Please try again.\n");
break;
}
} while (choice != 5);
return 0;
}

