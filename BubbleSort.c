#include <stdio.h>
#define tam 5

    void swap(int* x, int* y){
        int aux = *x;
        *x = *y;
        *y = aux;
    }

int main(){
    
    int array[tam];

    for(int i=0; i<tam; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &array[i]);
    }
    
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
    
   for(int i=0; i<tam; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}
