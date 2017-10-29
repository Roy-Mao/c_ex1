#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char *mptr; 																		/*a char pointer to heap*/
	char *more_mptr;																	/*a char pointer to heap for more memory*/
	char c;																				/*where to store each of the read-in char*/
	int length = 0;																		/*the length of the read-in string*/
	int size = 2;																		/*the size of the dynamically allocated spaces on the heap*/
	FILE *fp = fopen("test.txt", "w");
	if (fp == NULL)
	{
		exit(1);
	}
	puts("The file test.txt created successfully...!!");
	puts("Input a sentence for the file: ");
	mptr = malloc(size);																/*Initially allocate 2 char space on the heap*/
	if (mptr == NULL)
	{
		puts("something wrong with mallloc");
		exit(2);
	}
	while (((c = getchar()) != EOF) &&  (c != '\n'))									/*Ccontinue this block if c does not receive either \n or end of file signal*/
	{
		if (length >= size)
		{
			size *= 2;
			more_mptr = realloc(mptr, size);
			if (more_mptr == NULL)
			{
				puts("something wrong with realloc");
				exit(3);
			}
			else
			{
				mptr = more_mptr;														/*notic the correct way to swap the pointer after realloc*/
			}
		}
		mptr[length++] = c;
	}
	mptr[length] = '\0';
	puts("your input string has been added to the heap section mptr");
	puts("Now, print out the string you write to the heap: ");
	printf("Your input string is: %s \n", mptr);
	puts("Now, I am trying to write your string into the newly created file...");
	fprintf(fp, "%s\n", mptr);
	puts("The rewrite process is finished. Going close the newly created file and then free the malloc");
	int close_int = fclose(fp);
	if (close_int != 0)
	{
		puts("something wrong when closing the file");
		exit(4);
	}
	free(mptr);
	return (0);
}