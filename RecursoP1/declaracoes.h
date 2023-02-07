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
#define MIN_CONTRIBUINTE 111111111

#define MAX_CONTRIBUINTE 999999999

#define MIN_TELE 111111111

#define MAX_TELE 999999999

#define CLIENTES "cliente"

#define AGENDAMENTO "agendamento"

#endif // DECLARACOES_H_INCLUDED
