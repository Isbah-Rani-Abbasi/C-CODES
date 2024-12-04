# include<stdio.h>
# include<string.h>
struct player
{
    char name[50];
    int  id;
    int highest_kills;
    int highest_deaths;
};
void add()
{
   FILE *fptr;
   fptr = fopen ("player.txt" , "a");

   if ( fptr ==NULL)
   {
      printf("File is not opening.\n");
   }
   else
   {
      int n , i;
      printf("Enter the no of players you want to add.\n");
      scanf("%d" , &n);
      struct player p[n];
       
       
      for (i=0 ; i<n ; i++)
      {
        printf("Enter the name of player %d:\n" , i+1);
        //gets(p[i].name);
        getchar();
        fgets(p[i].name , sizeof(p[i].name) , stdin);
        p[i].name [strcspn ( p[i].name , "\n")] = '\0';
        printf("Enter the id of player %d:\n" , i+1);
        scanf("%d",&p[i].id);
        printf("Enter the highest kill of player %d:\n" , i+1);
        scanf("%d",&p[i].highest_kills);
        printf("Enter the highest deaths of player %d:\n" , i+1);
        scanf("%d",&p[i].highest_deaths);
      }


      for ( i =0 ; i<n ; i++)
      {
        fprintf( fptr ,"The name of player:%s\n" , p[i].name);
        fprintf( fptr ,"The id of player:%d\n" , p[i].id );
        fprintf( fptr ,"The highest kills of player:%d\n" , p[i].highest_kills);
        fprintf( fptr ,"The highest deaths of player:%d\n" , p[i].highest_deaths);
      }
     fclose(fptr);
   }
}
void update()
{
    FILE *fptr , *temp ;
    fptr = fopen("player.txt" , "r");

    if (fptr == NULL)
    {
        printf("Player file is not opening!\n");
        return;
    }

    temp = fopen("temp.txt" , "w");

    if (temp == NULL)
    {
        printf("Temp file is not opening!\n");
        fclose(fptr);
        return;
    }

    struct player p ; int yes=0;
    int id , newKill , newDeath ;
    printf("Enter the id of player whose highest score you want to update:\n");
    scanf("%d",&id);
    printf("Enter the new highest kills for player with id %d:\n" , id);
    scanf("%d",&newKill);
    printf("Enter the new highest deaths for player with id %d:\n" , id);
    scanf("%d",&newDeath);

    while ( fscanf( fptr ,"The name of player:%s\n" , &p.name) == 1 )
    {
        fscanf( fptr ,"The id of player:%d\n" , &p.id );
        fscanf( fptr ,"The highest kills of player:%d\n" , &p.highest_kills);
        fscanf( fptr ,"The highest deaths of player:%d\n" , &p.highest_deaths);

        if ( p.id == id)
        {
            p.highest_kills=newKill;
            p.highest_deaths=newDeath;
            yes = 1;
        }

        fprintf( temp ,"The name of player:%s\n" , p.name);
        fprintf( temp ,"The id of player:%d\n" , p.id );
        fprintf( temp ,"The highest kills of player:%d\n" , p.highest_kills);
        fprintf( temp ,"The highest deaths of player:%d\n" , p.highest_deaths);
    }
    
    if (yes)
    {
        printf("Data is updted successfully for %d", id);
    }
    else
    {
       printf("Data is not updated for %d", id);
    }
    fclose(fptr);
    fclose(temp);

    remove("player.txt");
    rename("temp.txt" , "player.txt");
    

}
void read()
{
    FILE *fptr;
    struct player p , max_kills, max_ratio;
    int high_kills = 0; int max;
    int ratio=0;
    fptr = fopen("player.txt" , "r");

    if ( fptr ==NULL)
    {
        printf("File is not opening!\n");
        return;
    }

    
        
        while (fscanf( fptr ,"The name of player:%[^\n]\n" , &p.name) == 1 )
        {
            fscanf( fptr ,"The id of player:%d\n" , &p.id );
            fscanf( fptr ,"The highest kills of player:%d\n" , &p.highest_kills);
            fscanf( fptr ,"The highest deaths of player:%d\n" , &p.highest_deaths);

            if (p.highest_kills > high_kills)
            {
                high_kills = p.highest_kills;
                max_kills=p;

            }
            if (p.highest_deaths != 0 )
            {
                max=p.highest_kills/p.highest_deaths;
                if (max > ratio)
            {
                ratio = p.highest_kills/p.highest_deaths;
                max_ratio=p;
            }

            }
            
          
        }

      
          
            
                printf("Player with highest kills:\n");
                printf( "The name of player:%s\n" , max_kills.name);
                printf( "The id of player:%d\n" , max_kills.id );
                printf( "The highest kills of player:%d\n" , max_kills.highest_kills);
                printf( "The highest deaths of player:%d\n" , max_kills.highest_deaths);
            
        
                printf("Player with highest kills to death ratio:\n");
                printf( "The name of player:%s\n" , max_ratio.name);
                printf( "The id of player:%d\n" , max_ratio.id );
                printf( "The highest kills of player:%d\n" , max_ratio.highest_kills);
                printf( "The highest deaths of player:%d\n" , max_ratio.highest_deaths);
            
        

        fclose(fptr);
        
        
    
}

void delete()
{
    FILE *fptr , *temp ;
    fptr = fopen("player.txt" , "r");

    if (fptr == NULL)
    {
        printf("Player file is not opening!\n");
        return;
    }

    temp = fopen("temp.txt" , "w");

    if (temp == NULL)
    {
        printf("Temp file is not opening!\n");
        fclose(fptr);
        return;
    }

    struct player p ; int yes=0;
    int id , newKill , newDeath ;
    printf("Enter the id of player whose highest score you want to delete:\n");
    scanf("%d",&id);
     while ( fscanf( fptr ,"The name of player:%s\n" , &p.name) == 1 )
    {
        fscanf( fptr ,"The id of player:%d\n" , &p.id );
        fscanf( fptr ,"The highest kills of player:%d\n" , &p.highest_kills);
        fscanf( fptr ,"The highest deaths of player:%d\n" , &p.highest_deaths);

        if ( p.id != id)
        {
        fprintf( temp ,"The name of player:%s\n" , p.name);
        fprintf( temp ,"The id of player:%d\n" , p.id );
        fprintf( temp ,"The highest kills of player:%d\n" , p.highest_kills);
        fprintf( temp ,"The highest deaths of player:%d\n" , p.highest_deaths);
        
        }
        else
        {
            yes = 1;
        }

       
    }
     if (yes)
    {
        printf("Data is deleted successfully for %d", id);
    }
    else
    {
       printf("Data is not deleted for %d", id);
    }
    fclose(fptr);
    fclose(temp);

    remove("player.txt");
    rename("temp.txt" , "player.txt");
    



}
int main()
{
    int n;
    while (1)
    {
        printf("\n0.Exit\n");
        printf("1.Add\n");
        printf("2.Update\n");
        printf("3.Read\n");
        printf("4.Delete\n");
        printf("Select a number between 0 to 4\n");
        scanf("%d",&n);
        if( n == 0 )
        {
            printf("End Program\n");
            break;
        }
        else
        {
            switch (n)
            {
            case 1:
                add();
                break;
            case 2:
               update();
                break;
            case 3:
                read();
                break;
            case 4:
                delete();
                break;            
            
            default:
            printf("Invalid input!\n");
                break;
            }
        }
    }
    
}