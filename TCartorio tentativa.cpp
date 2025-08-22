#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//criando variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	 //responsável por copiar os valores das string
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	 // Abre o arquivo para adicionar (modo "a" = append)
    FILE *file = fopen("usuarios.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
	
	system("pause");
	
		
	
}

void consulta() {
    setlocale(LC_ALL, "Portuguese");

    char nomeBusca[40], linha[200], nomeArmazenado[80];
    int encontrado = 0;

    printf("Digite o nome a ser consultado: ");
    scanf("%s", nomeBusca);

    FILE *file = fopen("usuarios.txt", "r"); // Abre o arquivo para leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários!\n");
        return;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) { // Lê cada linha do arquivo
        char cpf[40], nome[40], sobrenome[40], cargo[40];

        // Quebra a linha lida em partes (CPF, Nome, Sobrenome, Cargo)
        sscanf(linha, "%[^,], %[^ ] %[^,], %[^\n]", cpf, nome, sobrenome, cargo);

        // Junta Nome + Sobrenome para comparar com o nome digitado
        snprintf(nomeArmazenado, sizeof(nomeArmazenado), "%s %s", nome, sobrenome);

        // Verifica se o nome armazenado corresponde à busca
        if (strcmp(nomeArmazenado, nomeBusca) == 0) {
            printf("\nUsuário encontrado:\n");
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nomeArmazenado);
            printf("Cargo: %s\n\n", cargo);
            encontrado = 1;
        }
    }

    fclose(file);

    if (!encontrado) {
        printf("\nUsuário não encontrado.\n");
    }

    system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else (file);
	{
		printf("Usuário deletado.\n");
		system("pause");
	}
	
}



int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	
	    system("cls");
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Opção: "); //fim do menu
	
	
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
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
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;
        
        default:
        printf("Essa opção não está disponível\n");
	    system("pause");
	    break;
	}
	
	
    } //fim da seleção
    


    }
