#include<stdio.h>
#include<ctype.h>
#include<conio2.h>
#include<windows.h>

#define TFC 100
#define TFM 100
#define TFP 100
#define TFCP 500


// DIEGO ALEXANDRE SOUZA GODOY

// A exclusao fisica acontece todas as vezes que a logica e executada.

// -----------  BUSCAS  -----------
// Busca Exaustiva - busca_int()
// Busca Sequencial Indexada - busca_pizza2()
// Busca Binária - busca_pedido2()

// ----------- ORDENACAO -----------
// Inserção Direta - cadastrar_pizza()
// Seleção Direta - Ranking()
// Bubblesort (Ordenação por Bolhas) - ordenar_pedido()


/*###################### STRUCTS ######################*/

struct Ranking
{
	int quantidade, pizza;
};

struct Cliente
{
	int telefone;
	char nome[30];
	char endereco[50];
	char cidade[20];
	char CEP[9];
	char ativo;
};

struct Motoqueiros
{
	char CPF[12];
	char nome[30];
	char endereco[50];
	int telefone;
	int dataAd;
	char ativo;
};

struct Pizzas
{
	int codigo;
	char descricao[50];
	float valor;
	char ativo;
	
};

struct pedidos
{
	int numPedido;
	int telefone;
	int codigo;
	char CPF[12];
	int situacao;
	int data;
	char ativo;
};


/*###################### MOLDURAS ######################*/
char loading(int ci,int li,int cf,int lf,int cor)
{
	int i=0;
	gotoxy(ci,li);
	printf("%c", 201);
	gotoxy(cf,li);
	printf("%c", 187);
	gotoxy(ci,lf);
	printf("%c", 200);
	gotoxy(cf,lf);
	printf("%c", 188);
	
	for(i=ci+1; i<cf; i++)
	{
		gotoxy(i,li);
		printf("%c", 205);
		gotoxy(i,lf);
		printf("%c", 205);
	}
	for(i=li+1; i<lf; i++)
	{
		gotoxy(ci,i);
		printf("%c", 186);
		gotoxy(cf,i);
		printf("%c", 186);
		
	}
	
	for(i=ci+1; i<cf-1;i++)
	{
		gotoxy(i,16);
		printf("%c", 219);
		Sleep(0.1);
	}
	system("cls");

}

char moldura_toda(int ci,int li,int cf,int lf,int cor)
{
	int i=0;
	gotoxy(ci,li);
	printf("%c", 201);
	gotoxy(cf,li);
	printf("%c", 187);
	gotoxy(ci,lf);
	printf("%c", 200);
	gotoxy(cf,lf);
	printf("%c", 188);
	
	for(i=ci+1; i<cf; i++)
	{
		gotoxy(i,li);
		printf("%c", 205);
		gotoxy(i,lf);
		printf("%c", 205);
	}
	for(i=li+1; i<lf; i++)
	{
		gotoxy(ci,i);
		printf("%c", 186);
		gotoxy(cf,i);
		printf("%c", 186);
		
	}
	gotoxy(52,15);
	printf("***BEM VINDOS***");
	getch();
	gotoxy(52,15);
	printf("                 ");
}

char moldura_nome(int ci,int li,int cf,int lf,int cor)
{
	int i=0;
	gotoxy(ci,li);
	printf("%c", 201);
	gotoxy(cf,li);
	printf("%c", 187);
	gotoxy(ci,lf);
	printf("%c", 200);
	gotoxy(cf,lf);
	printf("%c", 188);
	
	for(i=ci+1; i<cf; i++)
	{
		gotoxy(i,li);
		printf("%c", 205);
		gotoxy(i,lf);
		printf("%c", 205);
	}
	for(i=li+1; i<lf; i++)
	{
		gotoxy(ci,i);
		printf("%c", 186);
		gotoxy(cf,i);
		printf("%c", 186);
		
	}
	
	gotoxy(52,3);
	printf("=== PIZZARIA ===");
}

char moldura_menu(int ci,int li,int cf,int lf,int cor)
{
	int i=0;
	gotoxy(ci,li);
	printf("%c", 201);
	gotoxy(cf,li);
	printf("%c", 187);
	gotoxy(ci,lf);
	printf("%c", 200);
	gotoxy(cf,lf);
	printf("%c", 188);
	
	for(i=ci+1; i<cf; i++)
	{
		gotoxy(i,li);
		printf("%c", 205);
		gotoxy(i,lf);
		printf("%c", 205);
	}
	for(i=li+1; i<lf; i++)
	{
		gotoxy(ci,i);
		printf("%c", 186);
		gotoxy(cf,i);
		printf("%c", 186);
		
	}
}

/*###################### FUNÇÕES ######################*/

char menu()
{
	char op;
	
	gotoxy(23,5);										                                             
	printf("***  MENU  ***");							
	gotoxy(3,7);									
	printf("[A] Cadastrar Clientes");				
	gotoxy(3,8);								
	printf("[B] Consultar Clientes");	
	gotoxy(3,9);									
	printf("[C] Excluir Clientes");					
	gotoxy(3,10);
	printf("[D] Relatorio Cliente");
	gotoxy(3,11);
	printf("[E] Alterar Cliente");
	
	gotoxy(3,13);
	printf("[F] Relatorio Pizza");
	gotoxy(3,14);
	printf("[G] Cadastrar Pizza");
	gotoxy(3,15);
	printf("[H] Consultar Pizza");
	gotoxy(3,16);
	printf("[I] Excluir Pizza");
	gotoxy(3,17);
	printf("[J] Alterar Pizza");
	
	gotoxy(3,19);
	printf("[K] Relatorio Motoqueiro");
	gotoxy(3,20);
	printf("[L] Excluir Motoqueiro");
	gotoxy(3,21);
	printf("[M] Cadastrar Motoqueiro");
	gotoxy(3,22);
	printf("[N] Consultar Motoqueiro");
	
	gotoxy(24,24);
	printf("[ESC] Sair");
	gotoxy(11,26);
	printf("     ");
	gotoxy(4,26);
	printf("OPCAO: ");
	
	gotoxy(30,7);
	printf("[O] Alterar Motoqueiro");
	
	gotoxy(30,9);
	printf("[P] Relatorio Pedidos");
	gotoxy(30,10);
	printf("[Q] Cadastrar Pedido");
	gotoxy(30,11);
	printf("[R] Consultar Pedido");
	gotoxy(30,12);
	printf("[S] Excluir Pedido");
	gotoxy(30,13);
	printf("[T] Alterar Pedido");
	
	gotoxy(30,15);
	printf("[U] Pesquisar Letra");
	gotoxy(30,16);
	printf("[V] Pesquisar Nome");
	gotoxy(30,17);
	printf("[W] Pizza Andamento");
	gotoxy(30,18);
	printf("[X] Pizza a Caminho");
	gotoxy(30,19);
	printf("[Z] Ranking pizzas");
	gotoxy(30,20);
	printf("[1] Re. pizza/cliente");
	gotoxy(30,21);
	printf("[2] Re. motoqueiro/cliente");
	
	
	gotoxy(12,26);
	return op=toupper(getche());
}

void apagador()
{
	int i, j=27;
	for(i=6;i<=j;i++)
	{
		gotoxy(59,i);
		printf("                                                          ");
	}
	
}

int valida_cpf (char cpf[])
{  
	int icpf[12];  
	int i=0, somador=0, digito1, result1, result2, digito2, valor;  
	   
	for(i=0;i<11;i++)  
	{  
		icpf[i]=cpf[i]-48;  
	}    
	  
	for(i=0;i<9;i++)  
	{  
		somador+=icpf[i]*(10-i);  
	}  
	  
	result1=somador%11;  
	  
	if( (result1==0) || (result1==1) )  
	{  
		digito1=0;  
	}  
	  
	else  
	{  
		digito1 = 11-result1;  
	}  
	  
	somador=0;  
	  
	for(i=0;i<10;i++)  
	{  
		somador+=icpf[i]*(11-i);  
	}  
	  
	valor=(somador/11)*11;  
	result2=somador-valor;  
	  
	if( (result2==0) || (result2==1) )  
	{  
		digito2=0;  
	}  
	  
	else  
	{  
		digito2=11-result2;  
	}  
	  
	if((digito1==icpf[9]) && (digito2==icpf[10]))  
		return 0;  /*Válio*/
	else  
		return -1; /*Errado*/
}  

/*###################### FUNÇÕES CLIENTE ######################*/

int busca_int(FILE *PtrArq, int telefone)
{
	Cliente cliente;
	
	rewind(PtrArq);
	fread(&cliente, sizeof(Cliente), 1, PtrArq);
	
	while(!feof(PtrArq)&& telefone != cliente.telefone)
		fread(&cliente, sizeof(Cliente), 1, PtrArq);
	if(!feof(PtrArq))
		return ftell(PtrArq)-sizeof(Cliente); /*achou*/
	else
		return -1; /* não achou */
}

void consulta_cliente(void)
{
	int aux=0,i;
	Cliente cliente;
	FILE *PtrCliente = fopen("cliente.dat","ab+");
	
	gotoxy(59,6);
	printf("Digite o telefone para consulta: ");
	scanf("%d", &aux);
	apagador();
	
	i = busca_int(PtrCliente, aux);

	if(i != -1)
	{
		fseek(PtrCliente, i, 0);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		if(cliente.ativo=='A')
		{
			gotoxy(59,6);
			printf("*** cliente Nome: %s ***", cliente.nome);
			gotoxy(59,7);
			printf("Telefone: %d", cliente.telefone);
			gotoxy(59,8);
			printf("Endereco: %s", cliente.endereco);
			gotoxy(59,9);
			printf("Cidade: %s", cliente.cidade);
			gotoxy(59,10);
			printf("CEP: %s", cliente.CEP);
			getch();
			apagador();
		}
		else
		{
			gotoxy(59,7);
			printf("Esse numero nao foi encontrado");
			getch();
			apagador();
		}
		
	}
	else
	{
		gotoxy(59,7);
		printf("Esse numero nao foi encontrado");
		getch();
		apagador();
	}
	
	fclose(PtrCliente);
}

void cadastrar_cliente(void)
{	
	int aux, i;

	Cliente cliente;
	FILE *PtrCliente = fopen("cliente.dat","ab+");
	
	gotoxy(59,6);
	printf("Digite o um telefone para contato: ");
	scanf("%d", &aux);
	
	i = busca_int(PtrCliente, aux);
	
	if(i == -1)
	{
		cliente.telefone=aux;
		gotoxy(59,7);
		printf("Digite o primeiro Nome do Cliente: ");
		fflush(stdin);
		gets(cliente.nome);
		gotoxy(59,8);
		printf("Digite seu endereco: ");
		fflush(stdin);
		gets(cliente.endereco);
		gotoxy(59,9);
		printf("Digite sua cidade:  ");
		fflush(stdin);
		gets(cliente.cidade);
		gotoxy(59,10);
		printf("Digite seu CEP: ");
		fflush(stdin);
		gets(cliente.CEP);
		apagador();
		cliente.ativo = 'A';
		
		fwrite(&cliente,sizeof(Cliente), 1, PtrCliente);
		
		gotoxy(59,6);
		printf("Cadastrado!!!");
		getch();
		apagador();
	
	}
	else
	{
		gotoxy(59,7);
		printf("Telefone ja cadastrado, cadastre novamente");
		getch();
		apagador();
	}
	
	fclose(PtrCliente);
}

void apagar_cliente(void) // COM EXCLUSÃO FISICA
{
	int i, aux;
	char op;
	Cliente cliente;
	
	FILE *PtrCliente = fopen("cliente.dat","rb+");
	
	gotoxy(59,6);
	printf("Digite o telefone para apagar: ");
	fflush(stdin);
	scanf("%d", &aux);
	apagador();
	
	i= busca_int(PtrCliente, aux);
	
	if(i == -1)
	{
		apagador();
		gotoxy(59,6);
		printf("Esse Cliente nao foi encontrado");
		getch();
		apagador();
	}
	else
	{	
		fseek(PtrCliente, i, 0);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		gotoxy(59,6);
		printf("*** Cliente Nome: %s ***", cliente.nome);
		gotoxy(59,7);
		printf("Telefone: %d", cliente.telefone);
		gotoxy(59,8);
		printf("Endereco: %s", cliente.endereco);
		gotoxy(59,9);
		printf("Cidade: %s", cliente.cidade);
		gotoxy(59,10);
		printf("CEP: %s", cliente.CEP);       
		  
		gotoxy(59,11);
		printf("Tem certeza que deseja EXCLUIR? | Sim - s | Nao - n:  ");  
		op = toupper(getche());
		if(op == 'S')
		{
			if(cliente.ativo=='A')
			{
				cliente.ativo='I';
				fseek(PtrCliente, i, 0);
				fwrite(&cliente, sizeof(Cliente), 1, PtrCliente);
				apagador();
				gotoxy(59,6);
				printf("Cliente apagado!!");
				getch();
				apagador();
			}	
			else
			{
				apagador();
				gotoxy(59,6);
				printf("Cliente apagado anteriormente");
				getch();
				apagador();
			}
		}

		else
		{
			apagador();
			gotoxy(59,6);
			printf("Cancelado!!!"); 
			getch();
			apagador();
		}
	}

	rewind(PtrCliente);
	FILE *PtrTemp=fopen("Temp.dat","wb");
	
	fread(&cliente,sizeof(Cliente),1,PtrCliente);
	while (!feof(PtrCliente))
	{
		if (cliente.ativo=='A')
			fwrite(&cliente,sizeof(Cliente),1,PtrTemp);
		fread(&cliente,sizeof(Cliente),1,PtrCliente);
	}
	
	fclose(PtrCliente);
	fclose(PtrTemp);
	remove("cliente.dat");
	rename("Temp.dat","cliente.dat");

}

void alterar_cliente(void)
{
	Cliente cliente;
	int i, aux;
	char aux_char[30];
	
	FILE *PtrCliente = fopen("cliente.dat","rb+");
	
	gotoxy(59,6);
	printf("Digite o telefone: ");
	fflush(stdin);
	scanf("%d", &aux);
	apagador();
	
	i= busca_int(PtrCliente, aux);
	
	if (i == -1)
	{
		gotoxy(59,7);
		printf("Esse numero nao foi encontrado");
		getch();
		apagador();
	}
	else
	{

		fseek(PtrCliente,i,0);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		gotoxy(59,6);
		printf("Cliente numero: %d", cliente.telefone);
		gotoxy(59,7);
		printf("Digite o novo nome: ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
			strcpy(cliente.nome, aux_char);
	
		gotoxy(59,8);
		printf("Novo Endereco: ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
			strcpy(cliente.endereco, aux_char);
			
		gotoxy(59,9);
		printf("Nova cidade:  ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
			strcpy(cliente.cidade, aux_char);

		gotoxy(59,10);
		printf("Novo CEP: ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
			strcpy(cliente.CEP, aux_char);
			
		apagador();
		
		fseek(PtrCliente, i,0);
		fwrite(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		gotoxy(59,6);
		printf("Alterado!!!");
		getch();
		apagador();
		
	}
	fclose(PtrCliente);
}

void relatorio_cliente(void)
{
	int i, linha;
	Cliente cliente;
	
	FILE *PtrCliente = fopen("cliente.dat","rb");
	
	gotoxy(59,7);
	printf("*** Relatorio de CLIENTES ***");
	
	if(PtrCliente == NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha CLIENTES cadastrados ***");
	}
	else
	{
		apagador();
		gotoxy(70,6);
		printf("*** Relatorio de CLIENTES ***");
		gotoxy(59,8);
		printf("Telefone");
		gotoxy(73,8);
		printf("Nome");
		gotoxy(83,8);
		printf("Cidade");
		gotoxy(93,8);
		printf("Endereco");
		gotoxy(105,8);
		printf("CEP");
		
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		for(linha=10; !feof(PtrCliente); linha++)
		{
			if(cliente.ativo=='A')
			{
				gotoxy(59,linha);
				printf("%d", cliente.telefone);
				gotoxy(73,linha);
				printf("%s", cliente.nome);
				gotoxy(83,linha);
				printf("%s", cliente.cidade);
				gotoxy(93,linha);
				printf("%s", cliente.endereco);
				gotoxy(105,linha);
				printf("%s", cliente.CEP);		
			}
			fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrCliente);
}

/*###################### FUNÇÕES MOTOQUEIROS ######################*/

int busca_moto2(FILE *PtrArq, char cpf[])
{
	Motoqueiros motoqueiro;
	
	rewind(PtrArq);
	fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrArq);
	
	while(!feof(PtrArq) && stricmp(motoqueiro.CPF, cpf) != 0)
		fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrArq);
	if(!feof(PtrArq))
		return ftell(PtrArq) - sizeof(Motoqueiros);
	else
		return -1;
}

void consulta_moto(void)
{
	int i,j;
	char aux[12];
	Motoqueiros motoqueiro;
	
	FILE *PtrArq = fopen("motoqueiro.dat","ab+");
	
	gotoxy(59,6);
	printf("Digite o CPF para consulta: ");
	fflush(stdin);
	gets(aux);
	apagador();
	
	j = valida_cpf(aux);
	if (j == 0)
	{
		i= busca_moto2(PtrArq, aux);
		gotoxy(59,6);
		if(i != -1)
		{
			fseek(PtrArq,i,0);
			fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrArq);
			
			if(motoqueiro.ativo == 'A')
			{
				gotoxy(59,6);
				printf("*** Motoqueiro CPF: %s ***", motoqueiro.CPF);
				gotoxy(59,8);
				printf("Data de Admissao: %d", motoqueiro.dataAd);
				gotoxy(59,9);
				printf("Endereco: %s", motoqueiro.endereco);
				gotoxy(59,10);
				printf("Nome: %s", motoqueiro.nome);
				gotoxy(59,11);
				printf("Telefone: %d", motoqueiro.telefone);
				getch();
				apagador();
			}
			else
			{
				gotoxy(59,7);
				printf("Esse CPF nao foi encontrado");
				getch();
				apagador();
			}
		}
		else
		{
			gotoxy(59,7);
			printf("Esse CPF nao foi encontrado");
			getch();
			apagador();
		}
	}
	else
	{
		gotoxy(59,8);
		printf("Esse CPF nao e valido!");
		gotoxy(59,9);
		printf("Por favor digite um CPF VALIDO");
		getch();
		apagador();
	}
	fclose(PtrArq);
}

void cadastrar_moto(void)
{
	int i,j;
	char aux[12];
	Motoqueiros motoqueiro;
	
	FILE * PtrMotoqueiro = fopen("motoqueiro.dat","ab+");
	
	gotoxy(59,6);
	printf("Digite o um CPF para cadastro: ");
	fflush(stdin);
	gets(aux);
	
	j = valida_cpf(aux);
	
	if (j == 0)
	{
		i = busca_moto2(PtrMotoqueiro, aux);
		
		if(i == -1)
		{
			strcpy(motoqueiro.CPF, aux);
			gotoxy(59,7);
			printf("Digite o nome: ");
			fflush(stdin);
			gets(motoqueiro.nome);
			gotoxy(59,8);
			printf("Digite seu endereco: ");
			fflush(stdin);
			gets(motoqueiro.endereco);
			gotoxy(59,9);
			printf("Digite seu telefone:  ");
			fflush(stdin);
			scanf("%d", &motoqueiro.telefone);
			gotoxy(59,10);
			printf("Digite a data de admissao: ");
			fflush(stdin);
			scanf("%d", &motoqueiro.dataAd);
			apagador();
			gotoxy(59,6);
			motoqueiro.ativo = 'A';
			
			fwrite(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
			
			
			printf("Cadastrado!!!");
			getch();
			apagador();
		}
		else
		{
			gotoxy(59,7);
			printf("CPF ja cadastrado, cadastre novamente!");
			getch();
			apagador();
		}
	}
	else
	{
		gotoxy(59,8);
		printf("Esse CPF nao e valido!");
		gotoxy(59,9);
		printf("Por favor digite um CPF VALIDO");
		getch();
		apagador();
	}
	fclose(PtrMotoqueiro);
}

void apagar_moto(void) // COM EXCLUSAO FISICA
{
	int i;
	char op, cpf[12];
	Motoqueiros motoqueiro;
	
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat","rb+");
	
	gotoxy(59,6);
	printf("Digite o CPF para apagar: ");
	fflush(stdin);
	gets(cpf);
	apagador();
	
	i= busca_moto2(PtrMotoqueiro, cpf);
	if(i == -1)
	{
		apagador();
		gotoxy(70,6);
		printf("Esse CPF nao foi encontrado");
		getch();
		apagador();
	}
	else
	{			
		fseek(PtrMotoqueiro,i,0);
		fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
	
		gotoxy(59,6);
		printf("*** cliente CPF: %s ***", motoqueiro.CPF);
		gotoxy(59,8);
		printf("Data de Admissao: %d", motoqueiro.dataAd);
		gotoxy(59,9);
		printf("Endereco: %s", motoqueiro.endereco);
		gotoxy(59,10);
		printf("Nome: %s", motoqueiro.nome);
		gotoxy(59,11);
		printf("Telefone: %d", motoqueiro.telefone);      
		  
		gotoxy(59,11);
		printf("Tem certeza que deseja EXCLUIR? | Sim - s | Nao - n:  ");  
		op = toupper(getche());
		if(op == 'S')
		{
			if(motoqueiro.ativo ==	'A')
			{
				motoqueiro.ativo = 'I';
				fseek(PtrMotoqueiro,i,0);
				fwrite(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
				apagador();
				gotoxy(59,6);
				printf("Motoqueiro apagado!!");
				getch();
				apagador();
			}
			else
			{
				apagador();
				gotoxy(59,6);
				printf("Cliente apagado anteriormente");
				getch();
				apagador();		
			}

		}

		else
		{
			apagador();
			gotoxy(59,6);
			printf("Cancelado!!!"); 
			getch();
			apagador();
		}
	}
	
	
	rewind(PtrMotoqueiro);
	FILE *PtrTemp=fopen("Temp.dat","wb");
	
	fread(&motoqueiro,sizeof(Motoqueiros),1,PtrMotoqueiro);
	while (!feof(PtrMotoqueiro))
	{
		if (motoqueiro.ativo=='A')
			fwrite(&motoqueiro,sizeof(Motoqueiros),1,PtrTemp);
		fread(&motoqueiro,sizeof(Motoqueiros),1,PtrMotoqueiro);
	}
	
	fclose(PtrMotoqueiro);
	fclose(PtrTemp);
	remove("motoqueiro.dat");
	rename("Temp.dat","motoqueiro.dat");
	
}

void alterar_moto(void)
{
	int i,j, aux_int;
	char aux[12];
	Motoqueiros motoqueiro;
		
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat","rb+");
		
	gotoxy(59,6);
	printf("Digite o CPF: ");
	fflush(stdin);
	gets(aux);
	apagador();
	
	j = valida_cpf(aux);
	if (j == 0)
	{
		i= busca_moto2(PtrMotoqueiro, aux);
		gotoxy(59,6);
		if(i != -1)
		{
			fseek(PtrMotoqueiro, i, 0);
			fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
			
			if(motoqueiro.ativo == 'A')
				{
				gotoxy(59,6);
				printf("Motoqueiro CPF: %s", motoqueiro.CPF);
				gotoxy(59,7);
				printf("Digite o novo nome: ");
				fflush(stdin);
				gets(aux);
				if (aux[1] != '\0')
					strcpy(motoqueiro.nome, aux);
			
				gotoxy(59,8);
				printf("Novo Endereco: ");
				fflush(stdin);
				gets(aux);
				if (aux[1] != '\0')
					strcpy(motoqueiro.endereco, aux);
				
				aux_int =0;	
				gotoxy(59,9);
				printf("Novo Telefone:  ");
				fflush(stdin);
				scanf("%d", &aux_int);
				if (aux_int > 1)
					motoqueiro.telefone = aux_int;
				
				aux_int =0;		
				gotoxy(59,9);
				printf("Nova Data de Admissao:  ");
				fflush(stdin);
				scanf("%d", &aux_int);
				if (aux_int > 0)
					motoqueiro.dataAd = aux_int;
		
				apagador();
				
				fseek(PtrMotoqueiro, i, 0);
				fwrite(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);	
				
				gotoxy(59,6);
				printf("Alterado!!!");
				getch();
				apagador();
			}
			else
			{
				gotoxy(59,7);
				printf("Esse CPF nao foi encontrado");
				getch();
				apagador();
			}
		}
		else
		{
			gotoxy(59,7);
			printf("Esse CPF nao foi encontrado");
			getch();
			apagador();
		}
	}
	else
	{
		gotoxy(59,8);
		printf("Esse CPF nao e valido!");
		gotoxy(59,9);
		printf("Por favor digite um CPF VALIDO");
		getch();
		apagador();
	}
	fclose(PtrMotoqueiro);
}

void relatorio_moto(void)
{
	int i, linha;
	Motoqueiros motoqueiro;
	
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat","rb");
	
	gotoxy(59,7);
	printf("*** Relatorio de MOTOQUEIROS ***");
	if(PtrMotoqueiro == NULL)
	{
		apagador();
		gotoxy(65,8);
		printf("*** Nao ha MOTOQUEIROS cadastrados ***");
	}
	else
	{
		apagador();
		gotoxy(65,6);
		printf("*** Relatorio de MOTOQUEIROS ***");
		gotoxy(59,8);
		printf("Telefone");
		gotoxy(73,8);
		printf("Nome");
		gotoxy(83,8);
		printf("Data Ad");
		gotoxy(93,8);
		printf("Endereco");
		gotoxy(105,8);
		printf("CPF");
		
		fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
		
		for(linha=10; !feof(PtrMotoqueiro); linha++)
		{
			if(motoqueiro.ativo=='A')
			{
				gotoxy(59,linha);
				printf("%d", motoqueiro.telefone);
				gotoxy(73,linha);
				printf("%s", motoqueiro.nome);
				gotoxy(83,linha);
				printf("%d", motoqueiro.dataAd);
				gotoxy(93,linha);
				printf("%s", motoqueiro.endereco);
				gotoxy(105,linha);
				printf("%s", motoqueiro.CPF);
			}
			fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiro);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrMotoqueiro);
}

/*###################### FUNÇÕES PIZZAS ######################*/

void ordernar_pizza(FILE *PtrPizza) 
{
	Pizzas ant, atual;
	int pos;
	
	fseek(PtrPizza, 0, 2);
	pos = ftell(PtrPizza)/sizeof(Pizzas)-1;
	
	fseek(PtrPizza, (pos-1)*sizeof(Pizzas), 0);
	fread(&ant, sizeof(Pizzas), 1, PtrPizza);
	fread(&atual, sizeof(Pizzas), 1, PtrPizza);	
	while(pos>0 && ant.codigo > atual.codigo)
	{
		fseek(PtrPizza, (pos-1)*sizeof(Pizzas), 0);
		fwrite(&atual, sizeof(Pizzas), 1, PtrPizza);
		fwrite(&ant, sizeof(Pizzas), 1, PtrPizza);
		
		pos--;
		fseek(PtrPizza, (pos-1)*sizeof(Pizzas), 0);
		fread(&ant, sizeof(Pizzas), 1, PtrPizza);
		fread(&atual, sizeof(Pizzas), 1, PtrPizza);		
	}
}

int busca_pizza2(FILE *PtrPizza, int cod) // Busca Sequencial Indexada
{
	Pizzas pizza;
	int i=0, pos;
	
	fseek(PtrPizza ,0 ,2);
	pos = ftell(PtrPizza)/sizeof(Pizzas)-1;
	
	fseek(PtrPizza, 0, 0);
	fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
	i++;
		
	while(i<=pos && cod > pizza.codigo)
	{
		fseek(PtrPizza, i*sizeof(Pizzas), 0);
		fread(&pizza, sizeof(Pizzas), 1, PtrPizza);	
		i++;	
	}	
	if(cod == pizza.codigo)
	{
		return ftell(PtrPizza)-sizeof(Pizzas);
	}
	else return -1;
				
}

void consulta_pizza(void)
{
	int aux, i;
	Pizzas pizza;
	
	FILE *PtrPizza = fopen("pizza.dat","ab+");
	
	gotoxy(59,6);
	fflush(stdin);
	printf("Digite o codigo para consulta: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pizza2(PtrPizza, aux);
	
	if(i != -1)
	{
		fseek(PtrPizza, i, 0);
		fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
		
		if(pizza.ativo=='A')
		{
			gotoxy(59,6);
			printf("*** Codigo Pizza: %d ***", pizza.codigo);
			gotoxy(59,7);
			printf("Valor: %f", pizza.valor);
			gotoxy(59,8);
			printf("Descricao: %s", pizza.descricao);
			getch();
			apagador();	
		}
		else
		{
			gotoxy(59,7);
			printf("Codigo de pizza nao encontrado");
			getch();
			apagador();
		}
	}
	else
	{
		gotoxy(59,7);
		printf("Codigo de pizza nao encontrado");
		getch();
		apagador();
	} 
	fclose(PtrPizza);
}

void cadastrar_pizza(void) // Inserção Direta chama ordernar_pizza()
{
	int i, aux=0;
	Pizzas pizza;
	
	FILE *PtrPizza = fopen("pizza.dat", "rb+");
	
	fflush(stdin);
	gotoxy(59,6);  
	printf("Digite um Codigo para a pizza: ");
	scanf("%d", &aux);
	
	i = busca_pizza2(PtrPizza, aux);
	if(i == -1)
	{
		pizza.codigo=aux;
		gotoxy(59,7);
		printf("Descricao da Pizza: ");
		fflush(stdin);
		gets(pizza.descricao);
		gotoxy(59,8);
		printf("Digite o valor: ");
		fflush(stdin);
		scanf("%f", &pizza.valor);
		apagador();
		gotoxy(59,6);
		pizza.ativo = 'A';
		
		fseek(PtrPizza, 0, 2);
		fwrite(&pizza, sizeof(Pizzas), 1, PtrPizza);
		
		ordernar_pizza(PtrPizza);
		
		printf("Cadastrado!!!");
		getch();
		apagador();
	}
	else
	{
		gotoxy(59,7);
		printf("Pizza ja cadastrada, cadastre novamente");
		getch();
		apagador();
	}
	fclose(PtrPizza);
}

void apagar_pizza(void) // COM EXCLUSAO FISICA
{
	int i=0, aux=0, j=0, x=0;
	char op, cpf[12];
	Pizzas pizza;
	
	FILE *PtrPizza = fopen("pizza.dat","rb+");
	
	gotoxy(59,6);
	printf("Digite o CODIGO para apagar: ");
	fflush(stdin);
	scanf("%d", &aux);
	apagador();
	
	i= busca_pizza2(PtrPizza,aux);
	
	if(i == -1)
	{
		apagador();
		gotoxy(70,6);
		printf("Esse CODIGO nao foi encontrado");
		getch();
		apagador();
	}
	else
	{	
		fseek(PtrPizza, i, 0);
		fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
		gotoxy(59,6);
		printf("*** Codigo Pizza: %d ***", pizza.codigo);
		gotoxy(59,7);
		printf("Valor: %.2f", pizza.valor);
		gotoxy(59,8);
		printf("Descricao: %s", pizza.descricao); 	
		
		gotoxy(59,10);
		printf("Tem certeza que deseja EXCLUIR? | Sim - s | Nao - n:  ");  
		op = toupper(getche());
		if(op == 'S')
		{
			fseek(PtrPizza, i, 0);
			fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
			
			if(pizza.ativo=='A')
			{
				pizza.ativo = 'I';
				fseek(PtrPizza, i, 0);
				fwrite(&pizza, sizeof(Pizzas), 1, PtrPizza);
				apagador();
				gotoxy(59,6);
				printf("Pizza apagada!!");
				getch();
				apagador();
			}
			else
			{		
				apagador();
				gotoxy(59,6);
				printf("Pizza apagada anteriormente");
				getch();
				apagador();	
			}
		}
		else
		{
			apagador();
			gotoxy(59,6);
			printf("Cancelado!!!"); 
			getch();
			apagador();
		}
	}
	
	
	rewind(PtrPizza);
	FILE *PtrTemp=fopen("Temp.dat","wb");
	
	fread(&pizza,sizeof(Pizzas),1,PtrPizza);
	while (!feof(PtrPizza))
	{
		if (pizza.ativo=='A')
			fwrite(&pizza,sizeof(Pizzas),1,PtrTemp);
		fread(&pizza,sizeof(Pizzas),1,PtrPizza);
	}
	
	fclose(PtrPizza);
	fclose(PtrTemp);
	remove("pizza.dat");
	rename("Temp.dat","pizza.dat");
	
}

void alterar_pizza(void)
{
	int aux, i, aux_int;
	char aux_char[50];
	Pizzas pizza;
	
	FILE *PtrPizza = fopen("pizza.dat","rb+");
	
	gotoxy(59,6);
	fflush(stdin);
	printf("Digite o codigo da Pizza: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pizza2(PtrPizza, aux);
	if(i != -1)
	{
		fseek(PtrPizza, i, 0);
		fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
		
		gotoxy(59,6);
		printf("*** Codigo Pizza: %d ***", pizza.codigo);
		gotoxy(59,7);
		printf("Digite novo Valor: ");
		fflush(stdin);
		scanf("%d", &aux_int);
		if (aux_int > 0)
			pizza.valor = aux_int;
			
		gotoxy(59,8);
		printf("Nova Descricao: ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
			strcpy(pizza.descricao, aux_char);
		
		fseek(PtrPizza, i, 0);
		fwrite(&pizza, sizeof(Pizzas), 1, PtrPizza);
		
		getch();
		apagador();
	}
	else
	{
		gotoxy(59,7);
		printf("Codigo de pizza nao encontrado");
		getch();
		apagador();
	} 
	fclose(PtrPizza);
}

void relatorio_pizza(void)
{
	int i, linha;
	Pizzas pizza;

	FILE *PtrPizza = fopen("pizza.dat","rb");

	gotoxy(59,7);
	printf("*** Relatorio de PIZZAS ***");
	if(PtrPizza == NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha PIZZAS cadastradas ***");
	}
	else
	{
		apagador();
		gotoxy(70,6);
		printf("*** Relatorio de PIZZAS ***");
		gotoxy(59,8);
		printf("Codigo");
		gotoxy(73,8);
		printf("Valor");
		gotoxy(83,8);
		printf("Descricao");

		fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
		for(linha=10; !feof(PtrPizza); linha++)
		{
			if(pizza.ativo=='A')
			{
				gotoxy(59,linha);
				printf("%d", pizza.codigo);
				gotoxy(73,linha);
				printf("%.2f", pizza.valor);
				gotoxy(83,linha);
				printf("%s", pizza.descricao);	
			}
			fread(&pizza, sizeof(Pizzas), 1, PtrPizza);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPizza);
}

/*###################### FUNÇÕES PEDIDOS ######################*/

void ordenar_pedido(FILE *PtrPedido) 
{
	pedidos pedido1, pedido2;
	int pos, i=0;
	
	fseek(PtrPedido, 0 ,2);
	pos = ftell(PtrPedido)/sizeof(pedidos)-1;						
				
	while(pos>0)
	{
		for(i=0; i<=pos; i++)
		{
			fseek(PtrPedido, i*sizeof(pedidos), 0);
			fread(&pedido1, sizeof(pedidos), 1, PtrPedido);	
			fread(&pedido2, sizeof(pedidos), 1, PtrPedido);	
			
			if(pedido1.numPedido > pedido2.numPedido)
			{
				fseek(PtrPedido, i*sizeof(pedidos), 0);
				fwrite(&pedido2, sizeof(pedidos), 1, PtrPedido);	
				fwrite(&pedido1, sizeof(pedidos), 1, PtrPedido);	
			}
		}
		pos--;	
	}
}
 
int busca_pedido2(FILE *PtrPedido, int cod) // BUSCA Binaria 
{
	pedidos pedido;
	int inicio=0, fim, meio, pos;
	
	fseek(PtrPedido, 0, 2);
	pos = ftell(PtrPedido)/sizeof(pedidos)-1;
	
	fim = pos-1;
	meio = fim/2;
		
	fseek(PtrPedido, meio*sizeof(pedidos), 0);
	fread(&pedido, sizeof(pedidos), 1, PtrPedido);
	
	while(inicio<fim && cod != pedido.numPedido)
	{
		if(pedido.numPedido<cod)
			inicio = meio+1;                          
		else
			fim = meio;
			
		meio = (inicio+fim)/2;
		
		fseek(PtrPedido, meio*sizeof(pedidos), 0);
		fread(&pedido, sizeof(pedidos), 1, PtrPedido);
	}
	
	
	if(cod == pedido.numPedido)
	{
		fseek(PtrPedido, meio*sizeof(pedidos), 0);
		return ftell(PtrPedido);
	}
	else
		return -1;
}

void consulta_pedido(void)
{
	int aux, i;
	pedidos pedido;
	
	FILE *PtrPedidos = fopen("pedidos.dat","ab+");
	
	gotoxy(59,6);
	fflush(stdin);
	printf("Digite o Numero do Pedido para consulta: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pedido2(PtrPedidos,aux);
	if(i != -1)
	{
		fseek(PtrPedidos, i, 0);
		fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
		
		if(pedido.ativo == 'A')
		{
			gotoxy(59,6);
			printf("*** Codigo do Pedido: %d ***", pedido.numPedido);
			gotoxy(59,7);
			printf("Telefone do cliente: %d", pedido.telefone);
			gotoxy(59,8);
			printf("Codigo da Pizza: %d", pedido.codigo);
			gotoxy(59,9);
			printf("CPF do Motoqueiro: %s", pedido.CPF);
			gotoxy(59,10);
			printf("Situacao do Pedido: %d", pedido.situacao);
			gotoxy(59,11);
			printf("Data do Pedido: %d", pedido.data);
			getch();
			apagador();
		}
		else
		{
			gotoxy(59,7);
			printf("Numero de Pedido nao encontrado");
			getch();
			apagador();	
		}
	}
	
	else
	{
		gotoxy(59,7);
		printf("Numero de Pedido nao encontrado");
		getch();
		apagador();
	} 
	fclose(PtrPedidos);
}

int cadastra_pedido(void) // Bubblesort (Ordenação por Bolhas) chama ordenar_pedido()
{
	int aux, i, aux_int, cpf;
	char aux_cpf[12];
	pedidos pedido;
	
	FILE *PtrCliente = fopen("cliente.dat","ab+");
	FILE *PtrPedidos = fopen("pedidos.dat","rb+");
	FILE *PtrPizza = fopen("pizza.dat","ab+");
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat", "ab+");
	
	gotoxy(59,6);
	fflush(stdin);
	printf("Digite o Numero do Pedido para Cadatro: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pedido2(PtrPedidos,aux);
	if(i == -1)
	{
		pedido.numPedido = aux;
		gotoxy(59,6);
		printf("Telefone do cliente: ");
		scanf("%d", &aux_int);
	
		while(busca_int(PtrCliente, aux_int) == -1)
		{
			gotoxy(80,6);
			printf("Cliente nao encontrado");
			Sleep(1000);
			gotoxy(80,6);
			printf("                         ");
			gotoxy(80,6);
			scanf("%d", &aux_int);
		}
		pedido.telefone = aux_int;
	
	
		gotoxy(59,7);
		printf("Codigo da Pizza: ");
		scanf("%d", &aux_int);
		
		while(busca_pizza2(PtrPizza, aux_int) == -1)
		{
			gotoxy(67,7);
			printf("Codigo nao encontrado");
			Sleep(1000);
			gotoxy(67,7);
			printf("                         ");
			gotoxy(67,7);
			scanf("%d", &aux_int);
		}
		pedido.codigo = aux_int;
		
		
		gotoxy(59,8);
		printf("CPF do Motoqueiro: ");
		fflush(stdin);
		gets(aux_cpf);
		
		while(busca_moto2(PtrMotoqueiro,aux_cpf) == -1)
		{
			gotoxy(78,8);
			printf("CPF nao encontrado");
			Sleep(1000);
			gotoxy(78,8);
			printf("                         ");
			gotoxy(78,8);
			fflush(stdin);
			gets(aux_cpf);
		}
		strcpy(pedido.CPF, aux_cpf);
	
	
		gotoxy(59,9);
		printf("Situacao do Pedido: ");
		scanf("%d", &aux_int);
		
		while(aux_int < 1 && aux_int > 3)
		{
			gotoxy(80,9);
			printf("Escolha numero entre 1 e 3");
			Sleep(1000);
			gotoxy(80,9);
			printf("                         ");
			gotoxy(80,9);
			scanf("%d", &aux_int);
		}
		pedido.situacao = aux_int;
		
		
		gotoxy(59,10);
		printf("Data do Pedido: ");
		scanf("%d", &pedido.data);
		
		pedido.ativo='A';
		
		fseek(PtrPedidos, 0 ,2);
		fwrite(&pedido, sizeof(pedidos), 1, PtrPedidos);
		
		ordenar_pedido(PtrPedidos);
		
		apagador();
		gotoxy(59,6);
		printf("Pedido Cadastrado!!!");
		getch();
		apagador();
		
	
	}
	
	else
	{
		gotoxy(59,7);
		printf("Numero de Pedido ja cadastrado");
		getch();
		apagador();
	} 
	fclose(PtrPedidos);
	fclose(PtrPizza);
	fclose(PtrCliente);
	fclose(PtrMotoqueiro);
}

int apaga_pedido(void) // COM EXCLUSAO FISICA
{
	int i=0, aux=0, j=0, x=0;
	char op, cpf[12];
	pedidos pedido;
	
	FILE *PtrPedidos = fopen("pedidos.dat","rb+");
	
	gotoxy(59,6);
	printf("Digite o CODIGO para apagar: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pedido2(PtrPedidos, aux);
	if(i == -1)
	{
		apagador();
		gotoxy(70,6);
		printf("Esse PEDIDO nao foi encontrado");
		getch();
		apagador();
	}
	else
	{	
		fseek(PtrPedidos, i, 0);
		fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
	
		gotoxy(59,6);
		printf("*** Numero Pedido: %d ***", pedido.numPedido);		
		gotoxy(59,7);
		printf("*** CPF (motoqueiro): %s ***", pedido.CPF);
		gotoxy(59,8);
		printf("Data: %d", pedido.data);
		gotoxy(59,9);
		printf("Codigo Pizza: %d", pedido.codigo);
		gotoxy(59,10);
		printf("Situacao: %d", pedido.situacao);
		gotoxy(59,11);
		printf("Telefone: %d", pedido.telefone);      
		  
		gotoxy(59,13);
		printf("Tem certeza que deseja EXCLUIR? | Sim - s | Nao - n:  ");  
		op = toupper(getche());
		if(op == 'S')
		{
			if(pedido.ativo == 'A')
			{
				pedido.ativo ='I';
				fseek(PtrPedidos, i, 0);
				fwrite(&pedido, sizeof(pedidos), 1, PtrPedidos);
				
				gotoxy(59,6);
				printf("Apagado!!!");
				getch();
				apagador();
					
			}
			else
			{
				apagador();
				gotoxy(59,6);
				printf("Pedido apagado anteriormente!!!"); 
				getch();
				apagador();
			}
		}
		else
		{
			apagador();
			gotoxy(59,6);
			printf("Cancelado!!!"); 
			getch();
			apagador();
		}
	}
	
	rewind(PtrPedidos);
	FILE *PtrTemp=fopen("Temp.dat","wb");
	
	fread(&pedido,sizeof(pedidos),1,PtrPedidos);
	while (!feof(PtrPedidos))
	{
		if (pedido.ativo=='A')
			fwrite(&pedido,sizeof(pedidos),1,PtrTemp);
		fread(&pedido,sizeof(pedidos),1,PtrPedidos);
	}
	
	fclose(PtrPedidos);
	fclose(PtrTemp);
	remove("pedidos.dat");
	rename("Temp.dat","pedidos.dat");

}

int alterar_pedido(void)
{
	int aux, i, aux_int;
	char aux_char[12];
	pedidos pedido;
	
	FILE *PtrPedidos = fopen("pedidos.dat","rb+");
	FILE *PtrCliente = fopen("cliente.dat","ab+");
	FILE *PtrPizza = fopen("pizza.dat","ab+");
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat", "ab+");
	
	gotoxy(59,6);
	fflush(stdin);
	printf("Digite o Numero do Pedido para Alteracao: ");
	scanf("%d", &aux);
	apagador();
	
	i= busca_pedido2(PtrPedidos ,aux);
	if(i != -1)
	{
		gotoxy(59,6);
		printf("Novo Telefone do cliente: ");
		scanf("%d", &aux_int);
		if (aux_int > 0)
		{
			while(busca_int(PtrCliente, aux_int) == -1)
			{
				gotoxy(80,6);
				printf("Cliente nao encontrado");
				Sleep(1000);
				gotoxy(80,6);
				printf("                         ");
				gotoxy(80,6);
				scanf("%d", &aux_int);
			}
			pedido.telefone = aux_int;
		}
	
		gotoxy(59,7);
		printf("Novo Codigo da Pizza: ");
		scanf("%d", &aux_int);
		if (aux_int > 0)
		{
			while(busca_pizza2(PtrPizza, aux_int) == -1)
			{
				gotoxy(67,7);
				printf("Codigo nao encontrado");
				Sleep(1000);
				gotoxy(67,7);
				printf("                         ");
				gotoxy(67,7);
				scanf("%d", &aux_int);
			}
			pedido.codigo = aux_int;
		}
		
		
		gotoxy(59,8);
		printf("Novo CPF do Motoqueiro: ");
		fflush(stdin);
		gets(aux_char);
		if (aux_char[1] != '\0')
		{
			while(busca_moto2(PtrMotoqueiro,aux_char) == -1)
			{
				gotoxy(78,8);
				printf("CPF nao encontrado");
				Sleep(1000);
				gotoxy(78,8);
				printf("                         ");
				gotoxy(78,8);
				fflush(stdin);
				gets(aux_char);
			}
			strcpy(pedido.CPF, aux_char);
		}
	
		gotoxy(59,9);
		printf("Nova Situacao do Pedido: ");
		scanf("%d", &aux_int);
		if (aux_int > 0)
		{
			while(aux_int < 1 && aux_int > 3)
			{
				gotoxy(80,9);
				printf("Escolha numero entre 1 e 3");
				Sleep(1000);
				gotoxy(80,9);
				printf("                         ");
				gotoxy(80,9);
				scanf("%d", &aux_int);
			}
			pedido.situacao = aux_int;
		}
		
		gotoxy(59,10);
		printf("Data do Pedido: ");
		scanf("%d", &aux_int);
		if (aux_int > 0)
		{
			pedido.data = aux_int;
		}
		
		apagador();
		gotoxy(59,6);
		printf("Pedido Alterado!!!");
		getch();
		apagador();
	}
	
	else
	{
		gotoxy(59,7);
		printf("Numero de Pedido nao encontrado");
		getch();
		apagador();
	} 
	fclose(PtrPedidos);
	fclose(PtrPizza);
	fclose(PtrCliente);
	fclose(PtrMotoqueiro);
}

void relatorio_pedido(void)
{
	int i, linha;
	pedidos pedido;

	FILE *PtrPedidos = fopen("pedidos.dat","ab+");

	gotoxy(59,7);
	printf("*** Relatorio de PEDIDOS ***");
	if(PtrPedidos==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha PEDIDOS cadastrados ***");
	}
	else
	{
	
		apagador();
		gotoxy(70,6);
		printf("*** Relatorio de PEDIDOS ***");
		gotoxy(59,8);
		printf("NUM");
		gotoxy(65,8);
		printf("Status");
		gotoxy(75,8);
		printf("Telefone");
		gotoxy(85,8);
		printf("Data");
		gotoxy(97,8);
		printf("CPF");
		gotoxy(109,8);
		printf("COD ");
		
		rewind(PtrPedidos);
		fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
		for(linha=10; !feof(PtrPedidos); linha++)
		{
	
			gotoxy(59,linha);
			printf("%d", pedido.numPedido);
			gotoxy(65,linha);
			printf("%d", pedido.situacao);
			gotoxy(75,linha);
			printf("%d", pedido.telefone);
			gotoxy(85,linha);
			printf("%d", pedido.data);
			gotoxy(97,linha);
			printf("%s", pedido.CPF);
			gotoxy(109,linha);
			printf("%d", pedido.codigo);	
			
			fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPedidos);
}

/*###################### B ######################*/

void relatorio_em_andamento(void)//FUNCIONA
{
	int linha;
	pedidos pedido;
	
	FILE *PtrPedido = fopen("pedidos.dat", "rb");

	gotoxy(59,7);
	printf("*** Relatorio de PEDIDOS ***");
	if(PtrPedido==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha PEDIDOS cadastrados ***");
	}
	else
	{
	
		apagador();
		gotoxy(60,6);
		printf("*** Relatorio de PEDIDOS em ANDAMENTO ***");
		gotoxy(59,8);
		printf("NUM");
		gotoxy(65,8);
		printf("Status");
		gotoxy(75,8);
		printf("Telefone");
		gotoxy(81,8);
		printf("Data");
		gotoxy(92,8);
		printf("CPF");
		gotoxy(110,8);
		printf("COD P.");
		
		rewind(PtrPedido);
		fread(&pedido, sizeof(pedidos), 1, PtrPedido);
		
		for(linha=10; !feof(PtrPedido); linha++)
		{
			if(pedido.ativo=='A')
			{
				if(pedido.situacao == 1)
				{
					gotoxy(59,linha);
					printf("%d", pedido.numPedido);
					gotoxy(65,linha);
					printf("%d", pedido.situacao);
					gotoxy(75,linha);
					printf("%d", pedido.telefone);
					gotoxy(81,linha);
					printf("%d", pedido.data);
					gotoxy(92,linha);
					printf("%s", pedido.CPF);
					gotoxy(110,linha);
					printf("%d", pedido.codigo);
				}	
			}
			fread(&pedido, sizeof(pedidos), 1, PtrPedido);	
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPedido);
}

void relatorio_caminho(void)//FUNCIONA
{
	int linha;
	pedidos pedido;
	
	FILE *PtrPedido = fopen("pedidos.dat", "rb");

	gotoxy(59,7);
	printf("*** Relatorio de PEDIDOS ***");
	if(PtrPedido==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha PEDIDOS cadastrados ***");
	}
	else
	{
	
		apagador();
		gotoxy(60,6);
		printf("*** Relatorio de PEDIDOS a CAMINHO ***");
		gotoxy(59,8);
		printf("NUM");
		gotoxy(65,8);
		printf("Status");
		gotoxy(75,8);
		printf("Telefone");
		gotoxy(81,8);
		printf("Data");
		gotoxy(92,8);
		printf("CPF");
		gotoxy(110,8);
		printf("COD P.");
		
		rewind(PtrPedido);
		fread(&pedido, sizeof(pedidos), 1, PtrPedido);
		
		for(linha=10; !feof(PtrPedido); linha++)
		{
			if(pedido.ativo=='A')
			{
				if(pedido.situacao == 2)
				{
					gotoxy(59,linha);
					printf("%d", pedido.numPedido);
					gotoxy(65,linha);
					printf("%d", pedido.situacao);
					gotoxy(75,linha);
					printf("%d", pedido.telefone);
					gotoxy(81,linha);
					printf("%d", pedido.data);
					gotoxy(92,linha);
					printf("%s", pedido.CPF);
					gotoxy(110,linha);
					printf("%d", pedido.codigo);
				}	
			}
			fread(&pedido, sizeof(pedidos), 1, PtrPedido);	
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPedido);
}

void relatorio_palavra(void)//FUNCIONA
{
	int linha;
	char word[10];
	Cliente cliente;
	
	FILE *PtrCliente = fopen("cliente.dat","rb");
	
	gotoxy(59,6);
	printf("*** Relatorio de CLIENTES ***");
	fflush(stdin);
	gotoxy(59,8);
	printf("Digite a Palavra desejada:");
	
	gets(word);
	if(PtrCliente == NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha CLIENTES cadastrados ***");
	}
	else
	{
		apagador();
		gotoxy(70,6);
		printf("*** Relatorio PALAVRA %s ***", word);
		gotoxy(59,8);
		printf("Telefone");
		gotoxy(73,8);
		printf("Nome");
		gotoxy(83,8);
		printf("Cidade");
		gotoxy(93,8);
		printf("Endereco");
		gotoxy(105,8);
		printf("CEP");
		
		rewind(PtrCliente);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		for(linha=10; !feof(PtrCliente); linha++)
		{
			if(strstr(cliente.nome, word) != NULL)
			{
				gotoxy(59,linha);
				printf("%d", cliente.telefone);
				gotoxy(73,linha);
				printf("%s", cliente.nome);
				gotoxy(83,linha);
				printf("%s", cliente.cidade);
				gotoxy(93,linha);
				printf("%s", cliente.endereco);
				gotoxy(105,linha);
				printf("%s", cliente.CEP);
			}
			fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		}	
	}
	getch();
	apagador();
	fclose(PtrCliente);
}

void relatorio_letra(void)//FUNCIONA
{
	int linha;
	char letra[2];
	Cliente cliente;
	
	FILE *PtrCliente = fopen("cliente.dat","rb");
	
	gotoxy(59,6);
	printf("*** Relatorio de CLIENTES ***");
	gotoxy(59,8);
	printf("Digite a Letra desejada: ");
	fflush(stdin);
	scanf("%s", &letra);
	if(PtrCliente==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nao ha CLIENTES cadastrados ***");
	}
	else
	{
	
		apagador();
		gotoxy(70,6);
		printf("*** Relatorio LETRA %s ***", letra);
		gotoxy(59,8);
		printf("Telefone");
		gotoxy(73,8);
		printf("Nome");
		gotoxy(83,8);
		printf("Cidade");
		gotoxy(93,8);
		printf("Endereco");
		gotoxy(105,8);
		printf("CEP");
		
		rewind(PtrCliente);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		for(linha=10; !feof(PtrCliente); linha++)
		{
			
			if(cliente.nome[0] == letra[0] && cliente.ativo=='A')
			{
				gotoxy(59,linha);
				printf("%d", cliente.telefone);
				gotoxy(73,linha);
				printf("%s", cliente.nome);
				gotoxy(83,linha);
				printf("%s", cliente.cidade);
				gotoxy(93,linha);
				printf("%s", cliente.endereco);
				gotoxy(105,linha);
				printf("%s", cliente.CEP);
			}
			fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		}
	}
	getch();
	apagador();
	fclose(PtrCliente);
}

void ordena_rank(FILE *PtrRank) //FUNCIONA
{
	int pos, maior, posmaior,i;
	Ranking rank1, rank2;
	
	fseek(PtrRank, 0, 2);
	pos = ftell(PtrRank)/sizeof(Ranking);
	
	while(pos > 0)
	{
		maior = 0;
		for(i=1; i<pos; i++)
		{
			fseek(PtrRank, maior*sizeof(Ranking), 0);
			fread(&rank1, sizeof(Ranking), 1, PtrRank);
			fseek(PtrRank, i*sizeof(Ranking), 0);
			fread(&rank2, sizeof(Ranking), 1, PtrRank);
			if(rank2.quantidade < rank1.quantidade)
			{
				maior = i;
			}
		}
		
		if(maior < pos-1)
		{
			fseek(PtrRank, maior*sizeof(Ranking), 0);
			fwrite(&rank2, sizeof(Ranking), 1, PtrRank);
			fseek(PtrRank, (pos-1)*sizeof(Ranking), 0);
			fwrite(&rank1, sizeof(Ranking), 1, PtrRank);
		}
		pos--;
	}

}

void ranking(void) //FUNCIONA
{
	int i, count, linha=8, qnt_pizzas, aux, num;
	Pizzas pizza;
	Ranking rank;
	pedidos pedido;
	
	FILE *PtrPedidos = fopen("pedidos.dat","rb+");
	FILE *PtrPizzas = fopen("pizza.dat","rb+");
	FILE *PtrRank = fopen("rank.dat", "wb+");

	gotoxy(59,7);
	printf("*** Relatorio de PIZZAS ***");
	if(PtrPedidos==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nenhum pedido foi cadastrado ***");
	}
	else
	{
		
		apagador();
		gotoxy(60,6);
		printf("*** Relatorio de PIZZAS + Pedidos ***");
		
		fseek(PtrPizzas,0,2);
		qnt_pizzas = ftell(PtrPizzas)/sizeof(Pizzas);
		
		fseek(PtrPizzas,0,0);
		fread(&pizza, sizeof(Pizzas), 1, PtrPizzas);
		
		while(!feof(PtrPizzas))
		{
			count = 0;
			aux = pizza.codigo;
			
			fseek(PtrPedidos, 0, 0);
			fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
		
			while(!feof(PtrPedidos))
			{
				if(aux == pedido.codigo)
				{
					count++;
				}
				fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
			}

			
			rank.pizza = aux;
			rank.quantidade = count;
			fwrite(&rank, sizeof(Ranking), 1, PtrRank);
			
			fread(&pizza, sizeof(Pizzas), 1, PtrPizzas);
		}
		
		ordena_rank(PtrRank);
		
		rewind(PtrRank);
		fread(&rank, sizeof(Ranking), 1, PtrRank);
		num = 1;
		while(!feof(PtrRank))
		{
			gotoxy(59,linha);
			printf("RANK %d - Pizza codigo %d     |||   %d pedidos", num, rank.pizza,rank.quantidade);
			linha++;
			num++;
			
			fread(&rank, sizeof(Ranking), 1, PtrRank);
		}
				
	}
	getch();
	apagador();
	
	fclose(PtrPedidos);
	fclose(PtrPizzas);
	fclose(PtrRank);
	remove("rank.dat");
}

void relatorio_clientes(void)//FUNCIONA
{
	int i, count, linha=8, aux,j;
	char aux2[30];
	float valor;
	Cliente cliente;
	pedidos pedido;
	Pizzas pizza;
	
	FILE *PtrPedidos = fopen("pedidos.dat","rb+");
	FILE *PtrCliente = fopen("cliente.dat","rb+");
	FILE *PtrPizzas = fopen("pizza.dat","rb+");

	gotoxy(59,7);
	printf("*** Relatorio de Clientes ***");
	if(PtrCliente==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nenhum cliente foi cadastrado ***");
	}
	else
	{
		
		apagador();
		gotoxy(65,6);
		printf("*** Relatorio de Clientes e Pediddos ***");
		
		fseek(PtrCliente,0,0);
		fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		
		while(!feof(PtrCliente))
		{
			count = 0;
			aux = cliente.telefone;
			strcpy(aux2, cliente.nome);
			
			fseek(PtrPedidos, 0, 0);
			fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
			
			valor =0;
		
			while(!feof(PtrPedidos))
			{
				if(aux == pedido.telefone)
				{
					count = pedido.codigo;
					gotoxy(59,linha);
					printf("Cliente %d | %s	  Cod Pizza pedida: %d", aux,aux2,count);
					linha++;
					
					j=busca_pizza2(PtrPizzas, count);
					fseek(PtrPizzas,j,0);
					fread(&pizza, sizeof(Pizzas), 1, PtrPizzas);
					
					valor += pizza.valor;
				}
				fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
			} 
			if(valor == 0)
			{
				gotoxy(70,linha);
				printf("Cliente nao realizou pedidos");
				linha ++;
			}

			gotoxy(59,linha);
			printf("====== Total gasto cliente %s: R$ %.2f ======", aux2, valor);
			linha+=3;

			fread(&cliente, sizeof(Cliente), 1, PtrCliente);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPedidos);
	fclose(PtrCliente);
	fclose(PtrPizzas);
}

void relatorio_moto_qnt(void)//FUNCIONA
{
	
	int i, count, linha=8, aux,j,entregas, data;
	char aux2[12];
	pedidos pedido;
	Motoqueiros motoqueiro;
	
	FILE *PtrPedidos = fopen("pedidos.dat","rb");
	FILE *PtrMotoqueiros = fopen("motoqueiro.dat","rb");

	if(PtrMotoqueiros==NULL)
	{
		apagador();
		gotoxy(70,8);
		printf("*** Nenhum motoqueiro foi cadastrado ***");
	}
	else
	{
		gotoxy(65,6);
		printf("*** Relatorio de Motoqueiros e Entregas ***");
		gotoxy(59,8);
		printf("para teste, cadastrei os pedidos com o dia 22112022 ");
		gotoxy(59,9);
		printf("Digite o dia que deseja pesquisar | DDMMAAAA:  ");	
		fflush(stdin);
		scanf("%d", &data);
		apagador();
		
		apagador();
		gotoxy(65,6);
		printf("*** Relatorio de Motoqueiros e Entregas ***");
		gotoxy(75,7);
		printf("*** Data %d ***", data);
		linha ++;
		fseek(PtrMotoqueiros,0,0);
		fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiros);
		
		while(!feof(PtrMotoqueiros))
		{
			count = 0;
			strcpy(aux2, motoqueiro.CPF);
			
			fseek(PtrPedidos, 0, 0);
			fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
			
			entregas =0;
		
			while(!feof(PtrPedidos))
			{
				if(strcmp(aux2, pedido.CPF) == 0)
				{
					if(data == pedido.data)
						entregas++;
				}
				fread(&pedido, sizeof(pedidos), 1, PtrPedidos);
			} 
			if(entregas == 0)
			{
				gotoxy(63,linha);
				printf("Motoqueiro nao realizou entregas nesse periodo");
				linha ++;
			}

			gotoxy(59,linha);
			printf("==== Total de entregas do motoqueiro %s foi de: %d", motoqueiro.nome, entregas);
			linha+=3;

			fread(&motoqueiro, sizeof(Motoqueiros), 1, PtrMotoqueiros);
		}	
	}
	getch();
	apagador();
	
	fclose(PtrPedidos);
	fclose(PtrMotoqueiros);
	
}

/*###################### EXECUTAR ######################*/

char executar()
{
		
	FILE *PtrCliente = fopen("cliente.dat","ab");
	FILE *PtrMotoqueiro = fopen("motoqueiro.dat","ab");
	FILE *PtrPedidos = fopen("pedidos.dat","ab");
	FILE *PtrPizzas = fopen("pizza.dat","ab");
	fclose(PtrMotoqueiro);
	fclose(PtrPedidos);
	fclose(PtrPizzas);
	fclose(PtrCliente);
	char op;
	
	do
	{
		op=menu();
		switch(op)
		{
			case 'A':	cadastrar_cliente();
						break;
						
			case 'B':	consulta_cliente();
						break;
			
			case 'C':	apagar_cliente();
						break;
									
			case 'D':	relatorio_cliente();
						break;
			
			case 'E':	alterar_cliente();
						break;
				
				
			case 'F':	relatorio_pizza();
						break;
			
			case 'G':	cadastrar_pizza();
						break;
						
			case 'H':	consulta_pizza();
						break;
						
			case 'I':	apagar_pizza();
						break;
				
			case 'J':	alterar_pizza();
						break;
						
						
			case 'K':	relatorio_moto();
						break;
			
			case 'L':	apagar_moto();
						break;
		
			case 'M':	cadastrar_moto();
						break;
				
			case 'N':	consulta_moto();
						break;
						
			case 'O':	alterar_moto();
						break;	
							
							
			case 'P':	relatorio_pedido();
						break;
						
			case 'Q':	cadastra_pedido();
						break;
						
			case 'R':	consulta_pedido();
						break;		
						
			case 'S':	apaga_pedido();
						break;

			case 'T':	alterar_pedido();
						break;
						
						
			case 'U':	relatorio_letra();
						break;			
						
			case 'V':	relatorio_palavra();
						break;
						
			case 'W':	relatorio_em_andamento();
						break;
						
			case 'X':	relatorio_caminho();
						break;	
			
			case 'Z':	ranking();
						break;	
			
			case '1': 	relatorio_clientes();
						break;	
			
			case '2':	relatorio_moto_qnt();
						break;										
		}
	}
	while(op!= 27);
}

 void todas_molduras()
{
	loading(2,15,117,17,255);
	moldura_toda(1,1,118,30,255);
	moldura_nome(2,2,117,4,255);
	moldura_menu(2,5,57,28,255);
	moldura_menu(3,25,56,27,255);
	moldura_menu(58,5,117,28,255);
}

int main(void)
{
	
	todas_molduras();
	executar();
	
	return 0;
	
}
