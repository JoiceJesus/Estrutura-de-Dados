#include<stdio.h>
#include<stdlib.h>
/*Aluna:Joice de Jesus dos Santos  Data:03/12/2021  Professor:Lucio Marcos  Disciplina:Estrutura de Dados
Alocação dinamica utilizando a função malloc.
*/
main(void){
	
	int *p;
	int a,i;
	
	
	p=(int *)malloc(a*sizeof(int));
	
	if (!p)
        {
        	printf ("** Erro: Memoria Insuficiente **");
        	exit;
        }

	for (i=0; i<a ; i++){
		p[i] = i*i;
		
}
	return 0;
}
