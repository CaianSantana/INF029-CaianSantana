#include <stdio.h>
#include <string.h>
//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar
int main(void) {
  char valor1[4], valor2[4];
  printf("Digite um valor: ");
  fgets(valor1, 4, stdin);
  strcpy(valor2 ,valor1);
  getchar();
  printf("Digite um valor: ");
  fgets(strcpy(valor1 ,valor2), 4, stdin);
  getchar();
  printf("primeiro valor: %s\nsegundo valor: %s ", valor1, valor2);
}