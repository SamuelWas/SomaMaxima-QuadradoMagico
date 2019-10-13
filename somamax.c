#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int val[20];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &val[i]);
    }

    int maxVectorSum = 0, currentVectorSum = 0, startIndex = 0, endIndex = 0;
    for(int i = 0; i < n; ++i) {
        if(currentVectorSum > 0) {
            currentVectorSum = val[i] + currentVectorSum;
        } else {
            currentVectorSum = val[i];
            startIndex = i + 1;
        }
        if(currentVectorSum > maxVectorSum) {
            endIndex = i + 1;
            maxVectorSum = currentVectorSum;
        }
    }

    printf("Soma: %d\n", maxVectorSum);
    printf("Indices: %d a %d", startIndex, endIndex);
    return 0;
}
