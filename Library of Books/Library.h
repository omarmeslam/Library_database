
#define LIBRSRY_SIZE  100

extern char noOfBooks;
extern char BooksIndex;
extern char* BookStatus[3];


typedef struct library{

    char BookTitle[100];
    char AuthorName[100];
    char Status[50];
    int PublicationYear;
    int NumberOfCopies;
    float Price;

}Library_t;

typedef enum{
    OK,
    NOK
}ErrorState_t;

Library_t BooksLibrary[LIBRSRY_SIZE];


ErrorState_t AddBook(Library_t* arrBook);
void PrintBooks(Library_t* arrBook, int size);
ErrorState_t DeleteBook(Library_t* arrBook, int id);
ErrorState_t BorrowBook(Library_t* arrBook, int id);
ErrorState_t BuyBook(Library_t* arrBook, int id);
