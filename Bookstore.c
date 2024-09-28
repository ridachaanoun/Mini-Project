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
void clearBuffer();
void addBook();
void displayBooks();
void searchBook();
void updateQuantity();
void deleteBook();
void totalBooks();

int main() {
    int choice;

    do {
    printf("\033[0;33m\n--- Book Stock Management System ---\n\033[0m");
    printf("1. \033[0;34mAdd a Book\033[0m\n");
    printf("2. \033[0;34mDisplay All Books\033[0m\n");
    printf("3. \033[0;34mSearch for a Book\033[0m\n");
    printf("4. \033[0;34mUpdate Book Quantity\033[0m\n");
    printf("5. \033[0;31mDelete a Book\033[0m\n");
    printf("6. \033[0;34mTotal Books in Stock\033[0m\n");
    printf("7. \033[0;34mExit\033[0m\n");
    printf("\033[0;32mEnter your choice: \033[0m"); 
        scanf("%d", &choice);
        clearBuffer();

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

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void addBook() {
    char another;
    
    do {
        if (bookCount < MAX_BOOKS) {
            printf("\033[0;35mEnter book title, author, price, and quantity (title/author/price/quantity) \033[0m: ");
            scanf("%[^/]/%[^/]/%f/%d", titles[bookCount], authors[bookCount], &prices[bookCount], &quantities[bookCount]);
            clearBuffer();

            printf("\033[0;32mBook added successfully!\n\033[0m");
            printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
                   titles[bookCount], authors[bookCount], prices[bookCount], quantities[bookCount]);

            bookCount++;
        } else {
            printf("Maximum book limit reached.\n");
            break;
        }

        printf("\033[0;35mDo you want to add another book? (y/n): \033[0m");
        scanf(" %c", &another); // Note the space before %c to consume any leftover newline
        clearBuffer();

    } while (another == 'y' || another == 'Y');
}
void displayBooks(){
    if (bookCount){
        
    for (int i = 0; i <bookCount ; i++)
    {
    printf("\nTitle: %s, Author: %s, Price: %.2f, Quantity: %d",
       titles[i], authors[i], prices[i], quantities[i]);

        // printf("\n");
    }

    }else printf("no books found.\n");
}
// Function to search for a book by its title
void searchBook() {
    char title[TITLE_LEN];
    printf("\033[0;32mEnter book title to search:\033[0m ");
    scanf(" %[^\n]", title); // Read title to search
    clearBuffer();
    for (int i = 0; i < bookCount ; i++) {
        if (strcmp(titles[i], title) == 0) { // Compare with existing titles
            // Print book details if found
            printf("Found: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
                   titles[i], authors[i], prices[i], quantities[i]);
            return; // Exit function after finding
        }
    }
    printf("\033[0;31mBook not found.\n\033[0m"); // Notify if book is not found
}

// Function to update the quantity of a book
void updateQuantity() {
    char title[TITLE_LEN];
    printf("\033[0;32mEnter book title to update: \033[0m");
    scanf(" %[^\n]", title); // Read title to update
    clearBuffer();
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) { // Check for matching title
            printf("\033[0;32mEnter new quantity:\033[0m ");
            scanf("%d", &quantities[i]); // Update quantity
            clearBuffer();

            printf("\033[0;32mquantity updated successfully!:\033[0m ");
            printf("%s, Author: %s, Price: %.2f, Quantity: %d\n", 
                    titles[i], authors[i], prices[i], quantities[i]);

            return; // Exit function after updating
        }
    }
    printf("\033[0;31mBook not found.\n\033[0m"); // Notify if book is not found
}
// Function to delete a book from stock
void deleteBook() {
    char title[TITLE_LEN];
    printf("\033[0;32mEnter book title to delete:\033[0m");
    scanf(" %[^\n]", title); // Read title to delete
    clearBuffer();
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
            printf("\033[0;32mBook deleted.\033[0m");
            return; // Exit function after deletion
        }
    }
    printf("\033[0;31mBook not found.\n\033[0m"); // Notify if book is not found
}

// Function to display the total number of books in stock
void totalBooks() {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += quantities[i]; // Sum quantities of all books
    }
    printf("Total number of books in stock: %d\n", total); // Display total
}
