
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CHOICES 3
#define EASY 1
#define AVERAGE 2
#define DIFFICULTY 3

// Prototypes
void welcome();
double lostPoints(int, int);
int random();
int attempsInGame();

// Enter point
int main(){

    welcome();

    int numberSecret = 42, choice = 0,  attempts = 0, win = 0, greather, runningGame = 0;

    double points = 1000.00;

    // use function to return value random
    numberSecret = random();



    //printf("Debugging: %d\n",attempts);

    printf("\n");

    while(!runningGame){

               // Use function to return quantity of attempts
               attempts = attempsInGame();

               printf("\n");

        for(int i = 0; i < attempts; i++){

            printf("-> Your %d chance: ", i+1);
            scanf("%d", &choice);

            printf("\n");

            win = numberSecret == choice;
            greather = choice > numberSecret;

            if(choice < 0) {
                printf("\n\nEnter a numbers positive!\n\n");
                i--;
                continue;
            }

            if(win){
                break;
            }
            else if(greather){
                printf("\nYour choice is greather than the number secret\n\n");
            }
            else{
                printf("\nYour choice is less than the number number secret\n\n");
            }

            // Function return a quantity of  points lost
            points -= lostPoints(numberSecret,choice);



        }

            printf("Want to play again, enter (0 to yes or 1 to no):  ");
            scanf("%d", &runningGame);

    }

    // Verify if user win or no
        if(win){
            printf("\nCogratulations!\n");
        }
        else{
            printf("\nTry new!\n");
        }

    // Show punctuation
    printf("Your pontuation: %.2lf\n", points);

    return 0;
}

// Function to show welcome for user
void welcome(){

        printf("\n\n");
        printf("          P  /_\\  P                              \n");
        printf("         /_\\_|_|_/_\\                            \n");
        printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
        printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
        printf("    |\" \"  |  |_|  |\"  \" |                     \n");
        printf("    |_____| ' _ ' |_____|                         \n");
        printf("          \\__|_|__/                              \n");
        printf("\n\n");
}

// Calculation of points lost
double lostPoints(int numberSecret, int choice){

    double pointsLost =  (double) (numberSecret - choice) / 2.00;

    // function to value absolute of numbers double
    return fabs(pointsLost);


}

// Generate number random
int random(){

    // We set the seed to the current time value
    srand(time(0));

    // return number random beetwen 0 and 99
    return rand() % 100;
}

// return attemps
int attempsInGame(){

    int lvl = 0;

    printf("What's is the difficulty level?\n");
    printf("(1) Easy\n(2) Average\n(3) difficult\n\n");
    printf("Choice: ");
    scanf("%d", &lvl);


    switch (lvl){

        case EASY:
            return 20;
        case AVERAGE:
            return 15;
        case DIFFICULTY:
            return 6;
        default:
            return 6;
    }

}
