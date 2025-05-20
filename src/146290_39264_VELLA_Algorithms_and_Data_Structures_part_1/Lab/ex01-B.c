#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 10;

int* char_to_int(char** C, int n){
    int* res = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){res[i] = atoi(C[i]);}

    return res;
}

int array_search(int* A, int n, int target){
    int res = -1;
    for(int i = 0; (i < n && res == -1); i++){
        if(A[i] == target){
            A[i] = 0;
            res = i;
        }
    }

    return res;
}

int array_search_r(int* A, int n, int target, int i){
    if(i >= n){return -1;}{
        if(A[0] == target){
            A[0] = 0;
    
            return i;
        }
        else{return array_search_r(&A[1], n, target, 1 + i);}
    }
}

int main(int argc, char** argv){
    printf("Target index: %d\n", array_search(char_to_int(&argv[1], MAX_SIZE), MAX_SIZE, atoi(argv[1 + MAX_SIZE])));
    printf("Target index (recursive): %d\n", array_search_r(char_to_int(&argv[1], MAX_SIZE), MAX_SIZE, atoi(argv[1 + MAX_SIZE]), 0));

    return 0;
}