#include <stdio.h>
//Faça um programa que leia a idade de duas pessoas e imprima a soma das idades

int main(void) {
  int idade[2], i, soma=0;
  for(i=0;i<2;i++)
  {
    printf("Digite uma idade: ");
    scanf("%i",&idade[i]);
    soma+= idade[i];
  }
  printf("A soma é: %d", soma);
}