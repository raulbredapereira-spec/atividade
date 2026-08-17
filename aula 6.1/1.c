#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100

int main(void) {
    int n;
    char nomes[MAX_ALUNOS][MAX_NOME];
    double notas[MAX_ALUNOS];
    double soma = 0.0;

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_ALUNOS) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s %lf", nomes[i], &notas[i]);
        soma += notas[i];
    }

    double media = soma / n;
    int idxMaior = 0;
    int idxMenor = 0;

    for (int i = 1; i < n; i++) {
        if (notas[i] > notas[idxMaior]) {
            idxMaior = i;
        }
        if (notas[i] < notas[idxMenor]) {
            idxMenor = i;
        }
    }

    int acimaMedia = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] > media) {
            acimaMedia++;
        }
    }

    printf("Tabela de alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", nomes[i], notas[i]);
    }
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %s %.2f\n", nomes[idxMaior], notas[idxMaior]);
    printf("Menor nota: %s %.2f\n", nomes[idxMenor], notas[idxMenor]);
    printf("Alunos acima da media: %d\n", acimaMedia);

    return 0;
}
