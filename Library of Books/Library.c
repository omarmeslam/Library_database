#include <stdio.h>
#include <stdlib.h>
#include "Library.h"


char noOfBooks=0, BooksIndex=0;
char* BookStatus[3]={"Available", "Not Available", "Not Found"};

ErrorState_t AddBook(Library_t* arrBook)
{
    ErrorState_t ErrorStatus=OK;

    if((arrBook==NULL) || (noOfBooks>=LIBRSRY_SIZE))
    {
        ErrorStatus=NOK;
    }
    else
    {
        fflush(stdin);
        printf("Enter Book Title: ");
        gets(&arrBook[BooksIndex].BookTitle);
        printf("Enter Author Name: ");
        gets(&arrBook[BooksIndex].AuthorName);
        printf("Enter Book Price: ");
        scanf(" %f", &arrBook[BooksIndex].Price);
        fflush(stdin);
        printf("Enter Publication Year: ");
        scanf("%d", &arrBook[BooksIndex].PublicationYear);
        fflush(stdin);
        printf("Enter Number Of Copies: ");
        scanf("%d", &arrBook[BooksIndex].NumberOfCopies);
        noOfBooks=noOfBooks+arrBook[BooksIndex].NumberOfCopies;
        if(noOfBooks>LIBRSRY_SIZE)
        {
            noOfBooks=LIBRSRY_SIZE;
        }
        strcpy(arrBook[BooksIndex].Status,BookStatus[0]);

        BooksIndex++;
        ErrorStatus=OK;
    }
    return ErrorStatus;
}

void PrintBooks(Library_t* arrBook, int size)
{
    int i;

    printf("\n\n");
    printf("Library Information:- \n");
    printf("Number of Books = %d\n", noOfBooks);
    printf("__________________________________________________________________________________________________________________\n");
    printf("              |                  |      |              |          |            \n");
    printf(" Book Title   |  Author Name     | Year | no.Of Copies | Price    | Status     \n");
    printf("              |                  |      |              |          |            \n");
    printf("~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~|~~~~~~|~~~~~~~~~~~~~~|~~~~~~~~~~|~~~~~~~~~~~~~~~~~\n");
    for(i=0; i<size; i++)
    {
        printf("%13s |%18s| %4d | \t %2d    |   %0.1f   | %s \t   \n",  arrBook[i].BookTitle,
                                                                        arrBook[i].AuthorName,
                                                                        arrBook[i].PublicationYear,
                                                                        arrBook[i].NumberOfCopies,
                                                                        arrBook[i].Price,
                                                                        arrBook[i].Status);
        printf("              |                  |      |              |          |          \n");

    }
}

ErrorState_t BorrowBook(Library_t* arrBook, int id)
{
    ErrorState_t ErrorState=OK;


    if((noOfBooks < LIBRSRY_SIZE) && (id <BooksIndex))
    {
        if(arrBook[id].NumberOfCopies>1)
        {
            arrBook[id].NumberOfCopies--;
            noOfBooks--;
        }
        else if(arrBook[id].NumberOfCopies==1)
        {
            arrBook[id].NumberOfCopies--;
            noOfBooks--;
            strcpy(arrBook[id].Status,BookStatus[1]);
        }
        ErrorState=OK;
    }
    else
    {
        ErrorState=NOK;
    }

    return ErrorState;
}


ErrorState_t DeleteBook(Library_t* arrBook, int id)
{
    char i, ErrorState=NOK;

    if((arrBook==NULL) ||(noOfBooks==0))
    {
        ErrorState = NOK;
    }
    else
    {
        noOfBooks=noOfBooks - (arrBook[id].NumberOfCopies);

        for(i=id; i<BooksIndex; i++)
        {
            arrBook[i] = arrBook[i+1];
        }
        BooksIndex--;
    }

    return ErrorState;
}


ErrorState_t BuyBook(Library_t* arrBook, int id)
{
    ErrorState_t ErrorState=OK;

    if(noOfBooks < LIBRSRY_SIZE)
    {
        if(id <BooksIndex)
        {
            arrBook[id].NumberOfCopies++;
            noOfBooks++;
            ErrorState=OK;
        }
        else if((id >=BooksIndex) && (id <LIBRSRY_SIZE))
        {
            ErrorState_t AddCheck=OK;
            AddCheck=AddBook(arrBook);
            if(AddCheck==OK)
            {
                printf("Addition succeeded\n");
                ErrorState=OK;
            }
            else
            {
                printf("ِِِAddition failed!!\n");
                ErrorState=NOK;
            }
        }

    }
    else
    {
        ErrorState=NOK;
    }

    return ErrorState;
}
