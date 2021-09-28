#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_PROCESS 10

int main() {
    int BT[MAX_NUMBER_OF_PROCESS];
    int AT[MAX_NUMBER_OF_PROCESS];
    int TAT[MAX_NUMBER_OF_PROCESS];
    int WT[MAX_NUMBER_OF_PROCESS];
    int ET[MAX_NUMBER_OF_PROCESS];
    int BT_original[MAX_NUMBER_OF_PROCESS];
    bool executed[MAX_NUMBER_OF_PROCESS];

    int n, quantum;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter quantum: ");
    scanf("%d", &quantum);
  
    for (int i = 0; i < n; i++) {
        printf("AT of %d process is: ", i + 1);
        scanf("%d", &AT[i]);
        executed[i] = false;
    }
    for (int i = 0; i < n; i++) {
        printf("BT of %d process is: ", i + 1);
        scanf("%d", &BT[i]);
        BT_original[i] = BT[i];
    }
   
    int current_time = AT[0], finished = 0;
    int k = 0;
    while (finished != n) {
        if (executed[k] == true) {
                k = (k + 1)%n;
                continue;
        }

        if (BT[k] <= quantum) {
            current_time += BT[k];
            ET[k] = current_time; 

            TAT[k] = ET[k] - AT[k]; 
            totalTAT += TAT[k];

            WT[k] = TAT[k] - BT_original[k];
            totalWT += WT[k];

            finished++;
            executed[k] = true;
            k = (k + 1)%n;
        } else {
            
            current_time += quantum;
            BT[k] -= quantum;
            k = (k + 1)%n;
        }
    }

    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, AT[i], BT_original[i], ET[i], TAT[i], WT[i]);
    printf("Average TAT: %f\n", totalTAT/n);
    printf("Average WT: %f\n", totalWT/n);
}
