#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[100];
    float nota;
} Aluno;

int main() {
    int n;
    if (printf("Quantidade de alunos: ") && scanf("%d", &n) != 1) return 0;
    if (n <= 0 || n > MAX) return 0;

    Aluno alunos[MAX];
    for (int i = 0; i < n; i++) {
        printf("Aluno %d nome: ", i+1);
        // consume newline
        int c; while ((c = getchar()) != '\n' && c != EOF);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        // remove newline
        size_t len = strlen(alunos[i].nome);
        if (len && alunos[i].nome[len-1] == '\n') alunos[i].nome[len-1] = '\0';
        printf("Aluno %d nota: ", i+1);
        if (scanf("%f", &alunos[i].nota) != 1) alunos[i].nota = 0.0f;
    }

    int idxMax = 0, idxMin = 0;
    for (int i = 1; i < n; i++) {
        if (alunos[i].nota > alunos[idxMax].nota) idxMax = i;
        if (alunos[i].nota < alunos[idxMin].nota) idxMin = i;
    }

    printf("\nAluno com maior nota:\nNome: %s\nNota: %.2f\n", alunos[idxMax].nome, alunos[idxMax].nota);
    printf("\nAluno com menor nota:\nNome: %s\nNota: %.2f\n", alunos[idxMin].nome, alunos[idxMin].nota);

    return 0;
}