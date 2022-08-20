#include <stdio.h>
//Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.
int main(void)
{
  int numero[11], i,j, contador, soma=0;
  for(i=1;i<11;i++)
    {
      contador=0;
      printf("Digite um número: ");
      scanf("%d", &numero[i]);
      for(j=1;j<=11;j++)
          if(numero[i]%j== 0)
            contador++;
      if(contador<=2 && numero[i] != 1)
      {
        printf("O número %d é primo.\n",numero[i]);
        soma+=numero[i];
      }
    }
  printf("A soma dos primos é: %d",soma);
}