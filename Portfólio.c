#include <stdio.h>
#include <string.h>

int idIgual(int id[], int tamanho, int idNovo){
    for(int i = 0; i < tamanho; i++){
        if (id[i] == idNovo){
            return 1;
        }
    }
    return 0;
}

int main(){
    int produto;

    printf("\nInforme a quantidade de itens que deseja inserir: ");
    scanf("%i", &produto);

    char nome[produto][20];
    int id[produto], qtde[produto];
    float unit[produto], total[produto];

    for(int i = 0; i < produto; i++){
        int idNovo;

        do{
            printf("\nInforme o ID do produto %i: ", i + 1);
            scanf("%i", &idNovo);
            if (idIgual(id, i, idNovo)){
                printf("\nID já existe. Por favor, insira um ID diferente.\n");
            }
            
        } while(idIgual(id, i, idNovo));
        id[i] = idNovo;

        printf("Informe o nome do produto %i: ", i + 1);
        scanf("%s", nome[i]);

        printf("Informe a quantidade do produto %i: ", i + 1);
        scanf("%i", &qtde[i]);

        printf("Informe o preço unitário do produto %i: ", i + 1);
        scanf("%f", &unit[i]);

        total[i] = qtde[i] * unit[i];
    }

    float totalFinal = 0;

    printf("\n%-10s %-20s %-6s %-7s %-7s\n", "CODIGO", "NOME", "QTDE", "UNIT", "TOTAL");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < produto; i++){
        printf("%-10d %-20s %-6d %-7.2f %-7.2f\n", id[i], nome[i], qtde[i], unit[i], total[i]);
        totalFinal += total[i];
    }

    printf("-------------------------------------------------------------\n");
    printf("%51s %.2f\n", "TOTAL FINAL", totalFinal);

    return 0;
}