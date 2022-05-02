#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main() {
    struct timeval t0;
    struct timeval t1;
    float elapsed;

    int i=0;
    unsigned long x;

    long int tamanho;
    scanf("%d",&tamanho);

    ArvBin *arvore;
    arvore = cria_ArvBin();

    /**
    * CRIANDO A ARVORE
    */
    gettimeofday(&t0, 0);
    srand(time(NULL));
    for (i=0;i<tamanho;i++){
        x = rand();
        x <<= 15;
        x ^= rand();
        x %= 99999;
        insere_ArvBin(arvore, x);
    }
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. CRIANDO ARVORE COM %d CHAVES\n", elapsed, tamanho);
    //posOrdem_ArvBin(arvore);

    /**
     * PEGANDO ALTURA
     */
    gettimeofday(&t0, 0);
    printf("ALTURA DA ARVORE %d\n", altura_ArvBin(arvore));
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. PEGANDO ALTURA COM %d CHAVES\n", elapsed, tamanho);

    /**
     * NÚMERO DE NÓS
     */
    gettimeofday(&t0, 0);
    printf("TOTAL DE NODOS NA ARVORE %d\n", totalNO_ArvBin(arvore));
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. PEGANDO NUMERO DE NOS COM %d CHAVES\n", elapsed, tamanho);

    /**
     * EM ORDEM
     */
    gettimeofday(&t0, 0);
    emOrdem_ArvBin(arvore);
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. EM ORDEM COM %d CHAVES\n", elapsed, tamanho);
    /**
     * PÓS ORDEM
     */
    gettimeofday(&t0, 0);
    posOrdem_ArvBin(arvore);
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. POS ORDEM COM %d CHAVES\n", elapsed, tamanho);
    /**
     * PRÉ ORDEM
     */
    gettimeofday(&t0, 0);
    preOrdem_ArvBin(arvore);
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds. PRE ORDEM COM %d CHAVES\n", elapsed, tamanho);
    /**
     * LIBERANDO A ARVORE
     */
    gettimeofday(&t0, 0);
    libera_ArvBin(arvore);
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);

    printf("Code executed in %f milliseconds. LIBERANDO ARVORE COM %d CHAVES\n", elapsed, tamanho);

    return 0;
}