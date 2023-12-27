#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h>  // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// in�cio cria��o de vari�veis/string 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se as string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w");  // cria o arquivo
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file, ","); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", nome); // %s refere-se as string
	
	file = fopen(arquivo, "a");  //cria o arquivo
	fprintf(file,nome); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); // salvo o valor da vari�vel
	fclose(file);  // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", sobrenome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cargo); // %s refere-se as string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause");
	
}

int Consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// in�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// final cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); // coletando informa��es do usu�rio
	scanf("%s",cpf); // %s refere-se as string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int Deletar()
{
    char cpf[40];
    
    printf ("Digite o cpf do usu�rio a ser deletado: "); // coletando informa��es do usu�rio
    scanf("%s",cpf); // %s refere-se as string
    
    remove(cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf, "r"); // cria o arquivo
    
    if(file == NULL)
    {
    	printf("O usu�rio nao se encontra no sistema!.\n");
    	system("pause");	
	}
    
    
}

int main ()
    {
	int opcao=0; //Definindo Vari�veis 
	int x=1;
		
	for(x=1;x=1;)	
{
		system("cls"); // respons�vel por limpar a tela

		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
 		printf("Cart�rio da EBAC\n\n"); //In�cio do menu	
 		printf("Escolha a op��o desejada do menu:\n\n");
 		printf("\t1 - Inclus�o de usu�rios\n");
 		printf("\t2 - Consulta de usu�rios\n");
 		printf("\t3 - Deletar usu�rios\n\n"); 
 		printf("\t4 - Sair do sistema\n\n");
 		printf("Op��o:");// Fim do menu
 
 		scanf("%d", &opcao); // armazenando a escolha do usu�rio
 
 		system ("cls");
 		
 		switch(opcao) // in�cio da sele��o do menu
			
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			Consulta(); // chamada de fun��es
			break;
			
			case 3:
			Deletar(); // chamada de fun��es	
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf ("N�o existe essa fun��o, tente novamente!\n");
			system("pause");
			break;
		
		}  	
	}	

}



