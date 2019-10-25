#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    #ifdef Windows
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimirVetor(int *A, int startIndex, int endIndex) {
    printf("[");
    for(int i = startIndex; i < endIndex - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[endIndex-1]);
}

int main()
{
    limparTela();
    printf("Informe o tamanho do vetor: ");
    int n = 0;
    scanf("%d", &n);
    int A[20];
    printf("Informe o(s) %d elemento(s) de forma espaçada: ", n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    printf("\n");

    int SMt = 0, SMi = 0, possibleStartIndex = 1, startIndex = 1, endIndex = n; 
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
    
    printf("Vetor Original: ");
    imprimirVetor(A, 0, n);
    printf("A maior soma possível de um sub-vetor contíguo é: %d\n", SMt);
    printf("Os indices dessa soma são: %d a %d\n", startIndex, endIndex);
    printf("Vetor que compoe a maior soma: ");
    imprimirVetor(A, startIndex - 1, endIndex);
    getchar();
    return 0;
}
