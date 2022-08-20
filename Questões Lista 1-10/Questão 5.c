#include <stdio.h>
//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor
int main(void) {
  int idade;
  printf("Digite sua idade: ");
  scanf("%d", &idade);
  if(idade >= 18)
    printf("É de maior.");
  else
    printf("É de menor");
}