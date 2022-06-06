#include <stdio.h>

int main(void) {
  	int count;

    scanf("%d", &count);

    while (count != -1) {
        for (int i = 1; i <= count; ++i) {
    	    printf("*");
        }

        printf("\n");

        scanf("%d", &count);
    }
  
  	return 0;
}