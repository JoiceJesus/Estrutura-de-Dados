 #include<stdio.h>
#include<stdlib.h>
#include<locale.h>
/*Calcule a média aritmética dos elementos da lista.
a)uma lista utilizando Pilha
b)Uma lista utilizando Fila
*/
struct tipo_no{
float elemento;
struct tipo_no *elo;	
};

typedef struct tipo_no *Tno;

typedef struct {
	Tno tpo;
}Pilha;

void inicializarPilha(Pilha *p){
	p->tpo=NULL;
}
void inserirPilha(Pilha *L,float r){
	
	Tno novo;
	novo=(Tno)malloc(sizeof(struct tipo_no));
	novo->elemento=r;
	novo->elo=L->tpo;
	L->tpo=novo;
}
main(){
	
	setlocale(LC_ALL, "Portuguese");
	
}
