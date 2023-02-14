//------------Bibliotecas utilizadas------------

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
int procurarCliente(tipoCliente cliente[150],int quantidadeCliente, int contribuinte);
void listarClienteData(tipoCliente cliente[MAX], int quantidadeCliente, tipoAgendamento agendamento[MAX]);

//----------Main----------

int main()
{
    tipoCliente cliente[MAX];
    tipoAgendamento agendamento[MAX];
    int quantidadeCliente = 0, opcao, quantidadeAgendamentos = 0, quantidadeVisitas = 0, opcSubMenu;

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
                        listarClienteData(cliente, quantidadeCliente, agendamento);
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
                       escreverFicheiroBinario(cliente, quantidadeCliente);
                    break;

                    case 2:
                        lerFicheiroBinario(cliente, &quantidadeCliente);
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
    printf("\n1 - Adicionar Novo Cliente");
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
