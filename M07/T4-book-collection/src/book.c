#include "book.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Initializes a book for the collection.
 *
 * \param p_book The book to be initialized.
 * \param p_id The book identifier string
 * \param p_title The book title string
 * \param p_author The book author string
 * \param release The release date of the book
 * \returns 0 if the book identifier is not valid. The identifier is invalid
 * 			  if the stated book identifier has more than 9 characters.
 * \returns 1 if the book can be initialized.
 */
int init_book(struct book *p_book,
			  const char *p_id,
			  const char *p_title,
			  const char *p_author,
			  struct date release)
{
	if (strlen(p_id) < 10) {
		for (unsigned int i = 0; i < strlen(p_id)+1; i++) 
		{
			p_book->id[i] = p_id[i];
		}
	}
	else{return 0;}

	p_book->author = malloc(strlen(p_author) * (sizeof(char)) + 1);
	strcpy(p_book->author, p_author);

	p_book->title = malloc(strlen(p_title) * (sizeof(char)) + 1);
	strcpy(p_book->title, p_title);

	p_book->release_date.day = release.day;
	p_book->release_date.month = release.month;
	p_book->release_date.year = release.year;

	return 1;
}

/**
 * \brief Adds a book to the collection. The collection is an array, and the
 * array should be reallocated to store the new book.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the current collection
 * \param new_book The new book to be copied to the collection
 * \return A pointer to enlarged collection
 */
struct book *add_to_collection(struct book *collection,
							   unsigned int size,
							   struct book new_book)
{
	struct book book_2;
	init_book(&book_2, new_book.id, new_book.title, new_book.author, new_book.release_date);
	struct book *new = realloc(collection, sizeof(struct book) * (size+1));
	if(new == NULL){
		return NULL;
	}
	new[size] = book_2;
	return new;
}
