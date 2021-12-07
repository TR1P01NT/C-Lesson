#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
  }
}

int main(void) {
    int i, num[100] = {0}, input, count = 0;

    for (i = 0; i < 100; i++) {
        scanf("%d", &input);
        
        if (input == -1) {
            break;
        }

        num[i] = input;
        count++;
    }

    selectionSort(num, count);

    for (i = 0; i < count; i++) {
        printf("%d ", num[i]);
    }
}