#include <stdio.h>  //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro()  //Fun��o respons�vel por cadastrar os us�arios no sistema
{		
		//Inicio cria��o v�riaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da cria��o de variaveis/string
		
		printf("Digite o CPF a ser cadastrado: "); // Coletando inform��es do us�ario 
	
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
		
		FILE *file; //cria o arquivo 
		file = fopen(arquivo, "w"); // cria o arquivo
		fprintf(file,cpf);  //salvo o valor da variavel 
		fclose(file);  // fecha arquivo
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);

		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
				
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s,",sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
		
}

int consulta()
{
	 	setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem 
	 	
	 	
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as observa��es do usu�rio:  ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system ("pause");
			
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o do us�ario CPF a ser deletado:  ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			
			printf("O us�ario n�o se encontra no sistema!.\n");
			system("pause");
			
			
			printf("Us�ario deletado com sucesso!.\n");
			system("pause");
			
		}
}


int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t Cart�rio da EBAC \t\n\n");
	printf("Login de administrador!\n\nDigite sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
			system("cls");
			for(laco=1;laco=1;)
			{
	
			system("cls");
	
			setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem 
	
	
			printf("\t Cart�rio da EBAC \t\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");  // Fim do Menu
	
			scanf("%d", &opcao);  //Armazenando a escolha do usu�rio 	
	
	
			system("cls");
		
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
				printf("Obrigado por utilizar nosso sistema!");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");		
				break;
			}
		}
		
	}
	
	else 
	printf("Senha incorreta!");
	
	
}
