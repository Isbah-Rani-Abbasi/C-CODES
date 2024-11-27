// Write a program that contains a structure named Employee which contains the following
// data members:
// ● employeeCode
// ● employeeName
// ● dateOfJoining
// Perform the following operations:
// 1. Define a function that assigns user-defined values to these variables.
// 2. Create an array of 4 Employee structs and initialize them with user-defined values.
// 3. Define a function that asks the user to enter the current date, calculates the tenure of
// each employee, and checks if the tenure is more than three years. Display the details of
// employees with tenure of more than three years and the count of such employees.
# include<stdio.h>
# include<string.h>
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    char employeename[20];
    int employeecode;
    struct date dateofjoining; 
};
void input(struct employee *E);
void date(struct date *D);
int count=0;
int main()
{
     struct employee EMPLOYEE[4];
     struct date DATE;
     
     input(EMPLOYEE);
     date(&DATE);

     for(int i=0;i<4;i++)
     {
        int tenure=DATE.year-EMPLOYEE[i].dateofjoining.year;

        if(DATE.month<EMPLOYEE[i].dateofjoining.month||(DATE.month==EMPLOYEE[i].dateofjoining.month &&DATE.day<EMPLOYEE[i].dateofjoining.day))
        {
            tenure--;
        }
        if(tenure>3)
        {
           printf("\nEmployee %d Details:\n", i + 1);
            printf("Employee Code: %d\n", EMPLOYEE[i].employeecode);
            printf("Employee Name: %s\n", EMPLOYEE[i].employeename);
            printf("Date of Joining: %d/%d/%d\n", EMPLOYEE[i].dateofjoining.day, EMPLOYEE[i].dateofjoining.month, EMPLOYEE[i].dateofjoining.year);
            printf("Tenure: %d years\n", tenure);
            count++;
        }
     }
     
    printf("\nNumber of employees with more than 3 years of tenure: %d\n", count);

     return 0;

}
void input(struct employee *E)
{
    int i;
    for(i=0;i<4;i++)
    {
       
        printf("Enter employe %d name:\n",i+1);
        getchar();
        fgets(E[i].employeename,20,stdin);
        E[i].employeename[strcspn(E[i].employeename, "\n")] = '\0';
        //gets(E[i].employeename);
        printf("Enter employe %d code:\n",i+1);
        scanf("%d",&E[i].employeecode);
        printf("Enter employe %d day of joining:\n",i+1);
        scanf("%d",&E[i].dateofjoining.day);
        printf("Enter employe %d month of joining:\n",i+1);
        scanf("%d",&E[i].dateofjoining.month);
        printf("Enter employe %d year of joining:\n",i+1);
        scanf("%d",&E[i].dateofjoining.year);
    }
}
void date(struct date *D)
{
    
      
        printf("Enter today's day:\n");
        scanf("%d",&D->day);
        printf("Enter current month:\n");
        scanf("%d",&D->month);
        printf("Enter current year:\n");
        scanf("%d",&D->year);
      
}
