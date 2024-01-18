#include <stdio.h>
#include <conio.h>

void addbook ();
void showbook ();
void searchbook ();
void updatebook ();
void delbook ();
void issuebook();
void exit ();

struct book
{
    int sn;
    int isbn;
    char name [20];
    int ed;
    char author[20];
    int rs;
};
struct book b[5];

void main ()
{
    char another = 'Y', choice, choice1;


    while (another == 'Y')
    {
    printf ("\n\n1. Add Book (A)\n2. Show Book (B)\n3. Search Book (C)\n4. Update Book Name (D)\n5. Delete book (E)\n6. Issue Book (F)\n7. Exit (G)\nChoice: ");
    fflush (stdin);
    choice = getche ();

    if (choice == 'A')
    addbook ();
    else if (choice == 'B')
    showbook();
    else if (choice == 'C')
    searchbook ();
    else if (choice == 'D')
    updatebook ();
    else if (choice == 'E')
    delbook();
    else if (choice == 'F')
    issuebook ();
    else if (choice == 'G')
        exit ();
    else
    printf ("\nInvalid Choice.");

    printf ("\n\nContinue (Y/N): ");
    fflush (stdin);
    another = getche ();

    }
}

void addbook ()
{
    int i,j;
    char abchoice;
    FILE *p;
    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","w");

    if (p == NULL)
    {
        printf ("\nFile not created.");
        exit (1);
    }

    for (i=0,j=1;i<=4;i++,j++)
    {
    printf ("\nSerial Number %d: ", j);
    scanf ("%d", & b[i].sn);
    printf ("Enter isbn %d: ", j);
    scanf ("%d", & b[i].isbn);
    printf ("Enter Name %d: ", j);
    scanf ("%s", b[i].name);
    printf ("Enter Edition %d: ",j);
    scanf ("%d", & b[i].ed);
    printf ("Enter Author Name %d: ",j);
    scanf ("%s", & b[i].author);
    printf ("Enter Reserved Status %d: ", j);
    scanf ("%d", &b[i].rs);


    fprintf (p,"%d %d %s %d %s %d\n", b[i].sn, b[i].isbn, b[i].name, b[i].ed, b[i].author, b[i].rs);

    printf ("Add book (Y/N): ");
    abchoice = getche ();

    if (abchoice == 'N')
        break;
    }

   fclose (p);
}

void showbook ()
{
 int i=0;
 FILE *p;

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","r");

    while (fscanf (p,"%d %d %s %d %s %d\n", &b[i].sn, &b[i].isbn, b[i].name, &b[i].ed, b[i].author, &b[i].rs) != EOF)
    {
     printf ("\n%d %d %s %d %s %d", b[i].sn, b[i].isbn, b[i].name, b[i].ed, b[i].author, b[i].rs);
     i++;
    }

    fclose (p);

}

void searchbook ()
{
 int i=0;
 FILE *p;
 p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","r");

 while (fscanf (p,"%d %d %s %d %s %d", &b[i].sn,&b[i].isbn,b[i].name,&b[i].ed,b[i].author,&b[i].rs) != EOF)
    i++;

char sbchoice;
int j,k,l,sva,found = 0;
char svbc [20];

printf ("\nSearch by (ISBN(A) or Name(B) or Author(C)): ");
sbchoice = getche ();

printf ("\nEnter Search Value: ");
if (sbchoice == 'A')
{
scanf ("%d",&sva);

for (j=0;j<=4;j++)
    {
        if (b[j].isbn == sva)
        {
            found = 1;
            printf ("Present");
            break;
        }

        else if (found == 0 && j==4)
            printf ("Absent");
    }
}
else if (sbchoice == 'B')
{
scanf ("%s", svbc);

for (k=0;k<=4;k++)
    {
        if (strcmp (b[k].name, svbc) == 0)
            {
            printf ("Present");
            break;
            }
        else if (strcmp (b[k].name, svbc) != 0 && k==4)
            printf ("Absent");
    }
}
else if (sbchoice == 'C')
{
scanf ("%s", svbc);

  for (l=0;l<=4;l++)
    {
        if (strcmp (b[l].author, svbc) == 0)
        {
        printf ("Present");
        break;
        }

        else if (strcmp (b[l].author, svbc) != 0 && l==4)
            printf ("Absent");
    }

}


}

void updatebook ()
{
    FILE *p;
    int i=0, j, k;
    char sv[20], nname [20];

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","r");

    while (fscanf (p,"%d %d %s %d %s %d", &b[i].sn, &b[i].isbn, b[i].name, &b[i].ed, b[i].author, &b[i].rs) != EOF)
        i++;
    fclose (p);

    printf ("\nEnter old name: ");
    scanf ("%s", sv);
    printf ("Enter new name: ");
    scanf ("%s",nname);

    for (j=0;j<=4;j++)
    {
        if (strcmp (b[j].name,sv) == 0)
            strcpy (b[j].name,nname);
    }

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","w");

    for (k=0;k<=4;k++)
    {
        fprintf (p, "%d %d %s %d %s %d\n", b[k].sn, b[k].isbn, b[k].name, b[k].ed, b[k].author, b[k].rs);
    }

    fclose (p);
}

void issuebook ()
{
    FILE *p;
    int i=0,j,k;
    char sv [15];

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","r");

    while (fscanf (p,"%d %d %s %d %s %d", &b[i].sn, &b[i].isbn, b[i].name, &b[i].ed, b[i].author, &b[i].rs) != EOF)
        i++;

    fclose (p);

    printf ("\nEnter book name for issue: ");
    scanf ("%s", sv);

    for (j=0;j<=4;j++)
    {
        if (strcmp(b[j].name,sv) == 0 && b[j].rs == 1)
        {
         b[j].rs = 0;
         printf ("Book Issued");
        }

        else if (strcmp(b[j].name,sv) == 0 && b[j].rs == 0)
            printf ("Not Available.");
    }

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","w");

    for (k=0;k<=4;k++)
    {
        fprintf (p,"%d %d %s %d %s %d\n", b[k].sn, b[k].isbn, b[k].name, b[k].ed, b[k].author, b[k].rs);
    }

    fclose (p);

}

void exit ()
{
    exit (1);
}

void delbook ()
{

   int i=0,j,a;
    char sv [20];
    FILE *p;

    p = fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","r");

    while (fscanf (p,"%d %d %s %d %s %d", &b[i].sn, &b[i].isbn, b[i].name, &b[i].ed, b[i].author, &b[i].rs) != EOF)
        i++;
    fclose (p);

    printf ("\nEnter the name of the book to be deleted: ");
    scanf ("%s", sv);

    fopen ("C:/Users/musta/OneDrive/Documents/M/UG/FIRST/A/PF/R/SBT (CODE BLOCK)/2/2.9/PROJECT/BOOKS.txt","w");

    for (j=0;j<=4;j++)
    {
        a = strcmp (b[j].name,sv);

        if (a==0)
            continue;
        else
        fprintf (p,"%d %d %s %d %s %d\n", b[j].sn, b[j].isbn, b[j].name, b[j].ed, b[j].author, b[j].rs);

    }
    fclose (p);
}






