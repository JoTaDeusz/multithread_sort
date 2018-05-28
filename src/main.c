/* Ordenador de numeros
 *
 * Este programa recebera uma serie de numeros em ordem aleatoria
 * como entrada. Ao receber um caractere fim de linha ('\n'),
 * deve imprimir na tela o vetor que recebeu ordenado de 
 * forma crescente e, apos, encerrar.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define THREADS 4

#define NUMEROS 10000000

pthread_mutex_t chave;

int x;
int numeros[NUMEROS];

void* thread(void *arg) {
  
  int i, j, a;
  int indice = 0;
  int *N = (int*)(arg);
  int M = (*N);
  
  //while (1) {
  
    pthread_mutex_lock(&chave);
   
    for (i = 0; i <= x; ++i) 

        {

            for (j = i + 1; j <= x; ++j)

            {

                if (numeros[i] > numeros[j]) 

                {
                    a =  numeros[i];

                    numeros[i] = numeros[j];

                    numeros[j] = a;

                }

            }

        }
  
    pthread_mutex_unlock(&chave);
    //printf("A thread %d trata o numero %d\n", M, numeros[i]);
//}
  return NULL;
}

int main() {
  
int p, h, k;
char c;
pthread_t threads[THREADS];
int thread_id[THREADS];
  
  while ((c = getchar()) != '\n')
  {
    if (c != ' ') {
      
      if(c == ',');
      
      else numeros[x] = numeros[x] * 10 + c - '0'; 
    }
    
    else
        x++;
   }
  
  /*Identificando threads*/
  for (h = 0; h < THREADS; h++) {
    thread_id[h] = h;
  }
  
  /*Criando threads*/
  for (h = 0; h < THREADS; h++) {
    pthread_create(&(threads[h]), NULL, thread, (void*)(&thread_id[h]));
  }
 
  /*Impondo espera às threads*/
  for (h = 0; h < THREADS; h++) {
    pthread_join(threads[h], NULL);
  }
  
  for(p = 0; p <= x; p++){
    printf("%d ", numeros[p]);
  }
  
  printf("\n");
  
  return 0;
}
