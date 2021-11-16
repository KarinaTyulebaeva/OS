#include <stdio.h>

int check(int A[], int R[], int n){
    for(int i = 0; i < n; ++i){
        if(A[i] < R[i]){
            return 0;
        }
    }
    return 1;
}


int main() {
    // Input
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int rows, cols; // rows = 5, cols = 3
    fscanf(input, "%d%d", &rows, &cols);
    int E[cols], A[cols], unmarked[rows];
    for (int i = 0; i < cols; ++i) {
        fscanf(input, "%d", &E[i]);
    }
    for (int i = 0; i < cols; ++i) {
        fscanf(input, "%d", &A[i]);
    }
    int C[rows][cols], R[rows][cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(input, "%d", &C[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(input, "%d", &R[i][j]);
        }
        unmarked[i] = 1;
    }
    // Algorithm
    int flag;
    for(int i = 0; i < rows; ++i){
        flag = 1;
        for(int j = 0; j < rows; ++j){
            if(unmarked[j] == 1 && check(A, R[j], cols) == 1){
                flag = 0;
                unmarked[j] = 0;
                for(int k = 0; k < cols; ++k){
                    A[k] += C[i][k];
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < rows; ++j){
            sum += unmarked[j];
        }
        if(sum == 0){
            break;
        }
        if(flag == 1){
            fprintf(output, "Deadlock detected!\n");
            fprintf(output, "Number of deadlocked processes: %d\n", sum);
            return 0;
        }
    }

    for(int i = 0; i < cols; ++i){
        fprintf(output, "A[%d] = %d ", i, A[i]);
    }
    fprintf(output, "\n");
    fprintf(output, "No deadlock is detected\n");
    fclose(input);
    fclose(output);
    return 0;
}
