#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    tipoCliente cliente[150];
    int quantidadeCliente,opcao;

    opcao = menuPrinc();

    do{
        switch(opcao)
        {
            case 1:
                
                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;
        }
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
    printf("\n5 - Sair");
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
