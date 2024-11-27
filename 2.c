# include<stdio.h>
# include<string.h>
int main()
{
    FILE *fptr;
    fptr=fopen("file.txt","r");
    char ch[20];
    fgets(ch,20,fptr);
    puts(ch);
    
    fclose(fptr);
    return 0;
}