#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char estado1[3], codigo1[4], nome1[50];
    int pop1, pontos1;
    float area1, pib1, densidade1, pibPerCapita1;

    // Dados da Carta 2
    char estado2[3], codigo2[4], nome2[50];
    int pop2, pontos2;
    float area2, pib2, densidade2, pibPerCapita2;

    // menu
    int opcao;

    // Entrada da Carta 1
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
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // Cálculos automáticos
    densidade1 = pop1 / area1;
    pibPerCapita1 = pib1 / pop1;

    // Entrada da Carta 2
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
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos automáticos
    densidade2 = pop2 / area2;
    pibPerCapita2 = pib2 / pop2;

    // Menu Interativo
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("5 - PIB per Capita\n");
    printf("6 - Pontos Turísticos\n");
    printf("Digite o número do atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    // Switch de comparação
    switch (opcao) {
        case 1: // População
            if (pop1 > pop2)
                printf("%s venceu com maior população!\n", nome1);
            else if (pop2 > pop1)
                printf("%s venceu com maior população!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");

                // Comparação aninhada POPULAÇÃO > ÁREA
                if (area1 > area2)
                    printf("Desempate: %s venceu com maior área!\n", nome1);
                else if (area2 > area1)
                    printf("Desempate: %s venceu com maior área!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        case 2: // Área
            if (area1 > area2)
                printf("%s venceu com maior área!\n", nome1);
            else if (area2 > area1)
                printf("%s venceu com maior área!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");
                
                // Comparação aninhada AREA > PIB
                if (pib1 > pib2)
                    printf("Desempate: %s venceu com maior PIB!\n", nome1);
                else if (pib2 > pib1)
                    printf("Desempate: %s venceu com maior PIB!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        case 3: // PIB
            if (pib1 > pib2)
                printf("%s venceu com maior PIB!\n", nome1);
            else if (pib2 > pib1)
                printf("%s venceu com maior PIB!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");
            
                // Comparação aninhada PIB > POPULAÇÃO
                if (pop1 > pop2)
                    printf("Desempate: %s venceu com maior População!\n", nome1);
                else if (pop2 > pop1)
                    printf("Desempate: %s venceu com maior População!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        case 4: // Densidade populacional (menor vence)
            if (densidade1 < densidade2)
                printf("%s venceu com menor densidade populacional!\n", nome1);
            else if (densidade2 < densidade1)
                printf("%s venceu com menor densidade populacional!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");
            
                // Comparação aninhada DENSIDADE > PIB per capita
                if (pibPerCapita1 > pibPerCapita2)
                    printf("Desempate: %s venceu com maior PIB per capita!\n", nome1);
                else if (pibPerCapita2 > pibPerCapita1)
                    printf("Desempate: %s venceu com maior PIB per capita!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        case 5: // PIB per capita
            if (pibPerCapita1 > pibPerCapita2)
                printf("%s venceu com maior PIB per capita!\n", nome1);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("%s venceu com maior PIB per capita!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");

                // Comparação aninhada PIB per capita > Pontos turísticos
                if (pontos1 > pontos2)
                    printf("Desempate: %s venceu com maior pontos turísticos!\n", nome1);
                else if (pontos2 > pontos1)
                    printf("Desempate: %s venceu com maior pontos turísticos!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        case 6: // Pontos turísticos
            if (pontos1 > pontos2)
                printf("%s venceu com mais pontos turísticos!\n", nome1);
            else if (pontos2 > pontos1)
                printf("%s venceu com mais pontos turísticos!\n", nome2);
            else {
                printf("Carta 1 escolheu pontos turísticos, deu empate.\nAgora o atributo será escolhido randomicamente...\n\n");
                
                // Comparação aninhada Pontos turísticos > Densidade populacional
                if (densidade1 < densidade2)
                    printf("Desempate: %s venceu com maior densidade populacional!\n", nome1);
                else if (densidade2 < densidade1)
                    printf("Desempate: %s venceu com maior densidade populacional!\n", nome2);
                else
                    printf("=== 2o RESULTADO DA COMPARAÇÃO ===\n Empate total!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
