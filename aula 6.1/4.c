#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float n1;
    float n2;
    float n3;
} Aluno;

int main(void)
{
    Aluno turma[] = {
        {"Ana", 8.5f, 7.0f, 9.0f},
        {"Bruno", 6.0f, 7.5f, 8.0f},
        {"Carla", 9.5f, 8.0f, 7.0f}
    };
    int quantidade = sizeof(turma) / sizeof(turma[0]);
    char nome_busca[50];
    int encontrado = 0;

    printf("Boletim da turma:\n");
    for (int i = 0; i < quantidade; i++) {
        float media = (turma[i].n1 + turma[i].n2 + turma[i].n3) / 3.0f;
        printf("%s: %.1f, %.1f, %.1f | media: %.2f\n",
               turma[i].nome,
               turma[i].n1,
               turma[i].n2,
               turma[i].n3,
               media);
    }

    printf("\nDigite um nome: ");
    if (fgets(nome_busca, sizeof(nome_busca), stdin) == NULL) {
        return 0;
    }
    size_t len = strlen(nome_busca);
    if (len > 0 && nome_busca[len - 1] == '\n') {
        nome_busca[len - 1] = '\0';
    }

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(turma[i].nome, nome_busca) == 0) {
            float media = (turma[i].n1 + turma[i].n2 + turma[i].n3) / 3.0f;
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", turma[i].nome);
            printf("Notas: %.1f, %.1f, %.1f\n", turma[i].n1, turma[i].n2, turma[i].n3);
            printf("Media: %.2f\n", media);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nAluno nao encontrado na turma.\n");
    }

    return 0;
}
