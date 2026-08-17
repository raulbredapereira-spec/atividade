#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
} Produto;

int main(void) {
    Produto p;

    if (fgets(p.nome, sizeof(p.nome), stdin) == NULL) return 0;
    size_t len = strlen(p.nome);
    if (len > 0 && p.nome[len-1] == '\n') p.nome[len-1] = '\0';

    if (scanf("%f", &p.preco) != 1) return 0;
    if (scanf("%d", &p.quantidade) != 1) return 0;

    float total = p.preco * p.quantidade;

    printf("Nome : %s\n", p.nome);
    printf("Preco : R$ %.2f\n", p.preco);
    printf("Quantidade : %d\n", p.quantidade);
    printf("---------------------------------\n");
    printf("Valor total em estoque : R$ %.2f\n", total);

    return 0;
}
