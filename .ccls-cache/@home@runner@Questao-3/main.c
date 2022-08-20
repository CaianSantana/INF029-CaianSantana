#include <stdio.h>
//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
int main(void) {
  int valor[4], i;
  for(i=0;i<2;i++)
  {
    printf("Digite um valor: ");
    scanf("%i",&valor[i]);
  }
  valor[3] = valor[0];
  valor[0] = valor[1];
  valor[1] = valor[3];
  printf("valor 1: %d\n valor 2: %d", valor[0], valor[1])
}