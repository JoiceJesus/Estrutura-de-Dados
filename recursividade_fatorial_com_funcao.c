#include<stdio.h>
#include<stdlib.h>

/*Aluna:Joice de Jesus dos Santos  Data:03/12/2021  Disciplina: Estrutura de Dados   Professor:Lucio Marcos
recursividade
lembrete:H� certos algoritmos que s�o mais eficientes quando feitos de maneira recursiva, mas a recursividade � algo a ser evitado
sempre que poss�vel, pois, se usada incorretamente, tende a consumir muita mem�ria e ser lenta. Lembre-se que mem�ria � consumida
cada vez que o computador faz uma chamada a uma fun��o. Com fun��es recursivas a mem�ria do computador pode se esgotar rapidamente.
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
