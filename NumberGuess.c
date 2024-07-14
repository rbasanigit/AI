#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int comp_points = 0;
int user_points = 0;

void comp_guess() {
    int begin = 1;
    int end = 100;
    printf("Computer's turn to guess the number (1-100):\n");
    for (int i = 0; i < 5; i++) {
        int mid = (begin + end) / 2;
        printf("%d\n", mid);
        char hint[10];
        printf("Enter if the guess is greater or lesser, or correct:");
        scanf("%s", hint);
        if (strcmp(hint, "greater") == 0) {
            begin = mid + 1;
        } 
        else if (strcmp(hint, "lesser") == 0) {
            end = mid - 1;
        } 
        else if (strcmp(hint, "correct") == 0) {
            printf("Computer wins!!\n");
            comp_points++;
            break;
        } 
        else {
            printf("Please enter 'greater', 'lesser', or 'correct':\n");
        }
    }
    if (comp_points == 0) {
        printf("Computer couldn't guess the number.\n");
    }
}

void user_guess() {
    srand(time(NULL));
    int num = rand() % 100 + 1;
    printf("User's turn to guess a number (1-100):\n");
    for (int i = 0; i < 5; i++) {
        int guess;
        printf("Enter your guess:");
        scanf("%d", &guess);
        if (guess < num) {
            printf("The number is greater. Try again!\n");
        } 
        else if (guess > num) {
            printf("The number is lesser. Try again!\n");
        } 
        else if (guess == num) {
            printf("User wins!!. The number is %d.\n", num);
            user_points++;
            break;
        } 
        else {
            printf("Please enter a valid number\n");
        }
    }
    if (user_points == 0) {
        printf("Couldn't guess the number. The correct number was %d\n", num);
    }
}

int main() {
    int rounds = 0;
    while (rounds < 5) {
        user_guess();
        comp_guess();
        rounds++;
        printf("Round %d complete. User points: %d, Computer points: %d\n", rounds, user_points, comp_points);
        if (rounds < 5) {
            char continue_play[2];
            printf("Do you want to continue playing? (y/n):");
            scanf("%s", continue_play);
            if (continue_play[0] == 'n') {
                break;
            }
        }
    }
    
    if (user_points > comp_points) {
        printf("\nUser wins with %d points!\nComputer loses with %d points.\n", user_points, comp_points);
    } 
    else if (comp_points > user_points) {
        printf("\nComputer wins with %d points!\nUser loses with %d points.\n", comp_points, user_points);
    } 
    else {
        printf("\nIt's a tie! Both user and computer have %d points.\n", user_points);
    }
    
    return 0;
}

