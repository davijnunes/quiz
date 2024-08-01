#include <stdio.h>
#include <stdlib.h>
#define CHOICES 3

void welcome();
int win(int, int);

int main(){

    welcome();

    int numberSecret = 42, choice = 0, hit = 0, try = 0;
    


    while(!hit){

        printf("Your %d chance: ", try+1);
        scanf("%d", &choice);


        int win = numberSecret == choice;
        int greather = choice > numberSecret;

        if(choice < 0) {
            printf("\nEnter a numbers positive!\n\n");
            continue;
        }


        if(win){
            printf("\nCongratulations!\n\n");
            hit = 1;
        }
        else if(greather){
            printf("\nYour choice is greather than the number secret\n\n");
        }
        else{
            printf("\nYour choice is less than the number number secret\n\n");
        }

        try ++;

    }

    printf("Quantity of try: %d", try);

    


    return 0;
}



void welcome(){

       printf("\n************************************\n");
       printf("* Welcome to the game of quiz *\n");
       printf("************************************\n\n");
}

