#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define CHOICES 3

void welcome();
int win(int, int);

int main(){

    welcome();

    int numberSecret = 42, choice = 0, hit = 0, try = 0;
    double point = 1000.00, pointLeft = 0.0;

    // generator of numbers random
    srand(time(0));

    // Number random between 0 e 99
    numberSecret = rand() % 100;

    printf("Number secret: %d\n", numberSecret);


    while(1){

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
            break;
        }
        else if(greather){
            printf("\nYour choice is greather than the number secret\n\n");
        }
        else{
            printf("\nYour choice is less than the number number secret\n\n");
        }

        pointLeft = (double)(numberSecret - choice) / 2.0;
        point -= abs(pointLeft);

        try ++;

    }

    printf("Total of points: %.2lf\n", point);
    printf("Quantity of try: %d\n", try);


    return 0;
}



void welcome(){

       printf("\n************************************\n");
       printf("* Welcome to the game of quiz *\n");
       printf("************************************\n\n");
}
