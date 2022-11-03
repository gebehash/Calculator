#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxnumber 100
float v[maxnumber];

float operatie_primara(float a, float b, char semn) {
    if (semn == '*' ) {
        return a * b;
    } else if (semn == '/') {
        return a / b;
    }

    return -1;
}

float operatie_secundara(float a, float b, char semn) {
    if (semn == '+') {
        return a + b;
    } else if (semn == '-') {
        return a - b;
    }

    return -1;
}

void remove_elem(float v[], int idx, int *size) {
    while (idx < *size) {
        v[idx] = v[idx+1];
        idx++;
    }
    (*size)--;
}

int main() { 
    int n;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%f\n", v+i);
    }

    char* semne = (char*) malloc(maxnumber - 1);
    char* aux = (char*) malloc(maxnumber - 1);

    fgets(semne, n, stdin);
    int idx_numere = 0;

    for (int i = 0; i < n - 1; i++) {
        if (operatie_primara(v[idx_numere], v[idx_numere+1], *(semne+i)) != -1) {
            // printf("%f %c %f ", v[idx_numere], *(semne+i), v[idx_numere + 1]);
            v[idx_numere+1] = operatie_primara(v[idx_numere], v[idx_numere+1], *(semne+i));
            remove_elem(v, idx_numere, &n);
            // strcpy(semne + i, semne + i + 1);
            strcpy(aux, semne + i + 1);
            strcpy(semne + i, aux);
            i--;
            idx_numere--;
            // printf("%s\n", semne);
        }
        idx_numere++;
    }

    idx_numere = 0;

    for (int i = 0; i < n - 1; i++) {
        // if (v[idx_numere] != -1 && v[idx_numere + 1] != -1) {
        // printf("%f %c %f\n", v[idx_numere], *(semne+i), v[idx_numere + 1]);
        v[idx_numere+1] = operatie_secundara(v[idx_numere], v[idx_numere+1], *(semne+i));
        // }
        idx_numere++;
    }

    printf("%f\n", v[idx_numere]);


    return 0;
}