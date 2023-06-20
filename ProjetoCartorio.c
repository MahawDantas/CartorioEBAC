#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //in�cio das fun��es
{	
	char arquivo[40]; //in�cio das op��es de registro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //fim das op��es de registro
	
	printf("Digite o CPF do usu�rio a ser cadastrado: \n");
	scanf("%s", cpf); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //abre o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salva a informa��o da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //separa��o das informa��es de registro com v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome do usu�rio a ser cadastrado: \n");
	scanf("%s", nome); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, nome); //salva a informa��o da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, " "); //separa��o das informa��es de registro com espa�o
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome do usu�rio a ser cadastrado: \n");
	scanf("%s", sobrenome); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome); //salva a informa��o da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //separa��o das informa��es de registro com v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo do usu�rio a ser cadastrado: \n");
	scanf("%s", cargo); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo); //salva a informa��o da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa at� que o usu�rio ordene o contr�rio	
}

int consulta()
{
	char cpf[40]; //in�cio das op��es de consulta
	char conteudo[200]; //fim das op��es de consulta
	
	printf("Digite o CPF do usu�rio a ser consultado: \n");
	scanf("%s", cpf); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //l� o arquivo
	
	if(file == NULL) //caso n�o fale o cpf registrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver conte�do no arquivo 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //armazenando a informa��o do usu�rio(%s refere-se a string)
		printf("\n\n"); //pulando linhas
	}
	
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa at� que o usu�rio ordene o contr�rio
}

int deletar()
{
	char cpf[40]; //op��o de deletar
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf); //armazenando a informa��o do usu�rio(%s refere-se a string)
	
	remove(cpf); //deletando o cpf
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //l� o arquivo
	
	if(file == NULL) //caso n�o fale o cpf registrado
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause"); //pausa at� que o usu�rio ordene o contr�rio
	}	
} //fim das fun��es
 
 
 
int main()
{	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	int opcao = 0; //definindo as vari�veis
	int laco = 1; //definindo as vari�veis
	char senhadigitada[10] = "a"; //definindo as vari�veis
	int comparacao; //definindo as vari�veis
	
	printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
	printf("Login de administrador\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada); //armazenando a informa��o do usu�rio
	system("cls"); //limpa a tela
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) //caso a senha estiver correta
	{
		for(laco = 1; laco = 1;) //mant�m o menu rodando at� que o usu�rio ordene o contr�rio
		{
		
			system("cls"); //limpa a tela
	
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar Informa��es\n");
			printf("\t2 - Consultar Informa��es\n");
			printf("\t3 - Deletar Informa��es\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Op��o: ");	//fim do menu

			scanf("%d", &opcao); //armazenando a escolha do usu�rio(%d refere-se a inteiro)

			system("cls"); //limpa a tela
		
			switch(opcao) //in�cio da sele��o
			{
				case 1: //case = caso seja
				registro(); //fun��o chamada
				break; //encerra o case
			
				case 2: //case = caso seja
				consulta(); //fun��o chamada
				break; //encerra o case
			
				case 3: //case = caso seja
				deletar(); //fun��o chamada
				break; //encerra o case
			
				case 4: //case = caso seja
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //quebra tudo e sai do sistema
				break; //encerra o case
				
				default: //caso seja qualquer n�mero fora dos cases
				printf("Esta op��o n�o est� dispon�vel!\n");
				system("pause"); //pausa at� que o usu�rio ordene o contr�rio
				break; //encerra o case
			} //fim da sele��o
	    }	
	}

	else
		printf("Senha incorreta!");
}
