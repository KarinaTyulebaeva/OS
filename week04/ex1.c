#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int n;
  pid_t pid_f = fork();
  pid_t pid = getpid();
  if (pid_f == 0) printf("Hello from child [%d - %d]\n", pid, n);
    else printf("Hel1lo from parent [%d - %d]\n", pid, n);
  return 0;
}

/*Output:

Hello from parent [1211-4317793]
Hello from child [1212-4317793]
Hello from parent [1213-4575841]
Hello from child [1214-4575841]
Hello from parent [1215-4256353]
Hello from child [1216-4256353]
Hello from parent [1217-5177953]
Hello from child [1218-5177953]
Hello from parent [1219-4506209]
Hello from child [1220-4506209]
Hello from parent [1221-4735585]
Hello from child [1222-4735585]
Hello from parent [1223-4395617]
Hello from child [1224-4395617]
Hello from parent [1225-4973153]
Hello from child [1226-4973153]
Hello from parent [1227-4670049]
Hello from child [1228-4670049]
Hello from parent [1229-4944481]
Hello from child [1230-4944481]

Output parents and children were mixed because they were executed on different cores
*/
