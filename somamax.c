#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int A[20];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    int SMt = 0, SMi = 0, possibleStartIndex, startIndex, endIndex; 
    for(int i = 0; i < n; ++i) {
        if(SMi >= 0) {
            SMi = A[i] + SMi;
        } else {
            SMi = A[i];
            possibleStartIndex = i + 1;
        }
        if(SMi > SMt) {
            startIndex = possibleStartIndex;
            endIndex = i + 1;
            SMt = SMi;
        }
    }

    printf("Soma: %d\n", SMt);
    printf("Indices: %d a %d\n", startIndex, endIndex);
    system("pause");
    return 0;
}
