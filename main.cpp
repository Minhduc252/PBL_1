#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <conio.h>
#define MAX_NUM_STUDENT 1000
#define MAX_CHAR_INFO 50

typedef struct Student_Information
{
    char Name[MAX_CHAR_INFO];
    int Age;
    char Class[MAX_CHAR_INFO];
    char Address[MAX_CHAR_INFO];
    char Birth[MAX_CHAR_INFO];
    char Gender[MAX_CHAR_INFO];
    char ID[MAX_CHAR_INFO];
    char Email[MAX_CHAR_INFO];
} Student_Information;


typedef struct Node 
{
    Student_Information Info;
    struct Node* next;
} Node;

Node* head = NULL;



int num_Student=0;


void Add_Student();
void Find_Student();
void Out();
void Delete_Student();
void Menu();
void Sep_Name();
void File_Open();
void File_Close();

main()
{
    Menu();

}


// void File_Open()
// {
//     char t_File;
//     printf("----Choose file to access!----\n");
//     t_File=getch();
//     FILE *fp;
//     switch(t_File)
//     {
//         case '1': fp = fopen(URL_FILE_toAccess1,"a+");
//         case '2': fp = fopen(URL_FILE_toAccess2,"a+");
//         ...
//         case 'n': fp = fopen(URL_FILE_toAccessn,"a+");
//     }
// }

// void File_Close()
// {
//     fclose(fp);
// }

void Menu()
{
	printf("-------------- CHOOSE YOUR OPTION---------------------\n");
	printf("******************************************************\n");
	printf("**            1. Add students                       **\n");
	printf("**            2. delete students                    **\n");
	printf("**            3. Find students                      **\n");
	printf("**            4. Print the student list             **\n");
	printf("**            5. Exit                               **\n");
	printf("******************************************************\n");
	char t;
    t= getch();
	switch (t)
	{
		case '1': {
			printf("1. Add students \n");
			Add_Student();
            Menu();
		}
//		case 2:	Delete_Student();
		case '3': 
        {
            printf("3. Find students \n");
            Find_Student();
        }
		case '4': 
        {
            printf("4. Print the student list \n");
            Out();
            
        }
        case '5': 
        {
            printf("Goodbye!");
            exit(1);
        }
		default: 
        {
            printf("Error!!");
            Menu();
        }	
	}
	
}

void Add_Student()
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    Student_Information NewStudent;


    int new_num_Student;
    printf("Enter the number of students to add:  ");
    scanf("%d",&new_num_Student);
    getchar(); // xóa kí tự khi xuống dòng
   

    int index=1;
    while (index <= new_num_Student)
    {
    printf("\n ----The %d student----\n",index);
    printf("Enter the student's name:     ");
    fgets(NewStudent.Name, sizeof(NewStudent.Name), stdin);

    printf("Enter the student's age:      ");
    scanf("%d", &NewStudent.Age);
    getchar();

    printf("Enter the student's gender:   ");
    fgets(NewStudent.Gender, sizeof(NewStudent.Gender), stdin);

    printf("Enter the student's date of birth:    ");
    fgets(NewStudent.Birth, sizeof(NewStudent.Birth), stdin);
    
    printf("Enter the student's class:    ");
    fgets(NewStudent.Class, sizeof(NewStudent.Class), stdin);
    
    printf("Enter the student's address:  ");
    fgets(NewStudent.Address, sizeof(NewStudent.Address), stdin);

   
    newNode->Info = NewStudent;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
    } 
    else 
    {
        Node* currentNode = head;
        while (currentNode->next != NULL) 
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }


    index++;
    num_Student++;
    }

    printf("----Add successfully!---- \n");
}

void Out() 
{
    Node* currentNode = head;
    int index=1;
    while (currentNode != NULL) 
    {
        printf("%d.\tName:\t%s", index++, currentNode->Info.Name);
        printf("\tAge:     \t\t%d\n",currentNode->Info.Age);
        printf("\tGender: \t\t\%s",currentNode->Info.Gender);
        printf("\tClass:  \t\t%s",currentNode->Info.Class);
        printf("\tAddress:\t\t%s",currentNode->Info.Address);
        printf("\n");
        currentNode = currentNode->next;
    }
  Menu();
}

void Find_Student()
{
    Node* currentNode = head;
    char Search_Name[MAX_CHAR_INFO];
    int count=0;
    printf("Enter the name of the student you want to search for: ");
    fgets(Search_Name,MAX_NUM_STUDENT,stdin);
    printf("Result:\n");
   while (currentNode != NULL) 
   {
        if (strcmp(strlwr(currentNode->Info.Name), strlwr(Search_Name)) == 0) // The strcmp function is used to compare 2 strings.  
        {
            count++;
            printf("%d.\t%s", count, currentNode->Info.Name);
            printf("\tAge:    \t\t%d\n",currentNode->Info.Age);
            printf("\tGender: \t\t\%s",currentNode->Info.Gender);
            printf("\tClass:  \t\t%s",currentNode->Info.Class);
            printf("\tAddress:\t\t%s",currentNode->Info.Address);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("%s information not found!!", Search_Name);
    Menu();
    
}

// char Sep_name(char a[MAX_NUM_STUDENT])
// {
//     char *token;
//     char Oname[MAX_CHAR_INFO]; // only name =))
//     token= strtok(Student_List->Name," ");
//     while(token!=NULL)
//     {
//         strcpy(Oname,token);
//         token=strtok(NULL," ");
//     }
//     printf("%s",Oname);
// }
