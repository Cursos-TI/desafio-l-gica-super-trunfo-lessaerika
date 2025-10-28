#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char estado1[3], codigo1[4], nome1[50];
    int populacao1, pontos1;
    float area1, pib1, densidade1;

    // Dados da Carta 2
    char estado2[3], codigo2[4], nome2[50];
    int populacao2, pontos2;
    float area2, pib2, densidade2;

    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (ex: RJ): ");
    scanf("%s", estado1);
    printf("Digite o código (ex: A01): ");
    scanf("%s", codigo1);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(nome1, 50, stdin); // Usar fgets para permitir nomes com espaços e usar o stdin para ler dados imputados no terminal
    nome1[strcspn(nome1, "\n")] = 0; // strcspn: Remover a nova linha do final. Essa linha procura o “\n” dentro do texto e substitui ele por um “\0” para não aparecer o "\n"para o usuário.

    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km2): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    densidade1 = populacao1 / area1;

    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (ex: SP): ");
    scanf("%s", estado2);
    printf("Digite o código (ex: B01): ");
    scanf("%s", codigo2);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = 0;

    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km2): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    densidade2 = populacao2 / area2;

    // Exibição
    printf("\n=== RESULTADO DE COMPARAÇÃO ===\n");
    printf("Carta 1: %s (%s - %s)\n", nome1, estado1, codigo1);
    printf("Carta 2: %s (%s - %s)\n", nome2, estado2, codigo2);

    printf("\nComparando População...\n");

    if (populacao1 > populacao2) {
        printf("%s venceu com maior população!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("%s venceu com maior população!\n", nome2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}