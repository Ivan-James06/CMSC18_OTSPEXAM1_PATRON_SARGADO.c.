/* PATRON AND SARGADO, M-2L, Problem 3 */
#include <stdio.h>

void printArray(int *arr, int n)
{
  /* Dereferencing where p is equal to the number of arrays  */
  int *p = arr;
    while (p < arr + n) {
        if (p != arr) printf(" ");
        printf("%d", *p);
        p++;
    }
    printf("\n");
}

int main()
{
    int arr[20];
    int n, i, sum = 0, temp;
    int *p, *left, *right;

    printf("Enter N: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Invalid N.\n");
        return 0;
    }

    printf("Enter %d integers: ", n);
    for (p = arr; p < arr + n; p++)
        scanf("%d", p);

    printf("Original: ");
    printArray(arr, n);

    /* reverse in place: swap from both ends moving inward */
    left = arr;
    right = arr + n - 1;
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    printf("Reversed: ");
    printArray(arr, n);

    for (p = arr; p < arr + n; p++)
        sum += *p;
    printf("Sum: %d\n", sum);

    /* double elements at even indices */
    for (i = 0; i < n; i += 2)
        *(arr + i) *= 2;
    printf("Final: ");
    printArray(arr, n);
    return 0;
}
