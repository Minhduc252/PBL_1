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
  
typedef struct {
    int ID;
    char name[MAX_CHAR_INFO];
} Faculty;
    
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
    Faculty Faculty;
} Student_Information;


typedef struct Node 
{
    Student_Information Info;
    Node* next;
    Node* prev;
} Node;
Node* head = NULL;


void fileProcessing();
void fileImport();
void AddStudent();
void FindStudentbyName();
void FindStudentbyID();
void Out(); 
void Menu();
void deleteLinebreak(char key[]);
void DeleteStudentbyID();
long long CreateID(Node* current_ref,Node* head_ref, int facultyID); 
void TextColor(int x);
void getLastname(char Name[], char lastName[]);

main()
{
    TextColor(6);
	printf("\t\t\t   TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG\n");
	printf("\t\t\t\t    KHOA CONG NGHE THONG TIN\n\n");
	printf("\t\t\t\tPBL1: DO AN LAP TRINH TINH TOAN\n\n");
	printf("\t\t\t\t\t    DE TAI:\n");
	printf("\t\t\t\t  QUAN LY DANH SACH SINH VIEN \n\n\n");
	printf("\t\t\t\t       SINH VIEN THUC HIEN\n");
	printf("\t\t\t  --------------------------------------------\n");
	printf("\t\t\t  |STT| MSSV    |     HO TEN         |  LOP  |\n");
	printf("\t\t\t  | 1 |102220224|NGUYEN VIET MINH DUC|22T_DT5| \n");
	printf("\t\t\t  | 2 |102220246|NGUYEN MINH PHUC    |22T_DT5| \n");
	printf("\t\t\t  --------------------------------------------");
    getch();
	system("cls");
    Menu();
}

void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void Menu()
{   
	TextColor(6);
    printf("\t\t\t\tPBL1: DO AN LAP TRINH TINH TOAN\n\n");
	printf("\t\t\t\t\t    DE TAI:\n");
	printf("\t\t\t\t  QUAN LY DANH SACH SINH VIEN \n\n\n");
	printf("\t\t\t----------------------------------------------");
    printf("\n\t\t\t|           STUDENT MANAGER MENU             |\n");
    printf("\t\t\t----------------------------------------------\n");
    printf("\t\t\t|<0>    EXIT                                 |\n");
	printf("\t\t\t|<1>    IMPORT STUDENTS LIST FROM FILE       |\n");
	printf("\t\t\t|<2>    ADD STUDENTS                         |\n");
	printf("\t\t\t|<3>    DELETE STUDENTS                      |\n");
	printf("\t\t\t|<4>    FIND STUDENT                         |\n");
	printf("\t\t\t|<5>    PRINT THE STUDENT LIST               |\n");
    printf("\t\t\t----------------------------------------------\n");
    TextColor(7);
    printf("\n\t> CHOOSE YOUR OPTION: ");
    char t;
    scanf("%s",&t);
    getchar();
	switch (t)
	{	case '1':
			fileImport();
            Menu();
		case '2':

			TextColor(6);
			printf("\n\t\t\t\t\tADD STUDENT \n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
			AddStudent();
            Menu();

		case '3':	

            TextColor(6);
            printf("\n\t\t\t\t\tDELETE STUDENTS \n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            DeleteStudentbyID();
            Menu();

		case '4': 

        	TextColor(6);
            printf("\n\t\t\t\t\tFIND STUDENTS \n");
            printf("\t\t\t----------------------------------------------\n");
            Try: printf("\n\t\t\t<0> MENU\n\t\t\t<1> FIND BY NAME\n\t\t\t<2> FIND BY ID\n\n");
            TextColor(7);
            char a;
            printf("\n\t> CHOOSE YOUR OPTION: ");
            scanf("%C",&a);
            getchar();
            switch(a)
            {
                case '1':
                {
                	TextColor(6);
                    printf("\n\t\t\t\tFIND STUDENTS BY NAME \n");
                    printf("\t\t\t----------------------------------------------\n");
                    TextColor(7);
                   FindStudentbyName();
                } 
                case '2':
                {
                	TextColor(6);
                    printf("\n\t\t\t\tFIND STUDENTS BY ID \n");
                    printf("\t\t\t----------------------------------------------\n");
                    TextColor(7);
                    FindStudentbyID();
                }
                case '0': Menu();
                default: 
                {
                    TextColor(4);
                    printf("\t\t\t\tCHOOSE AGAIN!! \n\n");
                    TextColor(7);   
                    goto Try;
                }
            }

		case '5': 

        	TextColor(6);
            printf("\n\t\t\t\t\tPRINT STUDENT LIST\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            Out();

        case '0': 

        	TextColor(6);
        	fileProcessing();
            printf("\nGOODBYE. SEE YOU LATER");
            TextColor(7);
            exit(1);
		default: 

            TextColor(4);
            printf("\t\t\t\tCHOOSE AGAIN!! \n\n");
            Menu();	
	}
}

int FacultyID()
{
    TextColor(3);
    printf("\n\n");
    printf("\t\t\t\t FACULTY LIST \n");
    printf("\t\t<1> Faculty of Mechanical Engineering\n"); //101
    printf("\t\t<2> Faculty of Information Technology\n");  //102
    printf("\t\t<3> Faculty of Transportation Mechanical Engineering\n");   //103
    printf("\t\t<4> Faculty of Heat and Refrigeration Technology\n");   //104
    printf("\t\t<5> Faculty of Electronics And Telecommunication Engineering\n");   //106
    printf("\t\t<6> Faculty of Chemical Engineering\n");    //107
    printf("\t\t<7> Faculty of Architecture\n");    //121
    printf("\t\t<8> Faculty of Environment\n"); //117
    printf("\t\t<9> Faculty of Project Management\n");  //118
    printf("\t\t<10> Faculty of Road And Bridge Engineering\n");    //109
    printf("\t\t<11> Faculty of Civil Engineering\n");  //110
    printf("\t\t<12> Faculty of Water Resources Engineering\n");    //111
    printf("\t\t<13> The Faculty of Advanced Science and Technology\n");    //123
    printf("\t\t<14> The Faculty of Advanced Science and Technology - PFIEV\n");    //122 
    printf("\t\t<15> Faculty of Electrical Engineering\n\n"); //105
    TextColor(7);
    printf("\tCHOOSE YOUR FACULTY: ");
    again:int i;
    scanf("%d",&i);
    getchar();
    if(i>16||i<1) 
    {
        printf("\t\t\tYOU MUST CHOICE A NUMBER BETWEEN 1 AND 15!!\n");
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
        if(temp->Info.Faculty.ID == facultyID && temp->Info.Age==current_ref->Info.Age)
        nextID=((temp->Info.ID)%100000)+1;
        temp=temp->next;
    }
    if(nextID==0) nextID=1;
    long long ID;
    ID = facultyID*1000000 + year*10000 + nextID;
    return ID;   
}

void AddStudent()
{
    int NumToAdd;
    printf("\t> ENTER THE NUMBER OF STUDENTS TO ADD: ");
    scanf("%d", &NumToAdd);
    getchar();
    for (int i = 0; i < NumToAdd; i++) {
        Student_Information new_student;
		
        TextColor(6);
		printf("\n\n\t> STUDENT %d \n",i+1);
        TextColor(7);
        printf("\tENTER THE STUDENT'S NAME:");
        fgets(new_student.Name, sizeof(new_student.Name), stdin);
        deleteLinebreak(new_student.Name);
        getLastname(new_student.Name, new_student.LastName);

        printf("\tENTER THE STUDENT'S AGE: ");
        scanf("%d", &new_student.Age);
        getchar();

        printf("\tENTER THE STUDENT'S GENDER: ");
        fgets(new_student.Gender, sizeof(new_student.Gender), stdin);
        deleteLinebreak(new_student.Gender);
        
        printf("\tENTER THE STUDENT'S DATE OF BIRTH: ");
        fgets(new_student.Birth, sizeof(new_student.Birth), stdin);
        deleteLinebreak(new_student.Birth);

        new_student.Faculty.ID= FacultyID();
        FacultySolve(new_student.Faculty.ID,new_student.Faculty.name);

        
        printf("\tENTER THE STUDENT'S CLASS: ");
        fgets(new_student.Class, sizeof(new_student.Class), stdin);
        deleteLinebreak(new_student.Class);
        
        printf("\tENTER THE STUDENT'S ADDRESS: ");
        fgets(new_student.Address, sizeof(new_student.Address), stdin);
        deleteLinebreak(new_student.Address);
        printf("\n");

        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->Info = new_student;
        new_node->next=new_node->prev=NULL;

        if (head == NULL) { 
            head = new_node;
        } 
        else{
            Node* current = head;
            while(current->next!=NULL)
            {
            	int check=strcmp(strlwr(current->Info.LastName), strlwr(new_node->Info.LastName));
                if(check<0) current=current->next;
                else break;
            }
            if(current==head && strcmp(strlwr(current->Info.LastName), strlwr(new_node->Info.LastName))<0){ 
                new_node->next=head;
                head->prev=new_node;
                new_node->prev=NULL;
                head=new_node;
            }
            else{
                new_node->next=current->next;
                new_node->prev=current;
                current->next=new_node;
                if(current->next!=NULL) current->next->prev=new_node;
            }
        } 
       new_node->Info.ID=CreateID(new_node,head,new_node->Info.Faculty.ID);
       sprintf(new_node->Info.Email, "%lld@sv.dut.udn.com", new_node->Info.ID);
    }
        printf("\n\n\t\t\t\tADD %d STUDENTS SUCCESSFULLY!\n", NumToAdd);
        TextColor(6);
        printf("\t\t\t----------------------------------------------\n\n\n");
        TextColor(7);
        getch();
}

void Out()
{
    int index=1;
    Node* current=head;
    if(head == NULL) 
    {
        printf("\t\t\t\t       STUDENT LIST IS EMPTY!\n\n");
        Menu();
    }
    while (current != NULL) { ;
    	printf("\t<%d> ",index++);
        printf("%s\n", current->Info.Name);
        printf("\tAGE:        %d\n",current->Info.Age);
        printf("\tGENDER:     %s\n",current->Info.Gender);
        printf("\tADDRESS:    %s\n",current->Info.Address);
        printf("\tID:         %lld\n",current->Info.ID);
        printf("\tEMAIL:      %s\n",current->Info.Email);
        printf("\tCLASS:      %s\n",current->Info.Class);
        printf("\tFACULTY:    %s\n",current->Info.Faculty.name);
        printf("\n");
        current=current->next;
    } 
    TextColor(7);
    printf("\t\t\t\tPRINTED STUDENT LIST COMPLETELY!\n");
    TextColor(6);
    printf("\t\t\t----------------------------------------------\n\n\n");
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
    printf("\t> ENTER THE NAME OF THE STUDENT YOU WANT TO SEARCH FOR: ");
    fgets(Search_info,MAX_NUM_STUDENT,stdin);
    deleteLinebreak(Search_info);
    printf("\t\t\t----------------------------------------------\n");
    printf("\tRESULT:\n");
    while (currentNode != NULL) 
    {
        /**
         * The strlwr( ) function is a built-in function in C and is used to convert a given string into lowercase.
         * The strcmp function is used to compare 2 strings. 
         */
        if (strcmp(strlwr(currentNode->Info.Name), strlwr(Search_info))==0 )   
        {
            count++;
            printf("\n\t\t<%d> %s\n", ++count, currentNode->Info.Name);
            printf("\t\tAGE:        %d\n",currentNode->Info.Age);
            printf("\t\tGENDER:     %s\n",currentNode->Info.Gender);
            printf("\t\tADDRESS:    %s\n",currentNode->Info.Address);
            printf("\t\tID:         %lld\n",currentNode->Info.ID);
            printf("\t\tEMAIL:      %s\n",currentNode->Info.Email);
            printf("\t\tCLASS:      %s\n",currentNode->Info.Class);
            printf("\t\tFACULTY:    %s\n",currentNode->Info.Faculty.name);
            printf("\n");
        }
        currentNode = currentNode->next;
    }
    if(count==0) printf("\t\t\t\t%s'S INFOMATION IS NOT FOUND!!\n", Search_info);
    else printf("\n\t\t\t\tCOMPLETELY!\n");
    TextColor(6);
    printf("\t\t\t----------------------------------------------\n\n\n");
    TextColor(7);
    getch();
    Menu();
}

void FindStudentbyID()
{
    Node* currentNode = head;
    long long Search_info_ID;
    int count=0;
    printf("\t> ENTER THE ID OF THE STUDENT YOU WANT TO SEARCH FOR: ");
    scanf("%lld",&Search_info_ID);
    getchar();
    printf("\n\tRESULT:\n\n");
    while (currentNode != NULL) 
    {
        if (Search_info_ID==currentNode->Info.ID)  
        {
            printf("\t\t<%d> %s\n", ++count, currentNode->Info.Name);
            printf("\t\tAGE:        %d\n",currentNode->Info.Age);
            printf("\t\tGENDER:     %s\n",currentNode->Info.Gender);
            printf("\t\tADDRESS:    %s\n",currentNode->Info.Address);
            printf("\t\tID:         %lld\n",currentNode->Info.ID);
            printf("\t\tEMAIL:      %s\n",currentNode->Info.Email);
            printf("\t\tCLASS:      %s\n",currentNode->Info.Class);
            printf("\t\tFACULTY:    %s\n",currentNode->Info.Faculty.name);
            printf("\n");
        }
        currentNode = currentNode->next;
    }
    if(count==0) printf("\t\t\t%lld'S INFOMATION IS NOT FOUND!!\n", Search_info_ID);
    else printf("\t\t\t\tCOMPLETELY!\n");
    TextColor(6);
    printf("\t\t\t----------------------------------------------\n\n\n");
    TextColor(7);
    getch();
    Menu();
}

void DeleteStudentbyID() {
    long long IdtoDelete;
    printf("\t> ENTER THE ID OF THE STUDENT TO DELETE: ");
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
	if(!found) printf("\t\t\t\tSTUDENT WITH ID %LLD IS NOT FOUND!\n", IdtoDelete);  
    else printf("\t\t\t\t\tCOMPLETELY DELETE STUDENT WITH ID: %lld\n",IdtoDelete);  
    TextColor(6);
    printf("\t\t\t----------------------------------------------\n\n\n");
    TextColor(7);
    getch();
}

void fileImport()
{
    FILE *fptr=NULL;
    fptr = fopen("input.txt", "r+");
    if(fptr == NULL)
    {
        printf("ERROR! Could not open file.\n");
        Menu();
    }

    char line[MAX_CHAR_INFO];
    while(fgets(line, MAX_CHAR_INFO, fptr) != NULL) {
        Student_Information student;

        // read name
        sscanf(line, "%*d. %s", student.Name);

        // read ID
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tID:\t%lld", &student.ID);

        // read email
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\temail:\t%s", student.Email);

        // read age
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tAge:\t%d", &student.Age);

        // read gender
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tGender:\t%s", student.Gender);

        // read class
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tClass:\t%s", student.Class);

        // read address
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tAddress:\t%s", student.Address);

        
        // add student to linked list
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->Info = student;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            int check;
            Node* currentNode = head;
            while(currentNode->next != NULL) {
                if(student.ID!=currentNode->Info.ID) check =1;
                currentNode = currentNode->next;
            }
            if(check!=1){
            currentNode->next = newNode;
            newNode->prev = currentNode;}
        }
    }
    fclose(fptr);
}

void fileProcessing()
{
    FILE *fptr;
    fptr = fopen("output.txt", "w");
    if(fptr == NULL)
    {
        printf("ERROR!");
        exit(1);
    }
    Node* currentNode = head;
    int count=0;
    while (currentNode != NULL) 
    {
        count++;
        fprintf(fptr, "%d.\t%s\n", count, currentNode->Info.Name);
        fprintf(fptr, "\tID:\t%lld\n", currentNode->Info.ID);
        fprintf(fptr, "\temail:\t%s\n", currentNode->Info.Email);
        fprintf(fptr, "\tAge:\t%d\n", currentNode->Info.Age);
        fprintf(fptr, "\tGender:\t%s\n", currentNode->Info.Gender);
        fprintf(fptr, "\tClass:\t%s\n", currentNode->Info.Class);
        fprintf(fptr, "\tAddress:\t%s\n\n", currentNode->Info.Address);
        currentNode = currentNode->next;
    }
    fclose(fptr);
}

void getLastname(char Name[], char lastName[])
{
    int N = strlen(Name);
    int index;
    for(int i=N-1;i>=0;i--)
    {
        if(Name[i]==' ') 
        {
        	index=i;
        	break;
		}
    }
    int i=0;
    for(int j=index+1;j<N;j++)
    {
        lastName[i++]=Name[j];
    }
}
