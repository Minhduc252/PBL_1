#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <ctime>

#define MAX_NUM_STUDENT 1000
#define MAX_CHAR_INFO 1000
    
typedef struct Student_Information
{
    char Name[MAX_CHAR_INFO];
    char LastName[MAX_CHAR_INFO];
    int Age;
    long long ID;
    char Email[MAX_CHAR_INFO];
    char Class[MAX_CHAR_INFO];
    char Address[MAX_CHAR_INFO];
    char Birth[MAX_CHAR_INFO];
    char Gender[MAX_CHAR_INFO];
    char Faculty[MAX_CHAR_INFO];
    int FacultyID;
} Student_Information;


typedef struct Node 
{
    Student_Information Info;
    Node* next;
    Node* prev;
} Node;
Node* head = NULL;


void fileProcessing();
void AddStudent();
void FindStudentbyName();
void FindStudentbyID();
void Out(); 
void Menu();
void deleteLinebreak(char key[]);
void DeleteStudentbyID();
long long CreateID(Node* current_ref,Node* head_ref, int facultyID); 
void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
main()
{
    Menu();
}
void Menu()
{   TextColor(6);
    printf("\nSTUDENT MANAGER MENU\n");
    printf("--------------------\n");
    printf("<0> Exit\n");
	printf("<1> Add students\n");
	printf("<2> delete students\n");
	printf("<3> Find students\n");
	printf("<4> Print the student list\n");
    printf("--------------------\n");
    TextColor(7);
    printf("\n> CHOOSE YOUR OPTION: ");
	char t;
    scanf("%s",&t);
    getchar();
	switch (t)
	{
		case '1':

			TextColor(6);
			printf("\nADD STUDENT \n");
            printf("--------------------\n");
            TextColor(7);
			AddStudent();
            Menu();

		case '2':	

            TextColor(6);
            printf("\nDELETE STUDENTS \n");
            printf("--------------------\n");
            TextColor(7);
            DeleteStudentbyID();
            Menu();

		case '3': 

        	TextColor(6);
            printf("\nFIND STUDENTS \n");
            printf("--------------------\n");
            Try: printf("\n<1> FIND BY NAME\n<2> FIND BY ID\n");
            TextColor(7);
            char a;
            a=getch();
            switch(a)
            {
                case '1':
                {
                	TextColor(6);
                    printf("\nFIND STUDENTS BY NAME \n");
                    printf("--------------------\n");
                    TextColor(7);
                   FindStudentbyName();
                } 
                case '2':
                {
                	TextColor(6);
                    printf("\nFIND STUDENTS BY ID \n");
                    printf("--------------------\n");
                    TextColor(7);
                    FindStudentbyID();
                }
                default: 
                {
                    printf("Choose again!");
                    goto Try;
                }
            }
            printf("--------------------\n");
            Menu();

		case '4': 

        	TextColor(6);
            printf("\nPRINT STUDENT LIST\n");
            printf("--------------------\n");
            TextColor(7);
            Out();

        case '0': 

        	TextColor(6);
            printf("\nGOODBYE. SEE YOU LATER");
            TextColor(7);
            getch();
            exit(1);

		default: 

            TextColor(4);
            printf("\n CHOOSE AGAIN!\n");
            Menu();	

	}
}


long long CreateID(Node* current_ref,Node* head_ref, int facultyID)
{
    Node* temp=head_ref;
    time_t now = time(0);
    tm* local_time = localtime(&now);
    long currentyear= (1900+local_time->tm_year)%100;
    long year = currentyear - (current_ref->Info.Age-18+1);
    int nextID=0;
    while(temp!=current_ref)
    {
        if(temp->Info.FacultyID==facultyID && temp->Info.Age==current_ref->Info.Age)
        nextID=((temp->Info.ID)%100000)+1;
    }
    if(nextID==0) nextID=1;
    long long ID;
    ID = facultyID*1000000 + year*10000 + nextID;
    return ID;   
}

int FacultyID()
{
    TextColor(6);
    printf("\n\nCHOOSE YOUR FACULTY\n");
    printf("<1> Faculty of Mechanical Engineering\n"); //101
    printf("<2> Faculty of Information Technology\n");  //102
    printf("<3> Faculty of Transportation Mechanical Engineering\n");   //103
    printf("<4> Faculty of Heat and Refrigeration Technology\n");   //104
    printf("<5> Faculty of Electronics And Telecommunication Engineering\n");   //106
    printf("<6> Faculty of Chemical Engineering\n");    //107
    printf("<7> Faculty of Architecture\n");    //121
    printf("<8> Faculty of Environment\n"); //117
    printf("<9> Faculty of Project Management\n");  //118
    printf("<10> Faculty of Road And Bridge Engineering\n");    //109
    printf("<11> Faculty of Civil Engineering\n");  //110
    printf("<12> Faculty of Water Resources Engineering\n");    //111
    printf("<13> The Faculty of Advanced Science and Technology\n");    //123
    printf("<14> The Faculty of Advanced Science and Technology - PFIEV\n");    //122 
    printf("<15> Faculty of Electrical Engineering\n"); //105
    TextColor(7);
    printf("> ");
    again:int i;
    scanf("%d",&i);
    getchar();
    if(i>16||i<1) 
    {
        printf("You must choice a number between 1 and 15!!\n");
        goto again;
    }
    switch (i)
    {
    case 1: return 101;
    case 2: return 102;
    case 3: return 103;
    case 4: return 104;
    case 5: return 106;
    case 6: return 107;
    case 7: return 121;
    case 8: return 117;
    case 9: return 118;
    case 10: return 109;
    case 11: return 110;
    case 12: return 111;
    case 13: return 123;
    case 14: return 122;
    case 15: return 105;
    }
}

void FacultySolve(int facultyID, char faculty[MAX_CHAR_INFO]) {
   switch (facultyID) {
      case 101:
         strcpy(faculty, "Faculty of Mechanical Engineering");
         break;
      case 102:
         strcpy(faculty, "Faculty of Information Technology");
         break;
      case 103:
         strcpy(faculty, "Faculty of Transportation Mechanical Engineering");
         break;
      case 104:
         strcpy(faculty, "Faculty of Heat and Refrigeration Technology");
         break;
      case 105:
         strcpy(faculty, "Faculty of Electronics And Telecommunication Engineering");
         break;
      case 106:
         strcpy(faculty, "Faculty of Chemical Engineering");
         break;
      case 107:
         strcpy(faculty, "Faculty of Architecture");
         break;
      case 109:
         strcpy(faculty, "Faculty of Environment");
         break;
      case 110:
         strcpy(faculty, "Faculty of Project Management");
         break;
      case 111:
         strcpy(faculty, "Faculty of Road And Bridge Engineering");
         break;
      case 117:
         strcpy(faculty, "Faculty of Civil Engineering");
         break;
      case 118:
         strcpy(faculty, "Faculty of Water Resources Engineering");
         break;
      case 121:
         strcpy(faculty, "The Faculty of Advanced Science and Technology");
         break;
      case 122:
         strcpy(faculty, "The Faculty of Advanced Science and Technology - PFIEV");
         break;
      case 123:
         strcpy(faculty, "Faculty of Electrical Engineering");
         break;
   }
}


void AddStudent()
{
    int NumToAdd;
    printf("Enter the number of students to add: ");
    scanf("%d", &NumToAdd);
    getchar();
    for (int i = 0; i < NumToAdd; i++) {
        Student_Information new_student;
		
		printf("\n> student %d \n",i+1);
        printf("Enter the student's name: ");
        fgets(new_student.Name, sizeof(new_student.Name), stdin);
        deleteLinebreak(new_student.Name);

        printf("Enter the student's age: ");
        scanf("%d", &new_student.Age);
        getchar();

        printf("Enter the student's gender: ");
        fgets(new_student.Gender, sizeof(new_student.Gender), stdin);
        deleteLinebreak(new_student.Gender);
        
        printf("Enter the student's date of birth:    ");
        fgets(new_student.Birth, sizeof(new_student.Birth), stdin);
        deleteLinebreak(new_student.Birth);

        new_student.FacultyID= FacultyID();
        FacultySolve(new_student.FacultyID,new_student.Faculty);

        
        printf("Enter the student's class:    ");
        fgets(new_student.Class, sizeof(new_student.Class), stdin);
        deleteLinebreak(new_student.Class);
        
        printf("Enter the student's address:  ");
        fgets(new_student.Address, sizeof(new_student.Address), stdin);
        deleteLinebreak(new_student.Address);
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
        new_node->Info.ID=CreateID(new_node,head,new_node->Info.FacultyID);
        sprintf(new_node->Info.Email, "%lld@sv.dut.udn.com", new_node->Info.ID);
    }
        printf("Added %d students successfully!\n", NumToAdd);
        
}


void Out()
{
    int index=1;
    Node* current=head;
    while (current != NULL) { 
    	TextColor(6);
    	printf("<%d> ",index++);
        printf("%s\n", current->Info.Name);
        TextColor(7);
        printf("Age:        %d\n",current->Info.Age);
        printf("Gender:     %s\n",current->Info.Gender);
        printf("Address:    %s\n",current->Info.Address);
        printf("ID:         %lld\n",current->Info.ID);
        printf("email:      %s\n",current->Info.Email);
        printf("Class:      %s\n",current->Info.Class);
        printf("Faculty:    %s\n",current->Info.Faculty);
        printf("\n");
        current=current->next;
    } 
    TextColor(2);
    printf("Printed student list successfully!\n");
    TextColor(7);
    Menu();
}

//this function is used to delete the line break char in the input string
void deleteLinebreak(char key[])
{
    size_t len= strlen(key);
    if(key[len-1]=='\n') key[len-1]='\0';
}

void FindStudentbyName()
{
    Node* currentNode = head;
    char Search_info[MAX_CHAR_INFO];
    int count=0;
    printf("Enter the name of the student you want to search for: ");
    fgets(Search_info,MAX_NUM_STUDENT,stdin);
    deleteLinebreak(Search_info);
    printf("Result:\n");
    while (currentNode != NULL) 
    {
        /**
         * The strlwr( ) function is a built-in function in C and is used to convert a given string into lowercase.
         * The strcmp function is used to compare 2 strings. 
         */
        if (strcmp(strlwr(currentNode->Info.Name), strlwr(Search_info))==0 )   
        {
            count++;
            printf("%d.\t%s", ++count, currentNode->Info.Name);
            printf("\tID:    \t\t%lld\n",currentNode->Info.ID);
            printf("\temail:   \t\t%s\n",currentNode->Info.Email);
            printf("\tAge:     \t\t%d\n",currentNode->Info.Age);
            printf("\tGender:  \t\t\%s\n",currentNode->Info.Gender);
            printf("\tClass:   \t\t%s\n",currentNode->Info.Class);
            printf("\tAddress: \t\t%s\n",currentNode->Info.Address);
            printf("\n\n");
        }
        currentNode = currentNode->next;
    }
    if(count==0) printf("%s's information not found!!", Search_info);
    else printf("completely!!!");
    Menu();
}

void FindStudentbyID()
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

void DeleteStudentbyID() {
    long long IdtoDelete;
    printf("Enter the ID of the student to delete: ");
    scanf("%lld", &IdtoDelete);
    Node* current = head;
    bool found = false;     
    for(current; current != NULL; current = current->next) {
        if(current->Info.ID == IdtoDelete) {
            found = true;
            if(current->prev == NULL) {
                head = current->next;
                if(head != NULL) head->prev = NULL;
            } else {
                current->prev->next = current->next;
                if(current->next != NULL) current->next->prev = current->prev;
            }
            free(current);
            break;
        }
    } 
    if(!found) printf("Student with ID %lld not found!\n", IdtoDelete);  
    printf("completely delete student ID: %lld",IdtoDelete);  
}

