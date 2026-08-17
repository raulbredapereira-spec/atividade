#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
} Produto;

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    Produto produtos[n];
    for (int i = 0; i < n; i++) {
        scanf("%99s %f %d", produtos[i].nome, &produtos[i].preco, &produtos[i].quantidade);
    }

    printf("Tabela de produtos:\n");
    printf("Nome Preco Quantidade ValorEmEstoque\n");

    int idxMaiorValor = 0;
    int idxMenorPreco = 0;
    float totalGeral = 0.0f;

    for (int i = 0; i < n; i++) {
        float valorEstoque = produtos[i].preco * produtos[i].quantidade;
        printf("%s %.2f %d %.2f\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade, valorEstoque);
        totalGeral += valorEstoque;

        if (valorEstoque > produtos[idxMaiorValor].preco * produtos[idxMaiorValor].quantidade) {
            idxMaiorValor = i;
        }
        if (produtos[i].preco < produtos[idxMenorPreco].preco) {
            idxMenorPreco = i;
        }
    }

    printf("Produto com maior valor em estoque: %s\n", produtos[idxMaiorValor].nome);
    printf("Produto com menor preco unitario: %s\n", produtos[idxMenorPreco].nome);
    printf("Valor total do estoque: %.2f\n", totalGeral);

    return 0;
}
