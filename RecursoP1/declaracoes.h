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
    int horas, minutos;
}tipoHorario;

typedef struct
{
    int id;
    char nome[80];
    char morada[80];
    int contactoTele;

}tipoCliente;

#endif // DECLARACOES_H_INCLUDED
