/******************************************************************************

                    Linda Ines Jimenez Vides - 21169
                        Laboratorio 3 - Ejercicio 1



hodckjdb cd
*******************************************************************************/
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
# define NUM_THREADS 2

using namespace std;
using std::cout;
using std::endl;

int divisores;
int i;
int N;

void *primos(void *threadID){
    
    divisores = 0;
    
    for(int i=1; i<=N; i++){
        if(N%i == 0){
            divisores++;
        }
    }
    
    if(divisores == 2){
        printf("True");
    } else{
        printf("False");
    }
    
    pthread_exit(NULL);
}

int main(){
    
    int N;
    int t;
    int r;
    
    cout << "Introduce un valor maximo: ";
    cin >> N;
    
    pthread_t threads[NUM_THREADS];
    for(t=0; t<NUM_THREADS; t++){
        r = pthread_create(&threads[t], NULL, primos, &t);
        if(r){
            printf("Error, return code from pthread_create() is %d \n", r);
            exit(-1);
        }
    }
    
    for (t = 0; t < NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }
    
    bool resultado;
    for(int i=1; i<=N; i++){
        resultado = primos(N);
        if(resultado == true){
            cout << i << ",";
        }
    }
    
    printf("\n Primos: %d \n", resultado);
    pthread_exit(NULL);
    
}
