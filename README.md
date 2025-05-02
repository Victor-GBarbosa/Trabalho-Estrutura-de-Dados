# Trabalho Estrutura de Dados

### Método de execução
Com o Visual Studio Code e MinGW instalados.

    1. Abra o CMD e digite “code <diretorio_do_projeto>”
    
    2. No terminal verifique se o diretório do projeto está correto, e use comando “gcc main.c o-<nome_exemplo>”
    
    3. Ainda no terminal use “.\\<nome_exemplo>” para executar o programa

### Método de Utilização
Seleção de arquivo: Ao iniciar o programa use a primeira opção para selecionar um arquivo, caso o arquivo não exista o programa irá criá-lo.

Adição de matrícula: Com um arquivo selecionado você pode adicionar uma nova matrícula, passando nome e curso, isso gerará uma matrícula aleatória associada ao nome e curso descrito pelo usuário.

Organização de arquivos: Caso haja um arquivo selecionado e este arquivo tenha matrículas o suficiente, o usuário poderá ordenar o conteúdo do arquivo selecionado, podendo passar o conteúdo organizado para outro arquivo, ou passando o nome do arquivo selecionado, o programa organizará o conteúdo dentro do arquivo selecionado.

Visualização de conteúdo: Usando a opção de visualizar matrículas o programa ira exibir as 10 primeiras matrículas do arquivo selecionado, dando a opção de ir para outra página a partir de um input de um número qualquer, esse input indicara a “página” a ser exibida, que o número escolhido pelo usuário será multiplicado por 10 exibido o conteúdo presente na dezena escolhida. Ex: caso o usuario escolha ver a pagina 7 o programa exibirá o conteudo da linha 61 ate a linha 70
