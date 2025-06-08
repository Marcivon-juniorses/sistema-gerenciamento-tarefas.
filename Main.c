#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparTerminal() 
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
 
char** aumentaLinha(char **matriz, int linha, int coluna)
{
    linha++;
    matriz = realloc(matriz, linha * sizeof(char *));
    
    matriz[linha - 1] = malloc(coluna * sizeof(char));
    return matriz;
}

void** mostraLista(char **matriz, int linhas)
{
    for(int i=0; i<linhas; i++)
    {
        printf("%d. %s\n", i+1, matriz[i]);
    }
    return 0;
}

void limpaBuffer()
{
    int i;
    while((i = getchar())!= '\n' && i != EOF);
}

void eliminaTarefa(char **matriz, int linhaE, int linhas)
{
    for(int i=linhaE - 1; i<linhas - 1; i++)
    {
        strcpy(matriz[i], matriz[i+1]);
    }
}

int main()
{
    int linha, coluna, tarefaslistadas, tarefa, num;
    char **lista, op[2], atividade[100];
    FILE *arquivo;

    tarefaslistadas = 0;
    linha = 1;
    coluna = 100;
    op[0] = ' ';

    lista = malloc(linha * sizeof(char *));
    lista[0] =  malloc(coluna * sizeof(char *));

    while(op[0] != '0')
    {
        printf("O que deseja fazer\nDigite:\n");
        printf("1.Cadastrar nova tarefa\n2.Mostrar tarefas\n3.Limpar o terminal\n4.Para eliminar uma tarefa\n5.Para alterar alguma tarefa\n6.Para criar um arquivo\n0.Para fechar o programa\n--> ");
        fgets(op, 2, stdin);
        printf("-----------------------------------------------------------------------------\n");
        limpaBuffer();

        if(op[0] == '1')
        {
            printf("Digite a %d tarefa\n--> ", tarefaslistadas + 1);
            fgets(lista[tarefaslistadas], 100, stdin);
            tarefaslistadas++;
        }

        else if(op[0] == '2')
        {
            mostraLista(lista, tarefaslistadas);
        }

        else if(op[0] == '3')
        {
            limparTerminal();
        }

        else if(op[0] == '4')
        {
            printf("Qual tarefa quer eliminar: ");
            scanf("%d", &tarefa);
            limpaBuffer();
            eliminaTarefa(lista, tarefa, linha);
            tarefaslistadas--;
            mostraLista(lista, tarefaslistadas);
        }

        else if(op[0] == '5')
        {
            printf("Digite o numero da tarefa que deseja alterar: ");
            scanf("%d", &num);
            limpaBuffer();
            printf("Digite a nova atividade\n--> ");
            fgets(atividade, 100, stdin);
            strcpy(lista[num-1], atividade);
        }

        else if(op[0] == '6')
        {
            arquivo =  fopen("Atividades.txt", "w");
            for(int i=0; i<tarefaslistadas; i++)
            {
                fprintf(arquivo, "%d. %s\n", i+1 ,lista[i]);
            }
            fclose(arquivo);
            printf("Arquivo criado com sucesso!\n");
        }
        else if(op[0] == '0')
        {}
        else
        {
            printf("Opcao invalida\n");
        }

        if(tarefaslistadas == linha)
        {
            aumentaLinha(lista, linha, coluna);
            linha++;
        }
        printf("-----------------------------------------------------------------------------\n");
    }
}