#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <dirent.h>
#define MAX_NUM_STUDENT 1000
#define MAX_CHAR_INFO 1000
typedef struct {
    int ID;
    char name[MAX_CHAR_INFO];
} Faculty;

typedef struct Student_Information
{
    char Name[MAX_CHAR_INFO];
    int Age;
    long long ID;
    char Email[MAX_CHAR_INFO];
    char Class[MAX_CHAR_INFO];
    char Address[MAX_CHAR_INFO];
    char Birth[MAX_CHAR_INFO];
    char Gender[MAX_CHAR_INFO];
    Faculty Faculty;
} Student_Information;

char fileopen[MAX_CHAR_INFO];

typedef struct Node 
{
    Student_Information Info;
    Node* next;
    Node* prev;
} Node;

Node* head = NULL;
Node* tail =NULL;

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
void swap(Node* temp1, Node* temp2);
void IDsort();
void Namesort(Node** head_ref, Node** tail_ref);
void Classsort();
int compareName(char name1[], char name2[]);
void Partname(char Name[], char Partname[], int N);
void getTXT_files(char *path, char a[][MAX_CHAR_INFO], int *count);
void Classsort(Node** head_ref, Node** tail_ref);
void ChangeInfo();
void header();
void Facultysolve(Student_Information* newstudent);
int isNumber(char* input) {
   int i;
   for (i = 0; input[i] != '\0'; i++) {
      if (!isdigit(input[i])) {
         return 0;
      }
   }
   return 1;
}

main()
{
    SetConsoleOutputCP(CP_UTF8);
    TextColor(6);
    header();
	printf("\t\t\t\t       SINH VIEN THUC HIEN\n");
	printf("\t\t\t  +---+---------+--------------------+-------+\n");
	printf("\t\t\t  |STT| MSSV    |     HO TEN         |  LOP  |\n");
    printf("\t\t\t  +---+---------+--------------------+-------+\n");
	printf("\t\t\t  | 1 |102220224|NGUYEN VIET MINH DUC|22T_DT5| \n");
	printf("\t\t\t  | 2 |102220246|NGUYEN MINH PHUC    |22T_DT5| \n");
	printf("\t\t\t  +---+---------+--------------------+-------+\n");
    getch();
	system("cls");
    TextColor(6);
    header();
    printf("\n\t\t\t\tIMPORT STUDENTS LIST FROM FILE \n");
    printf("\t\t\t----------------------------------------------\n");
    TextColor(7);
    fileImport();
    Menu();
}
void header()
{
    TextColor(6);
    printf("\t\t\t   TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG\n");
	printf("\t\t\t\t    KHOA CONG NGHE THONG TIN\n\n");
	printf("\t\t\t\tPBL1: DO AN LAP TRINH TINH TOAN\n\n");
	printf("\t\t\t\t\t    DE TAI:\n");
	printf("\t\t\t\t  QUAN LY DANH SACH SINH VIEN \n\n\n");
}

void pressanykey()
{
    TextColor(7);
    printf("\t\t\t\tpress any key to continue...\n");
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
    header();
    TextColor(6);
	printf("\t\t\t+--------------------------------------------+\n");
    printf("\t\t\t|           STUDENT MANAGER SYSTEM           |\n");
    printf("\t\t\t+--------------------------------------------+\n");
	printf("\t\t\t|<1>    IMPORT STUDENTS LIST FROM FILE       |\n");
	printf("\t\t\t|<2>    ADD STUDENTS                         |\n");
    printf("\t\t\t|<3>    CHANGE STUDENT INFOMATION            |\n");
	printf("\t\t\t|<4>    DELETE STUDENTS BY ID                |\n");
	printf("\t\t\t|<5>    FIND STUDENT BY ID                   |\n");
    printf("\t\t\t|<6>    FIND STUDENT BY NAME                 |\n");
    printf("\t\t\t|<7>    PRINT THE STUDENT LIST BY NAME       |\n");
	printf("\t\t\t|<8>    PRINT THE STUDENT LIST BY ID         |\n");
    printf("\t\t\t|<9>    PRINT THE STUDENT LIST BY CLASS      |\n");
    printf("\t\t\t|<0>    EXIT                                 |\n");
    printf("\t\t\t+--------------------------------------------+\n");
    TextColor(7);
    printf("\n\t> CHOOSE YOUR OPTION: ");
    char t1[MAX_CHAR_INFO];
    scanf("%s",&t1);
    getchar();
    if(isNumber(t1)!=1) 
    {
        TextColor(4);
        printf("\t\t\t\t\tCHOOSE AGAIN!! \n\n");
        Menu();
    }
    int t= atol(t1);
	switch (t)
	{	case 1:
    
            TextColor(6);
			printf("\n\t\t\t\tIMPORT STUDENTS LIST FROM FILE \n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            fileProcessing();
			fileImport();
		case 2:

			{TextColor(6);
			printf("\n\t\t\t\t\tADD STUDENT \n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
			AddStudent();}
        
        case 3: 
            {
            TextColor(6);
            printf("\n\t\t\t\tCHANGE STUDENT INFOMATION\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            ChangeInfo();
			}

		case 4:	

            TextColor(6);
            printf("\n\t\t\t\tDELETE STUDENTS BY ID\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            DeleteStudentbyID();

		case 5: 
        	TextColor(6);
            printf("\n\t\t\t\tFIND STUDENTS BY ID\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            FindStudentbyID();
            
        case 6:
            TextColor(6);
            printf("\n\t\t\t\tFIND STUDENTS BY NAME \n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            FindStudentbyName();

		case 7: 

        	TextColor(6);
            printf("\n\t\t\t\tPRINT STUDENT LIST BY NAME\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            Namesort(&head,&tail);
            Out();

        case 8: 

        	TextColor(6);
            printf("\n\t\t\t\tPRINT STUDENT LIST BY ID\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            IDsort();
            Out();

        case 9: 

            TextColor(6);
            printf("\n\t\t\t\tPRINT STUDENT LIST BY CLASS\n");
            printf("\t\t\t----------------------------------------------\n");
            TextColor(7);
            Classsort(&head,&tail);
            Out();

        case 0: 

        	TextColor(6);
        	fileProcessing();
            printf("\n--------------GOODBYE! SEE YOU LATER---------------");
            TextColor(7);
            exit(1);
            
		default: 

            TextColor(4);
            printf("\t\t\t\t\tCHOOSE AGAIN!! \n\n");
            pressanykey();
	}
}

void Facultysolve(Student_Information* newstudent)
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
    again:printf("\tCHOOSE YOUR FACULTY: ");
    char i[MAX_CHAR_INFO];
    scanf("%s",&i);
    getchar();
    int j=atoi(i);
    if(j>16||j< 1)
    {
        printf("\t\t\tYOU MUST CHOICE A NUMBER BETWEEN 1 AND 15!!\n");
        goto again;
    }
    switch (j)
    {
    case 1: 
        newstudent->Faculty.ID= 101;
        strcpy(newstudent->Faculty.name, "Faculty of Mechanical Engineering");
    case 2: 
        newstudent->Faculty.ID =102;
        strcpy(newstudent->Faculty.name, "Faculty of Information Technology");
    case 3: 
        newstudent->Faculty.ID =103;
        strcpy(newstudent->Faculty.name, "Faculty of Transportation Mechanical Engineering");
    case 4: 
        newstudent->Faculty.ID =104;
        strcpy(newstudent->Faculty.name, "Faculty of Heat and Refrigeration Technology");
    case 5: 
        newstudent->Faculty.ID =105;
        strcpy(newstudent->Faculty.name, "Faculty of Electronics And Telecommunication Engineering");
    case 6: 
        newstudent->Faculty.ID =106;
        strcpy(newstudent->Faculty.name, "Faculty of Chemical Engineering");
    case 7: 
        newstudent->Faculty.ID=107;
        strcpy(newstudent->Faculty.name, "Faculty of Architecture");
    case 8: 
        newstudent->Faculty.ID=109;
        strcpy(newstudent->Faculty.name, "Faculty of Environment");
    case 9: 
        newstudent->Faculty.ID = 110;
        strcpy(newstudent->Faculty.name, "Faculty of Project Management");
    case 10: 
        newstudent->Faculty.ID=111;
        strcpy(newstudent->Faculty.name, "Faculty of Road And Bridge Engineering");
    case 11: 
        newstudent->Faculty.ID=117;
        strcpy(newstudent->Faculty.name, "Faculty of Civil Engineering");
    case 12: 
        newstudent->Faculty.ID=118;
        strcpy(newstudent->Faculty.name, "Faculty of Water Resources Engineering");
    case 13: 
        newstudent->Faculty.ID=121;
        strcpy(newstudent->Faculty.name, "The Faculty of Advanced Science and Technology");
    case 14: 
        newstudent->Faculty.ID=122;
        strcpy(newstudent->Faculty.name, "The Faculty of Advanced Science and Technology - PFIEV");
    case 15: 
        newstudent->Faculty.ID=123;
        strcpy(newstudent->Faculty.name, "Faculty of Electrical Engineering");
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
    char Numtoadd[MAX_CHAR_INFO];
    againnum: printf("\t> ENTER THE NUMBER OF STUDENTS TO ADD: ");
    scanf("%s", &Numtoadd);
    getchar();
    if(isNumber(Numtoadd)!=1) 
    {
        TextColor(12);
        printf("\t\t\t\tThe input must be a number!\n");
        TextColor(7);
        goto againnum;
    }
    NumToAdd= atol(Numtoadd);
    for (int i = 0; i < NumToAdd; i++) {
        Student_Information new_student;
		
        TextColor(6);
		printf("\n\n\t> STUDENT %d \n",i+1);
        TextColor(7);
        printf("\tENTER THE STUDENT'S NAME:");
        fgets(new_student.Name, sizeof(new_student.Name),stdin);
        deleteLinebreak(new_student.Name);

        
        againAge:printf("\tENTER THE STUDENT'S AGE: ");
        char reAge[MAX_CHAR_INFO];
        scanf("%s", &reAge);
        getchar();
        if(isNumber(reAge)==0){
            TextColor(12);
            printf("\t\t\t\tAge must be a number!\n");
            TextColor(7);
            goto againAge;
        }
        new_student.Age=atol(reAge);
        
        printf("\tENTER THE STUDENT'S GENDER: ");
        fgets(new_student.Gender, sizeof(new_student.Gender), stdin);
        deleteLinebreak(new_student.Gender);
        
        printf("\tENTER THE STUDENT'S DATE OF BIRTH: ");
        fgets(new_student.Birth, sizeof(new_student.Birth), stdin);
        deleteLinebreak(new_student.Birth);

        Facultysolve(&new_student);
        
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
            head = tail = new_node;
        } 
        else{
            tail->next = new_node;
            new_node->prev=tail;
            tail = new_node;
        } 
       new_node->Info.ID=CreateID(new_node,head,new_node->Info.Faculty.ID);
       sprintf(new_node->Info.Email, "%lld@sv.dut.udn.com", new_node->Info.ID);
    }
        printf("\n\n\t\t\t\tADD %d STUDENTS SUCCESSFULLY!\n", NumToAdd);
        TextColor(6);
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
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
        printf("\tBIRTH:      %s\n",current->Info.Birth);
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
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
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
    printf("\n\t    RESULT:\n");
    while (currentNode != NULL) 
    {
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
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
}

void FindStudentbyID(){
    Node* currentNode = head;
    char Search_info_ID1[MAX_CHAR_INFO];
    int count=0;
    again:printf("\t> ENTER THE ID OF THE STUDENT YOU WANT TO SEARCH FOR: ");
    scanf("%s",&Search_info_ID1);
    getchar();
    if (isNumber(Search_info_ID1)!=1)
    {   
        TextColor(12);
        printf("\t\t\t\tId must be a number!\n");
        TextColor(7);
        goto again;

    }
    long long Search_info_ID = atol(Search_info_ID1);
    printf("\n\t   RESULT:\n\n");
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
    if(count==0) printf("\t\t\t\t%lld'S INFOMATION IS NOT FOUND!!\n", Search_info_ID);
    else printf("\t\t\t\t\tCOMPLETELY!\n");
    TextColor(6);
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
}

void DeleteStudentbyID() {
    char IDtodel[MAX_CHAR_INFO];
    long long IdtoDelete;
    again:printf("\t> ENTER THE ID OF THE STUDENT TO DELETE: ");
    scanf("%s", &IDtodel);
    getchar();
    if (isNumber(IDtodel)!=1)
    {
        TextColor(12);
        printf("\t\t\t\tId must be a number!\n");
        TextColor(7);
        goto again;
    }
    IdtoDelete=atol(IDtodel);

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
	if(!found) printf("\t\t\t\tSTUDENT WITH ID %lld IS NOT FOUND!\n", IdtoDelete);  
    else printf("\t\t\t\tCOMPLETELY DELETE STUDENT WITH ID: %lld\n",IdtoDelete);  
    TextColor(6);
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
}

void fileImport()
{
    FILE *fptr = NULL;  
    tail=head=NULL;
    char filename[MAX_CHAR_INFO][MAX_CHAR_INFO];
    char path[MAX_CHAR_INFO] = ".";
    
    int count = 0;
    getTXT_files(path, filename, &count);
    if (count == 0) {
        TextColor(12);
        printf("\t\t\tINVALID *.TXT DOCUMENT FILE");
        TextColor(7);
    }
    for (int i = 0; i < count; i++) {
        printf("\n\t\t\t\t<%d>\t%s", i + 1, filename[i]);
    }
    printf("\n\t\t\t\t<%d>\t%s", count+1,"CREATE A NEW FILE");
    printf("\n\t\t\t\t<0>\tMENU");
    int choose;
    char j[MAX_CHAR_INFO];
    do {
        again:printf("\n\n\t> CHOOSE FILE TO OPEN: ");
        scanf("%s", &j);
        getchar();
        choose = atoi(j);
        if (choose > count+1 || choose < 0 || isNumber(j)!=1) {
            TextColor(12);
            printf("\t\t\t\t You must choice a number between 1 and %d!!", count+1);
            TextColor(7);
        }
    } while (choose > count+1 || choose < 0 || isNumber(j)!=1);
    if(choose==0) Menu();
    if(choose==count+1) 
    {
        bool check;
        do {   
            check = false;
            printf("\t\tENTER THE NAME OF THE NEW FILE TO CREATE: ");
            scanf("%s", &filename[count]);
            getchar();
            char* pos = strstr(filename[count], ".txt");
            if (!(pos && pos == filename[count] + strlen(filename[count]) - 4)) {
                strcat(filename[count], ".txt");
            }
            for(int i = 0; i < count; i++)
            {
                if(strcmp(filename[i], filename[count]) == 0) check = true;
            }
            if (check) {
                TextColor(3);
                printf("\t\t\tA FILE WITH THE SAME NAME ALREADY EXISTS!!\n");
                TextColor(7);
            }
        } while(check);
        fptr = fopen(filename[choose-1], "w+");
    } 
    else fptr = fopen(filename[choose-1], "r");
    strcpy(fileopen,filename[choose-1]);

    if (fptr == NULL) {
        perror("COULDN'T OPEN FILE");
        exit(EXIT_FAILURE);
    }
    char line[MAX_CHAR_INFO];
    while (fgets(line, MAX_CHAR_INFO, fptr) != NULL) {
        Student_Information student;

        // read name
        sscanf(line, "%*d. %[^\n]", student.Name);

        // read age
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tAge:\t%d", &student.Age);

        // read gender
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tGender:\t%s", student.Gender);

        // read gender
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tBirth:\t%s", student.Birth);

        // read ID
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tID:\t%lld", &student.ID);

        // read class
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tClass:\t%s", student.Class);

        // read email
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tEmail:\t%s", student.Email);

        // read faculty
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tFaculty:\t%[^\n]", student.Faculty.name);


        // read address
        fgets(line, MAX_CHAR_INFO, fptr);
        sscanf(line, "\tAddress:\t%[^\n]", student.Address);
        fgets(line, MAX_CHAR_INFO, fptr);

        // add student to linked list
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->Info = student;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    TextColor(6);
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
}

void fileProcessing()
{
    FILE *fptr;
    fptr = fopen(fileopen, "w+");
    Node* currentNode = head;
    int count=0;
    while (currentNode != NULL) 
    {
        count++;
        fprintf(fptr, "%d.\t%s\n", count, currentNode->Info.Name);
        fprintf(fptr, "\tAge:\t%d\n", currentNode->Info.Age);
        fprintf(fptr, "\tGender:\t%s\n", currentNode->Info.Gender);
        fprintf(fptr, "\tID:\t%lld\n", currentNode->Info.ID);
        fprintf(fptr, "\tBirth:\t%s\n", currentNode->Info.Birth);
        fprintf(fptr, "\tClass:\t%s\n", currentNode->Info.Class);
        fprintf(fptr, "\tEmail:\t%s\n", currentNode->Info.Email);
        fprintf(fptr, "\tFaculty:\t%s\n", currentNode->Info.Faculty.name);
        fprintf(fptr, "\tAddress:\t%s\n\n", currentNode->Info.Address);
        currentNode = currentNode->next;
    }
    fclose(fptr);
}

void Partname(char Name[], char Partname[], int N)
{
    int  index;
    for(int i=N-1;i>=0;i--)
    {
        if(Name[i]==' ') 
        {
            index=i;
            break;
        }
    }
    int i=0;
    for(int j=index+1;j<=N;j++)
    {
        Partname[i++] = Name[j];
    }

    Partname[i] = '\0';
}

void IDsort() {
    bool swapped;
    Node* temp;
    do {
        swapped = false;
        temp = head;
        while (temp && temp->next) {
            if (temp->Info.ID > temp->next->Info.ID) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}
                         
void swap(Node* temp1, Node* temp2) {
  Student_Information temp = temp1->Info;
  temp1->Info = temp2->Info;
  temp2->Info = temp;
}

void Namesort(Node** head_ref, Node** tail_ref) {
    bool swapped;
    Node* temp;
    if (*head_ref == NULL)
        return;
    do {
        swapped = false;
        temp = *head_ref;
        while (temp != *tail_ref) {
            char name1[MAX_CHAR_INFO];
            char name2[MAX_CHAR_INFO];
            Partname(temp->Info.Name, name1, strlen(temp->Info.Name));
            Partname(temp->next->Info.Name, name2, strlen(temp->next->Info.Name));
            if (compareName(name1, name2) > 0 || (compareName(name1, name2) == 0 && strlen(temp->Info.Name) > strlen(temp->next->Info.Name))) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

char* lower(char a[]) {
  int i=0;
  while(a[i]) {
    a[i] = tolower(a[i]);
    i++;
  }
  return a;
}

int compareName(char name1[], char name2[]) {
  char* lowerName1 = strdup(name1);
  char* lowerName2 = strdup(name2);
  lower(lowerName1);
  lower(lowerName2);
  int result = strcmp(lowerName1, lowerName2);
  free(lowerName1);
  free(lowerName2);
  return result;
}

int compareClass(char class1[], char class2[]) {
  char* lowerClass1 = strdup(class1);
  char* lowerClass2 = strdup(class2);
  lower(lowerClass1);
  lower(lowerClass2);
  int size = strlen(class1);
  if(strlen(class1)<strlen(class2)) size=strlen(class2);
  for(int i=0;i<size;i++)
  {
    if(class1[i]<class2[i]) 
    {
        free(lowerClass1);
        free(lowerClass2);
        return -1;
    }
    if(class1[i]>class2[i])
    {
        free(lowerClass1);
        free(lowerClass2);
        return 1;
    }
  }
  return 0;
  
}

void getTXT_files(char *path, char a[][MAX_CHAR_INFO], int *count) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".txt") != NULL) {
                strcpy(a[*count], ent->d_name);
                (*count)+=1;
            }
        }
        closedir(dir);
    } else {
        TextColor(12);
        perror("COULDN'T OPEN DIRECTORY");
        TextColor(7);
        exit(EXIT_FAILURE);
    }
}

 void Classsort(Node** head_ref, Node** tail_ref){
    bool swapped;
    Node* temp;
    if (*head_ref == NULL)
        return;
    do {
        swapped = false;
        temp = *head_ref;
        while (temp->next != (*tail_ref)) {
            char name1[MAX_CHAR_INFO];
            char name2[MAX_CHAR_INFO];
            Partname(temp->Info.Class, name1, strlen(temp->Info.Class));
            Partname(temp->next->Info.Class, name2, strlen(temp->next->Info.Class));
            if (compareClass(name1, name2) > 0) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void ChangeInfo()
{
    Node* currentNode = head;
    char reInfo[MAX_CHAR_INFO];
    againid: printf("\n\t> ENTER THE ID OF THE STUDENT: ");
    scanf("%s", reInfo);
    if(isNumber(reInfo)==0) 
    {
        TextColor(12);
        printf("\t\t\tThe Id must be a number!");
        TextColor(7);
        goto againid;
    }
    long long reInfoID = atol(reInfo);
    getchar();
    Student_Information reInfo1;
    while (currentNode != NULL)
    {
        if (reInfoID == currentNode->Info.ID) break;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL)
    {
        printf("\n\t\t\t\tID \"%lld\" IS NOT FOUND!!\n", reInfoID);
        TextColor(6);
        printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
        TextColor(7);
        return;
    }
    printf("\tENTER THE STUDENT'S NAME");
    printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
    scanf("%s", reInfo1.Name);
    getchar();
    int age;
    do
    {
        printf("\tENTER THE STUDENT'S AGE ");
        printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
        if (scanf("%d", &age) != 1) {

            printf("\t\tAGE MUST BE A NUMBER!\n");
            scanf("%*[^\n]%*c"); // clear input buffer
            continue;
        }
        reInfo1.Age = age;
        getchar();
        break;
    } while (1);

    printf("\tENTER THE STUDENT'S GENDER ");
    printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
    scanf("%s", reInfo1.Gender);
    getchar();

    printf("\tENTER THE STUDENT'S DATE OF BIRTH ");
    printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
    scanf("%s", reInfo1.Birth);
    getchar();

    printf("\tENTER THE STUDENT'S ADDRESS ");
    printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
    scanf("%s", reInfo1.Address);
    getchar();

    Facultysolve(&reInfo1);

    printf("\tENTER THE STUDENT'S CLASS ");
    printf("\n\t\t(press \"0\" if you don't want to change it)\n\t\t>");
    scanf("%s", reInfo1.Class);
    getchar();

    if (reInfoID == currentNode->Info.ID)
    {
        if (strcmp(reInfo1.Name, "0") != 0) strcpy(currentNode->Info.Name, reInfo1.Name);
        if (reInfo1.Age != 0) currentNode->Info.Age = reInfo1.Age;
        if (strcmp(reInfo1.Birth, "0") != 0) strcpy(currentNode->Info.Birth, reInfo1.Birth);
        if (strcmp(reInfo1.Class, "0") != 0) strcpy(currentNode->Info.Class, reInfo1.Class);
        if (reInfo1.Faculty.ID != 0)
        {
            currentNode->Info.Faculty.ID = reInfo1.Faculty.ID;
            strcpy(currentNode->Info.Faculty.name, reInfo1.Faculty.name);
        }
        if (strcmp(reInfo1.Gender, "0") != 0) strcpy(currentNode->Info.Gender, reInfo1.Gender);
    }
    TextColor(6);
    printf("\t\t\t------------------COMPLETELY!------------------\n\n\n");
    pressanykey();
}

