#ifndef NODO_H
#define NODO_H

#include <iostream>

class Grafo{

	public:

	int matriz[7][7];

	Grafo(){
		for(int i = 0; i < 7; i++){
			for(int j = 0; j < 7; j++){
				matriz[i][j] = 0;
			}
		}
	}

	void crearAristas(int pInicio, int pFinal){

		matriz[pInicio][pFinal] = 1;



	}

	void mostarGrafo(){

		int filas = 7;
		int colum = 7;

		for(int i = 0; i < filas; i++){
			for(int j = 0; j < colum; j++){
				
				std::cout << matriz[i][j];

			}
			std::cout << std::endl;
		}
		
	}

	int obtenerOpcion1(int pNodoA){

		for(int i = 0; i < 7; i++){

			if(matriz[pNodoA][i] == 1){
				return i;
			}
		}

	}

	int obtenerOpcion2(int pNodoA){

		for(int j = 7; j > 0; j--){
			if(matriz[pNodoA][j] == 1){
				return j;
			}
		}
	}

	int getOption(int pNodoA, int opt){

		int cont = 0;

		for(int i = 0; i < 7; i++){

			if(matriz[pNodoA][i] == 1){	

				cont++;
				if(cont == opt){

					return i;

				}
			}
		}
		return 0;
	}

};

#endif