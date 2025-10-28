#include <stdio.h>
#include <string.h>

// PROTÓTIPO DA FUNÇÃO
float obterValor(int atributo, int carta, int *invertido,
                 int pop1, int pop2, float area1, float area2, float pib1, float pib2,
                 float densidade1, float densidade2, float pibPerCapita1, float pibPerCapita2,
                 int pontos1, int pontos2);
          
int main() {
    // Dados da Carta 1
    char estado1[3], codigo1[4], nome1[50];
    int pop1, pontos1;
    float area1, pib1, densidade1, pibPerCapita1;

    // Dados da Carta 2
    char estado2[3], codigo2[4], nome2[50];
    int pop2, pontos2;
    float area2, pib2, densidade2, pibPerCapita2;

    // Variáveis auxiliares
    float valor1, valor2;
    int invertido = 0;
    int atributo1, atributo2;

    // ENTRADA DOS DADOS CARTA 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (ex: RJ): ");
    scanf("%s", estado1);

    printf("Digite o código (ex: A01): ");
    scanf("%s", codigo1);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = 0;

    printf("População: ");
    scanf("%d", &pop1);
    printf("Área (km2): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // Cálculos automáticos
    densidade1 = pop1 / area1;
    pibPerCapita1 = pib1 / pop1;

    // ENTRADA DOS DADOS CARTA 2
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
    scanf("%d", &pop2);
    printf("Área (km2): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);
    getchar();

    // Cálculos automáticos
    densidade2 = pop2 / area2;
    pibPerCapita2 = pib2 / pop2;

    // === MENU INTERATIVO ===
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("5 - PIB per Capita\n");
    printf("6 - Pontos Turísticos\n");
    printf("Digite dois atributos separados por espaço (ex: 1 3): ");
    scanf("%d %d", &atributo1, &atributo2);

    // Verificação antes de chamar a função
    if (atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6) {
        printf("\n=== Opção inválida! ===\nEscolha números entre 1 e 6.\n");
        return 0;
    }

    // COMPARAÇÃO DAS CARTAS
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    valor1 = obterValor(atributo1, 1, &invertido,
                        pop1, pop2, area1, area2, pib1, pib2,
                        densidade1, densidade2, pibPerCapita1, pibPerCapita2,
                        pontos1, pontos2);
    valor2 = obterValor(atributo1, 2, &invertido,
                        pop1, pop2, area1, area2, pib1, pib2,
                        densidade1, densidade2, pibPerCapita1, pibPerCapita2,
                        pontos1, pontos2);

    int empate = (valor1 == valor2);
    int carta1Vence = invertido ? (valor1 < valor2) : (valor1 > valor2);

    if (!empate) {
        printf("Resultado do primeiro atributo: %s venceu!\n",
               carta1Vence ? nome1 : nome2);
    } else {
        printf("Empate no primeiro atributo!\n");
        printf("Usando segundo atributo para desempate...\n\n");

        invertido = 0;
        valor1 = obterValor(atributo2, 1, &invertido,
                            pop1, pop2, area1, area2, pib1, pib2,
                            densidade1, densidade2, pibPerCapita1, pibPerCapita2,
                            pontos1, pontos2);
        valor2 = obterValor(atributo2, 2, &invertido,
                            pop1, pop2, area1, area2, pib1, pib2,
                            densidade1, densidade2, pibPerCapita1, pibPerCapita2,
                            pontos1, pontos2);

        empate = (valor1 == valor2);
        carta1Vence = invertido ? (valor1 < valor2) : (valor1 > valor2);

        if (empate)
            printf("Empate total! Nenhuma carta venceu.\n");
        else
            printf("%s venceu com base no segundo atributo!\n",
                   carta1Vence ? nome1 : nome2);

    }
    return 0;
}

// CORPO DA FUNÇÃO obterValor
float obterValor(int atributo, int carta, int *invertido,
                 int pop1, int pop2, float area1, float area2, float pib1, float pib2,
                 float densidade1, float densidade2, float pibPerCapita1, float pibPerCapita2,
                 int pontos1, int pontos2) {
    switch (atributo) {
        case 1: return (carta == 1 ? pop1 : pop2);
        case 2: return (carta == 1 ? area1 : area2);
        case 3: return (carta == 1 ? pib1 : pib2);
        case 4:
            *invertido = 1; // menor vence
            return (carta == 1 ? densidade1 : densidade2);
        case 5: return (carta == 1 ? pibPerCapita1 : pibPerCapita2);
        case 6: return (carta == 1 ? pontos1 : pontos2);
        default:
            return 0;
    }
}