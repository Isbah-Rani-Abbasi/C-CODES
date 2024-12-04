# include<stdio.h>
# include<string.h>
# include<stdlib.h>
struct player
{
    char name[50];
    int  id;
    int highest_kills;
    int highest_deaths;
};
int main()
{
    struct player *p = NULL , temp;
    int n , i , choice , id ,  index =-1 , newID , j ;
    char name[20];
    printf("Enter n:\n");
    scanf("%d",&n);
    p = (struct player *)calloc( n , sizeof( struct player));

    if ( p == NULL)
    {
        printf("Memory does not allocated!\n");
        return 1;
    }

    for ( i = 0 ;i < n ; i++)
    {
       printf("Enter the name of player %d:\n", i+1);
       scanf("%s" , &(p+i)->name);
       printf("Enter the id of player %d:\n", i+1);
       scanf("%d" , &(p+i)->id);
       printf("Enter the highest kills of player %d:\n", i+1);
       scanf("%d",&(p+i)->highest_kills);
       printf("Enter the highest deaths of player %d:\n",i+1);
       scanf("%d",&(p+i)->highest_deaths);
    }


    while (1)
    {
       
        printf("\n0.Exit\n");
        printf("1.Add\n");
        printf("2.Read\n");
        printf("3.Delete\n");
        printf("4.Update\n");
        printf("4.Sorting by hightest kills\n");
        printf("Select a number between 0 to 4\n");
        scanf("%d",&choice);
        if( choice == 0 )
        {
            printf("End Program\n");
            break;
        }
        else
        {
            switch (choice)
            {
            case 1:
               n++;
               p = (struct player *)realloc( p , n*sizeof(struct player));
               if ( p ==NULL)
               {
                 printf("Memory not allocate!\n");
                 return 1;
               }
                printf("Enter the name of player:\n");
                scanf("%s", &(p+n-1)->name);
                printf("Enter the id of player:\n");
                scanf("%d" , &(p+n-1)->id);
                printf("Enter the highest kills of player:\n");
                scanf("%d",&(p+n-1)->highest_kills);
                printf("Enter the highest deaths of player:\n");
                scanf("%d",&(p+n-1)->highest_deaths);
               

                break;
            case 2:
                if ( n == 0)
                {
                    printf("empt!\n");
                    return 1;
                }
                for(i=0 ; i<n ;i++)
                {
                    printf("The name of player %d:%s\n",i+1,(p+i)->name);
                    printf("The id of player %d:%d\n",i+1,(p+i)->id);
                    printf("The highest kill of player %d:%d\n",i+1,(p+i)->highest_kills);
                    printf("The highest deaths of player %d:%d\n",i+1,(p+i)->highest_deaths);

                }
                break;
            case 3:
                 
                 printf("Enter the id of player you wan to delete:\n");
                 scanf("%d",&id);
                 for(i=0;i<n;i++)
                 { 
                   if ((p+i)->id == id)
                   {
                    index = i;
                    break;
                   }
                 }
                 if (index == -1)
                 {
                    printf("Player not found!\n");
                 }
                 else
                 {
                    for( i=index ; i<n ; i++)
                    {
                        *(p+i)=*(p+i+1);
                    }
                     printf("Player deleted successfully!\n");
                    n--;
                    p=(struct player *) realloc (p ,sizeof (struct player));
                 }

                break;
              case 4:
                printf("Enter the id of player you want to update:\n");
                scanf("%d",&newID);
                  printf("Enter the new name of player %d:\n",newID);
                scanf("%s",&name);


                for(i=0;i<n;i++)
                {
                    if((p+i)->id == newID)
                    {
                         strcpy((p+i)->name,name);
                         index=1;
                         break;
                    }
                }
                if(index)
                {
                    printf("Updated successfully!\n");
                }
                else 
                {
                    printf("Not update!\n");
                }
            
                 break; 
             case 5:
             for (i=0 ; i<n-1 ;i++)
             {
                for(j=0;j<n-i-1;j++)
                {
                    if((p+j)->highest_kills > (p+j+1)->highest_kills)
                    {
                       temp = *(p+j) ;
                       *(p+j)= *(p+j+1);
                       *(p+j+1)= temp;
                    }
                }
            }
                   printf("Players sorted by highest kills in descending order.\n");
                   break;

             default:
            printf("Invalid input!\n");
                break;
            }
        } 
    }
    free(p);
    return 0;
    
}