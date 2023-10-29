#include<stdio.h>

void fifo(int string[], int n, int size) {
    int frames[n];
    for (int i = 0; i < n; i++)
        frames[i] = -1;

    int index = -1;
    int page_miss = 0;
    int page_hits = 0;

    for (int i = 0; i < size; i++) {
        int symbol = string[i];
        int flag = 0;

        for (int j = 0; j < n; j++) {
            if (symbol == frames[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\nSymbol: %d  Frame: ", symbol);
            for (int j = 0; j < n; j++)
                printf("%d ", frames[j]);
            page_hits += 1;
        } else {
            index = (index + 1) % n;
            frames[index] = symbol;
            page_miss += 1;
            printf("\nSymbol: %d  Frame: ", symbol);
            for (int j = 0; j < n; j++)
                printf("%d ", frames[j]);
        }
    }
    printf("\nPage hits: %d", page_hits);
    printf("\nPage misses: %d", page_miss);
}

int main(void) {
    int size, no_frames;
    printf("Enter the number of frames: ");
    scanf("%d", &no_frames);

    printf("Enter the size of the input string: ");
    scanf("%d", &size);

    int string[size];
    printf("Enter the input string elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &string[i]);
    }

    fifo(string, no_frames, size);
    return 0;
}

/*
 * Enter the number of frames: 3
Enter the size of the input string: 20
Enter the input string elements: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/

