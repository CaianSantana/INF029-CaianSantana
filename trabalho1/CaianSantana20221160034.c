// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "CaianSantana20221160034.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  
  //quebrar a string data em strings sDia, sMes, sAno
// 1-Se o ano for uniformemente divisível por 4, vá para a etapa 2. Caso contrário, vá para a etapa5. 
//2-Se o ano for uniformemente divisível por 100, vá para a etapa 3. Caso contrário, vá para a etapa 4. 
//3-Se o ano for uniformemente divisível por 400, vá para a etapa 4. Caso contrário, vá para a etapa 5. 
//4-O ano é bissexto (tem 366 dias). 
//5-O ano não é um ano bissexto (tem 365 dias).
  DataQuebrada dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0) 
    return 0;
  if(dataQuebrada.iMes == 2)
    if(dataQuebrada.iDia == 29)
      if(!(dataQuebrada.iAno%4 == 0 || dataQuebrada.iAno%400 == 0))
        if((dataQuebrada.iAno%100 !=0))  
          return 0;
  if(dataQuebrada.iMes==1||dataQuebrada.iMes==3||dataQuebrada.iMes==5||dataQuebrada.iMes==7||
    dataQuebrada.iMes==8||dataQuebrada.iMes==10||dataQuebrada.iMes==12)
    if(dataQuebrada.iDia > 31)
      return 0;
  if(dataQuebrada.iMes==4||dataQuebrada.iMes==6||dataQuebrada.iMes==9||dataQuebrada.iMes==11)
    if(dataQuebrada.iDia > 30)
      return 0;
  if(dataQuebrada.iMes>12 || dataQuebrada.iMes <1)
    return 0;
  return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DataQuebrada di, df;
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    dma.qtdDias =0;
    dma.qtdMeses =0;
    dma.qtdAnos =0;
    int mNegativos = 0;
    int aNegativos = 0;
    di = quebraData(datainicial);
    df = quebraData(datafinal);
    int trintaum[] = {1,3,5,7,8,10,12}, i = 0, bissextodi = 0, bissextodf=0;
    
    //verifica se os dias ou os meses são válidos
    if((di.iDia <1 || di.iDia>31)||(di.iMes <1 || di.iMes>12)){ 
        dma.retorno = 2;
        return dma;
    }
    if((df.iDia <1 || df.iDia>31)||(df.iMes <1 || df.iMes>12)){
        dma.retorno = 3;
        return dma;
    }
    if(!(di.iAno%4 == 0 || di.iAno%400 == 0)&& di.iDia ==29){
                dma.retorno = 2;
                return dma;
    }else if(di.iAno%4 == 0 || di.iAno%400 == 0) bissextodi = 1;
    if(!(df.iAno%4 == 0 || df.iAno%400 == 0)&& df.iDia ==29){
                dma.retorno = 3;
                return dma;
    }else if(df.iAno%4 == 0 || df.iAno%400 == 0) bissextodf = 1;
    
    
    //calcula diferença de dias
    if(di.iDia < df.iDia){
        dma.qtdDias = df.iDia - di.iDia;
    }
    if(di.iDia == df.iDia){
        dma.qtdDias = 0;
    }
    if(di.iDia>df.iDia){
        for(i=0;i<8;i++){
            if(di.iMes == trintaum[i]){
                dma.qtdDias = 31 - (di.iDia - df.iDia);
                mNegativos--;
            }
        }
            if(di.iMes == 2 && (bissextodi == 0 && bissextodf == 0)){
                dma.qtdDias = 28 - (di.iDia - df.iDia);
                mNegativos--;
            }
            else if(di.iMes == 2 && (bissextodi == 1 || bissextodf == 1)){
                dma.qtdDias = 29 - (di.iDia - df.iDia);
                mNegativos--;
            }
        if(dma.qtdDias ==0){
            dma.qtdDias = 30 - (di.iDia - df.iDia);
            mNegativos--;
        }
        if(bissextodi == 1 && bissextodf == 0) dma.qtdDias-=1;
    }
    
    //calcula diferença de meses
    if(di.iMes < df.iMes){
        dma.qtdMeses = df.iMes - di.iMes;
    }
    if(di.iMes == df.iMes){
        dma.qtdMeses = 0;
    }
    if(di.iMes>df.iMes){
        dma.qtdMeses-= 12 - (di.iMes - df.iMes);
        dma.qtdAnos-=1;
    }
    
    //calcula diferença de anos
    if(di.iAno < df.iAno){
        dma.qtdAnos = df.iAno - di.iAno;
    }
    if(di.iAno == df.iAno){
        dma.qtdAnos = 0;
    }
    if(di.iAno>df.iAno){
        dma.qtdAnos-= di.iAno - df.iAno;
    }
    
    //verifica se a data final é maior do que a inicial
    if(dma.qtdDias <0 || dma.qtdMeses <0 || dma.qtdAnos <0){
        dma.retorno = 4;
        return dma; 
    }
    //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas

        dma.qtdMeses += mNegativos;
      //se tudo der certo
      dma.retorno = 1;
      return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char texto[], char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, i=0;
    if(isCaseSensitive == 1)
        for(;texto[i]!='\0';i++){
            if(texto[i]==c) qtdOcorrencias++;}
    else 
        for(;texto[i]!='\0';i++){
            if(texto[i]==c || texto[i]==c-32 ||texto[i]==c+32) qtdOcorrencias++;}
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char strTexto[], char strBusca[], int posicoes[30])
{
    int qtdOcorrencias = 0, i, j,k=0, d=0,cont,cont2,tam=0;
    for(i=0;strBusca[i]!='\0';i++){
        tam++;
    }
    for(i=0;strTexto[i]!='\0';i++){
        j=0;
        cont=0;
        cont2=0;
        if(strTexto[i]<-61){
          d--;
        } 
        if(strTexto[i] == strBusca[j]){
            for(j=1;strBusca[j]!='\0';j++){
                if(strBusca[j]!=strTexto[i+j]){ 
                    cont++;
                }
            }
            if(cont==0){
                posicoes[k]=i+1+d;
                posicoes[k+1]=i+tam+d;
                k+=2;
                qtdOcorrencias++;
                i+=1;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int descobreBase(int numero){ //Descobre a base do numero escolhido
  int i, potencia=0;
  while(numero>9){
    numero/=10;
    potencia++;
  }
   if(potencia == 0)
    potencia = 0;
  return potencia;
}

int q5(int num)
{
    int i, k=10, dividido, multiplicador, notacao=descobreBase(num), inverso=0;
    while(num>0){ //para inverter um numero, eu preciso ir cortando cada numero do inicio e jogando multiplicado pela base certa pro inverso
        multiplicador =1;
        dividido = num%10;
        for(i=0;i<notacao;i++) multiplicador*=10;
        inverso += dividido * multiplicador;
        notacao--;
        num = (num - dividido)/10;
    }
    return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */


int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0, nbase[10], nbusca[10], notacao, notacao2, i, j, d1=numerobase, d2=numerobusca, igual=0;
    notacao = descobreBase(numerobase);
    notacao2 = descobreBase(numerobusca);
    for(i=notacao; d1>0;i--){
      nbase[i] = d1%10;
      d1/=10;
    }
    for(i=notacao2; d2>0;i--){
      nbusca[i] = d2%10;
      d2/=10;
    }
    for(i=0;i<=notacao;i++){
        if(notacao2>0){
            igual=0;
            if(nbase[i]==nbusca[0]){
                for(j=1; j<=notacao2; j++){
                    if(nbase[i+j] != nbusca[j]) igual=1;
                }
                if(igual==0) qtdOcorrencias++;
                if(nbase[i] == nbase[i+1]) i++;
            }
        }
        else{
            if(nbase[i]==nbusca[0]) qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}
