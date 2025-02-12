#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, i, j;

    // Input the number of rows in the ragged array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Array of pointers to hold each row of the ragged array
    int* jaggedArray[rows];

    // Input the number of columns for each row and allocate memory
    for (i = 0; i < rows; i++) {
        int cols;

        // Input the number of columns for the current row
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &cols);

        // Allocate memory for the current row
        jaggedArray[i] = (int*)malloc(cols * sizeof(int));

        // Check if memory allocation was successful
        if (jaggedArray[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i + 1);
            return -1;  // Exit if memory allocation fails
        }

        // Input elements for the current row
        printf("Enter %d elements for row %d: ", cols, i + 1);
        for (j = 0; j < cols; j++) {
            scanf("%d", &jaggedArray[i][j]);
        }
    }

    // Print the jagged array
    printf("\nJagged Array:\n");
    for (i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < sizeof(jaggedArray[i]) / sizeof(jaggedArray[i][0]); j++) {
            printf("%d ", jaggedArray[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (i = 0; i < rows; i++) {
        free(jaggedArray[i]);
    }

    return 0;
}
