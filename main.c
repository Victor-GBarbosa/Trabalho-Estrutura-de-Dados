#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {

    srand(time(NULL)); //Gerando a seed para o srand baseado no tempo no sistema operacional

    const char *mainFName = "Arquivo.csv";

    int index = 0;
    char nome[50], materia[50], matricula[6];
    char appendString[250];
    char stringConversor[100];
    

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
              printf("Digite o nome do aluno: ");
              scanf("%s", nome);
              printf("Digite a materia em que o aluno sera matriculado: ");
              scanf("%s", materia);
              for (i = 0; i < 5; i++) { //Criando a matricula
                matricula[i] = '0' + (rand() % 10); // Convertendo int's para strings
            }
                matricula[5] = '\0'; // Fechando a string

                snprintf(stringConversor, sizeof(stringConversor), "%d", index);

                strncat(appendString, stringConversor, sizeof(stringConversor));
                strncat(appendString, ",", 1);
                strncat(appendString, nome, sizeof(nome));
                strncat(appendString, ",", 1);
                strncat(appendString, materia, sizeof(materia));
                strncat(appendString, ",", 1);
                strncat(appendString, matricula, sizeof(matricula));

                printf(appendString);

                arquivo = fopen(mainFName, "a");

                fputs(appendString, arquivo);
                fputs("\n", arquivo);

                fclose(arquivo);

                memset(appendString, 0, sizeof(appendString));
                memset(stringConversor, 0, sizeof(stringConversor));
              
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
    if (arquivo != NULL){
    fclose(arquivo);
    }
   return 0;
}