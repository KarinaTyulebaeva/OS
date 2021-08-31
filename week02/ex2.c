#include <stdio.h>

int main()
{
    char string[50], reverse[50];
        int begin, end, count = 0;

        fgets(string,100,stdin);
	
        while (string[count] != '\0')
            count++;
        end = count - 1;

        for (begin = 0; begin < count; begin++) {
            reverse[begin] = string[end];
            end--;
        }

        reverse[begin] = '\0';
        printf("%s \n", reverse);
    return 0;
}
