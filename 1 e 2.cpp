#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int* numAleatorio(int n, int minimo, int maximo){
int* res = (int*) malloc (n* sizeof(int));
for (int i = 0; i < n; i++){
	res[i] = (rand() % (maximo - minimo)) + minimo;
}
return res;
}
int tempo (int* V, int N, void fun(int*, int)){
	clock_t t = clock();
	fun(V,N);
	t = clock() - t;
	int r = (int) ((float)t)*1000 / CLOCKS_PER_SEC;
	return r;
}
void swap(int* a, int* b){
	int aux= *a;
	*a = *b;
	*b = aux;
}
void bubblesort (int* V, int N){
	if (N < 1){
		return;
	} else{
		for(int i = 0; i < N; i++){
			if(V[i] > V[i+1]){
				swap(&V[i], &V[i+1]);
			}
		}
		 bubblesort(V, N - 1);
	}
}
int main(){
	int* V = numAleatorio(1000, 1000, 10000);
	int x = tempo(V,1000, bubblesort);
	printf("Tempo (ms): %d\n", x);
	
    V = numAleatorio(2000, 1000, 10000);
	x = tempo(V,2000, bubblesort);
	printf("Tempo (ms): %d\n", x);
	
    V = numAleatorio(4000, 1000, 10000);
	x = tempo(V,4000, bubblesort);
	printf("Tempo (ms): %d\n", x);
	
	V = numAleatorio(8000, 1000, 10000);
	x = tempo(V,8000, bubblesort);
	printf("Tempo (ms): %d\n", x);
}
