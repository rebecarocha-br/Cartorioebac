#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bilbioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuirdar dos strings

int registro ()  //função responsável por cadastrar os unuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("DIGITE O CPF A SER CADASTRADO: ");  //coletando informação do usuário
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável	
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abrindo o arquivo
	fprintf(file,",");  
	fclose(file);  //fecha o arquivo
	
	printf("DIGITE O NOME A SER CADASTRADO: "); //coletando informação "nome"
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo
	fprintf(file,nome);
	fclose(file);  //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME A SER CADASTRADO: "); //coletando a informação "sobrenome"
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");  //abrindo o arquivo
	fprintf(file,sobrenome);
	fclose(file);  //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O CARGO A SER CADASTRADO: ");  //coletando a informação "cargo"
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");  //encerrando o menu de registro
	
}

int consulta()  //função responsável por fazer a consulta de dados
{
	//início do menu de consulta
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];  //definindo a char cpf e seu tamanho
	char conteudo[200];  //definindo a char conteúdo e seu tamanho
	
	printf("DIGITE O CPF A SER CONSULTADO: ");  //coletando a informação "cpf"
	scanf("%s",cpf);
	
	FILE *file;  //armazenando a informação no arquivo
	file = fopen(cpf,"r");  //lendo a informação no arquivo r=read
	
	if(file == NULL)  //definindo a condição de informação incompatível com as registradas no sistema
	{ 
		printf("NÃO FOI POSSÍVEL ABRIR O ARQUIVO, NÃO LOCALIZADO!.\n");  //mensagem que aparece na tela
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //se a informação for válida
	{
		printf("\nESSAS SÃO AS INFORMAÇÕES DO USUÁRIO: ");  //mostrando as informações do usuário solicitado na tela
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);  //fechando o arquivo
	system("pause");  //encerrando o menu consulta
}


int deletar()  //menu de deletar informações
{
	//iniciando o menu
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //definindo o char e seu tamanho
	
	printf("DIGITE O CPF A SER DELETADO: ");  //solicitando informação 
	scanf("%s",cpf);  //procurando dados no arquivo
	
	remove(cpf);  //deletando os dados do arquivo
	
	FILE *file; //abrindo o arquivo
	file = fopen(cpf,"r");  //lendo o arquivo
	
	if(file == NULL)  //definindo a condicional
	{
		printf("O USUÁRIO DIGITADO NÃO SE ENCONTRA NO SISTEMA!.\n");  //mensagem que aparece na tela após o dado ser deletado
		system("pause");  //encerrando o menu
	 } 
	
}


int main()  //definindo o menu principal
{
	int opcao=0; //definindo as variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu\n\n");  //mensagem para o usuário
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n\n"); 
		printf("OPÇÃO: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");  //responsável por limpar a tela
		
		
		switch(opcao)  //início da seleção do menu
		{
			case 1:
			registro();  //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:  //para entrada de opção não disponível no menu
			printf("ESSA OPÇÃO NÃO ESTÁ DISPONÍVEL\n");  //mensagem na tela
			system("pause");  //fim do menu
			break;	
		}
	
		
	}
}

