#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int pontos;
    int vitorias;
} Jogador;

int main() {
    int n;
    printf("Digite o número de jogadores: ");
    scanf("%d", &n);
    getchar();
    
    Jogador jogadores[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nJogador %d:\n", i + 1);
        printf("Nome: ");
        fgets(jogadores[i].nome, sizeof(jogadores[i].nome), stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';
        
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
        
        printf("Vitórias: ");
        scanf("%d", &jogadores[i].vitorias);
        getchar();
    }
    
    printf("\n========== TABELA DE JOGADORES ==========\n");
    printf("%-30s | Pontos | Vitórias\n", "Nome");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s | %6d | %8d\n", jogadores[i].nome, jogadores[i].pontos, jogadores[i].vitorias);
    }
    
    int maxPontos = 0;
    int indicePontos = 0;
    for (int i = 0; i < n; i++) {
        if (jogadores[i].pontos > maxPontos) {
            maxPontos = jogadores[i].pontos;
            indicePontos = i;
        }
    }
    printf("\nJogador com MAIS PONTOS: %s (%d pontos)\n", jogadores[indicePontos].nome, maxPontos);
    
    int maxVitorias = 0;
    int indiceVitorias = 0;
    for (int i = 0; i < n; i++) {
        if (jogadores[i].vitorias > maxVitorias) {
            maxVitorias = jogadores[i].vitorias;
            indiceVitorias = i;
        }
    }
    printf("Jogador com MAIS VITÓRIAS: %s (%d vitórias)\n", jogadores[indiceVitorias].nome, maxVitorias);
    
    double mediaVitorias = 0;
    for (int i = 0; i < n; i++) {
        mediaVitorias += jogadores[i].vitorias;
    }
    mediaVitorias /= n;
    
    int contagem = 0;
    for (int i = 0; i < n; i++) {
        if (jogadores[i].vitorias > mediaVitorias) {
            contagem++;
        }
    }
    printf("Média de vitórias: %.2f\n", mediaVitorias);
    printf("Jogadores com vitórias ACIMA DA MÉDIA: %d\n", contagem);
    
    return 0;
}
