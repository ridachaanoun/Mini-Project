#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100  // Maximum number of books
#define TITLE_LEN 50   // Maximum title length
#define AUTHOR_LEN 50  // Maximum author name length

// Arrays to store book information
char titles[MAX_BOOKS][TITLE_LEN];
char authors[MAX_BOOKS][AUTHOR_LEN];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int book_count = 0; // Current number of books in stock

// Function to add a book to the stock
void addBook() {
    if (book_count < MAX_BOOKS) { // Check if there's space for a new book
        printf("Enter book title: ");
        scanf(" %[^\n]", titles[book_count]); // Read book title
        printf("Enter author name: ");
        scanf(" %[^\n]", authors[book_count]); // Read author name
        printf("Enter price: ");
        scanf("%f", &prices[book_count]); // Read book price
        printf("Enter quantity: ");
        scanf("%d", &quantities[book_count]); // Read book quantity
        book_count++; // Increment the book count
    } else {
        printf("Stock is full!\n"); // Notify if stock is full
    }
}

// Function to display all available books
void displayBooks() {
    for (int i = 0; i < book_count; i++) {
        // Print details of each book
        printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
               titles[i], authors[i], prices[i], quantities[i]);
    }
}

// Function to search for a book by its title
void searchBook() {
    char title[TITLE_LEN];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", title); // Read title to search
    for (int i = 0; i < book_count; i++) {
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
    for (int i = 0; i < book_count; i++) {
        if (strcmp(titles[i], title) == 0) { // Check for matching title
            printf("Enter new quantity: ");
            scanf("%d", &quantities[i]); // Update quantity
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
    for (int i = 0; i < book_count; i++) {
        if (strcmp(titles[i], title) == 0) { // Check for matching title
            // Shift all subsequent books down one position
            for (int j = i; j < book_count - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            book_count--; // Decrement the book count
            printf("Book deleted.\n");
            return; // Exit function after deletion
        }
    }
    printf("Book not found.\n"); // Notify if book is not found
}

// Function to display the total number of books in stock
void totalBooks() {
    int total = 0;
    for (int i = 0; i < book_count; i++) {
        total += quantities[i]; // Sum quantities of all books
    }
    printf("Total number of books in stock: %d\n", total); // Display total
}

// Main function to drive the program
int main() {
    int choice;
    do {
        // Display menu options
        printf("\n1. Add Book\n2. Display All Books\n3. Search Book\n4. Update Quantity\n5. Delete Book\n6. Total Books\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice
        switch (choice) {
            case 1: addBook(); break; // Add a book
            case 2: displayBooks(); break; // Display all books
            case 3: searchBook(); break; // Search for a book
            case 4: updateQuantity(); break; // Update book quantity
            case 5: deleteBook(); break; // Delete a book
            case 6: totalBooks(); break; // Show total books
            case 7: printf("Exiting...\n"); break; // Exit program
            default: printf("Invalid choice. Please try again.\n"); // Invalid input
        }
    } while (choice != 7); // Continue until exit option is chosen
    
    return 0; // Return success
}
