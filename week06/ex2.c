#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NUMBER_OF_PROCESS 10

int main() {
    int BT[MAX_NUMBER_OF_PROCESS];
    int AT[MAX_NUMBER_OF_PROCESS];
    int TAT[MAX_NUMBER_OF_PROCESS];
    int WT[MAX_NUMBER_OF_PROCESS];
    int ET[MAX_NUMBER_OF_PROCESS];
    bool executed[MAX_NUMBER_OF_PROCESS];

    int n, minAT = INT_MAX;
    float totalTAT = 0, totalWT = 0;
  
    printf("Enter number of processes: ");
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        executed[i] = false;

        printf("AT of process number %d : ", i + 1);
        scanf("%d", &AT[i]);
        if (AT[i] < minAT)
            minAT = AT[i];
    }
  
    for (int i = 0; i < n; i++) {
        printf("BT of process number %d : ", i + 1);
        scanf("%d", &BT[i]);
    }

    int current_time = minAT;
    int pos = 0, minBT = INT_MAX;
    for (int i = 0; i < n; i++) {    
        for (int j = 0; j < n; j++) {
            if (!executed[j] && AT[j] <= current_time && BT[j] < minBT) {
                pos = j;
                minBT = BT[j];
            }
        }

        executed[pos] = true;
        current_time += BT[pos];
        ET[pos] = current_time; 

        TAT[pos] = ET[pos] - AT[pos]; 
        totalTAT += TAT[pos];

        WT[pos] = TAT[pos] - BT[pos]; 
        totalWT += WT[pos];
    }
  
    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, AT[i], BT[i], ET[i], TAT[i], WT[i]);

    printf("Average TAT : %f\n", totalTAT/n);
    printf("Average WT : %f\n", totalWT/n);
}
