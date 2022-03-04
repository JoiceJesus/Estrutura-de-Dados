#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
/*Discente: Joice de J. dos Santos  Data:24/02/2022  Disciplina: Estrutura de Dados  Docente: Lucio Marcos
*Esse programa cria duas Listas Simplesmente e Duplamente Encadeada do tipo PILHA e FILA, realiza a inser็ใo e dele็ใo de valores tanto na PILHA quanto na FILA,
* E efetua tamb้m a exclusใo sem amarra็ใo nas Listas tanto PILHA como FILA.
*/
struct tipo_no{
	float elemento;
	struct tipo_no *ant;
	struct tipo_no *suc;
};

typedef struct tipo_no *Tipo_no;

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
Tipo_no delete_elementos(float y, Tipo_no lista){
	
	Tipo_no aux,S=NULL;
	Tipo_no remov = NULL;
	int op;
	
	if(lista){
	if((lista)->elemento == y){
	remov = lista;
	lista = remov->suc;
	}else{
	aux = lista;
	while((aux->suc)&&((aux->suc->elemento)!=y))
	aux=aux->suc;
	if(aux->suc){
	remov = aux->suc;
	aux->suc = remov->suc;
	}
	}
	}
	if(remov)
	printf("\n\t\t\t\t\t\tExcluindo [%f] da lista!",remov->elemento);
	free(remov);
	printf("\n\t\t\t\t\t\tElemento DELETADO com Sucesso!\n\t\t\t\t\t\t");
}

Tipo_no delete_elemento(Tipo_no inicio){
	Tipo_no alvo = inicio;
	Tipo_no novo_inicio = inicio->suc;
	int n;
	
	while((n!=1)&&(n!=2)){
	printf("\n\t\t\t\t\t\tDeseja excluir esse elemento da lista:\n\t\t\t\t\t\t(1.sim) (2.nใo)\n\t\t\t\t\t\t");
	scanf("%d",&n);
	}
	if(n=1){
	free(alvo);
	return novo_inicio;
	}else if(n=2){
	return inicio;
	}
	printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
}
int menu(int n){
	while(n!=4){
	printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจINFORMEจจAจจOPERAวรOจจDESEJADAจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
	printf("\t\t\t\t\t\t1.INSERIR elemento;\n");
	printf("\t\t\t\t\t\t2.DELETAR elemento no TOPO;\n");
	printf("\t\t\t\t\t\t3.ESCOLHER Valor a ser DELETADO em qualque posi็ใo;\n");
	printf("\t\t\t\t\t\t4.ENCERRAR o Programa.\n\t\t\t\t\t\t");
	scanf("%d",&n);
	return n;
	}
	printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
}
main(){
	
	setlocale(LC_ALL, "Portuguese");
	system("color f0");
	Tipo_no S = NULL;
	Tipo_no F = NULL;
	Tipo_no j;
	float valor,y;
	int op1,op2,op3,n;
	
	
	//MENU INICIAL
	while((op1!=1)&&(op1!=2)){
	printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจINFORMEจจAจจOPERAวรOจจDESEJADAจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
	printf("\n\t\t\t\t\t\t1.Lista *SIMPLESMENTE* Encadeada\n");
	printf("\t\t\t\t\t\t2.Lista *DUPLAMENTE* Encadeada\n\t\t\t\t\t\t");
	scanf("%d",&op1);
	printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
	}
	//duplamente ou simpesmente encadeada 1ฐ switch case.
	switch(op1){
		case 1://case 1, 1ฐ switch, simpesmente encadeada.
		while((op2!=1)&&(op2!=2)){//MENU para o tipo de Lista a ser usada-:simpesmente encadeada
		printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจINFORMEจจAจจOPERAวรOจจDESEJADAจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
		printf("\t\t\t\t\t\t1.Lista tipo PILHA\n");
		printf("\t\t\t\t\t\t2.Lista tipo FILA\n\t\t\t\t\t\t");
		scanf("%d",&op2);
		printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
	//simpesmente encadeada 2ฐ switch case.
	switch(op2){
		case 1://case 1(PILHA), 2ฐ switch, simpesmente encadeada.
		while(op3!=4){
		op3=menu(n);
		//simpesmente encadeada 3ฐ switch case.	
		switch(op3){
		case 1://case 1(INSERIR), 3ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tInforme o valor:\n\t\t\t\t\t\t");
		S=Tipo_Pilha(S);
		if(!S)
		S=F;
		printf("\n\t\t\t\t\t\tElemento INSERIDO com Sucesso no topo da PILHA!\n\t\t\t\t\t\t");
		Exibe_Elementos(S);
		break;//break do case 1, 3ฐ switch, simpesmente encadeada.
		case 2://case 2(DELETAR), 3ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tO ๚ltimo elemento inserido sera DELETADO da Pilha!\n\n");
		S=delete_elemento(S);
		if(!S){
		F = NULL;
		}
		printf("\n\t\t\t\t\t\tElemento DELETADO com Sucesso!\n\t\t\t\t\t\t");
		Exibe_Elementos(S);
		break;//break do case 2, 3ฐ switch, simpesmente encadeada.
		case 3://case 3(ESCOLHER), 3ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tInforme o valor a ser DELETADO:\n\t\t\t\t\t\t");
		scanf("%f",&y);
		delete_elementos(y,S);
		Exibe_Elementos(S);
		printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ");
		break;//break do case 3, 3ฐ switch, simpesmente encadeada.
		}
		}
		break;//break do case 1, 2ฐ switch, simpesmente encadeada.
		
		case 2://case 2(FILA), 2ฐ switch, simpesmente encadeada.
		while(op3!=4){
		op3=menu(n);
		//simpesmente encadeada 3ฐ switch case.	
		switch(op3){
		case 1://case 1(INSERIR), 3.2ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tInforme o valor:\n\t\t\t\t\t\t");
		F=Tipo_Fila(F);
		if(!S)
		S=F;
		printf("\n\t\t\t\t\t\tElemento INSERIDO com Sucesso no fim da FILA!\n\t\t\t\t\t\t");
		Exibe_Elementos(S);
		break;//break do case 1, 3.2ฐ switch, simpesmente encadeada.
		case 2://case 2(DELETAR), 3.2ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tO ๚ltimo elemento inserido serแ DELETADO da FILA!\n\n");
		S=delete_elemento(S);
		if(!S){
		F = NULL;
		}
		printf("\n\t\t\t\t\t\tElemento DELETADO com Sucesso!\n\t\t\t\t\t\t");
		Exibe_Elementos(S);
		break;//break do case 2, 3.2ฐ switch, simpesmente encadeada.
		
		case 3://case 3(ESCOLHER), 3ฐ switch, simpesmente encadeada.
		printf("\n\t\t\t\t\t\tInforme o valor a ser DELETADO:\n\t\t\t\t\t\t");
		scanf("%f",&y);
		delete_elementos(y,S);
		Exibe_Elementos(S);
		//printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ");
		break;//break do case 3, 3ฐ switch, simpesmente encadeada.
		}
		}
		break;//break do case 2, 2ฐ switch, simpesmente encadeada.
		}//fim switch 2
		}
		break;//break do case 1, 1ฐ switch, simpesmente encadeada.
//------------------------------------------------------------------------------------------------------------------------------------------------------------//		
		case 2://case 2, 1ฐ switch, duplamente encadeada.
		while((op2!=1)&&(op2!=2)){//MENU para o tipo de Lista a ser usada-:duplamente encadeada
		printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจINFORMEจจAจจOPERAวรOจจDESEJADAจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
		printf("\t\t\t\t\t\t1.Lista tipo PILHA\n");
		printf("\t\t\t\t\t\t2.Lista tipo FILA\n\t\t\t\t\t\t");
		scanf("%d",&op2);
		//printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ\n");
		}
		switch (op2){
			case 1://case 1, 3ฐ switch, duplamente encadeada.
			while(op3!=4){
			op3 = menu(n);
			switch(op3){
			case 1://case 1(INSERIR), 3ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tInforme o valor:\n\t\t\t\t\t\t");
			S=Pilha(S);
			if(!S)
			S=F;
			printf("\n\t\t\t\t\t\tElemento INSERIDO com Sucesso no topo da PILHA!\n\t\t\t\t\t\t");
			Exibe_Elementos(S);
			break;//break 1, 3ฐ switch, duplamente encadeada.
			case 2://case 2(DELETAR), 3ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tO ๚ltimo elemento inserido sera DELETADO da Pilha!\n\n");
			S=delete_elemento(S);
			if(!S){
			F = NULL;
			}
			printf("\n\t\t\t\t\t\tElemento DELETADO com Sucesso!\n\t\t\t\t\t\t");
			Exibe_Elementos(S);
			break;//break 2, 3ฐ switch, duplamente encadeada.
			case 3://case 3(ESCOLHER), 3ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tInforme o valor a ser DELETADO:\n\t\t\t\t\t\t");
			scanf("%f",&y);
			delete_elementos(y,S);
			Exibe_Elementos(S);
			//printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ");
			break;//break 3, 3ฐ switch, duplamente encadeada.
			}
			}
			break;//break 1, 2ฐ switch, duplamente encadeada.
			case 2://case 2, 2ฐ switch, duplamente encadeada.
			while(op3!=4){
			op3 = menu(n);
			switch(op3){
			case 1://case 1(INSERIR), 3.2ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tInforme o valor:\n\t\t\t\t\t\t");
			F=Fila(F);
			if(!S)
			S=F;
			printf("\n\t\t\t\t\t\tElemento INSERIDO com Sucesso no topo da PILHA!\n\t\t\t\t\t\t");
			Exibe_Elementos(S);
			break;//break 1, 3.2ฐ switch, duplamente encadeada.
			case 2://case 2(DELETAR), 3.2ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tO ๚ltimo elemento inserido sera DELETADO da Pilha!\n\n");
			S=delete_elemento(S);
			if(!S){
			F = NULL;
			}
			printf("\n\t\t\t\t\t\tElemento DELETADO com Sucesso!\n\t\t\t\t\t\t");
			Exibe_Elementos(S);
			break;//break 2, 3.2ฐ switch, duplamente encadeada.
			case 3://case 3(ESCOLHER), 3.2ฐ switch, duplamente encadeada.
			printf("\n\t\t\t\t\t\tInforme o valor a ser DELETADO:\n\t\t\t\t\t\t");
			scanf("%f",&y);
			delete_elementos(y,S);
			Exibe_Elementos(S);
			//printf("\n\t\tจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ");
			break;//break 3, 3.2ฐ switch, duplamente encadeada.
			}
			}
			break;//break 2, 2ฐ switch, duplamente encadeada.
			}
			break;//break do case 1, 1ฐ switch, duplamente encadeada.
		}	
}
