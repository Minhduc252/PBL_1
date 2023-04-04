#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <conio.h>
#include <time.h>


#define MAX_NUM_STUDENT 1000
#define MAX_CHAR_INFO 50

typedef struct Student_Information
{
    char Name[MAX_CHAR_INFO];
    char OName[MAX_CHAR_INFO];
    int Age;
    long ID;
    char Email[MAX_CHAR_INFO];
    char Class[MAX_CHAR_INFO];
    char Address[MAX_CHAR_INFO];
    char Birth[MAX_CHAR_INFO];
    char Gender[MAX_CHAR_INFO];
} Student_Information;


typedef struct Node 
{
    Student_Information Info;
    Node* next;
    Node* prev;

} Node;

Node* head = NULL;


int num_Student=0;


void Add_Student();
void Find_Student_name();
void Find_Student_ID();
void Out(); 
void Delete_Student();
void Menu();
long long Create_ID(Node* current_ref);
bool Is_Duplicate(long long key, Node* head_ref,Node* current);
char* get_last_name(char *name);

main()
{
    Menu();
}

void Menu()
{
	printf("-------------- CHOOSE YOUR OPTION---------------------\n");
	printf("******************************************************\n");
    printf("**            0. Exit                               **\n");
	printf("**            1. Add students                       **\n");
	printf("**            2. delete students                    **\n");
	printf("**            3. Find students                      **\n");
	printf("**            4. Print the student list             **\n");
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
            printf("\n\n1. search by name\n2.search by ID\n");
            char a;
            a=getch();
            switch(a)
            {
                case '1':
                {
                    printf("3.1. Find students by name \n");
                    Find_Student_name();
                } 
                case '2':
                {
                    printf("3.2. Find students by ID \n");
                    Find_Student_ID();
                }
            }
            
        }
		case '4': 
        {
            printf("4. Print the student list \n");
            Out();
            
        }
        case '0': 
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
    int num_to_add;
    printf("Enter the number of students to add:  ");
    scanf("%d", &num_to_add);
    getchar();

    for (int i = 0; i < num_to_add; i++) {
        Student_Information new_student;

        printf("Enter the student's name:     ");
        fgets(new_student.Name, sizeof(new_student.Name), stdin);

        printf("Enter the student's age:      ");
        scanf("%d", &new_student.Age);
        getchar();

        printf("Enter the student's gender:   ");
        fgets(new_student.Gender, sizeof(new_student.Gender), stdin);

        printf("Enter the student's date of birth:    ");
        fgets(new_student.Birth, sizeof(new_student.Birth), stdin);
        
        printf("Enter the student's class:    ");
        fgets(new_student.Class, sizeof(new_student.Class), stdin);
        
        printf("Enter the student's address:  ");
        fgets(new_student.Address, sizeof(new_student.Address), stdin);
        printf("\n");

        Node* new_node = (Node*) malloc(sizeof(Node));
        Node* last = head;
        new_node->Info = new_student;
        new_node->next = NULL; // chèn theo kiểu append

        if (last == NULL) { 
            new_node->prev = NULL; 
            head = new_node; 
        } 
        else{
            while(last->next!=NULL)
            {
                last=last->next;
            }
            last->next=new_node;
            new_node->prev=last;
        }
        new_node->Info.ID=Create_ID(new_node);
        sprintf(new_node->Info.Email, "%lld@sv.dut.udn.com", new_node->Info.ID); // tạo email 
    }
        printf("Added %d students successfully!\n", num_to_add);
}

void Out()
{
    int index=1;
    Node* current=head;
    while (current != NULL) { 
        printf("%d.\tName:\t%s", index++, current->Info.Name);
        printf("\tOname:    \t\t%lld\n",current->Info.OName);
        printf("\tID:    \t\t%lld\n",current->Info.ID);
        printf("\temail:  \t\t%s\n",current->Info.Email);
        printf("\tAge:    \t\t%d\n",current->Info.Age);
        printf("\tGender: \t\t\%s",current->Info.Gender);
        printf("\tClass:  \t\t%s",current->Info.Class);
        printf("\tAddress:\t\t%s",current->Info.Address);
        printf("\n\n");
        current=current->next;
    } 
    Menu();
}

void Find_Student_name()
{
    Node* currentNode = head;
    char Search_info[MAX_CHAR_INFO];
    int count=0;
    printf("Enter the name of the student you want to search for: ");
    fgets(Search_info,MAX_NUM_STUDENT,stdin);
    printf("Result:\n");
    while (currentNode != NULL) 
    {
        if (strcmp(strlwr(currentNode->Info.Name), strlwr(Search_info))==0 ) // The strcmp function is used to compare 2 strings.  
        {
            count++;
            printf("%d.\t%s", ++count, currentNode->Info.Name);
            printf("\tID:    \t\t%lld\n",currentNode->Info.ID);
            printf("\temail:  \t\t%s\n",currentNode->Info.Email);
            printf("\tAge:    \t\t%d\n",currentNode->Info.Age);
            printf("\tGender: \t\t\%s",currentNode->Info.Gender);
            printf("\tClass:  \t\t%s",currentNode->Info.Class);
            printf("\tAddress:\t\t%s",currentNode->Info.Address);
            printf("\n\n");
        }
        currentNode = currentNode->next;
    }
    if(count==0) printf("%s's information not found!!", Search_info);
    else printf("completely!!!");
    Menu();
}

void Find_Student_ID()
{
    Node* currentNode = head;
    long long Search_info_ID;
    int count=0;
    printf("Enter the name of the student you want to search for: ");
    scanf("%lld",&Search_info_ID);
    getchar();
    printf("Result:\n");
    while (currentNode != NULL) 
    {
        if (Search_info_ID==currentNode->Info.ID) // The strcmp function is used to compare 2 strings.  
        {
            count++;
            printf("%d.\t%s", ++count, currentNode->Info.Name);
            printf("\tID:    \t\t%lld\n",currentNode->Info.ID);
            printf("\temail:  \t\t%s\n",currentNode->Info.Email);
            printf("\tAge:    \t\t%d\n",currentNode->Info.Age);
            printf("\tGender: \t\t\%s",currentNode->Info.Gender);
            printf("\tClass:  \t\t%s",currentNode->Info.Class);
            printf("\tAddress:\t\t%s",currentNode->Info.Address);
            printf("\n\n");
        }
        currentNode = currentNode->next;
    }
    if(count==0) printf("Information not found!!\n");
    Menu();
}

bool Is_Duplicate(long long ID, Node* head_ref, Node* current) {

    Node* temp = head_ref;

    while (temp != current) {
        if (temp->Info.ID == ID) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

long long Create_ID( Node* current_ref)
{
    Node* current =current_ref;
    srand(time(NULL));
    long long ID = (rand() % 90000000) + 10000000;
    if( Is_Duplicate(ID,head,current)==true)
    {
        ID = (rand() % 90000000) + 10000000;
    }
    return ID;
}


char* get_last_name(char *name) {
    char *tokens[MAX_CHAR_INFO]; // mảng lưu các chuỗi kí tự tách được
    char *space = " "; // kí tự phân cách các chuỗi kí tự trong tên

    int i = 0;
    char *token = strtok(name, space); // tách chuỗi đầu tiên trong tên
    while (token != NULL && token!=space ) {
        tokens[i++] = token; // lưu chuỗi vào mảng
        token = strtok(NULL, space); // tiếp tục tách chuỗi kế tiếp
    }

    char *last_name = tokens[i-1]; // lấy chuỗi cuối cùng trong mảng
    return last_name;
}
