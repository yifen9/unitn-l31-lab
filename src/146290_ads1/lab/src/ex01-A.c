#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 10;

int* char_to_int(char** C, int n){
    int* res = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){res[i] = atoi(C[i]);}

    return res;
}

int array_element_mininum(int* A, int n){
    int res = A[0];
    for(int i = 1; i < n; i++){res = (A[i] > res)? res: A[i];}

    return res;
}

int main(int argc, char** argv){
    printf("Mininum element: %d\n", array_element_mininum(char_to_int(&argv[1], MAX_SIZE), MAX_SIZE));

    return 0;
}