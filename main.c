#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    srand(time(NULL)); //Gerando a seed para o srand baseado no tempo no sistema operacional

    const char *mainFName = "Arquivo.txt";

    FILE *arquivo = fopen(mainFName, "r+"); //Tentando abrir o arquivo

    if (arquivo == NULL) { //Verificando se o arquivo foi aberto
        printf("Criando Arquivo.\n");
        arquivo = fopen(mainFName, "w"); //Craiando um arquivo caso não seja encontrado
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo");
            return 1;
        }
        
    } else {
        printf("Arquivo encontrado. Pronto para manipulação\n");
    }

    fclose(arquivo); // Fechando o arquivo para que possa ser aberto de diferentes formas futuramente

    //Arquivo aberto ou Criado

    int index;
    char nome[50], materia[50], matricula[6]; // Increased size to accommodate null terminator

    //Estrutura CSV ==> index,nome,materia,matricula (Ex 0,Eduardo,Biologia,25209) 
    
    int opt;
    do { //iniciando o menu do programa
        printf("\nMenu:\n");
        printf("1- Ver matriculas\n");
        printf("2- Adicionar matricula\n");
        printf("3- Ornizar itens\n");
        printf("4. Remover matricula\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);
        int i;
        

        switch (opt) {
            case 1:
                // Código para Ver alunos matriulados
                break;
            case 2:
              printf("Digite o nome do aluno");
              scanf("%s", nome);
              printf("Digite a materia em que o aluno sera matriculado");
              scanf("%s", materia);
              for (i = 0; i < 5; i++) { //Criando a matricula
                matricula[i] = '0' + (rand() % 10); // Convertendo int's para strings
            }
                matricula[5] = '\0'; // Fechando a string
              
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