#include <stdio.h> 					//biblioteca de comunica��o do usu�rio
#include <stdlib.h> 				//biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h>					//biblioteca de aloca��o de texto por regi�o
#include <string.h>					//biblioteca repons�vel por cuidar das string


int registro() 						//registrar usu�rios
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);				//Responsavel por armazenar a informa��o na variavel atraves do % o s � de string
	
	strcpy(arquivo, cpf); 			//Responsavel por copiar os valores das strings
	
	FILE *file; 					//cria o arquivo
	file = fopen(arquivo, "w"); 	//cria o arquivo
	fprintf(file,cpf); 				//abri no arquivo e salvar o valor da variavel dentro
	fclose(file);					//fecha o arquivo
	
	file = fopen(arquivo, "a"); 	//atualizar o arquivo com virgula
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 	//atualizar o arquivo com virgula
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 	//atualizar o arquivo com virgula
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome do cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}
int consulta() 							//consulta de usu�rio
{
	setlocale(LC_ALL, "Portuguese"); 	//define linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultat: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");				//consultar o cpf na base
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o loclizado. \n");
	}
	
	while(fgets(conteudo, 200,file)!= NULL)		//la�o temporal para procurar na base
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()  						 //deletador de usu�rios
{
	char cpf[40];
	printf("Digite o CPF para deletar: \n");
	scanf("%s", cpf);
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");


	if(file == NULL){
		
		printf("O usu�rio n�o se encotra no sistema! \n");
	
		system("pause");
		}
	
	
}


int main()
{
	int opcao=0;  		//definindo variavel
	int laco=1;

	for(laco=1;laco=1;){
		
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
	printf("-------- Cart�rio da EBAC --------\n\n");   //inicio do meu
	printf(" Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes:\n");
	printf("\t2 - Consultar nomes:\n");
	printf("\t3 - Excluir nomes:\n"); 
	printf("\t4 - Sair do sistema:\n\n");
	printf("Op��o: "); //fim menu	
	
	scanf("%d", &opcao);  //armazena as variaveis
	system("cls");		//apaga o que tiver na tela
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();	
		break;
		
		case 3:
		deletar();	
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema\n\n");
		return 0;
		break;
		
		default:
				printf("\n Essa op�ao n�o est� disponivel!!\n\n");
		system("pause\n");
		break;
			
	}
	

}
	
	printf(" Esse software � de livre uso de estudo: autor Jo�o Vitor");
	}
