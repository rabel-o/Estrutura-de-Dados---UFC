// LUÍS GUSTAVO RABELO DE OLIVEIRA - 540974
// KAUAN OLIVEIRA PERDIGAO LOPES - 514867

#ifndef TEMPO
#define TEMPO
#include <iostream>
#include <chrono>
#include <fstream>
#include "Lista.h"

using namespace std;

void gera_dados(int num_iteracoes, const int vetor_tam[]){
	for(int n = 0; n < num_iteracoes; ++n) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n com numeros aleatorios
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente	
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*) &r, sizeof(r)); // escreve numero r no arquivo binario
			}
			fout.close();
		}
	}
}
// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], List *v, const char *nomeArquivo) 
{	
	std::ifstream input_file(nomeArquivo, std::ios::binary); // abre arquivo binario para leitura
	for (int i = 0; i < n; i++) 
	{
		input_file.read((char*) &A[i], sizeof(int)); // ler um inteiro do arquivo e guarda na posicao A[i]
        v->push_back(A[i]); // inserindo o valor do vetor na posição i na lista
	}
	input_file.close(); // fecha o arquivo de leitura
}



// ----------------------------------------------------------------------------
// Funcao Principal

void marcador(std::string nome, void (*func) (List*)) 
{ 
	// Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 
					   29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
					   38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000, 
					   47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000, 
					   56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000, 
					   65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000, 
					   74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000, 
					   83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000, 
					   92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000, 100000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// ------------------------------------------------------------
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	// Os arquivos sao gerados e salvos na pasta com nome 'dados'
	gera_dados(TOTAL_N, tam);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execucao do algoritmo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs("resultados/resultado" + nome + ".txt", std::ofstream::out ); // abre arquivo de resultados do algoritmo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; 
		
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar os algoritmos para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			List* lista = new List();

			std::string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";

			ler_dados(tamanho_vetor, vetor, lista, nome_arquivo.c_str());
			
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			func(lista); // ordena o vetor 
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();

			// obtendo a duração total da ordenação
			auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media += duracao;

			lista->clear();
			delete lista;
		}
		duracao_media = duracao_media / 5.0;
		std::cout << "["+nome+"] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media << " microssegundos" << std::endl;
		ofs << tamanho_vetor << " " << duracao_media << "\n"; // grava no arquivo de resultados do algoritmo
	}
		
	ofs.close(); // fecha arquivo de resultados do algoritmo
	// ------------------------------------------------------------
	
	
}
#endif