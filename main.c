#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int won = 0;
int lose = 0;
char word[20];
char user_input[2];
char guess;
char status[20];
int length;
int i;
int lives = 3;

void getWord(){
    printf("Enter the word: ");
    scanf(" %s", word);
    printf("\n");
    length = strlen(word);
    for (int j = 0; j < length; j++) {
        status[j] = '_';
    }
}

void requestLetter(){
    int valid = 0;
    while(valid == 0){
        printf("Enter your letter: ");
        scanf(" %s", user_input);
        if(strlen(user_input) == 1 ){
            valid = 1;
        } else {
            printf("Invalid input. Please enter a single letter.\n\n");
        }
    }
    guess = user_input[0];
}

void checkLetter(char status[], char word[], int length, char guess, int *lives){
    int correct = 0;
    for(i = 0; i < length; i++){
        if(tolower(guess) == tolower(word[i])){
            status[i] = guess;
            correct = 1;
        }
    }
    if (correct == 0){
        (*lives)--;
    }
}

void printProgress(char status[], int lives){
    printf("So far, you have: %s\nWith %d lives left\n\n", status, lives);
}

int checkWin(char status[], char word[], int length){
    for(i = 0; i < length; i++){
        if(tolower(status[i]) != tolower(word[i])){
            return 0;
        }
    }
    return 1;
}

int checkLose(int lives){
    if(lives == 0){
        return 1;
    } else {
    return 0;
    }
}


int main()
{
    getWord();
    while(won == 0 && lose == 0){
        requestLetter();
        checkLetter(status, word, length, guess, &lives);
        printProgress(status, lives);
        won = checkWin(status, word, length);
        lose = checkLose(lives);
    }
    if(won == 1){
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}
