#include <stdio.h>
//Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.
int main() 
{
  struct Ficha_Aluno
  {
    char nome[50];
    char matricula[30];
    char semestre[10];
  };
  struct Ficha_Aluno aluno1 = { "Caian de Jesus Santana", "20221160034", 
  "2022.1"};
  printf("Nome: %s\nMatrícula: %s\nSemestre: %s",
    aluno1.nome, aluno1.matricula, aluno1.semestre);
  return 0;
}