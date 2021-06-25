// A rock-paper-scissor game created using C

// -----README-----
// Choose 0 to quit, 1 for rock, 2 for paper, and 3 for scissors
// First player to 5 points wins
// ----------------


# include<stdio.h>
# include<stdlib.h>
# include<time.h>


typedef struct player{
    int points;
    int choice;
}Player;


void play_one_round(Player *p1, Player *p2, int *quit); // This function will conduct one round of rock-paper-scissor, and update the scores according to the results

int main(){
    int quit = 0;
    int *q = &quit;
    Player player1 = {0, 4}, player2 = {0, 4};
    Player *p1 = &player1, *p2 = &player2;

    while((p1->points<5) && (p2->points<5) && (!quit)){
        play_one_round(p1, p2, q);
    }

    if(quit){
        printf("Program exited.");
    }

    else if(player1.points==5){
        printf("Congrats, Player 1 has won.");
    }
    
    else if(player2.points==5){
        printf("Congrats, Player 2 has won.");
    }

    return 0;
}


void play_one_round(Player *p1, Player *p2, int *quit){
    // Player 1's Turn
    printf("Player 1's option (1 for rock, 2 for paper, 3 for scissor, and 0 to quit): ");
    scanf("%d", &p1->choice);
    fflush(stdin);

    // Preventing Player 1's invalid input
    while((p1->choice<0 || (p1->choice>3))){
        printf("Invalid Option. Please try again. \n");
        printf("Player 1's option (1 for rock, 2 for paper, 3 for scissor, and 0 to quit): ");
        scanf("%d", &p1->choice);
        fflush(stdin);
    } 

    // Player 2's Turn
    srand(time(0));
    int choice = (rand() % (3)) + 1;
    p2->choice = choice;
    // printf("Player 2's option (1 for rock, 2 for paper, 3 for scissor, and 0 to quit): "); // (THIS CODE IS FOR WHEN PLAYER 2 IS A HUMAN PLAYER )
    // scanf("%d", &p2->choice);
    // fflush(stdin);

    // // Preventing Player 2's invalid input
    // while((p2->choice<0 || (p2->choice>3))){
    //     printf("Invalid Option. Please try again. \n");
    //     printf("Player 2's option (1 for rock, 2 for paper, 3 for scissor, and 0 to quit): ");
    //     scanf("%d", &p2->choice);
    //     fflush(stdin);
    // } 

    // Scenarios where either player quits
    if((p1->choice==0)||(p2->choice==0)){
        *quit = 1;
    }

    else{
        // Scenario where it is a draw
        if(p1->choice==p2->choice){
            printf("It's a tie! \n");
            printf("Points-- Player 1: %d points, Player 2: %d points \n",p1->points, p2->points);
        }

        // Scenarios where Player 1 wins
        else if(((p1->choice==1) && (p2->choice==3)) || ((p1->choice==2) && (p2->choice==1)) || ((p1->choice==3) && (p2->choice==2))){
            (p1->points)++;
            printf("Player 1 wins this round! \n");
            printf("Points-- Player 1: %d points, Player 2: %d points \n",p1->points, p2->points);
        }

        // Scenarios where Player 2 wins
        else if(((p2->choice==1) && (p1->choice==3)) || ((p2->choice==2) && (p1->choice==1)) || ((p2->choice==3) && (p1->choice==2))){
            (p2->points)++;
            printf("Player 2 wins this round! \n");
            printf("Points-- Player 1: %d points, Player 2: %d points \n",p1->points, p2->points);
        }
    }

}