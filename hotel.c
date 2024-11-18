# include<stdio.h>
# include<string.h>
struct bill
{
  char room_type[30];
  char room_type1[30];
  char room_services[30];
  char other_facilities[3][30];
  int cost;
  int discout;
}b1,b2,b3;
void hotel(char hotelname[]);
int main()
{
  char hotel123[30];
  printf("enter hotel\n");
  gets(hotel123);
  hotel(hotel123);
  return 0;
  
}
void hotel(char hotelname[])
{
    char name[30][30]={"Pearl Continental Hotel","Beach Luxury Hotel","Royal Inn Hotel","Xefan Hotel","Ambiance Boutique Hotel","Avari Towers Hotel","Days Inn Hotel","Burj Al Arab Hotel","Mandariab Oriental Hotel","Peninsula Hotel","pearl continental hotel","beach luxury hotel","royal inn hotel","xefan xotel","ambiance boutique hotel","avari towers hotel","days inn hotel","burj al arab hotel","mandariab oriental hotel","peninsula hotel","PEARL CONTINENTAL HOTEL","BEACH LUXURY HOTEL","ROYAL INN HOTEL","XEFAN HOTEL","AMBIANCE BOUTIQUE HOTEL","AVARI TOWERS HOTEL","DAYS INN HOTEL","BURJ AL ARAB HOTEL","MANDARIN ORIENTAL HOTEL","PENINSULA HOTEL"};

    int num_hotels=sizeof(name)/sizeof(name[0]);
    int i;
    int yes=0;
    int room;
    int room1;
    int roomservice;
    int service;
    int cost=0;
    int num_sercice=0;
    struct bill b1;
    for(i=0;i<num_hotels;i++)
    {
        if (strcmp(hotelname,name[i])==0)
        {
            yes=1;
            break;
        }
    }
    if(yes==1)
    {   
         printf("Welcome to %s!\n",hotelname);
         printf("Enter the type of room you want!\n");
         printf("Press 1 for single.\n");
         printf("Press 2 for double.\n");
         scanf("%d",&room);
         switch(room)
         {
            case 1:
            strcpy(b1.room_type,"Single");
            printf("Enter the type of room you want!\n");
            printf("Press 1 for Premium.\n");
            printf("Press 2 for VIP,\n");
            printf("Press 3 for Medium,\n");
            scanf("%d",&room1);
            cost+=10;
                switch (room1)
                  {
                  case 1:
                       //printf("You have alloted a Premium room.\n");
                       strcpy(b1.room_type1,"Premium");
                       cost+=20;
                       break;

                  case 2: 
                        //printf("You have alloted a VIP  room.\n");
                        strcpy(b1.room_type1,"VIP");
                        cost+=10;
                        break;

                  case 3:
                        //printf("You have alloted a Medium room.\n");
                        strcpy(b1.room_type1,"Medium");
                        cost+=5;
                        break;   
            
                  default:
                        break;
                   }
            break;

            case 2:
            strcpy(b1.room_type,"Double");
            printf("Enter the type of room you want!\n");
            printf("Press 1 for King and Queen.\n");
            printf("Press 2 for Family.\n");
            scanf("%d",&room1);
            switch (room1)
                  {
                  case 1:
                       //printf("You have alloted a Premium room.\n");
                       strcpy(b1.room_type1,"King and Queen");
                       cost+=20;
                       break;

                  case 2: 
                        //printf("You have alloted a VIP  room.\n");
                        strcpy(b1.room_type1,"Family");
                        cost+=10;
                        break;

            
                  default:
                        break;
                   }


         }
         printf("Welcome to room services!\"n");
         printf("Press 1 fro availing breakfast only.\n");
         printf("Press 2 for availing lunch only.\n");
         printf("Press 3 for availing Dinner only.\n");
         printf("Press 4 for availing all and you will get 20 percent discount.\n");
         scanf("%d",&roomservice);

         switch (roomservice)
         {
         case 1:
           strcpy(b1.room_services,"Breakfast");
           cost+=10;
            break;
         case 2:
           strcpy(b1.room_services,"Lunch");
            cost+=30;
           break;
         case 3:
           strcpy(b1.room_services,"Dinner"); 
            cost+=40; 
           break;
         case 4:
           strcpy(b1.room_services,"Lunch,Dinner, and Breakfast");   
           cost+=70;
         
         default:
            break;
         }
         printf("Welcome to hotel services!\n");
         printf("Press 0 to exit hotel services.\n");
         printf("Press 1 fro availing Parking.\n");
         printf("Press 2 for availing SPA.\n");
         printf("Press 3 for availing Swimming Pool.\n");
         printf("Press 4 for availing Fitness centre.\n");
         printf("Press 5 for availing Business centre.\n");
        
         while(1)
         {
         printf("Enter service choice from 0 t05\n");
         scanf("%d",&service);
         if(service==0)
         {
            break;
         }
         else if (service>=1&& service<=5)
         {

         
         switch (service)
         {
         case 1:
            strcpy(b1.other_facilities[num_sercice],"Parking");
            cost+=70;
            break;
          case 2:
            strcpy(b1.other_facilities[num_sercice],"SPA");
            cost+=70;
            break;
          case 3:
            strcpy(b1.other_facilities[num_sercice],"Swimming Pool");
            cost+=70;
            break;
          case 4:
            strcpy(b1.other_facilities[num_sercice],"Fitness Centre");
            cost+=70;
            break;
          case 5:
            strcpy(b1.other_facilities[num_sercice],"Bussiness");
            cost+=70;
            break;
           default:
          printf("invalid serive choice");
            break;
         }
         num_sercice++;
         }
         else 
         {
            printf("invalid serive choice");
         }
        }
    }
    else
    {
        printf("Hotel not found");
    }

    printf("your room type is %s\n",b1.room_type);
    printf("your room class is %s\n",b1.room_type1);
    printf("your room services is %s\n",b1.room_services);
    printf("your total cost is %d\n",cost);
    for(i=0;i<num_sercice;i++)
    {
           printf("your other facilities is %s\n",b1.other_facilities[i]);
    }

    }



     
  
