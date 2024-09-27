#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

// Global arrays to store book details
char titles[MAX_BOOKS][TITLE_LEN];
char authors[MAX_BOOKS][AUTHOR_LEN];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int bookCount = 0; // Count of current books

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void updateQuantity();
void deleteBook();
void totalBooks();

int main() {
    int choice;

    do {
        printf("\n--- Book Stock Management System ---\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Update Book Quantity\n");
        printf("5. Delete a Book\n");
        printf("6. Total Books in Stock\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1: addBook();; break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: updateQuantity(); break;
            case 5: deleteBook(); break;
            case 6: totalBooks(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
void addBook() {
    char another;
    
    do {
        if (bookCount < MAX_BOOKS) {
            printf("Enter book title, author, price, and quantity (title/author/price/quantity): ");
            scanf("%[^/]/%[^/]/%f/%d", titles[bookCount], authors[bookCount], &prices[bookCount], &quantities[bookCount]);

            printf("Book added successfully!\n");
            printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
                   titles[bookCount], authors[bookCount], prices[bookCount], quantities[bookCount]);

            bookCount++;
        } else {
            printf("Maximum book limit reached.\n");
            break;
        }

        printf("Do you want to add another book? (y/n): ");
        scanf(" %c", &another); // Note the space before %c to consume any leftover newline

    } while (another == 'y' || another == 'Y');
}
void displayBooks(){
    if (bookCount){
        
    for (int i = 0; i <bookCount ; i++)
    {
        printf("\nTitle: %s, Author: %s, Price: %.2f, Quantity: %d",
        titles[i],authors[i],prices[i],quantities[i]);
        // printf("\n");
    }

    }else printf("no books found.\n");
}
// Function to search for a book by its title
void searchBook() {
    char title[TITLE_LEN];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", title); // Read title to search
    for (int i = 0; i < bookCount ; i++) {
        if (strcmp(titles[i], title) == 0) { // Compare with existing titles
            // Print book details if found
            printf("Found: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
                   titles[i], authors[i], prices[i], quantities[i]);
            return; // Exit function after finding
        }
    }
    printf("Book not found.\n"); // Notify if book is not found
}

// Function to update the quantity of a book
void updateQuantity() {
    char title[TITLE_LEN];
    printf("Enter book title to update: ");
    scanf(" %[^\n]", title); // Read title to update
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) { // Check for matching title
            printf("Enter new quantity: ");
            scanf("%d", &quantities[i]); // Update quantity

            printf("quantity updated successfully!: ");
            printf("%s, Author: %s, Price: %.2f, Quantity: %d\n", 
                    titles[i], authors[i], prices[i], quantities[i]);

            return; // Exit function after updating
        }
    }
    printf("Book not found.\n"); // Notify if book is not found
}
// Function to delete a book from stock
void deleteBook() {
    char title[TITLE_LEN];
    printf("Enter book title to delete: ");
    scanf(" %[^\n]", title); // Read title to delete
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) { // Check for matching title
            // Shift all subsequent books down one position
            for (int j = i; j < bookCount - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            bookCount--; // Decrement the book count
            printf("Book deleted.\n");
            return; // Exit function after deletion
        }
    }
    printf("Book not found.\n"); // Notify if book is not found
}

// Function to display the total number of books in stock
void totalBooks() {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += quantities[i]; // Sum quantities of all books
    }
    printf("Total number of books in stock: %d\n", total); // Display total
}