#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"





int main()
{

    printf("-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tWelcome to the Library\n");
	printf("-----------------------------------------------------------------------------------------\n");

    printf("1- Add Book.\n");
    printf("2- Print Library.\n");
    printf("3- Borrow Book.\n");
    printf("4- Delete Book.\n");
    printf("5- Buy Book.\n");
    printf("6- Exit.\n\n");



    while(1)
    {
        int op=0;
        printf("Enter the option: ");
        scanf("%d", &op);
        fflush(stdin);

        if(op==1) /*Add Book*/
        {
            ErrorState_t AddCheck=OK;
            AddCheck=AddBook(BooksLibrary);
            if(AddCheck==OK)
            {
                printf("Addition succeeded\n");
            }
            else
            {
                printf("ِِِAddition failed!!, Library is Fully\n");
            }
        }
        else if(op==2)/*Print Library*/
        {
            if(noOfBooks>0)
            {
                PrintBooks(BooksLibrary,BooksIndex);
            }
            else
            {
                printf("No Books in the Library\n");
            }

        }
        else if(op==3)/*Borrow Book*/
        {
            int bookID=0;
            ErrorState_t BorrowCheck=OK;
            printf("Enter Book ID to borrow: ");
            scanf("%d", &bookID);
            fflush(stdin);

            BorrowCheck=BorrowBook(BooksLibrary,bookID);
            if(BorrowCheck==OK)
            {
                printf("%s", BooksLibrary[bookID].Status);
            }
            else
            {
                printf("%s", BookStatus[2]);
            }
        }
        else if(op==4)/*Delete Book*/
        {
            int bookID=0;
            printf("Enter Book ID to delete: ");
            scanf("%d", &bookID);
            fflush(stdin);

            if(noOfBooks>0)
            {
                DeleteBook(BooksLibrary,bookID);
                printf("Deleted Successfully\n");
            }
            else
            {
                printf("Library Empty\n");
            }

        }
        else if(op==5)/*Buy Book*/
        {
            ErrorState_t BuyCheck=OK;
            int bookID=0;
            printf("Enter Book ID to buy: ");
            scanf("%d", &bookID);
            fflush(stdin);
            BuyCheck=BuyBook(BooksLibrary,bookID);

            if(BuyCheck==OK)
            {
                 printf("Buyed Successfully\n");
            }
            else
            {
                printf("Library is Full\n");
            }
        }
        else if(op==6)/*Exit*/
        {
            break;
        }

        fflush(stdin);
    }



    return 0;
}
