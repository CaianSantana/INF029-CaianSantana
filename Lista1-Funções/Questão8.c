#include <stdio.h>
#include <string.h>
//8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente.
typedef struct{
  char Nome[51];
  char DataNascimento[12];
  char CPF[16];
  char Sexo[2];
}Cliente;
Cliente SetCliente(char Nome[51], char DataNascimento[11], char CPF[15], char Sexo[2]){
  Cliente c;
  strcpy(c.Nome, Nome);
  strcpy(c.DataNascimento, DataNascimento);
  strcpy(c.CPF, CPF);
  strcpy(c.Sexo, Sexo);
  return c;
}
Cliente CadastrarCliente();
Cliente CadastrarCliente(){
  char nome[51], data[11], cpf[15], sexo[2];
  Cliente cliente;
  printf("Digite o nome: ");
  fgets(nome, 51, stdin);
  printf("Digite a data de nascimento: ");
  fgets(data, 11, stdin);
  printf("Digite o CPF: ");
  fflush(stdin);
  fgets(cpf, 15, stdin);
  printf("Digite o sexo: ");
  fflush(stdin);
  fgets(sexo, 2, stdin);
  cliente = SetCliente(nome, data, cpf, sexo);
  return cliente;
}

int main(void) {
  Cliente cliente = CadastrarCliente();
  printf("Nome: %sData de Nascimento: %sCPF: %sSexo: %s",
        cliente.Nome, cliente.DataNascimento, cliente.CPF, cliente.Sexo);
}

