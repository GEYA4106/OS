#include <stdio.h>
int main() {
    int pages[] = {1, 2, 3, 4, 5, 6};
    int n = 6, f = 3;
    int frame[3];
    int i, j, k, pos = 0, fault = 0, found;
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
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
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