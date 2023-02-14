#ifndef FUNCIONALIDADES_H_INCLUDED
#define FUNCIONALIDADES_H_INCLUDED

void inserirCliente(tipoCliente cliente[150], int *quantidadeCliente);
void listarClientes(tipoCliente cliente[150], int quantidadeCliente);
int procurarCliente(tipoCliente cliente[150],int quantidadeCliente, int contribuinte);
void listarClienteData(tipoCliente cliente[MAX], int quantidadeCliente, tipoAgendamento agendamento[MAX]);

#endif // FUNCIONALIDADES_H_INCLUDED
