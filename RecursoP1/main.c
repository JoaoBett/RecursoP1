#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "declaracoes.h"
#include "exame.h"
#include "funcoesaux.h"

int menuPrinc(int quantidadeAgendamentos, int quantidadeVisitas);
int menuClientes();
int menuEstatistica();
int menuFicheiros();
void inserirCliente(tipoCliente cliente, int *quantidadeCliente);

int main()
{
    tipoCliente cliente[150];
    int quantidadeCliente, opcao, quantidadeAgendamentos = 0, quantidadeVisitas = 0, opcao2;

    do{
        opcao = menuPrinc(quantidadeAgendamentos, quantidadeVisitas);

        switch(opcao)
        {
            case 1:
                opcao2 = menuClientes();

                switch (opcao2)
                {
                    case 1:
                        inserirCliente(cliente, *quantidadeCliente);
                    break;

                    case 2:
                        listarCliente(cliente, *quantidadeCliente);
                    break;
            break;

            case 2:
                opcao3 = menuFicheiros();

                switch (opcao3)
                {
                    case 1:
                        gravarFicheiro();
                    break;

                    case 2:
                        lerFicheiro();
                    break;
                }
            break;

            case 3:
                opcao4 = menuEstatisticos();

                switch (opcao4)
                {
                case 1:
                    melhoresClientes();
                break;

                case 2:
                    percentagemSatisfacao();
                break;
                }
            break;
    } while(opcao != 5);

    return 0;
}

int menuPrinc(int quantidadeAgendamentos, int quantidadeVisitas)
{
    //Declaracao de variaveis
    int opcao;

    //Menu
    printf("\t\tTecnico de Reparacoes\n");
    printf("Total de agendamentos: %d \t Total de visitas realizadas: %d \n\n", quantidadeAgendamentos, quantidadeVisitas);
    printf("\n1 - Menu Clientes");
    printf("\n2 - Menu Agendamentos");
    printf("\n3 - Menu Ficheiros");
    printf("\n4 - Menu Estatistica");
    printf("\n5 - Voltar");
    printf("\nOpcao--> ");

    scanf("%d", &opcao);

    return opcao;
}


int menuClientes()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("\t\tMenu Clientes\n");
    printf("\n1 - Adicionar Novo Agendamento");
    printf("\n2 - Registar Visita");
    printf("\n3 - Consultar Agendamento(por data)");
    printf("\n4 - Listar Clientes e respetivos agendamentos");
    printf("\n5 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);

    return opc;
}

int menuFicheiros()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("\t\tMenu Ficheiros\n");
    printf("\n1 - Guardar Ficheiro");
    printf("\n2 - Ler Ficheiro");
    printf("\n3 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);

    return opc;
}

int menuEstatistica()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("\t\tMenu Estatistico\n");
    printf("\n1 - Melhores Clientes");
    printf("\n2 - Percentagem com grau de satisfacao");
    printf("\n3 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);

    return opc;
}

//Funcao que insere um novo cliente na base de dados
void inserirCliente(tipoCliente cliente[150], int *quantidadeCliente)
{
    int numContribuinte, posicao;
    
    if(*quantidadeCliente == 150)
    {
        printf("Erro - Limite máximo de clientes!");
    } else
    {
        printf("--Novo Cliente--");
        numContribuinte = lerInteiro("\nNumero de Contribuinte: ", MIN_CONTRIBUINTE, MAX_CONTRIBUINTE);
        posicao = procurarCliente(cliente, *quantidadeCliente, numContribuinte);

        if(posicao > -1)
        {
            printf("Erro - Este contribuinte já existe!");
        }
        else
        {
            cliente[*quantidadeCliente].numContribuinte = numContribuinte;
            cliente[*quantidadeCliente].contactoTele = lerInteiro("\nTelefone: ",)
            lerString("\nNome: ", cliente[*quantidadeCliente].nome, 80);
            lerString("\nMorada: ", cliente[*quantidadeCliente].morada, 80);
            gravarFicheiro(cliente[*quantidadeCliente]);
            (*quantidadeClientes)++;
        }
    }
}

//Funcao que procura o cliente pelo seu contribuinte
int procurarCliente()
{
    int posicao= -1, i;

    for(i = 0; i < quantidadeCliente; i++)
    {
        if(quantidadeCliente[i].contribuinte == posicao)
        {
            posicao = i;
            i = quantidadeCliente;
        }
    }
    return posicao;
}

//Funcao para listar as informacoes dos clientes
void listarClientes(tipoCliente cliente[150], int *quantidadeCliente)
{
    int i;
    for(i = 0, i < *quantidadeCliente, i++)
    {
        printf("A listar clientes...\n\n");

        printf("\nContribuinte : %d", cliente[i].numContribuinte);
        printf("\nContribuinte : %s", cliente[i].nome);
        printf("\nContribuinte : %s", cliente[i].morada);
        printf("\nContribuinte : %d", cliente[i].contactoTele);
    }
}