#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<unistd.h>

// estruturas
typedef struct funcionario{
	char nome[20];
	char matricula[20];
	char loginFunc[10];
	char senhaFunc[10];
}Funcionario;

typedef struct livro{
	char nomeLivro[20];
	int ISBN;
	int quantidade;
	char status[20];
}Livro;


typedef struct curso{
	char nomeCurso[15];
	char area[15];
}Curso;

typedef struct aluno{
	char nomeAluno[20];
	char matricula[20];
	Curso curso[0];
}Aluno;

typedef struct livrosEmprestados{
	char titulo[20];
	int quantidade;
}Emprestados;

// Admin root
char loginRoot[10] = "root";
char senhaRoot[10] = "root";

// variaveis globais
int opMenu;
char login[10];
char senha[10];
int dia, mes, ano;

// estruturas
Funcionario funcionario[5];
Curso curso[3];
Livro livro[5];
Aluno aluno[5];
Livro livroEmprestado[2];
Emprestados emprestados[5];

// procedimentos
void loginSistema();
void menu();
void cadFuncionario();
void cadLivro();
void cadAluno();
void encontrarAlunoCadastrado();
void emprestarLivro();


int main() {
	setlocale(LC_ALL, "Portuguese");
	loginSistema();
	menu();
	return 0;
}


void loginSistema() {
	printf("\nBem vindo, para entrar no sistema informa suas credenciais!");
		
	printf("\nLogin: ");
	fflush(stdin);
	gets(login);
		
	printf("\nSenha: ");
	fflush(stdin);
	gets(senha);
		
	if ( (strcmp(login, loginRoot) != 0) || (strcmp(senha, senhaRoot) != 0) ) {
		do{
			system("cls");
			printf("\nUsuário ou senha incorretos, tente novamente!");
		
			printf("\nLogin: ");
			fflush(stdin);
			gets(login);
				
			printf("\nSenha: ");
			fflush(stdin);
			gets(senha);
		}while( (strcmp(login, loginRoot) != 0) || (strcmp(senha, senhaRoot) != 0) );
	}
	printf("\nLogin efetuado com sucesso, bem vindo!!");
	sleep(3);	
}

void menu() {
	do{
		system("cls");
		printf("\nBem vindo ao sistema!");
		printf("\nEscolha uma opção!");
		printf("\n1 - Cadastrar livro.");
		printf("\n2 - Cadastrar funcionário.");
		printf("\n3 - Cadastrar aluno.");
		printf("\n4 - Emprestar livro.");
		printf("\n5 - Devolver livro.");
		printf("\n6 - Sair do sistema.\n---> ");
		scanf("%d",&opMenu);
		
		switch(opMenu){
			case 1:
				cadLivro();
				break;
			case 2:
				cadFuncionario();
				break;
			case 3:
				cadAluno();
				break;
			case 4:
				emprestarLivro();
				printf("\nInforme a data de emprestimo.");
				printf("\ndia - mes - ano:\n--> ");
				scanf("%d",&dia);
				printf("-->----- ");
				printf("\n--> ");
				scanf("%d",&mes);
				printf("-->----- ");
				printf("\n--> ");
				scanf("%d",&ano);
				
				printf("\nData de emprestimo: %d/%d/%d", dia, mes, ano);
				sleep(10);
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				printf("\nOpção invalida!");
		}
		
	}while(opMenu != 6);
	printf("\nFinalizando sistema...");
	sleep(2);
}

void cadFuncionario() {
	int n = 0;
	do{
		system("cls");
		printf("\nBem vindo ao cadastro de funcionários.");
		printf("\nNome: ");
		fflush(stdin);
		gets(funcionario[n].nome);
		
		printf("\nMatrícula: ");
		fflush(stdin);
		gets(funcionario[n].matricula);
		
		printf("\nLogin: ");
		fflush(stdin);
		gets(funcionario[n].loginFunc);
		
		printf("\nSenha: ");
		fflush(stdin);
		gets(funcionario[n].senhaFunc);
		
		n++;
		printf("\nDeseja cadastrar outro funcionário? Para sair, digite 0:\n-->");
		scanf("%d",&opMenu);
	}while(opMenu != 0);
	printf("\nCadastro realizado com sucesso!");
	sleep(2);
}

void cadLivro() {
	int n = 0;
	do{
		system("cls");
		printf("\nBem vindo ao cadastro de livros.");
		printf("\nNome: ");
		fflush(stdin);
		gets(livro[n].nomeLivro);
		
		printf("\nISBN: ");
		scanf("%d",&livro[n].ISBN);
		
		printf("\nQuantidade: ");
		scanf("%d", &livro[n].quantidade);
		
		printf("\nStatus: ");
		fflush(stdin);
		gets(livro[n].status);
		
		n++;
		printf("\nDeseja cadastrar outro livro? Para sair, digite 0:\n-->");
		scanf("%d",&opMenu);
	}while(opMenu != 0);
	printf("\nCadastro realizado com sucesso!");
	sleep(2);
}

void cadAluno() {
	int n = 0;
	do{
		system("cls");
		printf("\nBem vindo ao cadastro de alunos.");
		printf("\nNome: ");
		fflush(stdin);
		gets(aluno[n].nomeAluno);
		
		printf("\nMatrícula: ");
		fflush(stdin);
		gets(aluno[n].matricula);
		
		printf("\nÁrea: ");
		fflush(stdin);
		gets(aluno[n].curso[n].area);
		
		printf("\nCurso: ");
		fflush(stdin);
		gets(aluno[n].curso[n].nomeCurso);
		
		n++;
		printf("\nDeseja cadastrar outro aluno? Para sair, digite 0:\n-->");
		scanf("%d",&opMenu);
	}while(opMenu != 0);
	printf("\nCadastro realizado com sucesso!");
	sleep(2);
}

void emprestarLivro() {
	int n, id;
	int quantidade;
	int escolha;
	int quantidadeRestante;
	int idEmp = 0;
	int contador = 0;
	
	encontrarAlunoCadastrado();
	do{	
		system("cls");
		printf("\nEstes são os livros disponíveis: ");
		printf("\nID -- Título   --------   ISBN  --- Quantidade  --- Status");
		for(id=0; id < 5; id++) {
			printf("\n%d ----  %s   -------- %d --- %d --- %s", id, livro[id].nomeLivro, livro[id].ISBN, livro[id].quantidade, livro[id].status);
		}
		
		printf("\nEscolha até 2 livros: ");
		scanf("%d", &escolha);
		
		for(n=0; n<5; n++) {
			if(n == escolha) {
				do{
					if(strcmp(livro[n].status, "indisponivel") == 0) {
						printf("\nLivro indisponivel no momento!");
						sleep(2);
						break;
					}
					printf("\nQuantidade: ");
					scanf("%d",&quantidade);
					quantidadeRestante = livro[n].quantidade - quantidade;
					
					if(quantidadeRestante < 0) {
						printf("\nQuantidade indisponivel, tente novamente!");
						sleep(2);
					}
					else if(quantidade > 2) {
						printf("\nNo máximo 2 livros!");
						sleep(2);
					}
					else if(quantidadeRestante == 0) {
						strcpy(livro[n].status, "indisponivel");
					}
						
				}while(quantidadeRestante < 0 || quantidade > 2);
				
				strcpy(emprestados[idEmp].titulo, livro[n].nomeLivro);
				emprestados[idEmp].quantidade = quantidade;
				
				livro[n].quantidade = quantidadeRestante;
			}
		}
		
		idEmp++;
		
		printf("\nPegar outro livro? (s) ou Para sair digite 0: ");
		scanf("%d", &opMenu);
		contador++;
	}while(opMenu != 0 || contador == 2);
	
	printf("\nLivro emprestado com sucesso!");
	sleep(2);
}

void encontrarAlunoCadastrado() {
	char nomeAluno[20];
	char matriculaAluno[20];
	int count = 0;	
	system("cls");
	printf("\nBem vindo a interface de emprestimo de livros!");
	printf("\nPesquisar aluno");
	printf("\nInforme o nome do meliante: ");
	fflush(stdin);
	gets(nomeAluno);
		
	printf("\nInforme a matrícula do meliante: ");
	fflush(stdin);
	gets(matriculaAluno);
		
	for(count; count < 2; count++) {
		if( (strcmp(nomeAluno, aluno[count].nomeAluno) == 0) && (strcmp(matriculaAluno, aluno[count].matricula) == 0) ) {
			printf("\nAluno %s encontrado!", aluno[count].nomeAluno);
			sleep(2);
			break;
		}
	}
	
	do{
		system("cls");
		if( (strcmp(nomeAluno, aluno[count].nomeAluno) != 0) || (strcmp(matriculaAluno, aluno[count].matricula) != 0) ){
			printf("\nCadastro não identificado! Tente novamente!");
			printf("\nInforme o nome do meliante: ");
			fflush(stdin);
			gets(nomeAluno);
						
			printf("\nInforme a matrícula do meliante: ");
			fflush(stdin);
			gets(matriculaAluno);
			
			count = 0;		
			for(count; count < 2; count++) {
				if( (strcmp(nomeAluno, aluno[count].nomeAluno) == 0) && (strcmp(matriculaAluno, aluno[count].matricula) == 0) ) {
					printf("\nAluno %s encontrado!", aluno[count].nomeAluno);
					sleep(2);
					break;
				}
			}	
		}
	}while( (strcmp(nomeAluno, aluno[count].nomeAluno) != 0) || (strcmp(matriculaAluno, aluno[count].matricula) != 0) );	
	
	printf("\nAluno encontrado!");
	sleep(2);
		
}





