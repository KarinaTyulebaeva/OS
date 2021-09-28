#include <stdio.h>

#define MAX_NUMBER_OF_PROCESS 10

int main() {
    int BT[MAX_NUMBER_OF_PROCESS];
    int AT[MAX_NUMBER_OF_PROCESS];
    int ET[MAX_NUMBER_OF_PROCESS];
    int TAT[MAX_NUMBER_OF_PROCESS];
    int WT[MAX_NUMBER_OF_PROCESS];
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("AT of process number %d : ", i + 1);
        scanf("%d", &AT[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("BT of process number %d : ", i + 1);
        scanf("%d", &BT[i]);
    }

    int current_time = AT[0];
    for (i = 0; i < n; i++) {
        current_time += BT[i];
        ET[i] = current_time; 

        TAT[i] = ET[i] - AT[i]; 
        totalTAT += TAT[i];

        WT[i] = TAT[i] - BT[i]; 
        totalWT += WT[i];
    }

    printf("Processrocess#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("Process%d\t %d\t %d\t %d\t %d\t %d\n", i+1, AT[i], BT[i], ET[i], TAT[i], WT[i]);

    printf("Average TAT: %f\n", totalTAT/n);
    printf("Average WT: %f\n", totalWT/n);
}
