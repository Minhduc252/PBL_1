#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num;
	FILE *fptr;

	fptr=fopen("1.txt","a+");
	if(fptr == NULL) 
	{
		printf("Error! Opening file");
		exit(1);
	}
	else {
	printf("Enter num: ");
   	scanf("%d",&num);
   	fprintf(fptr," %d",num);
  	fclose(fptr);
	}
   return 0;
}