 // best practice to cehck existence of file before reading
 # include<stdio.h>
 int main()
 {
    FILE *fptr;
    fptr=fopen("abc.txt","r");   // when file doesnot exist and we open it in reading mode file pointer store null
    if(fptr==NULL)
    {
        printf("file doesnot exist.\n");
    }
    else
    {
        printf("file does exist.\n");
        fclose(fptr);
    }
  

    return 0;
 }