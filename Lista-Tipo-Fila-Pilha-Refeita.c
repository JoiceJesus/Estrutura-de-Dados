#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
/*Discente:Joice Jesus  Data:14/12/2021  Disciplina:Estrutura de Dados  Docente:Lucio Marcos
*Esse algoritmo implementa uma lista do tipo Pilha,do tipo Fila e a operação de recebe n valores, exclusão de elementos, exibe elementos
e faz o calculo da média aritmética dos valores inseridos na lista.
*Referências:C Completo e Total 3° edição(Herbert Schildt),Estruturas de dados usando C (Tenenbaum)*/
struct tipo_no{
	float elemento;
	struct tipo_no *ant;
	struct tipo_no *suc;
};

typedef struct tipo_no *Tipo_no;
//simplesmente encadeada
Tipo_no Tipo_Pilha(Tipo_no inicio){
	Tipo_no novo;
	
	novo=malloc(sizeof(Tipo_no));
	scanf("%f",&novo->elemento);
	novo->suc=inicio;
	return novo;
}
//simplesmente encadeada
Tipo_no Tipo_Fila(Tipo_no fim){
		Tipo_no novo;
		
		novo=malloc(sizeof(Tipo_no));
		scanf("%f",&novo->elemento);
		if(fim)
		fim->suc=novo;
		novo->suc=NULL;
		return novo;
}
//duplamente encadeada
Tipo_no Pilha(Tipo_no inicio){
	Tipo_no novo;
	
	novo = malloc(sizeof(Tipo_no));
	scanf("%f",&novo->elemento);
	novo->suc = inicio;
	novo->ant=NULL;
	if(inicio!=NULL)
	inicio->ant=novo;
	return novo;
}
//duplamente encadeada
Tipo_no Fila(Tipo_no inicio){
	Tipo_no novo;
	
	novo = malloc(sizeof(Tipo_no));
	scanf("%f",&novo->elemento);
	novo->ant=inicio;
	novo->suc=NULL;
	if(inicio!=NULL)
	inicio->suc=novo;
	
	return novo;
}
Tipo_no delete_elemento(Tipo_no inicio){
	Tipo_no alvo = inicio;
	Tipo_no novo_inicio = inicio->suc;
	int n;
	
	while((n!=1)&&(n!=2)){
	printf("\nDeseja excluir esse elemento da lista:\n(1.sim) (2.não)\n");
	scanf("%d",&n);
	}
	if(n=1){
	free(alvo);
	return novo_inicio;
	}else if(n=2){
	return inicio;
	}
}
void media(Tipo_no lista){
	Tipo_no aux;
	float soma,media;
	int c;
	
	aux=lista; soma=0; c=0;
	while(aux){
	if(aux){
	soma = soma+(aux->elemento);
	c=c+1;
	}
	aux=aux->suc;
	}
	media=soma/c;
	
	printf("%f",media);
	
}
int menu(int n){
	while(n!=4){
	printf("\nInforme a operação desejada:\n");
	printf("0.Inserir elemento\n");
	printf("1.Mostrar elementos\n");
	printf("2.Mostrar Média dos elementos\n");
	printf("3.Deletar elemento\n");
	printf("4.Encerrar Programa\n");
	scanf("%d",&n);
	return n;
	}
}
void Exibe_Elementos(Tipo_no lista){
	Tipo_no aux;
	aux=lista;
	
	while(aux){
	printf("[%f]->",aux->elemento);
	aux=aux->suc;
	if(!aux){
	printf("NULL");
	}
	}
}
main(){
	setlocale(LC_ALL, "Portuguese");
	system("color f0");
	Tipo_no S = NULL;
	Tipo_no F = NULL;
	
	int op1,op2,op3,n;
	//MENU INICIAL
	while((op1!=1)&&(op1!=2)){
	printf("\nInforme a operação desejada:\n");
	printf("1.Lista SIMPLESMENTE Encadeada\n");
	printf("2.Lista DUPLAMENTE Encadeada\n");
	scanf("%d",&op1);
	}system("cls");
	
	switch(op1){
	case 1:
	while((op2!=1)&&(op2!=2)){
	printf("\nInforme a operação desejada:\n");
	printf("1.Lista tipo Pilha\n");
	printf("2.Lista tipo Fila\n");
	scanf("%d",&op2);
	}
	switch(op2){
	case 1: 
	while(n!=4){
	n=menu(op3);
	switch(n){
	case 0:system("cls");
	printf("\nInforme o valor:\n");
	S=Tipo_Pilha(S);
	printf("\nElemento Inserido com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	case 1:system("cls");
	printf("\nElementos inseridos na Pilha foram:\n");
	Exibe_Elementos(S);
	break;
	case 2:system("cls");
	printf("\n\nMedia dos valores adicionados a Pilha:\n");
	media(S);
	break;
	case 3:system("cls");
	printf("\n\nO último elemento inserido sera DELETADO da Pilha!\n\n");
	S=delete_elemento(S);
	if(!S){
	F = NULL;
	}
	printf("\nElemento DELETADO com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
    }
	}
	break;
	case 2:
	while(n!=4){
	n=menu(op3);
	switch(n){
	case 0:system("cls");
	printf("\nInforme o valor:\n");
	F=Tipo_Fila(F);
	if(!S)
	S=F;
	printf("\nElemento Inserido com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	case 1:system("cls");
	printf("\nElementos inseridos na Fila foram:\n");
	Exibe_Elementos(S);
	break;
	case 2:system("cls");
	printf("\n\nMedia dos valores adicionados a Pilha:\n");
	media(S);
	break;
	case 3:system("cls");
	printf("\n\nO último elemento inserido sera DELETADO da Fila\n");
	S=delete_elemento(S);
	if(!S)
	F = NULL;
	printf("\nElemento DELETADO com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	}
	}
	break;
	}//CASE 1 switch 1 fim
	break;
	
	//incio case 2 switch 1
	case 2: 
	while((op2!=1)&&(op2!=2)){
	printf("\nInforme a operação desejada:\n");
	printf("1.Lista tipo Pilha\n");
	printf("2.Lista tipo Fila\n");
	scanf("%d",&op2);
	}
	switch(op2){
	case 1:	
	while(n!=4){
	n=menu(op3);
	switch(n){
	case 0:system("cls");
	printf("\nInforme o valor:\n");
	S=Pilha(S);
	printf("\nElemento Inserido com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	case 1:system("cls");
	printf("\nElementos inseridos na Fila foram:\n");
	Exibe_Elementos(S);
	break;
	case 2:system("cls");
	printf("\n\nMedia dos valores adicionados a Pilha:\n");
	media(S);
	break;
	case 3:
	system("cls");
	printf("\n\nO último elemento inserido sera DELETADO da Pilha!\n\n");
	S=delete_elemento(S);
	if(!S){
	F = NULL;
	}
	printf("\nElemento DELETADO com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	}
	}
	break;
	case 2:	
	while(n!=2){
	n=menu(op3);
	switch(n){
	case 0:system("cls");
	printf("\nInforme o valor:\n");
	F=Fila(F);
	if(!S)
	S=F;
	printf("\nElemento Inserido com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	case 1:
	Exibe_Elementos(S);
	break;
	case 2:system("cls");
	printf("\n\nMedia dos valores adicionados a Pilha:\n");
	media(S);
	break;
	case 3:system("cls");
	printf("\n\nO último elemento inserido sera DELETADO da Fila\n");
	S=delete_elemento(S);
	if(!S)
	F = NULL;
	printf("\nElemento DELETADO com Sucesso!\n---------------------------\n");
	Exibe_Elementos(S);
	printf("\n---------------------------\n");
	break;
	}
	}
	break;
	}
	}//SWITCH 1 FIM
}
