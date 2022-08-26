#include <stdio.h>
#include <string.h>
//IDENTACAO
int main() {
  int n = 0, i = 0, j = 0;
  int idade[4],  acima[4];
  double media = 0;
  char s;
  char nome [6][6];
  while (i<4)
  {
    printf("Digite um nome: ");
    scanf("%s", &nome[i][i]);
    printf("Digite uma idade: ");
    scanf("%d", &idade[i]);
    media += idade[i];
    i++;
  }
  media = media/4;
  for(i=0;i<4;i++)
  {
    if(media < idade[i])
    {
      acima[j] = idade[i];
      s = nome[i][i];
      printf("Nome: %s \n" ,&nome[i][i] );
      printf("idade: %d",acima[j]);
    }
  }
}