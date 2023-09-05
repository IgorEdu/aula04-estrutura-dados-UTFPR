/*1) Crie um programa em C que realiza as seguintes tarefas, uma a seguir a outra

a) definir um TAD auto-referenciado composto de um campo int chamado inteiro,  um campo char chamado letra, um campo float chamado real e o campo ponteiro chamado prox cujo tipo será da própria struct sendo criada;

b) declarar um ponteiro para a TAD criada e fazê-lo apontar para uma variável TAD alocada dinamicamente. Se a alocação for mal sucedida, finalize o programa com -1. Do contrário, inicialize o campo prox com NULL e o campo inteiro com 1 (demais campos use valores de sua escolha)

c) Aloque dinamicamente dois outros nós. Inicialize o campo prox com NULL e atribua os valores 1 e 2 (se a alocação ocorreu) ao campo inteiro de cada um deles, respectivamente (demais campos atribua valores de sua escolha).

d) Faça com que o nó de campo inteiro 1 aponte para aquele de campo inteiro 2 e este aponte para o de campo inteiro 3.

e) desaloque o nó 2 e faça com que o nó 1 aponte para o nó 3.
*/


#include <stdio.h>
#include <stdlib.h>

struct t_TAD {
    int inteiro;
    char letra;
    float real;
    struct t_TAD* prox;
};


struct t_TAD* alocarNo() {
    struct t_TAD* novoNo = (struct t_TAD*)malloc(sizeof(struct t_TAD));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(-1);
    }
    return novoNo;
}

int main() {
    struct t_TAD* no1 = alocarNo();

    no1->inteiro = 1;
    no1->letra = 'A';
    no1->real = 3.14;
    no1->prox = NULL;

    struct t_TAD* no2 = alocarNo();
    struct t_TAD* no3 = alocarNo();

    no2->inteiro = 2;
    no2->letra = 'B';
    no2->real = 2.71;
    no2->prox = NULL;

    no3->inteiro = 3;
    no3->letra = 'C';
    no3->real = 1.618;
    no3->prox = NULL;

    no1->prox = no2;
    no2->prox = no3;

    printf("No 1 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no1->inteiro, no1->letra, no1->real, (no1->prox != NULL) ? no1->prox->inteiro : no1->prox);
    printf("No 2 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no2->inteiro, no2->letra, no2->real, (no2->prox != NULL) ? no2->prox->inteiro : no2->prox);
    printf("No 3 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no3->inteiro, no3->letra, no3->real, (no3->prox != NULL) ? no3->prox->inteiro : no3->prox);

    free(no2);
    no1->prox = no3;

    printf("No 1 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no1->inteiro, no1->letra, no1->real, (no1->prox != NULL) ? no1->prox->inteiro : no1->prox);
    //printf("No 2 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no2->inteiro, no2->letra, no2->real, (no2->prox != NULL) ? no2->prox->inteiro : no2->prox);
    printf("No 3 - Inteiro: %d, Letra: %c, Real: %.2f, Proximo Inteiro:%d\n", no3->inteiro, no3->letra, no3->real, (no3->prox != NULL) ? no3->prox->inteiro : no3->prox);

    free(no1);
    free(no3);

    return 0;
}
