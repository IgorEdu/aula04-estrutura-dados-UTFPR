/*a) Crie uma TAD (struct) de sua escolha com pelo menos 2 campos de tipos distintos;

b) Declare uma variável local da main com o tipo TAD criado

c) Preencha os campos de sua variável a partir de valores lidos do teclado. Use o nome (ou seja, identificador) da variável juntamente com o operador ponto "." para acessar os valores dos campos

d) Declare uma variável ponteiro para TAD e inicialize-a com o endereço de memória da variável TAD declarada no item b.

e) Imprima na tela cada um dos valores dos campos mas, desta vez, no lugar de usar o nome da variável struct com o operador ponto, você deverá usar a variável ponteiro para acessar os imprimir na tela o valor de cada um dos campos. DICA: Você precisar pesquisar o significado do operador seta (no código, esse operador é composto de dois caracteres, são eles, ->).
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
