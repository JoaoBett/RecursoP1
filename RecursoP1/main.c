#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "declaracoes.h"
#include "exame.h"
#include "funcoesaux.h"

//----------Funcoes dos Menus----------

int menuPrinc(int *quantidadeAgendamentos, int *quantidadeVisitas);
int menuClientes();
int menuEstatistico();
int menuFicheiros();
int menuAgendamento();

//----------Funcoes das funcionalidades----------

void inserirCliente(tipoCliente cliente[150], int *quantidadeCliente);
void listarClientes(tipoCliente cliente[150], int quantidadeCliente);
int procurarCliente(tipoCliente cliente[150],int *quantidadeCliente, int contribuinte);

//----------Main----------

int main()
{
    tipoCliente cliente[150];
    int quantidadeCliente, opcao, quantidadeAgendamentos = 0, quantidadeVisitas = 0, opcSubMenu;

    do{
        opcao = menuPrinc(&quantidadeAgendamentos, &quantidadeVisitas);

        switch(opcao)
        {
            case 1:
                opcSubMenu = menuClientes();

                switch (opcSubMenu)
                {
                    case 1:
                        inserirCliente(cliente, &quantidadeCliente);
                    break;

                    case 2:
                        listarClientes(cliente, quantidadeCliente);
                    break;

                    case 3:
                        listarClienteData();
                    break;
                }
                break;

            case 2:
                    opcSubMenu = menuAgendamento();

                    switch (opcSubMenu)
                {
                    case 1:

                    break;

                    case 2:

                    break;
                }
            break;


            case 3:
                opcSubMenu = menuFicheiros();

                switch (opcSubMenu)
                {
                    case 1:
                       // gravarFicheiro(cliente,);
                    break;

                    case 2:
                       // lerFicheiro();
                    break;
                }
            break;

            case 4:
                opcSubMenu = menuEstatistico();

                switch (opcSubMenu)
                {
                case 1:
                  //  melhoresClientes();
                break;

                case 2:
                   // percentagemSatisfacao();
                break;
                }
            break;

            default:
            break;
        }
    } while(opcao < 5);

    return 0;
}

//----------Funcoes dos Menus----------

int menuPrinc(int *quantidadeAgendamentos, int *quantidadeVisitas)
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("----------------------------Tecnico de Reparacoes----------------------------\n\n");
    printf("Total de agendamentos: %d \t Total de visitas realizadas: %d \n\n", *quantidadeAgendamentos, *quantidadeVisitas);
    printf("\n\t1 - Menu Clientes");
    printf("\n\t2 - Menu Agendamentos");
    printf("\n\t3 - Menu Ficheiros");
    printf("\n\t4 - Menu Estatistica");
    printf("\n\t5 - Voltar");
    printf("\n\nOpcao--> ");

    scanf("%d", &opc);

    return opc;
}


int menuClientes()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("\t\tMenu Clientes\n");
    printf("\n1 - Adicionar Novo Cliente Visita");
    printf("\n2 - Listar Clientes");
    printf("\n3 - Listar Clientes e respetivos agendamentos");
    printf("\n4 - Sair");

    opc = lerInteiro("\nOpcao",1,4);

    return opc;
}

int menuFicheiros()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    while (opc != 3)
    {
    printf("\t\tMenu Ficheiros\n");
    printf("\n1 - Guardar Ficheiro");
    printf("\n2 - Ler Ficheiro");
    printf("\n3 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }

    return opc;
}

int menuEstatistico()
{
    //Declaracao de variaveis
    int opc;

    //Menu

    while (opc != 3)
    {
    printf("\t\tMenu Estatistico\n");
    printf("\n1 - Melhores Clientes");
    printf("\n2 - Percentagem com grau de satisfacao");
    printf("\n3 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }
    return opc;
}

int menuAgendamento()
 {
    //Declaracao de variaveis
    int opc;

    //Menu
    while(opc != 4)
    {
    printf("\t\tMenu Agendamento\n");
    printf("\n1 - Adicionar Novo Agendamento");
    printf("\n2 - Registar visita");
    printf("\n3 - Consultar Agendamentos (por data)");
    printf("\n4 - Sair");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }
    return opc;
 }

//-----------Funcoes das Funcionalidades----------

//Funcao que insere um novo cliente na base de dados
void inserirCliente(tipoCliente cliente[150], int *quantidadeCliente)
{
    int numContribuinte, posicao;

    if(*quantidadeCliente > 150)
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
            cliente[*quantidadeCliente].contribuinte = numContribuinte;
            cliente[*quantidadeCliente].contactoTele = lerInteiro("\nTelefone: ",MIN_TELE,MAX_TELE);
            lerString("\nNome: ", cliente[*quantidadeCliente].nome, 80);
            lerString("\nMorada: ", cliente[*quantidadeCliente].morada, 80);
            (*quantidadeCliente)++;
        }
    }
}

//Funcao que procura o cliente pelo seu contribuinte
int procurarCliente(tipoCliente cliente[150], int *quantidadeCliente, int contribuinte)
{
    int posicao= -1, i;

    for(i = 0; i < *quantidadeCliente; i++)
    {
        if(cliente[i].contribuinte == posicao)
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
        printf("A listar clientes...\n\n");

        printf("\nContribuinte: %d", cliente[i].contribuinte);
        printf("\nNome: %s", cliente[i].nome);
        printf("\nMorada: %s", cliente[i].morada);
        printf("\nTelefone : %d", cliente[i].contactoTele);
    }
}

void listarClienteData(tipoCliente cliente[150], int quantidadeCliente, tipoData data, tipoAgendamento agendamento)
{
    int i;

    if(quantidadeCliente < 0)
    {
        printf("Atencao - Nao existem Clientes");
    }
    else
    {
        data = lerData();

        if(data.dia == agendamento.data.dia && data.mes == agendamento.data.mes && data.ano == agendamento.data.ano)
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
            printf("Atencao - Nao existem nenhum cliente e/ou agendamneto com esta data!");
        }
    }
}
