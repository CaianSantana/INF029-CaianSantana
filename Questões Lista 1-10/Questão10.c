#include <stdio.h>
#include <string.h>
//Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.
typedef struct 
  {
    char nome[51];
    int idade;
    char sexo[11];
    char cpf[16];
  }Pessoa;
int main() 
{
  char nome[51], sexo[11], cpf[16];
  int idade, i, j;
  Pessoa pessoas[5];
  for(i=0;i<5;i++)
  {
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(pessoas[i].nome, 51, stdin);
    pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;
    printf("Digite a idade: ");
    scanf("%d",&pessoas[i].idade);
    getchar();
    printf("Digite o sexo: ");
    fflush(stdin);
    fgets(pessoas[i].sexo, 11, stdin);
    pessoas[i].sexo[strcspn(pessoas[i].sexo, "\n")] = 0;
    printf("Digite o cpf: ");
    fflush(stdin);
    fgets(pessoas[i].cpf, 16, stdin);
    pessoas[i].cpf[strcspn(pessoas[i].cpf, "\n")] = 0;
    printf
    (
      "Nome: %s\nIdade: %d\nSexo: %s\nCPF: %s\n",
      pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo, pessoas[i].cpf
    );
  }
}