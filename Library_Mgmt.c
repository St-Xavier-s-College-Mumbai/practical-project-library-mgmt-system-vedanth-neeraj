#include <stdio.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50

struct Book {
    int id;
    char title[MAX_TITLE];
    int isIssued;
};

struct Book library[MAX_BOOKS];
int totalBooks = 0;

void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    int id;
    char title[MAX_TITLE];
    
    printf("Enter Book ID: ");
    scanf("%d", &id);
    
    printf("Enter Book Title: ");
    scanf(" %[^\n]", title);

    library[totalBooks].id = id;
    
    int i = 0;
    while (title[i] != '\0' && i < MAX_TITLE - 1) {
        library[totalBooks].title[i] = title[i];
        i++;
    }
    library[totalBooks].title[i] = '\0';

    library[totalBooks].isIssued = 0;
    totalBooks++;
    printf("Book '%s' added successfully!\n", title);
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued == 0) {
                library[i].isIssued = 1;
                printf("Book '%s' issued!\n", library[i].title);
                return;
            } else {
                printf("Book '%s' is already issued.\n", library[i].title);
                return;
            }
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued == 1) {
                library[i].isIssued = 0;
                printf("Book '%s' returned!\n", library[i].title);
                return;
            } else {
                printf("Book '%s' was not issued.\n", library[i].title);
                return;
            }
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void checkAvailability() {
    int id;
    printf("Enter Book ID to check availability: ");
    scanf("%d", &id);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued == 0) {
                printf("Book '%s' is available.\n", library[i].title);
            } else {
                printf("Book '%s' is currently issued.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Check Availability\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                issueBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                checkAvailability();
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
