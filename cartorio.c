#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuirdar dos strings

int registro ()  //fun��o respons�vel por cadastrar os unu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("DIGITE O CPF A SER CADASTRADO: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel	
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abrindo o arquivo
	fprintf(file,",");  
	fclose(file);  //fecha o arquivo
	
	printf("DIGITE O NOME A SER CADASTRADO: "); //coletando informa��o "nome"
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo
	fprintf(file,nome);
	fclose(file);  //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME A SER CADASTRADO: "); //coletando a informa��o "sobrenome"
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");  //abrindo o arquivo
	fprintf(file,sobrenome);
	fclose(file);  //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O CARGO A SER CADASTRADO: ");  //coletando a informa��o "cargo"
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");  //encerrando o menu de registro
	
}

int consulta()  //fun��o respons�vel por fazer a consulta de dados
{
	//in�cio do menu de consulta
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];  //definindo a char cpf e seu tamanho
	char conteudo[200];  //definindo a char conte�do e seu tamanho
	
	printf("DIGITE O CPF A SER CONSULTADO: ");  //coletando a informa��o "cpf"
	scanf("%s",cpf);
	
	FILE *file;  //armazenando a informa��o no arquivo
	file = fopen(cpf,"r");  //lendo a informa��o no arquivo r=read
	
	if(file == NULL)  //definindo a condi��o de informa��o incompat�vel com as registradas no sistema
	{ 
		printf("N�O FOI POSS�VEL ABRIR O ARQUIVO, N�O LOCALIZADO!.\n");  //mensagem que aparece na tela
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //se a informa��o for v�lida
	{
		printf("\nESSAS S�O AS INFORMA��ES DO USU�RIO: ");  //mostrando as informa��es do usu�rio solicitado na tela
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);  //fechando o arquivo
	system("pause");  //encerrando o menu consulta
}


int deletar()  //menu de deletar informa��es
{
	//iniciando o menu
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //definindo o char e seu tamanho
	
	printf("DIGITE O CPF A SER DELETADO: ");  //solicitando informa��o 
	scanf("%s",cpf);  //procurando dados no arquivo
	
	remove(cpf);  //deletando os dados do arquivo
	
	FILE *file; //abrindo o arquivo
	file = fopen(cpf,"r");  //lendo o arquivo
	
	if(file == NULL)  //definindo a condicional
	{
		printf("O USU�RIO DIGITADO N�O SE ENCONTRA NO SISTEMA!.\n");  //mensagem que aparece na tela ap�s o dado ser deletado
		system("pause");  //encerrando o menu
	 } 
	
}


int main()  //definindo o menu principal
{
	int opcao=0; //definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu\n\n");  //mensagem para o usu�rio
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n\n"); 
		printf("OP��O: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");  //respons�vel por limpar a tela
		
		
		switch(opcao)  //in�cio da sele��o do menu
		{
			case 1:
			registro();  //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:  //para entrada de op��o n�o dispon�vel no menu
			printf("ESSA OP��O N�O EST� DISPON�VEL\n");  //mensagem na tela
			system("pause");  //fim do menu
			break;	
		}
	
		
	}
}

