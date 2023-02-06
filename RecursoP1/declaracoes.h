#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

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
    int contribuinte;
    char nome[80];
    char morada[80];
    int contactoTele;

}tipoCliente;

///Declaracoes de constantes

MIN_CONTRIBUINTE 111111111

MAX_CONTRIBUINTE 999999999

MIN_TELE 111111111

MAX_TELE 999999999

#endif // DECLARACOES_H_INCLUDED
