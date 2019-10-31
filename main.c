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

void print2DArray(int arr[6][6], int n) 
{ 
    int i, j; 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            printf("%d ", arr[i][j]); 
    printf("\n");
    }
} 

void reset2DArray(int arr[6][6], int n) 
{ 
    int i, j; 
    for (i = 0; i < n; i++) 
      for (j = 0; j < n; j++) 
        arr[i][j] = 0;
} 

void generateOddSquare(int magicSquare[6][6], int n, int startX, int startY, int startValue) {
    int i = startY;
    int j =  startX + n/2;
    int endValue = startValue - 1 + (n * n);
    for(int num = startValue; num <= endValue; ) {
        if (j >= startX + n) {
            j -= n;
        } else if (j < startX) {
            j += n;
        }
        if (i >= n + startY) {
            i -= n;
        } else if (i < startY) {
            i += n;
        }

        if(magicSquare[i][j]) {
            i+=2;
            j--;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        i--;
        j++;
    }
}

void generateEvenSquare(int magicSquare[6][6], int n) {
    n = n/2;
    int startNum = 1;
    generateOddSquare(magicSquare, n, 0, 0, startNum);
    startNum += n * n;
    generateOddSquare(magicSquare, n, n, n, startNum);
    startNum += n * n;
    generateOddSquare(magicSquare, n, n, 0,startNum);
    startNum += n * n;
    generateOddSquare(magicSquare, n, 0, n, startNum);

    int auxSwap = magicSquare[0][0];
    magicSquare[0][0] = magicSquare[3][0];
    magicSquare[3][0] = auxSwap;
    auxSwap = magicSquare[1][1];
    magicSquare[1][1] = magicSquare[4][1];
    magicSquare[4][1] = auxSwap;
    auxSwap = magicSquare[2][0];
    magicSquare[2][0] = magicSquare[5][0];
    magicSquare[5][0] = auxSwap;
    
}

void generateDoublyEvenSquare(int magicSquare[6][6], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            magicSquare[i][j] = i*n + j + 1;
        }
    }
    
    magicSquare[0][0] = 17 - magicSquare[0][0];
    magicSquare[0][3] = 17 - magicSquare[0][3];
    magicSquare[3][0] = 17 - magicSquare[3][0];
    magicSquare[3][3] = 17 - magicSquare[3][3] ;

    for(int i = 1; i < 3; i++) {
        for(int j = 1; j < 3; j++) {
            magicSquare[i][j] = n * n + 1 - magicSquare[i][j];
        }
    }
}

void printMagicConstant(int n) {
    int magicConstant = n * (n * n + 1) / 2;
    printf(", Soma: %d\n", magicConstant);
}

int main()
{
    while(1) {
    limparTela();
    int e;
    printf("1. Soma Maxima\n");
    printf("2. Quadrado Magico\n");
    printf("3. Sair\n");
    scanf("%d", &e);
    if(e == 2) {
        int magicSquare[6][6];
        int n;
        limparTela();
        reset2DArray(magicSquare, 6);
        printf("Informe o tamanhado do quadrado magico a ser gerado entre 3 e 6 (para sair digite 0): ");
        scanf("%d", &n);
        if(n == 0) {
            break;
        }
        if(n < 3 || n > 6) {
            printf("Entrada Inválida, digite um número entre 3 e 6\n");
        } else if(n%2 == 0) {
            if(n%4 == 0) {
                generateDoublyEvenSquare(magicSquare, n);
                printf("Quadradro Mágico duplamente par de tamanho %dx%d", n, n);
                printMagicConstant(n);
                print2DArray(magicSquare, n);
            } else {
                generateEvenSquare(magicSquare, n);
                printf("Quadradro Mágico singularmente par de tamanho %dx%d", n, n);
                printMagicConstant(n);
                print2DArray(magicSquare, n);
            }
        } else {
            generateOddSquare(magicSquare, n, 0, 0, 1);
            printf("Quadradro Mágico ímpar de tamanho %dx%d", n, n);
            printMagicConstant(n);
            print2DArray(magicSquare, n);
        }
        getchar();
        getchar();
    } else if(e == 1) {
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
        getchar();
        } else if(e == 3) {
            break;
        }
    }
    return 0;
}
