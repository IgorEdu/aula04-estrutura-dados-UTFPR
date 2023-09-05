/*a) Crie uma TAD (struct) de sua escolha com pelo menos 2 campos de tipos distintos;

b) Declare uma vari�vel local da main com o tipo TAD criado

c) Preencha os campos de sua vari�vel a partir de valores lidos do teclado. Use o nome (ou seja, identificador) da vari�vel juntamente com o operador ponto "." para acessar os valores dos campos

d) Declare uma vari�vel ponteiro para TAD e inicialize-a com o endere�o de mem�ria da vari�vel TAD declarada no item b.

e) Imprima na tela cada um dos valores dos campos mas, desta vez, no lugar de usar o nome da vari�vel struct com o operador ponto, voc� dever� usar a vari�vel ponteiro para acessar os imprimir na tela o valor de cada um dos campos. DICA: Voc� precisar pesquisar o significado do operador seta (no c�digo, esse operador � composto de dois caracteres, s�o eles, ->).
*/

#include <stdio.h>

struct t_pessoa{
    char nome[50];
    int idade;
};

int main(){
    struct t_pessoa pessoa1;
    struct t_pessoa *p_pessoa = &pessoa1;

    printf("Digite o nome da pessoa: ");
    fgets(pessoa1.nome , sizeof(pessoa1.nome), stdin);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa1.idade);

    size_t length = strlen(pessoa1.nome);
    if (length > 0 && pessoa1.nome[length - 1] == '\n') {
        pessoa1.nome[length - 1] = '\0';
    }


    printf("Valor do campo 'nome': %s\n", p_pessoa->nome);
    printf("Valor do campo 'idade': %d\n", p_pessoa->idade);

    return 0;
}
