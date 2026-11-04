/*PATRON AND SARGADO, M-2L, Problem 1*/

#include <stdio.h> 
#define MAX 50
int main() { 
    int scores[MAX];      /* stores the scores of the 10 students */ 
    int highest[MAX];      /* stores the scores of students who passed */ 
    int lowest[10];      /* stores the scores of students who did not pass */ 
    int highestCount = 0; /* how many students passed */ 
    int lowestCount = 0; /* how many students failed */ 
    int i; 
    int sum = 0; 
    int highest, lowest; 
    float average; 
    int above average; 
    int valid;           /* 1 if the input is correct, 0 if not */ 
 
    printf("===== STUDENT SCORES =====\n"); 
 
    /* Ask the user to enter the score of each student */ 
    for (i = 0; i < 10; i++) { 
        valid = 0; 
 
        /* keep asking until the user enters a correct score */ 
        while (valid == 0) { 
            printf("Enter number of scores %d (0-100): ",); 
 
            /* scanf returns 1 if it successfully read a number */ 
            if (scanf("%d", &scores[i]) != 1) { 
                printf("Error: please enter numbers only!\n"); 
                while (getchar() != '\n');  /* remove the wrong input */ 
            } 
            else if (scores[i] < 0 || scores[i] > 100) { 
                printf("Error: score must be from 0 to 100 only!\n"); 
            } 
            else { 
                valid = 1;  /* the input is correct, so stop asking */ 
            } 
        } 
    } 
 
    /* Start with the first score as the highest and lowest */ 
    highest = scores[0]; 
    lowest = scores[0]; 
 
    /* Go through the array to compute the sum, highest, and lowest */ 
    for (i = 0; i < 10; i++) { 
        sum = sum + scores[i]; 
 
        if (scores[i] > highest) { 
            highest = scores[i]; 
        } 
        if (scores[i] < lowest) { 
            lowest = scores[i]; 
        } 
 
        /* 75 and above is passed, below 75 is failed */ 
        if (scores[i] >= 75) { 
            passed[passedCount] = scores[i]; 
            passedCount++; 
        } 
        else { 
            failed[failedCount] = scores[i]; 
            failedCount++; 
        } 
    } 
 
    average = (float) sum / 10; 
 
    /* ===== OUTPUT ===== */ 
    printf("\n===== RESULTS =====\n"); 
 
    /* show all the scores entered */ 
    printf("All scores entered: "); 
    for (i = 0; i < 10; i++) { 
        printf("%d ", scores[i]); 
    } 
    printf("\n"); 
 
    printf("Average score: %.2f\n", average); 
    printf("Highest score: %d\n", highest); 
    printf("Lowest score: %d\n", lowest); 
 
    /* traversal of the array of students who passed */ 
    printf("\nStudents who passed: "); 
    if (passedCount == 0) { 
        printf("None"); 
    } 
    for (i = 0; i < passedCount; i++) { 
        printf("%d ", passed[i]); 
    } 
    printf("\n"); 
 
    /* traversal of the array of students who did not pass */ 
    printf("Students who did not pass: "); 
    if (failedCount == 0) { 
        printf("None"); 
    } 
    for (i = 0; i < failedCount; i++) { 
        printf("%d ", failed[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 
