#include<stdio.h>
#include<stdlib.h>

/*Aluna:Joice de Jesus dos Santos  Data:03/12/2021  Disciplina: Estrutura de Dados   Professor:Lucio Marcos
recursividade
lembrete:Há certos algoritmos que são mais eficientes quando feitos de maneira recursiva, mas a recursividade é algo a ser evitado
sempre que possível, pois, se usada incorretamente, tende a consumir muita memória e ser lenta. Lembre-se que memória é consumida
cada vez que o computador faz uma chamada a uma função. Com funções recursivas a memória do computador pode se esgotar rapidamente.
*/
int entrada(int n){
	printf("Informe o valor:\n");
	scanf("%d",&n);
	return n;
}
int fatorial(int n){
	
	if(n!=0){
		return n*fatorial(n-1);
	}else{
		return 1;
	}
}
int saida(int n){
	printf("O fatorial de %d = [%d]",n,fatorial(n));
	return 0;
}
void main(){
	int n=5;
	
	entrada(n);
	fatorial(n);
	saida(n);
}
