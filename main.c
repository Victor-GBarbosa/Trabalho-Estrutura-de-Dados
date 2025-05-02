#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/organizar.h"

int gerarMatricula() {
    int matricula = 0;
    for (int i = 0; i < 6; i++) { //gerando numeros aleatorios 
        matricula = matricula * 10 + (rand() % 10); //colocando numero ao final da matricula
    }
    if (matricula < 100000) { //garantindo que a matricula tenha 6 dígitos
        matricula += 100000;
    }
    return matricula;
}

int main() {

    srand(time(NULL)); //gerando a seed para o srand baseado no tempo no sistema operacional

    char nomeArquivo[100] = "";
    char linha[256];

    char arquivoDeSaida[256];
    int oopt;

    
    char nome[50], materia[100], matricula[6];

    FILE *arquivo;

    //estrutura CSV ==> index,nome,materia,matricula (Ex 0,Eduardo,Biologia,25209) 
    
    int opt;
    do { //iniciando o menu do programa
        printf("\nMenu:\n");
        if (strlen(nomeArquivo) > 0) {
            printf("Arquivo atual: %s\n\n", nomeArquivo);
        } else {
            printf("nenhum arquivo selecionado\n\n");
        }
        printf("1- Selecionar arquivo\n");
        printf("2- Adicionar matricula\n");
        printf("3- Ornganizar itens\n");
        printf("4- Visualizar matriculas\n");
        printf("5- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opt);
        int i;

        switch (opt) {
            case 1: 
                printf("Digite o nome do arquivo (com extensao): ");
                
                scanf(" %[^\n]", nomeArquivo);

                FILE *fp = fopen(nomeArquivo, "r");
                if (fp == NULL) {
                    printf("Arquivo nao encontrado. Criando arquivo...\n");
                    fp = fopen(nomeArquivo, "w");
                    if (fp == NULL) {
                        printf("Erro ao criar o arquivo.\n");
                        break;
                    }
                    fprintf(fp, "Nome,Curso,Matricula\n\n");
                } else {
                    printf("Arquivo encontrado. Pronto para manipulacao.\n");
                }
                fclose(fp);
                break;
            case 2:
                if (strlen(nomeArquivo) == 0 || (arquivo = fopen(nomeArquivo, "r")) == NULL) { //verificnado se algum arquivo foi seleciondo
                    printf("nenhum arquivo selecionado\n");
                    if (arquivo != NULL) fclose(arquivo);
                    break;
                }
                fclose(arquivo);
              printf("Digite o nome do aluno: ");
              scanf(" %[^\n]", nome);
              printf("Digite a materia em que o aluno sera matriculado: ");
              scanf(" %[^\n]", materia);

                arquivo = fopen(nomeArquivo, "a"); //abrindo o arquivo para adicionar a matricula
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    break;
                }
                
                sprintf(linha, "%s,%s,%d\n", nome, materia, gerarMatricula()); //construção da linha
                fprintf(arquivo, "%s", linha); //escrevendo a matricula no arquivo
                fclose(arquivo); //fechando o arquivo
                break;
            case 3:
                printf("Digite o nome do arquivo organizado (arquivo de saida)");
                scanf("%s", arquivoDeSaida);
                printf("Selecione o por qual atributo deseja organizar:\n\n1-Nome\n2-Materia\n3-Matricula");
                scanf("%d", &oopt);
                switch (oopt) {
                    case 1:
                        ordenarPorNome(nomeArquivo, arquivoDeSaida);
                        printf("Arquivo organizado por nome.\n");
                        break;
                    case 2:
                        ordenarPorMateria(nomeArquivo, arquivoDeSaida);
                        printf("Arquivo organizado por matéria.\n");
                        break;
                    case 3:
                        ordenarPorMatricula(nomeArquivo, arquivoDeSaida);
                        printf("Arquivo organizado por matrícula.\n");
                        break;
                    default:
                        printf("Opcao invalida para organizacao.\n");
                }
                break;
            case 4:
                exibirPaginas(nomeArquivo);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opt != 5);

    //finalizando o programa
    if (arquivo != NULL){
    fclose(arquivo);
    }
   return 0;
}