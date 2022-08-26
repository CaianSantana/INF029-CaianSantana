#include <stdio.h>
//Faça um programa que verifique se um número é primo
int main(void)
{
  int numero, i, contador=0;
  printf("Digite um número: ");
  scanf("%d", &numero);
  for(i=1;i<12;i++)
    {
      if(numero%i==0)
        contador++;
    }
  if(contador>2)
    printf("O número não é primo.");
  else
    printf("O número é primo.");
}