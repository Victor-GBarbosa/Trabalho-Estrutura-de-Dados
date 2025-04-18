#include <stdio.h>

int main() {

    const char *fname = "Arquivo.txt";

    FILE *arquivo = fopen(fname, "r+");

    if (arquivo == NULL) {
        printf("Criando Arquivo.\n");
        arquivo = fopen(fname, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo");
            return 1;
        }
        
    } else {
        printf("Arquivo encontrado. Pronto para manipulação\n");
    }

    //Arquivo aberto ou Criado

    int index, matricula;
    char nome[50], materia[50]; 

    //Estrutura CSV ==> index,nome,materia,matricula (Ex 0,Eduardo,Biologia,252009) 
    
    int opt;
    do {
        printf("\nMenu:\n");
        printf("1- Ver matriculas\n");
        printf("2- Adicionar matricula\n");
        printf("3- Ornizar itens\n");
        printf("4. Remover matricula\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                // Código para Ver alunos matriulados
                break;
            case 2:
                // Código para Adicionar uma nova matricula
                break;
            case 3:
                // Código para reorganizar as matriculas
                break;
            case 4:
                // Código para remover uma matricula
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opt != 5);

    //Finalizando o programa

    fclose(arquivo);
    
   return 0;
}