#include <iostream>
#include <vector>

using namespace std;

typedef struct{
	string estado_inicial;
	vector<string> estadosFinais;
	vector< pair< pair<string, char>, string> > transicoes;
}AFND;

bool estadoFinal(AFND A, string estado){
	for (int i = 0; i < (int) A.estadosFinais.size(); i++){
		if(A.estadosFinais[i] == estado){
			return true;
		}
	}
	return false;
}

bool verifica(AFND A, string estadoAtual, string cadeia, int caractereAtual){
	if(caractereAtual == cadeia.size()){
		return estadoFinal(A, estadoAtual);
	}

	for (int i = 0; i < (int) A.transicoes.size(); i++){
		if((A.transicoes[i].first.first == estadoAtual) && (A.transicoes[i].first.second == cadeia[caractereAtual])){
			if(verifica(A, A.transicoes[i].second, cadeia, caractereAtual+1)){
				return true;
			}
		}
	}

	return false;
}

int main(){

	int N, M, S;

	string q, q1, q2, cadeia;
	char c;
	AFND A;

	cin >> A.estado_inicial; // Estado inicial

	cin >> N; // Numero de estados finais

	for (int i = 0; i < N; i++){
		cin >> q; // Lendo os estados finais
		A.estadosFinais.push_back(q);
	}

	cin >> M; // Numero de transicoes

	for (int i = 0; i < M; i++){
		cin >> q1 >> c >> q2; // Lendo as transicoes
		A.transicoes.push_back(make_pair( make_pair(q1, c), q2));		
	}

	cin >> S; // Numero de strings a serem lidas

	for (int i = 0; i < S; i++){
		cin >> cadeia;
		if(verifica(A, A.estado_inicial, cadeia, 0)){
			cout << "aceita" << endl;
		}else{
			cout << "rejeita" << endl;
		}		
	}	

	return 0;
}