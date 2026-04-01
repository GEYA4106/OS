#include <stdio.h>
int main() {
    int pages[] = {1, 2, 3, 4, 5, 6};
    int n = 6, f = 3;
    int frame[3], i, j, k;
    int fault = 0, found;
    for (i = 0; i < f; i++)
        frame[i] = -1;
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int pos = -1, farthest = i + 1;
            for (j = 0; j < f; j++) {
                int nextUse = -1;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }
                if (nextUse == -1) {
                    pos = j;
                    break;
                }
                if (nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }
            if (pos == -1)
                pos = 0;
            frame[pos] = pages[i];
            fault++;
        }
        printf("Page %d -> ", pages[i]);
        for (k = 0; k < f; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }
    printf("Total Page Faults = %d\n", fault);
    return 0;
}