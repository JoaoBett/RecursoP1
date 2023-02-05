#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

#include s

///Declaracoes de estruturas

typedef struct
{
    int dia, mes, ano;

}tipoData;

typedef struct
{
    int id;
    char nome[80];
    char morada[80];
    int contactoTele;

}tipoCliente;

typedef struct
{
    int id;
    int contribuinte;
    tipoData data;
    int hora;
    char descricao[80];
    int custoVisita;
    int satisfacao;

}tipoAgendamento;

#endif // DECLARACOES_H_INCLUDED
