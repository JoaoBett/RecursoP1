#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "declaracoes.h"
#include "funcoesaux.h"
#include "menus.h"

//-----------Funcoes das Funcionalidades----------

//Funcao que insere um novo cliente na base de dados
void inserirCliente(tipoCliente cliente[150], int *quantidadeCliente)
{
    int numContribuinte, posicao;

    if(*quantidadeCliente > MAX)
    {
        printf("Erro - Limite máximo de clientes!");
    }
    else
    {
        printf("\n\n--Novo Cliente--\n\n");
        numContribuinte = lerInteiro("\nNumero de Contribuinte: ", MIN_CONTRIBUINTE, MAX_CONTRIBUINTE);
        posicao = procurarCliente(cliente, *quantidadeCliente, numContribuinte);

        if(posicao > -1)
        {
            printf("\n\nErro - Este contribuinte já existe!\n");
            printf("%d",posicao);
        }
        else
        {
            cliente[*quantidadeCliente].contribuinte = numContribuinte;
            cliente[*quantidadeCliente].contactoTele = lerInteiro("\nTelefone: ",MIN_TELE,MAX_TELE);
            lerString("\nNome: ", cliente[*quantidadeCliente].nome, 80);
            lerString("\nMorada: ", cliente[*quantidadeCliente].morada, 80);
            (*quantidadeCliente)++;
        }
    }
}

//Funcao que procura o cliente pelo seu contribuinte
int procurarCliente(tipoCliente cliente[150], int quantidadeCliente, int contribuinte)
{
    int posicao= -1, i;

    for(i = 0; i < quantidadeCliente; i++)
    {
        if(cliente[i].contribuinte == contribuinte)
        {
            posicao = i;
            i = quantidadeCliente;
        }
    }
    return posicao;
}

//Funcao para listar as informacoes dos clientes
void listarClientes(tipoCliente cliente[150], int quantidadeCliente)
{
    int i;
    if (quantidadeCliente < 0)
    {
        printf("\n\nAtencao - Não existem Clientes.\n\n");
    }

    for(i = 0; i < quantidadeCliente; i++)
    {
        printf("\nA listar clientes...\n\n");

        printf("\n---------------------------\n");
        printf("\nContribuinte: %d\n", cliente[i].contribuinte);
        printf("\nNome: %s\n", cliente[i].nome);
        printf("\nMorada: %s\n", cliente[i].morada);
        printf("\nTelefone : %d\n", cliente[i].contactoTele);
        printf("\n---------------------------\n");
    }
    pressionarContinuar();
}

void listarClienteData(tipoCliente cliente[MAX], int quantidadeCliente, tipoAgendamento agendamento[MAX])
{
    int i;

    tipoData data;

    if(quantidadeCliente < 0)
    {
        printf("Atencao - Nao existem Clientes");
    }
    else
    {
        data = lerData();

        if(data.dia == agendamento->data.dia && data.mes == agendamento->data.mes && data.ano == agendamento->data.ano)
        {
        for(i = 0; i < quantidadeCliente ; i++)
        {
            printf("A listar clientes...\n\n");

            printf("\nContribuinte: %d", cliente[i].contribuinte);
            printf("\nNome: %s", cliente[i].nome);
            printf("\nMorada: %s", cliente[i].morada);
            printf("\nTelefone : %d", cliente[i].contactoTele);
        }
        }
        else
        {
            printf("Atencao - Nao existem nenhum cliente/agendamento com esta data!");
        }
    }
}

tipoAgendamento adicionarAgendamento(int *quantidadeCliente, int *quantidadeAgendamento, tipoCliente cliente[MAX], tipoAgendamento agendamento[MAX])
{
    int numeroContribuinte, i, posicao, k;

    if(quantidadeCliente < 0)
    {
        printf("Atencao - Nao existem clientes!");
    }
    else
    {
        numeroContribuinte = lerInteiro("Qual o numero de contribuinte que pretende adicionar um agendamento?",MIN_CONTRIBUINTE,MAX_CONTRIBUINTE);
        posicao = procurarCliente(cliente, *quantidadeCliente, numeroContribuinte);

        if(posicao < 0)
        {
            printf("Atencao - Nao existem clientes");
        }
        else
        {
            for (i = 0; i < *quantidadeCliente; i++)
            {
                if (cliente[i].contribuinte == numeroContribuinte)
                {
                    posicao = i;
                    i = *quantidadeCliente;
                }

                    agendamento[i].data = lerData();

                    agendamento[i].horario = lerHorario();

                    for(k = 0; k < *quantidadeCliente; k++)
                    {
                        if(agendamento[k].data.dia == agendamento[i].data.dia && agendamento[k].data.mes == agendamento[i].data.mes && agendamento[k].data.ano == agendamento[i].data.ano)
                        {
                            printf("\n\nAtencao - Ja existe um agendamento com esta data!\n");
                        }

                        if(agendamento[k].horario.horas == agendamento[i].horario.horas && agendamento[k].horario.minutos == agendamento[i].horario.minutos)
                        {
                            printf("\n\nAtencao - Ja existe um agendamento com este horario!\n");
                        }
                    }
                lerString("\nDescricao: ", agendamento[i].descricao, 500);
            }
        }
    }
}
