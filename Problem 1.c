/*PATRON AND SARGADO, M-2L, Problem 1*/

#include <stdio.h>
#define MAX 50

int main()
{
    int scores[MAX];
    int n, i;
    int highest, lowest, above = 0;
    long sum = 0;
    double average;

    printf("Enter number of scores: ");
    scanf("%d", &n);
    /* Number of scores where negative integers and more than the MAX is invalid */
    if (n < 1 || n > MAX) {
        printf("Invalid number of scores.\n");
        return 0;
    }
    /* Scores where all non-negative integers can be input */
    printf("Enter the scores: ");
    for (i = 0; i < n; i++)
        scanf("%d", &scores[i]);
    
    /* Scores where the highest and lowest scores shown in the output */
    highest = lowest = scores[0];
    for (i = 0; i < n; i++) {
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest)  lowest  = scores[i];
        sum += scores[i];
    }
    /* Average scores of the input scores */
    average = (double)sum / n;
    
    /* Number of scores that is above average */
    for (i = 0; i < n; i++)
        if (scores[i] > average) above++;

    /* capacity computed with sizeof: total bytes / bytes per element */
    printf("Array capacity: %d\n", (int)(sizeof(scores) / sizeof(scores[0])));
    printf("Highest: %d\n", highest);
    printf("Lowest: %d\n", lowest);
    printf("Average: %.2f\n", average);
    printf("Above average: %d\n", above);
    return 0;
}
