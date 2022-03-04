#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//cria a estrutura da árvore
struct t_no{
	float elemento;
	struct t_no *esqd;
	struct t_no *dirt;
};
typedef struct t_no *T_no;
//cria uma árvore binária
T_no criaRaiz(float novo){
	T_no no;
	
	no = malloc(sizeof(T_no));
	scanf("%f",&novo);
	no->elemento=novo;
	printf("\t\t\t\t[%f]",no->elemento);
	no->esqd = NULL;
	no->dirt = NULL;
	
	return no;
}
T_no InserirFilhoaEsquerda(T_no raiz,float atual,float novo){
	T_no folha;
	
	if(raiz!=NULL){
	if(raiz->elemento==atual){
	if(raiz->esqd==NULL){
	folha = criaRaiz(novo);
	raiz->esqd  = folha;
	}else
	printf("Inserção invalida");
	}else{
	InserirFilhoaEsquerda(raiz->esqd,atual,novo);
	InserirFilhoaEsquerda(raiz->dirt,atual,novo);
	}
	}
}
T_no InserirFilhoaDireita(T_no raiz,float atual,float novo){
	T_no folha;
	
	if(raiz!=NULL){
	if(raiz->elemento==atual){
	if(raiz->dirt==NULL){
	folha = criaRaiz(novo);
	raiz->dirt  = folha;
	}else
	printf("Inserção invalida");
	}else{
	InserirFilhoaEsquerda(raiz->dirt,atual,novo);
	InserirFilhoaEsquerda(raiz->esqd,atual,novo);
	}
	}
}
main(){
	setlocale(LC_ALL,"Portuguese");
	system("color f0");
	
	float valor,atual;
	T_no raiz;
	int opc;
	
	//MENU
	printf("\n\n\t\t\t¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨INFORME¨¨A¨¨OPIÇÃO¨¨¨DESEJADA¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n");
	printf("\t\t\t¨¨¨¨¨¨¨¨¨¨1.INSERIR¨A¨ESQUERDA¨¨¨¨¨¨¨¨¨2.INSERIR¨A¨DIREITA¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\t\t\t\t");
	scanf("%d",&opc);
	
	switch(opc){
	case 1:
	printf("\t\t\t\tINFORME O VALOR A SER INSERIDO A ESQUERDA:\n\n\t\t\t\t");
	criaRaiz(valor);
	InserirFilhoaEsquerda(raiz,atual,valor);
	break;
	case 2:
	printf("\t\t\t\tINFORME O VALOR A SER INSERIDO A DIREITA:\n\n\t\t\t\t");
	criaRaiz(valor);
	InserirFilhoaDireita(raiz,atual,valor);
	break;
	}
}
