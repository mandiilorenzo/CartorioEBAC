#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //definindo fun��o de cadastrar o usu�rio no sistema
{
	//in�cio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/strings
	
	printf("Digite o seu CPF para cadastrar:\n"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	

	FILE *file; //acessa e cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file, "CPF:");
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo e adiciona itens
	fprintf(file, "\nNome:");
	fclose(file);
	
	printf("Digite seu nome para cadastrar:\n");
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome:");
	fclose(file);
	
	printf("Digite seu sobrenome para cadastrar:\n");
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo:");
	fclose(file);
	
	printf("Digite o cargo na empresa para cadastrar:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, "\n");
	fclose(file);
	
	system("pause");
	

	
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler arquivo
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado\n");
	}
	
	    printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	    fclose(file);
	    system("pause");
		
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar:\n");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	
	if(file == NULL) //se o arquivo for igual � nulo
	{
		printf("Usu�rio n�o encontrado\n");
		system("pause");
	}
	
	else //sen�o, deleta o arquivo
	{
		remove(cpf); //fun��o de deletar
		printf("Usu�rio deletado\n");
	}
	
	system("pause");
	
    
	
}

int main ()
{
	int opcao=0; //definindo vari�veis
	int laco=1; //definindo repeti��es
	
	for (laco=1;laco=1;)
	{
		
		system ("cls"); //sistema de limpar a tela
		
	
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
	    printf("Escolha a op��o desejada no menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
	    printf ("Op��o: "); //fim do menu
	
	    scanf ("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system ("cls");
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar nosso sistema!\n");
		    return 0; //quebra de la�o/repeti��o/fun��o
		    break;
		    
		    default: 
		    printf ("Esta op��o n�o est� dispon�vel\n");
		    system ("pause");
		    	
} //fim da sele��o
	

	
}
}
