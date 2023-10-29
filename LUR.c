#include <stdio.h>

int main() {
    int m, n, position, k;
    int a = 0, b = 0, page_fault = 0;

    int total_frames;
    printf("Enter the number of frames: ");
    scanf("%d", &total_frames);

    int frames[total_frames];
    for (m = 0; m < total_frames; m++) {
        frames[m] = -1;
    }

    int total_pages;
    printf("Enter the total number of pages: ");
    scanf("%d", &total_pages);

    int pages[total_pages];
    printf("Enter the page reference sequence:\n");
    for (n = 0; n < total_pages; n++) {
        scanf("%d", &pages[n]);
    }

    for (n = 0; n < total_pages; n++) {
        printf("%d: ", pages[n]);
        a = 0, b = 0;
        for (m = 0; m < total_frames; m++) {
            if (frames[m] == pages[n]) {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0) {
            for (m = 0; m < total_frames; m++) {
                if (frames[m] == -1) {
                    frames[m] = pages[n];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }
        if (b == 0) {
            int recent = -1;
            for (m = 0; m < total_frames; m++) {
                for (k = n + 1; k < total_pages; k++) {
                    if (frames[m] == pages[k]) {
                        if (k > recent) {
                            recent = k;
                            position = m;
                        }
                        break;
                    }
                }
            }
            frames[position] = pages[n];
            page_fault++;
        }

        for (m = 0; m < total_frames; m++) {
            printf("%d\t", frames[m]);
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);

    return 0;
}

/*
 * sample input 
 * Enter the number of frames: 3
Enter the total number of pages: 20
Enter the page reference sequence:
1 2 3 2 1 5 2 1 6 2 5 6 3 1 3 6 1 2 4 3
*/

