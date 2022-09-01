/******************************************************************************

                    Linda Ines Jimenez Vides - 21169
                        Laboratorio 3 - Ejercicio 1

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

void *primos(void *threadID){
    
    divisores = 0;
    
    for(int i=1; i<= N; i++){
        if(n%i == 0){
            divisores++;
        }
    }
    
    if(divisores == 2){
        return true;
    } else{
        return false;
    }
    
    pthread_exit(NULL);
}

int main(){
    
    int N;
    int t;
    pthread_t threads[NUM_THREADS];
    for(t=0; t<NUM_THREADS; t++){
        N = pthread_create(&threads[t], NULL, primos, &t);
        if(N){
            printf("Error, return code from pthread_create() is %d \n", N);
            exit(-1);
        }
    }
    
    for (t=0; t<NUM_THREADS; t++){
        pthread_exit(NULL);
    }
    
    printf("\n Primos: %d \n", divisores);
    pthread_exit(NULL);
    
    
    
    bool resultado;
    cout << "Introduce un valor maximo: ";
    cin >> N;
    for(int i=1; i<=N; i++){
        resultado = esprimo(i);
        if(resultado == true){
            cout << i << ",";
        }
    }
    
    return 0;
}