#include <stdio.h>
#include <stdlib.h>
#define maxnumber 100
float v[maxnumber];

float operatie(float a, float b, char semn) {
    if (semn == '+') {
        return a + b;
    } else if (semn == '-') {
        return a - b;
    } else if (semn == '*' ) {
        return a * b;
    } else if (semn == '/') {
        return a / b;
    }

    return -1;
}

int main() {
    int n;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%f\n", v+i);
    }

    char semn;
    int idx_numere = 0;

    
    for (int i = 0; i < n - 1; i++) {
        scanf("%c", &semn);
        // printf("%f %c %f\n", v[idx_numere], semn, v[idx_numere + 1]);
        v[idx_numere+1] = operatie(v[idx_numere], v[idx_numere+1], semn);
        idx_numere++;
    }

    
    printf("%f\n", v[idx_numere]);


    return 0;
}