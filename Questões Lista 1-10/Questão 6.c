#include <stdio.h>
//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada
int main(void) {
  int idade = 0;
  
  while(idade>=0)
    {
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    if(idade >= 18)
      printf("É de maior.\n");
    else if(idade <0)
      printf("Não existe idade negativa.");
    else
      printf("É de menor.\n");
    }
}