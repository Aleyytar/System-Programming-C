#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct book
{
    int book_id[4];
    char book_name[32];
    char writer[32];
    char publisher[32];
    int number_of_borrowing;
    int status;
} book_t;




typedef struct student
{
    int stu_id[6];
    char stu_name[32];
    int total_book_borrowed;
    char password[8];
    book_t *book;
} student_t;
typedef struct librarian
{
    int lib_id[6];
    char librarian_name[32];
    char password[8];

} librarian_t;



int main()
{
    FILE *fp;
    char buff[255];
    book_t *books;
    student_t *students;
    librarian_t *librarians;
    int stu_id[6];
    char stu_name[32];
    int total_book_borrowed;
    char password[8];
    int book_id;
    int total_books =0;
    int total_students =0;
    int total_librarians =0;
    int student = 2; // student 1-> student, student 0-> librarian
    //fp = fopen("student.bin", "r");
    memset(stu_name, 0, 32);
    memset(password, 0, 8);
    //fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &stu_id[0],&stu_id[1],&stu_id[2],&stu_id[3],&stu_id[4],&stu_id[5],stu_name,&total_book_borrowed,password,&book_id);


   // printf("%d  %d  %d  %d  %d  %d  %s  %d  %s  %d", stu_id[0],stu_id[1],stu_id[2],stu_id[3],stu_id[4],stu_id[5],stu_name,total_book_borrowed,password,book_id);
    char name[32];

    memset(name, 0, 32);
    char pswd[8];
    memset(pswd, 0, 8);
    int user_name_correct = 0;
    int fileEnd = 1;








/*


     fp = fopen("student.bin", "r");
            int i = 0;
            fileEnd = 0;

            memset(stu_name, 0, 32);
            memset(password, 0, 8);


                student_t * tstudent =  malloc(sizeof(student_t));
                printf("%d\n",sizeof(student_t));

            fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &tstudent->stu_id[0],&tstudent->stu_id[1],&tstudent->stu_id[2],&tstudent->stu_id[3],&tstudent->stu_id[4],&tstudent->stu_id[5],
                            tstudent->stu_name,&tstudent->total_book_borrowed,tstudent->password,&tstudent->book);
            students =malloc( sizeof(student_t)*(i+1));

            while(fileEnd!=EOF)
            {

               students[i] = *tstudent;
                //memcpy(&students[i],tstudent, sizeof(student_t));
                i++;
                tstudent= malloc( sizeof(student_t));
                total_students = i;
                students =realloc(students, (i+2)*sizeof(student_t));

                memset(stu_name, 0, 32);
                memset(password, 0, 8);
                fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &tstudent->stu_id[0],&tstudent->stu_id[1],&tstudent->stu_id[2],&tstudent->stu_id[3],&tstudent->stu_id[4],&tstudent->stu_id[5],
                                tstudent->stu_name,&tstudent->total_book_borrowed,tstudent->password,&tstudent->book);
printf("i= %d %d\n", i, fileEnd);
            }

            FILE *fp3;
                    fp3 = fopen("s2.bin", "w");
            for(int i = 0; i< total_students; i++)
            {

                        fileEnd =fprintf(fp3, "%d %d %d %d %d %d %s %d %s %d\n", students[i].stu_id[0],students[i].stu_id[1],students[i].stu_id[2],students[i].stu_id[3],students[i].stu_id[4],
                                         students[i].stu_id[5],students[i].stu_name,students[i].total_book_borrowed,students[i].password, &students[i].book[0]);

                                         printf("%d %d %d %d %d %d %s %d %s %d\n", students[i].stu_id[0],students[i].stu_id[1],students[i].stu_id[2],students[i].stu_id[3],students[i].stu_id[4],
                                         students[i].stu_id[5],students[i].stu_name,students[i].total_book_borrowed,students[i].password, &students[i].book[0]);

            }


*/

printf("son");








    while(1)
    {
        printf("\nKullanici adini giriniz\n");
        // read 32 character next to each other with \n
        fgets(name, 32, stdin);
        //remove the last newline
        if (name[strlen (name) - 1] == '\n')
            name[strlen (name) - 1] = 0;
        fileEnd = 0;
        fp = fopen("student.bin", "r");
        while(user_name_correct == 0 && fileEnd!=EOF)
        {

            memset(stu_name, 0, 32);
            memset(password, 0, 8);
            fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &stu_id[0],&stu_id[1],&stu_id[2],&stu_id[3],&stu_id[4],&stu_id[5],stu_name,&total_book_borrowed,password,&book_id);
            if(strcmp(stu_name, name)==0)
            {
                user_name_correct = 1;
                student = 1;
            }
        }

        if(user_name_correct != 1)
        {
            fclose(fp);
            fp = fopen("librarian.bin", "r");
            fileEnd = 0;
            while(user_name_correct == 0 && fileEnd!=EOF)
            {

                memset(stu_name, 0, 32);
                memset(password, 0, 8);
                fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%s", &stu_id[0],&stu_id[1],&stu_id[2],&stu_id[3],&stu_id[4],&stu_id[5],stu_name,password);
                if(strcmp(stu_name, name)==0)
                {
                    user_name_correct = 1;
                    student = 0;
                }
            }
            fclose(fp);
        }



        if(strcmp(stu_name, name) == 0)
        {
            memset(pswd, 0, 8);
            printf("Enter password \n");
            fgets(pswd, 8, stdin);
            if (pswd[strlen (pswd) - 1] == '\n')
                pswd[strlen (pswd) - 1] = 0;


            if(strcmp(pswd, password) == 0)
            {
                printf("Login succced\n");
                break;

            }
            else
                printf("Wrong password\n");
        }
        else
        {
            printf("User does not exists \n");
        }
    }
    if(student == 0)
        printf("Hello librarian! %s \n", name);
    else if(student == 1)
        printf("Hello student! %s \n", name);

    if(student == 1)
    {
        int selection;

        printf("for list the books press 1\n");
        printf("for borrow books and return the borrowed book press 2\n");
        printf("for log out press 3\n");
        printf("Enter your choice: ");
        scanf("%d",&selection);
        int book_id[4];
        char book_name[32];
        char writer[32];
        char publisher[32];
        int number_of_borrowing;
        int status;
        if(selection == 1)
        {
/*

            fp = fopen("book.bin", "r");
            int i = 0;
            fileEnd = 0;
            memset(book_name, 0, 32);
            memset(publisher, 0, 32);
            memset(writer, 0, 32);

            fileEnd =fscanf(fp, "%d%d%d%d%s%s%s%d%d", &book_id[0],&book_id[1],&book_id[2],&book_id[3],book_name, writer, publisher,&number_of_borrowing,&status);
            books =malloc(sizeof(book_t));
            while(fileEnd!=EOF)
            {


                printf("%d. book with id %d%d%d%d name: %s,\twriter: %s,\tpublisher: %s,\tnumber of borrowing: %d,\tstatus: %d\n",i,book_id[0],book_id[1],book_id[2],book_id[3],book_name, writer, publisher,number_of_borrowing,status);

                book_t * tbook;

                tbook->book_id[0] = book_id[0];
                tbook->book_id[1] = book_id[1];
                tbook->book_id[2] = book_id[2];
                tbook->book_id[3] = book_id[3];
                printf("1");

                strcpy(tbook->book_name, book_name);
                printf("1.2");
                strcpy(tbook->writer, writer);
                printf("1.3");
                strcpy(tbook->publisher, publisher);
                printf("1.4");
                tbook->number_of_borrowing = number_of_borrowing;
                printf("1.");
                tbook->status = status;
                printf("2");
                books[i] = *tbook;
                printf("3");
                i++;
                total_books = i;
                books =realloc(books, (i+1)*sizeof(book_t));
                memset(book_name, 0, 32);
                memset(publisher, 0, 32);
                memset(writer, 0, 32);
                printf("4");
                fileEnd =fscanf(fp, "%d%d%d%d%s%s%s%d%d", &book_id[0],&book_id[1],&book_id[2],&book_id[3],book_name, writer, publisher,&number_of_borrowing,&status);

            }

*/

            fp = fopen("book.bin", "r");
            int i = 0;
            fileEnd = 0;



                 book_t * tbook =  malloc(sizeof(book_t));

              fileEnd =fscanf(fp, "%d%d%d%d%s%s%s%d%d", &tbook->book_id[0],&tbook->book_id[1],&tbook->book_id[2],&tbook->book_id[3],tbook->book_name, tbook->writer, tbook->publisher,&tbook->number_of_borrowing,&tbook->status);



              books =malloc( sizeof(book_t)*(i+1));

            while(fileEnd!=EOF)
            {

               books[i] = *tbook;


                printf("%d. book with id %d%d%d%d name: %s,\twriter: %s,\tpublisher: %s,\tnumber of borrowing: %d,\tstatus: %d\n",i,books[i].book_id[0],books[i].book_id[1],books[i].book_id[2],books[i].book_id[3],books[i].book_name, books[i].writer, books[i].publisher,books[i].number_of_borrowing,books[i].status);

                //memcpy(&students[i],tstudent, sizeof(student_t));
                i++;
                tbook= malloc( sizeof(book_t));
                total_books= i;
                books =realloc(books, (i+2)*sizeof(book_t));


              fileEnd =fscanf(fp, "%d%d%d%d%s%s%s%d%d", &tbook->book_id[0],&tbook->book_id[1],&tbook->book_id[2],&tbook->book_id[3],tbook->book_name, tbook->writer, tbook->publisher,&tbook->number_of_borrowing,&tbook->status);

            }

        }
        else if(selection == 2)
        {

            FILE *fp2;
            fp2 = fopen("student.bin", "w");
            for(int i = 0; i< total_books; i++)
            {
                // this book is previously borrowed and it is returning now
                if(&books[i] == book_id)
                {
                    FILE *fp3;
                    fp3 = fopen("books.bin", "w");
                    /// status 0 not available, status 1 available
                    books[i].status = 1; /// this book is returned and available
                    fileEnd =fscanf(fp3, "%d%d%d%d%s%s%s%d%d", books[i].book_id[0],books[i].book_id[1],books[i].book_id[2],books[i].book_id[3],
                            books[i].book_name, books[i].writer, books[i].publisher,books[i].number_of_borrowing,books[i].status);

                }
            }

            fileEnd =fprintf(fp2, "%d%d%d%d%d%d%s%d%s%d", stu_id[0],stu_id[1],stu_id[2],stu_id[3],stu_id[4],stu_id[5],stu_name,total_book_borrowed,password, &books[0]);



        }
        else if(selection == 3)
        {

        }
        /*
        */
    }
    /*


    Listing all books
     Searching a book
     Update book information
     Adding a new book
     Deleting a book saved in the system*/


    return 0;
}





/*
----------

            fp = fopen("student.bin", "r");
            int i = 0;
            fileEnd = 0;

            memset(stu_name, 0, 32);
            memset(password, 0, 8);


                student_t * tstudent1;
            fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &tstudent1->stu_id[0],&tstudent1->stu_id[1],&tstudent1->stu_id[2],&tstudent1->stu_id[3],&tstudent1->stu_id[4],&tstudent1->stu_id[5],tstudent1->stu_name,&tstudent1->total_book_borrowed,tstudent1->password,&tstudent1->book_id);

            students =malloc(students, sizeof(student_t));
            students[i] = tstudent1;
            i++;
            while(fileEnd!=EOF)
            {
                student_t * tstudent;
                students[i] = tstudent;
                i++;
                total_students = i;
                students =malloc(students, (i+1)*sizeof(book_t));

                memset(stu_name, 0, 32);
                memset(password, 0, 8);
                fileEnd =fscanf(fp, "%d%d%d%d%d%d%s%d%s%d", &tstudent->stu_id[0],&tstudent->stu_id[1],&tstudent->stu_id[2],&tstudent->stu_id[3],&tstudent->stu_id[4],&tstudent->stu_id[5],
                                tstudent->stu_name,&tstudent->total_book_borrowed,tstudent->password,&tstudent->book_id);

            }
            FILE *fp3;
                    fp3 = fopen("books.bin", "w"));
            for(int i = 0; i< total_books; i++)
            {

                        fileEnd =fprintf(fp2, "%d%d%d%d%d%d%s%d%s%d", students[i].stu_id[0],students[i].stu_id[1],students[i].stu_id[2],students[i].stu_id[3],students[i].stu_id[4],
                                         students[i].stu_id[5],students[i].stu_name,students[i].total_book_borrowed,students[i].password, &students[i].books[0]);

                }
            }

            */
