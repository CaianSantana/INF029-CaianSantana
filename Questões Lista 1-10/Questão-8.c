#include <stdio.h>
//Faça um programa que calcula o fatorial de um número
int main(void) {
  int numero, fatorial=1, i;
  printf("Digite um número: ");
  scanf("%d", &numero);
  for(i=1;i<=numero;i++)
    fatorial *= i;
  printf("A fatorial é: %d",fatorial);
}