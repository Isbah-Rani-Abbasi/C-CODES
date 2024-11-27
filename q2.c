// Write a program that organizes a digital cricket match, "Cricket Showdown," where two players,
// Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each
// ball. Players can enter scores between 0 and 6 for each ball, and if a score outside this range is
// entered, it will be disregarded, but the ball will still be marked.
// 1. Define a structure Player with the following members:
// a. ballScores[12]: An array to store the score for each ball.
// b. playerName: A string to hold the player's name.
// c. totalScore: An integer to store the total score for each player.
// 2. Define functions:
// a. playGame(struct Player player): This function prompts each player to enter their
// score for each of the 12 balls.
// b. validateScore(int score): This function checks if the score is between 0 and 6
// (inclusive). If it’s not, the score is disregarded, but the ball is still marked.
// c. findWinner(struct Player player1,struct Player player2): Determines the winner
// based on the total score.
// d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
// summary of each player’s performance, including each ball’s score, the average
// score, and total score.
# include<stdio.h>
# include<string.h>
struct player
{
    char playername[20];
    int ball_score[12];
    int total_score;
};
void playgame(struct player *P1,struct player *P2);
void validscore(struct player *score1,struct player *score2);
void findWinner(struct player *P1,struct player *P2);
void displaymatchscoreboard(struct player P1,struct player P2);

void main()
{
   struct player p1,p2;
   printf("Enter player 1 name:\n");
   
   fgets(p1.playername,20,stdin);
   p1.playername[strcspn(p1.playername,"\n")]='\0';
   printf("Enter player 2 name:\n");
   
   fgets(p2.playername,20,stdin);
   p2.playername[strcspn(p2.playername,"\n")]='\0';
    p1.total_score=0;
    p2.total_score=0;
   playgame(&p1,&p2);
   validscore(&p1,&p2);
   findWinner(&p1,&p2);
   if(p1.total_score>p2.total_score)
   {
       printf("%s is winner.\n",p1.playername);
   }
   else if(p1.total_score<p2.total_score)
   {
      printf("%s is winner.\n",p2.playername);
   }
   else
   {
      printf("TIE!\n");
   }
   displaymatchscoreboard(p1,p2);

}
void playgame(struct player *P1,struct player *P2)
{
   int i;
   for(i=0;i<12;i++)
   {
    printf("enter score of %d ball of player 1.\n",i+1);
    scanf("%d",&P1->ball_score[i]);
   }
   for(i=0;i<12;i++)
   {
    printf("enter score of %d ball of player 2.\n",i+1);
    scanf("%d",&P2->ball_score[i]);
   }
}
void validscore(struct player *score1,struct player *score2)
{
   int i;
   for(i=0;i<12;i++)
   {
     if (score1->ball_score[i]<0||score1->ball_score[i]>6)
     {
       score1->ball_score[i]=0;
     }
   }
   for(i=0;i<12;i++)
   {
     if (score2->ball_score[i]<0||score2->ball_score[i]>6)
     {
       score2->ball_score[i]=0;
     }
   }
}
void findWinner(struct player *P1,struct player *P2)
{
    int i;

    for(i=0;i<12;i++)
    {
       P1->total_score+=P1->ball_score[i];
    }
    for(i=0;i<12;i++)
    {
       P2->total_score+=P2->ball_score[i];
    }
}
void displaymatchscoreboard(struct player P1,struct player P2)
{
   int i;
   printf("Score board of %s is :\n",P1.playername);
   for(i=0;i<12;i++)
   {
     printf("%d score of %d ball.\n",P1.ball_score[i],i+1);
   }
   printf("Total score of %s is %d :\n",P1.playername,P1.total_score);
   printf("Average score of %s is %f :\n",P1.playername,(float)P1.total_score/12);


    printf("Score board of %s is :\n",P2.playername);
   for(i=0;i<12;i++)
   {
     printf("%d score of %d ball.\n",P2.ball_score[i],i+1);
   }
     printf("Total score of %s is %d :\n",P2.playername,P2.total_score);
     printf("Average score of %s is %f :\n",P2.playername,(float)P2.total_score/12);

}