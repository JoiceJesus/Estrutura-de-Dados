#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct tno{
    int elemento;
    struct tno *qd;
	struct tno *dt;
    short alt;
};

typedef struct tno Tno;

Tno *CriaR(int valor){
    Tno *novo; 
	
	novo = malloc(sizeof(Tno));
    if(novo){
    novo->elemento = valor;
    novo->qd = NULL;
    novo->dt = NULL;
    novo->alt = 0;
    }
    else
    printf("\nOps ERRO......!\n");
    return novo;
}
short maior_sub(short a, short b){
    return (a > b)? a: b;
}
short altoNo(Tno *no){
    if(no == NULL)
    return -1;
    else
    return no->alt;
}
short fatdeBalance(Tno *no){
    if(no)
    return (altoNo(no->qd) - altoNo(no->dt));
    else
    return 0;
}
Tno *rotQd(Tno *r){
    Tno *y, *f;

    y = r->dt;
    f = y->qd;
    y->qd = r;
    r->dt = f;
    r->alt = maior_sub(altoNo(r->qd), altoNo(r->dt)) + 1;
    y->alt = maior_sub(altoNo(y->qd), altoNo(y->dt)) + 1;
    return y;
}
Tno *rotDt(Tno *r){
    Tno *y, *f;

    y = r->qd;
    f = y->dt;
    y->dt = r;
    r->qd = f;
    r->alt = maior_sub(altoNo(r->qd), altoNo(r->dt)) + 1;
    y->alt = maior_sub(altoNo(y->qd), altoNo(y->dt)) + 1;
    return y;
}

Tno *rotQd_Dt(Tno *r){
    r->qd = rotQd(r->qd);
    return rotDt(r);
}

Tno *rotDt_Qd(Tno *r){
    r->dt = rotDt(r->dt);
    return rotQd(r);
}
Tno *balancear(Tno *raiz){
    short fb = fatdeBalance(raiz);

    //rotação a esquerda
    if(fb < -1 && fatdeBalance(raiz->dt) <= 0)
    raiz = rotQd(raiz);
    //rotação a direita
    else if(fb > 1 && fatdeBalance(raiz->qd) >= 0)
    raiz = rotDt(raiz);
    //rotação dupla a esquerda
    else if(fb > 1 && fatdeBalance(raiz->qd) < 0)
    raiz = rotQd_Dt(raiz);
    //rotação dupla a direita
    else if(fb < -1 && fatdeBalance(raiz->dt) > 0)
    raiz = rotDt_Qd(raiz);
    return raiz;
}
Tno *inserir(Tno *raiz, int valor){
    if(raiz == NULL)
    return CriaR(valor);
    else{
    if(valor < raiz->elemento)
    raiz->qd = inserir(raiz->qd,valor);
    else if(valor > raiz->elemento)
    raiz->dt = inserir(raiz->dt,valor);
    else
    printf("\nOps Erro.....!");
    }
    raiz->alt = maior_sub(altoNo(raiz->qd),altoNo(raiz->dt)) + 1;
    raiz = balancear(raiz);

    return raiz;
}
void imprimir(Tno *r,int l){
    int i;
    
    if(r){
    imprimir(r->dt,l+1);
    printf("\n");
    for(i=0;i<l;i++)
    printf("   ");
    printf("(%d)",r->elemento);
    imprimir(r->qd,l+1);
    }
}
void Intra_Ordem(Tno *raiz){
	
    if(raiz != NULL){
    Intra_Ordem(raiz->qd);
    printf(" %d", raiz->elemento);
    Intra_Ordem(raiz->dt);
    }
}
void PreOrdem(Tno *raiz){
    if(raiz != NULL){
    printf(" %d",raiz->elemento);
    PreOrdem(raiz->qd);
    PreOrdem(raiz->dt);
    }
}
void PosOrdem(Tno *raiz){
	if(raiz != NULL){
    PosOrdem(raiz->qd);
    PosOrdem(raiz->dt);
    printf(" %d",raiz->elemento);
    }
}
void main(){
	setlocale(LC_ALL,"portuguese");
	system("color f0");

    int op,valor,op1;
    Tno *raiz = NULL;
    
		printf("INFORME A OPÇÃO DESEJADA\n");
    	while(op!=3){
        printf("\n1.Inserir Valor  2.Imprimir  3.Encerrar Programa\n\n");
        scanf("%d",&op);

        switch(op){
        case 1:
        printf("\nInforme o Valor:\n");
        scanf("%d",&valor);
        raiz = inserir(raiz,valor);
        printf("\n**********************************\n");
        imprimir(raiz, 1);
        printf("\n**********************************\n");
        break;
        case 2:
        printf("Informe a Impreção desejada:\n1.Intra-Ordem\t2.Pré-Ordem\t3.Pós-Ordem\n");
        scanf("%d",&op1);
        switch(op1){
        case 1:
        printf("\n**********************************\n");
        imprimir(raiz,1);
        printf("\n**********************************\n");
		Intra_Ordem(raiz);
		break;
        case 2:
        printf("\n**********************************\n");
        imprimir(raiz,1);
        printf("\n**********************************\n");
		PreOrdem(raiz);
		break;
        case 3:
        printf("\n**********************************\n");
        imprimir(raiz,1);
        printf("\n**********************************\n");
		PosOrdem(raiz);
		break;
		}
        break;
        }
    	};
}
