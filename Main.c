#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int linha, coluna, tarefaslistadas;
    char **lista, op[2];
    tarefaslistadas = 0;
    linha = 1;
    coluna = 100;
    op[0] = ' ';

    lista = malloc(linha * sizeof(char *));
    lista[0] =  malloc(coluna * sizeof(char *));

    while(op[0] != '0')
    {
        printf("O que deseja fazer\nDigite:\n");
        printf("1.Cadastrar nova tarefa\n2.Mostrar tarefas\n3.Limpar o terminal\n0.Para fechar o programa\n--> ");
        scanf("%c", op);
        limpaBuffer();
        printf("-----------------------------------------------------------------------------\n");
        if(op[0] == '1')
        {
            aumentaLinha(lista, linha, coluna);
            linha++;
            printf("Digite a %d tarefa\n--> ", tarefaslistadas + 1);
            fgets(lista[tarefaslistadas], 100, stdin);
            tarefaslistadas++;
            limpaBuffer();
        }
        else if(op[0] == '2')
        {
            mostraLista(lista, tarefaslistadas);
        }
        else if(op[0] == '3')
        {
            limparTerminal();
        }
        printf("-----------------------------------------------------------------------------\n");
    }
}