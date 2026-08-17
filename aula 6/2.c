#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    char (*names)[100] = malloc(n * 100);
    if (!names) return 0;
    float *grades = malloc(n * sizeof(float));
    if (!grades) { free(names); return 0; }

    for (int i = 0; i < n; ++i) {
        scanf("%99s %f", names[i], &grades[i]);
    }

    printf("Tabela de alunos:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s %.2f\n", names[i], grades[i]);
    }

    float sum = 0.0f;
    for (int i = 0; i < n; ++i) sum += grades[i];
    float media = sum / n;
    int acima = 0;
    for (int i = 0; i < n; ++i) if (grades[i] > media) ++acima;

    printf("Media da turma: %.2f\n", media);
    printf("Alunos acima da media: %d\n", acima);

    free(names);
    free(grades);
    return 0;
}
