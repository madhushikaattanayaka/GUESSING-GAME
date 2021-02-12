#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 200     // upper limit of the guessing numbers
#define CHANCES 10      // number of chances a player has given

      

int main(int argc, char **argv)
{
    char name[30];          // the name of the player
	int number =rand() % MAX_NUM + 1;      // making a random number
    int value;      // checking whether the user inputs are valid or not.
    int guess;	// player's guessing numbers
    int guess_count = 1;    // counting the guessing chances
    char fname[] = "guessingLog.txt";
    FILE * fp = fopen(fname,"a");

    printf("       ...$$$ '''Guess & Win''' $$$...\n\n");
    printf("<<< Created by #AA2104 W.P.Rashmi Prabodya >>>\n\n");

    printf("Enter your name here : ");

    scanf("%s", name);
    printf("Hi %s ! Welcome to my guessing game.\n\n",name);

    printf("    ==> I have a number between 1 and %d.\n", MAX_NUM);     // Instructions to play
    printf("    ==> If you guess the number correctly you will win this game.\n");
    printf("    ==> You have only %d chances to guess the correct number.\n\n", CHANCES);
    printf("LET'S START !!!...\n\n");

   
	if(fp == NULL){
                printf("Could not open %s the file\n", fname);
                return -1;
            }

    while(guess != number && guess_count <= CHANCES){

        if(guess_count <= CHANCES){
            printf("Guessing chance %d : ", guess_count);
            value = scanf("%d", &guess);
        
            
            fprintf(fp, "%s , %d , %d\n", name,guess_count,guess);

            guess_count ++;

            if(value == 1){
                if(guess > number)
                    printf("%d is higher than my number.\n\n", guess);
                else if(guess < number)
                    printf("%d is lower than my number.\n\n", guess);
                else{
                    printf("Congratulations %s!... You won the game.\n", name);
                    break;
                }
            }
            else{
                scanf("%*[^\n]");
                printf("Invalid guess. Try again...\n");
                guess_count --;
                continue;
            }
        }
       
    }

    if(guess_count > CHANCES){
            printf("Sorry %s!... Your guessing chances are over.\n", name);
            printf("My number is %d\n", number);
            printf("You lost the game.\n");
    }
	 fclose(fp);

    return 0;
}