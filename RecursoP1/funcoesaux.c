#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "funcoesaux.h"
#include "declaracoes.h"

// Limpa caracteres indesejados
void limpaBufferStdin(void)
{
    char chr;

    do
    {
        chr = getchar();
    } while (chr != '\n' && chr != EOF);
}

// Funcao para ler um numero inteiro
int lerInteiro(char mensagem[80], int minimo, int maximo)
{
    int numero, controlo;

    do
    {
        printf("%s (%d a %d) : ", mensagem, minimo, maximo);

        // scanf devolve quantidade de valores v�lidos obtidos
        controlo = scanf ("%d", &numero);

        // limpa todos os caracteres do buffer stdin (nomeadamente o \n)
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Deve inserir um numero inteiro \n");
        }
        else
        {
            if(numero < minimo || numero > maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    } while(numero < minimo || numero > maximo || controlo == 0);

    return numero;
}

// Funcao para ler uma float
float lerFloat(char mensagem[80], float minimo, float maximo)
{
    float numero;
    int controlo;

    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);

        // scanf devolve quantidade de valores v�lidos obtidos
        controlo = scanf ("%f", &numero);

        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Deve inserir um numero decimal \n");
        }
        else
        {
            if (numero < minimo || numero > maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    } while(numero < minimo || numero > maximo || controlo == 0);

    return numero;
}

// Funcao para ler uma string
void lerString(char mensagem[80], char vetorCaracteres[80], int maximoCaracteres)
{
    int tamanhoString;

    // Repete leitura caso sejam obtidas strings vazias
    do
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres! Apenas carregou no ENTER \n\n");
        }
    } while (tamanhoString == 1);

    // verifica se existirem caracteres
    if(vetorCaracteres[tamanhoString-1] != '\n')
    {
        // apenas faz sentido limpar buffer se existirem caracteres
        limpaBufferStdin();
    }
    else
    {
        //Elimina o \n da string armazenada em vetor
        vetorCaracteres[tamanhoString-1] = '\0';
    }
}

// Funcao para ler uma float
tipoData lerData()
{
    tipoData data;
    int maxDiasMes;

    printf("Insira a data pretendida - ");
    data.ano = lerInteiro("ano:", 1948,2023);
    data.mes = lerInteiro("mes:", 1, 12);

    switch (data.mes)
    {
        case 2:
            if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
            {
                maxDiasMes = 29;
            }
            else
            {
                maxDiasMes = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDiasMes = 30;
            break;
        default:
            maxDiasMes = 31;
    }

    data.dia = lerInteiro("dia:", 1, maxDiasMes);

    return data;
}

void lerFicheiro(char nomeFicheiro[80])
{
    FILE * ficheiro;
    char linha[150];

    ficheiro = fopen(nomeFicheiro + ".txt","r");

    while (!feof(ficheiro))
    {
        fgets(linha, 150, ficheiro);
        puts(linha);
    }

    fclose(ficheiro);
}

void gravarFicheiro(char linha[150])
{
    FILE * ficheiro;

    ficheiro = fopen("clientes.txt", "a");

    fprintf(ficheiro,linha);

    fclose(ficheiro);
}

void pressionarContinuar()
{
    char lixo;

    printf("\nPressione qualquer tecla para continuar...");
    scanf(" %c", &lixo);

    limpaBufferStdin();
}

void limpaEcra()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

