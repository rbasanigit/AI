#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void user_guess(int num, int *user_points) {
    int guess, ch = 5;
    printf("\nUser's turn to guess:\n");

    while (ch != 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (num == guess) {
            printf("Correct! The number is %d\n", num);
            (*user_points)++;
            printf("Your score is %d.\n", *user_points);
            break;
        } else if (num > guess) {
            printf("The number is greater than your guess. Try again!\n");
        } else {
            printf("The number is lesser than your guess. Try again!\n");
        }
        ch--;
    }

    if (ch == 0 && num != guess) {
        printf("You Lost! The correct number was %d.\n", num);
    }
}

void computer_guess(int num, int *comp_points) {
    int guess, ch = 5;
    printf("\nComputer's turn to guess:\n");

    while (ch != 0) {
        guess = rand() % 100 + 1;
        printf("Computer guesses: %d\n", guess);

        if (num == guess) {
            printf("Correct! The number is %d\n", num);
            (*comp_points)++;
            printf("Computer's score is %d.\n", *comp_points);
            break;
        } else if (num > guess) {
            printf("The number is greater than computer's guess.\n");
        } else {
            printf("The number is lesser than computer's guess.\n");
        }
        ch--;
    }

    if (ch == 0 && num != guess) {
        printf("Computer Lost! The correct number was %d.\n", num);
    }
}

int main() {
    int num, play = 1, user_points = 0, comp_points = 0, rounds = 0;
    char continue_play;

    printf("Press 1 to play: ");
    scanf("%d", &play);

    srand(time(0)); 

    while (play == 1 && rounds < 5) {
        num = rand() % 100 + 1;

        user_guess(num, &user_points);

        num = rand() % 100 + 1;

        computer_guess(num, &comp_points);

        rounds++;
        printf("\nRound %d complete. User points: %d, Computer points: %d\n", rounds, user_points, comp_points);

        if (rounds < 5) {
            printf("Do you want to continue playing? (y/n): ");
            scanf(" %c", &continue_play); 
            if (continue_play == 'n' || continue_play == 'N') {
                break;
            }
        }
    }

    if (user_points > comp_points) {
        printf("\nUser wins with %d points!\n", user_points);
        printf("Computer loses with %d points.\n", comp_points);
    } else if (comp_points > user_points) {
        printf("\nComputer wins with %d points!\n", comp_points);
        printf("User loses with %d points.\n", user_points);
    } else {
        printf("\nIt's a tie! Both user and computer have %d points.\n", user_points);
    }

    return 0;
}
