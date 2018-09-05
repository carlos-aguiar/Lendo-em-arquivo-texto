#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 31

typedef struct{
	
    long long int contrato;
    int consumoMes, consumoAnterior;
    int dia, mes, ano;
    float valorMes, taxaPublica;
    char situacao[7]; 
    
}Dados;

 Dados cliente[TOTAL];

// prototipo das funções
void listarContratos(int a);
void analiseConsumoZero();
void listarExcetoZero();
void listarAPartirData();
void listarQuedaConsumo();
void listarAumentoConsumo();

int main(){
	
	FILE *arqRead; 
	
	/*
	 * No trecho abaixo há uma condição que não será satisfeita se o ponteiro criado não apontar para a abertura do arquivo
	 * correto. Neste caso, será retornado uma mensagem para o usuário informando que não foi possível abrir o arquivo.
	 *
	 */

	if((arqRead = fopen("energia.txt", "r")) ==NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
	    exit(1); // fecha o programa
	}
	    
	/* 
	 * No trecho abaixo criamos uma string de caracteres que será apropriada para substituir as barras por espaços.
	 * Utilizamos essa forma para facilitar a leitura dos dados (apenas os dados sem as barras) pela struct que criamos. 
	 */   
	    
    int i = 0;
	char lbarra[43];
	    
	char c = fscanf(arqRead, "%s", lbarra); // faz a primeira leitura antes de entrar no while   
	while(c != EOF){ // enquanto não for encontrado o final do arquivo(end of file) c continuará fazendo a leitura 
    	
    lbarra[10]=' '; lbarra[13] = ' '; lbarra[16] = ' '; lbarra[21] = ' '; lbarra[25] = ' '; lbarra[32] = ' ';
	lbarra[38] = ' '; lbarra[42] = ' ';
    	
	sscanf(lbarra,"%lld %d %d %d %d %f %f %d %s\n", &cliente[i].contrato, &cliente[i].dia, &cliente[i].mes, &cliente[i].ano,
	&cliente[i].consumoMes, &cliente[i].valorMes, &cliente[i].taxaPublica, &cliente[i].consumoAnterior, cliente[i].situacao);
    
   
	c = fscanf(arqRead, "%s", lbarra); // repete a leitura antes de voltar para a condição while
	i++;
    } 
    			
    fclose(arqRead); // fecha o arquivo
    
    int opcao=6;
 
    while(opcao!=0){
 	
    system("cls");
    
 printf("*****************************************************************\n"); 
 printf("*       *    *  *     *  *  *****   ****  ******  ******        *\n");                              
 printf("*       *    *  * *   *  *  *      *    * *       *             *\n");                              
 printf("*       *    *  *  *  *  *  *****  ****** *       ******        *\n");                              
 printf("*       *    *  *    **  *  *      *    * *            *        *\n");                              
 printf("*        ****   *     *  *  *      *    * ******  ******        *\n");
 printf("*                     SISTEMA DE INFORMACAO                     *\n");
 printf("*****************************************************************\n");   
 
 printf("\n[1] LISTAR TODOS OS CONTRATOS, EXCETO CONSUMO ZERO\n");
 printf("[2] LISTAR OS CONTRATOS CONSUMO ZERO PARA ANALISE\n");
 printf("[3] LISTAR CONTRATOS EM ATRASO A PARTIR DA DATA SOLICITADA\n");
 printf("[4] LISTAR CONTRATOS QUE TIVERAM QUEDA NO CONSUMO, INCLUSIVE ZERO\n");
 printf("[5] LISTAR CONTRATOS QUE TIVERAM AUMENTO DE CONSUMO\n");
 printf("[0] PARA SAIR DO SISTEMA\n");
 printf("\nOPCAO: ");
 scanf("%d", &opcao);
 
      printf("***********************************************\n"); 
      printf("  CONTRATO|VENCIMENTO|C.M|VL.MES|T.PBL|C.A|SIT \n");                              
      printf("***********************************************\n");   
  
  //Aqui entra a opção desejada pelo usuário
 switch(opcao){
 	
 	case 1: listarExcetoZero();
 	        system("pause");
 	
		break;
	 	 
	case 2: analiseConsumoZero();
	        system("pause");
	 	
		break;
	 	 
	case 3: listarAPartirData();
	        system("pause");
		break;
	 	 
	case 4: listarQuedaConsumo();
	        system("pause");   
	 	
		break;
	 	  
	case 5: listarAumentoConsumo();
	        system("pause");
	 	
		break;

	default: system("cls");
		break;

    }
       
   }
      
 }
 
 /* Essa função é universal, todas as funções que necessitam lista o documento chamam essa função. Desta forma, encurtamos 
  * a quantidade de linhas de código e deixamos o código mais legível, mais apropriado.
  */
  
 void listarContratos(int i){
 	
	     
	printf("%lld|%02d/%d/%d|%03d|%6.2f|%5.2f|%03d|%s\n", cliente[i].contrato, cliente[i].dia, cliente[i].mes, cliente[i].ano, cliente[i].consumoMes, cliente[i].valorMes, cliente[i].taxaPublica, cliente[i].consumoAnterior, cliente[i].situacao);
		 	
 }
 
 void listarExcetoZero(){
 	
 	int i;
 	
	 for(i = 0; i < TOTAL; i++){
 	 	
	    if(cliente[i].consumoMes != 0)
	    listarContratos(i);
	     		
	}
 	 	
 }
 
 void analiseConsumoZero(){
 	int i;
 	
 	for(i = 0; i < TOTAL; i++){
	 
 		if(cliente[i].consumoMes == 0)
 		listarContratos(i);
    }
 } 
 
 void listarAPartirData(){
 	
 	int i, dia;
 	
 	printf("DIGITE O DIA: ");
 	scanf("%d", &dia);
 	
 	dia--;    	
	for(i = dia; i < TOTAL; i++){
	if(cliente[i].situacao[i] != 'pago')
	listarContratos(i);		
    }
  
  }
  
  void listarQuedaConsumo(){
   
  int i; 
  
    for(i = 0; i < TOTAL; i++){
    if(cliente[i].consumoMes < cliente[i].consumoAnterior)	
    listarContratos(i);
    }	
  }
  
  void listarAumentoConsumo(){
  	int i;
  	
  	for(i = 0; i < TOTAL; i++){
  		if(cliente[i].consumoMes > cliente[i].consumoAnterior)
  		listarContratos(i);
	  }
  }
