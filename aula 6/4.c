#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[101];
    double preco;
    int quantidade;
} Produto;

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 0;
    getchar(); 

    Produto *v = malloc(sizeof(Produto) * N);
    for (int i = 0; i < N; i++) {
        if (!fgets(v[i].nome, sizeof(v[i].nome), stdin)) {
            v[i].nome[0] = '\0';
        } else {
            size_t l = strlen(v[i].nome);
            if (l > 0 && v[i].nome[l-1] == '\n') v[i].nome[l-1] = '\0';
        
        if (scanf("%lf %d", &v[i].preco, &v[i].quantidade) != 2) {
            v[i].preco = 0.0;
            v[i].quantidade = 0;
        }
        getchar(); 
    }

    printf("Tabela de produtos:\n");
    printf("%-30s %10s %10s %15s\n", "Produto", "Preco", "Quantidade", "Valor Estoque");
    for (int i = 0; i < N; i++) {
        double valor = v[i].preco * v[i].quantidade;
        printf("%-30s %10.2f %10d %15.2f\n", v[i].nome, v[i].preco, v[i].quantidade, valor);
    }

    int idx_max = 0;
    double max_val = v[0].preco * v[0].quantidade;
    double total_geral = max_val;
    for (int i = 1; i < N; i++) {
        double val = v[i].preco * v[i].quantidade;
        total_geral += val;
        if (val > max_val) {
            max_val = val;
            idx_max = i;
        }
    }
    printf("\nProduto com maior valor em estoque: %s (%.2f)\n", v[idx_max].nome, max_val);

    printf("Valor total geral: %.2f\n", total_geral);

    free(v);
    return 0;
}
