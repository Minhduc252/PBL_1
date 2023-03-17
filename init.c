#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> // thư viện làm việc liên quan đến con trỏ và bộ nhớ được cấp phát
#include <math.h>
#include <string.h> // thư viện làm việc với chuỗi
#include <ctype.h> // ham dung de kiem tra va anh xa cac ki tu

struct Student_Information // struct khai báo thông tin của 1 sinh viên
{
	char Name[100]; // tên học sinh
	char Class[100]; // lớp của sinh viên
	long Student_ID_Number; // mã số sinh viên
	char Email_Address [100]; // địa chỉ email của sinh viên
};

void Get_Name(); // hàm khởi tạo tên sinh viên

// void Create_Email_Address(char Ar_Student[100]); 

// void Get_Class();
// void Sort_Student();
// void Create_ID_Num_Student();
// void Export_Out_List();

int main()
{	
	Get_Name();

   return 0;
}
void Get_Name(char Name_Student[1000])
{
	struct Student_Information *person;
	int i,n;
	again:printf("enter the number of persons: ");
	scanf("%d",&n);
	if(n!=(int)n)  // -> Đang xử lí nếu nhập input vào không phải là number thì bắt nhập lại
	{
		printf("n must be a number. Enter the password again!");
		goto again;
	}
	person= (struct Student_Information*) malloc(n * sizeof(struct Student_Information)); // khởi tạo ô nhớ cho n học sinh (ô nhớ phụ thuộc vào n/ ô nhớ động)
	for(i = 1; i <= n; i++)
   	{
    	printf("Enter name of student %d: ",i);
       	scanf("%s", (person+i)->Name);
   	}
	printf("\nDisplaying Information:\n");
	for (i=1;i<=n;i++)
	{
		printf("%s\n",(person+i)->Name);
	}
}
