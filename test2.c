#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100  // Maximum number of books
#define TITLE_LEN 50   // Maximum title length
#define AUTHOR_LEN 50  // Maximum author name length

// Global arrays to store book details
char titles[MAX_BOOKS][TITLE_LEN];
char authors[MAX_BOOKS][AUTHOR_LEN];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int bookCount = 0; // Count of current books

int main() {
int i = 0;
    // printf("Enter book title , author ,price and quantity like (titles/author/price/quantity) :");
    // scanf("%[^/]/%[^/]/%f/%d", titles[bookCount], authors[bookCount], &prices[bookCount], &quantities[bookCount]);
    //         printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n", 
    //            titles[i], authors[i], prices[i], quantities[i]);
    return 0;
}
