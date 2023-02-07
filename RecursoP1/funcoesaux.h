#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include "declaracoes.h"

///PROTOTIPOS

int lerInteiro(char mensagem[80], int minimo, int maximo);
float lerFloat(char mensagem[80], float minimo, float maximo);
void lerString(char mensagem[80], char vetorCaracteres[80], int maximoCaracteres);
tipoData lerData();
void limpaBufferStdin(void);
void pressionarContinuar();
void limpaEcra();
void lerFicheiro();
void gravarFicheiro(char linha[150]);

#endif // FUNCOES_AUXILIARES_H
