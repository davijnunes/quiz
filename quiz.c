<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define CHOICES 3

void welcome();
double lostPoints(int, int);

int random();

int main(){

    welcome();

    int numberSecret = 42, choice = 0,  try = 0;

    double points = 1000.00;


    // use function to return value random
    numberSecret = random();



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

        points -= lostPoints(numberSecret,choice);
        try ++;

    }

    printf("Quantity of try: %d\n", try);

    printf("Your pontuation: %.2lf\n", points);




    return 0;
}

void welcome(){

       printf("\n************************************\n");
       printf("* Welcome to the game of quiz *\n");
       printf("************************************\n\n");
}

double lostPoints(int numberSecret, int choice){

    double pointsLost =  (double) (numberSecret - choice) / 2.00;

    // function to value absolute of numbers double
    return fabs(pointsLost);


}

int random(){

    // We set the seed to the current time value
    srand(time(0));

    // return number random beetwen 0 and 99
    return rand() % 100;
}

