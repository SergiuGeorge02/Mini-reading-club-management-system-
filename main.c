#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE 1000
// Struct for searching and displaying members from the text file
struct Reading_club
{
    char first_name[30];
    char last_name[30];
    char gender[10];
    char age[5];

};
//Menu of the program
void console_menu()
{
    printf("Please select a choice from the menu of my program:\n");
    printf("  1. Add a reader to the database.\n");
    printf("  2. Show detalis of all members involved in the reading club.\n");
    printf("  3. Display all readers by a specific gender.\n");
    printf("  4. Search a reader by his last name.\n");
    printf("  5. Search a reader by his first name.\n");
    printf("  6. Delete a specific reader from the database if u know his or her first name and last name.\n");
    printf("  7. Close the program.\n");
}

//Option 2-->show all members from the database
void show_all_members(FILE* fp)
{

    fp=fopen("..\\file.txt","r" );
    if(fp==NULL)
    {
        perror("File is empty");
        exit(1);
    }
    char detailsofmembers[300];
    while(fgets(detailsofmembers,sizeof detailsofmembers,fp))
    {
        printf(detailsofmembers);


    }
    fclose(fp);

}
//Option 1-->add a member to the database
void add_reader(FILE *fp)
{

    int k=-1;
    fp=fopen("..\\file.txt", "a+");
    fputs("\n", fp);
    char c[50];

    printf("Please introduce the reader's first name:\n");
    scanf ("%s", c);
    if (c[0]>='a' && c[0]<='z')
        c[0]-=32;
    fputs(c, fp);

    fputs(" ", fp);
    printf("Please introduce the reader's last name:\n");
    scanf ("%s", c);
    if (c[0]>='a' && c[0]<='z')
        c[0]-=32;
    fputs(c, fp);

    printf("Please introduce 1 if the reader is male or 2 if the reader if female:\n");
    fputs(" ", fp);
    while(k!=1 && k!=2)
    {
        scanf ("%d", &k);
        if(k==1)
            fputs("male",fp);
        else if(k==2)
            fputs("female",fp);
        else
            printf("There is no such option: Please introduce 1 if the reader is male or 2 if the reader if female:\n");
    }

    fputs(" ", fp);
    printf("Please introduce the reader's age:\n");
    scanf ("%s", c);
    fputs(c, fp);

    fclose(fp);
}
//Size of our text file
int size_of_file ()
{
    FILE *p=fopen("..\\file.txt", "r");
    int k=0;
    char file[MAX_FILE];
    char c;

    if (p == NULL)
    {
        printf("The file is empty %s");
        return 0;
    }

    for (c = getc(p); c != EOF; c = getc(p))
        if (c == '\n')
            k++;
    fclose(p);
    return k;
}
//Option 3-->display all members by gender
void display_all_members_by_gender(FILE* fp)
{
    int k=size_of_file()+1;
    struct Reading_club s[k];
    fp=fopen("..\\file.txt","r");

    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    for(int i=0; i<k; i++)
    {
        char c[200];
        fgets(c,sizeof(c),fp);
        char*p=strtok(c," ");
        int contor=1;
        while(p!=NULL)
        {
            if(contor==1)
                strcpy(s[i].first_name,p);
            else if(contor==2)
                strcpy(s[i].last_name,p);
            else if(contor==3)
               strcpy(s[i].gender,p);
            else if(contor==4)
                strcpy(s[i].age,p);

            contor++;
            p=strtok(NULL," ");
        }

    }
    printf("Please introduce 1 if you want to display all male members or 2 if you want to display all female members :\n");
    int gender=0,ok=0;
    char m[50]="male";
    char f[50]="female";
    char t[50]="";

    while(gender!=1 && gender!=2)

    {
        scanf ("%d", &gender);
        if(gender==1)
            for (int i=0; i<k; i++)

            {


                if(strcmp(s[i].gender, m)==0)
                {
                    printf("%s %s %s %s",s[i].first_name,s[i].last_name,s[i].gender,s[i].age);


                }

            }
        else if(gender==2)
            for (int i=0; i<k; i++)
            {
                if(strcmp(s[i].gender,f)==0)
                {
                    printf("%s %s %s %s",s[i].first_name,s[i].last_name,s[i].gender,s[i].age);

                }

            }
       else
            printf("There is no such option: Please introduce 1 if you want to display all male members or 2 if you want to display all female memmbers:\n");
    }
    fclose(fp);
    }
//option 4-->search members from database by the last name
void search_by_last_name(FILE* fp)
{
    int k=size_of_file()+1;
    struct Reading_club s[k];
    fp=fopen("..\\file.txt","r");

    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    for(int i=0; i<k; i++)
    {
        char c[200];
        fgets(c,sizeof(c),fp);
        char*p=strtok(c," ");
        int contor=1;
        while(p!=NULL)
        {
            if(contor==1)
                strcpy(s[i].first_name,p);
            else if(contor==2)
                strcpy(s[i].last_name,p);
            else if(contor==3)
                strcpy(s[i].gender,p);
            else if(contor==4)
                strcpy(s[i].age,p);

            contor++;
            p=strtok(NULL," ");
        }

    }
    printf("Please introduce the last name of the reader you are searching for:\n");

    int ok=0;
    char search_last_name[50];
    scanf("%s",search_last_name);
    for (int i=0; i<k; i++)
    {
        if(strcmp(s[i].last_name,search_last_name)==0)
        {
            printf("%s %s %s %s",s[i].first_name,s[i].last_name,s[i].gender,s[i].age);
            ok=1;

        }

    }
    if (ok==0)
        printf("There are no readers with this last name");
    fclose(fp);
}
//Option 5-->search members from database by the first name
void search_by_first_name(FILE* fp)
{
    int k=size_of_file()+1;
    struct Reading_club s[k];
    fp=fopen("..\\file.txt","r");

    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    for(int i=0; i<k; i++)
    {
        char c[200];
        fgets(c,sizeof(c),fp);
        char*p=strtok(c," ");
        int contor=1;
        while(p!=NULL)
        {
            if(contor==1)
                strcpy(s[i].first_name,p);
            else if(contor==2)
                strcpy(s[i].last_name,p);
            else if(contor==3)
                strcpy(s[i].gender,p);
            else if(contor==4)
                strcpy(s[i].age,p);

            contor++;
            p=strtok(NULL," ");
        }

    }
    printf("Please introduce the first name of the reader you are searching for:\n");

    int ok=0;
    char search_first_name[50];
    scanf("%s",search_first_name);
    for (int i=0; i<k; i++)
    {
        if(strcmp(s[i].first_name,search_first_name)==0)
        {
            printf("%s %s %s %s",s[i].first_name,s[i].last_name,s[i].gender,s[i].age);
            ok=1;

        }

    }
    if (ok==0)
        printf("There are no readers with this first name");
    fclose(fp);
}
//Option 6-->delete a member from the database if u know the first and last name
void delete_by_first_and_last_name(FILE *fp)
{
    int k=size_of_file()+1;
    struct Reading_club s[k];
    fp=fopen("..\\file.txt","r");

    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    for(int i=0; i<k; i++)
    {
        char c[200];
        fgets(c,sizeof(c),fp);
        char*p=strtok(c," ");
        int contor=1;
        while(p!=NULL)
        {
            if(contor==1)
                strcpy(s[i].first_name,p);
            else if(contor==2)
                strcpy(s[i].last_name,p);
            else if(contor==3)
                strcpy(s[i].gender,p);
            else if(contor==4)
                strcpy(s[i].age,p);

            contor++;
            p=strtok(NULL," ");
        }

    }
    fclose(fp);
    char first_name[30], last_name[30];
    printf("Please introduce the reader you want to delete first name:\n");
    scanf("%s",first_name);
    printf("Please introduce the reader you want to delete last name:\n");
    scanf("%s",last_name);
    int ok=0;
    fp=fopen("..\\file.txt","w");
    for (int i=0; i<k; i++)
    {
        if(strcmp(s[i].first_name,first_name)!=0 || strcmp(s[i].last_name,last_name)!=0)
        {
            ok=1;
            fputs(s[i].first_name, fp);
            fputs(" ", fp);
            fputs(s[i].last_name, fp);
            fputs(" ", fp);
            fputs(s[i].gender, fp);
            fputs(" ", fp);
            fputs(s[i].age, fp);

        }

    }

    if (ok==0)
        printf("There are no readers with this name so there is nothing to delete\n");
    else
        printf("The reader was successfully deleted from the database\n");

    fclose(fp);
}

//main function
int main()
{
    FILE *fp;

    int reader;
    console_menu();
    scanf("%d", &reader);

    while (reader != 7)
    {
        if (reader==1)
        {
            add_reader(fp);
            printf("The reader was successfully introduced into the database!");
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);

        }
        else if (reader==2)
        {
            show_all_members(fp);
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);
        }
        else if (reader==3)
        {
            display_all_members_by_gender(fp);
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);
        }
        else if (reader==4)
        {
            search_by_last_name(fp);
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);
        }
        else if (reader==5)
        {
            search_by_first_name(fp);
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);
        }
        else if (reader==6)
        {
            delete_by_first_and_last_name(fp);
            printf("\n\n");
            console_menu();
            scanf("%d", &reader);
        }

    }
}