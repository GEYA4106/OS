#include <stdio.h>
int main() {
    int n, frames, i, j, k, pageFaults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int frame[frames];
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    int index = 0; 
    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
        printf("%d\t", pages[i]);
        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}