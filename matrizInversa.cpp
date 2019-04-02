#include <iostream>
#include<cmath> 
#define max 4
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float determinante(float matriz[][max], float n);
float cofactor(float matriz[][max], float n, float fil, float colum);
float Transpuesta(float matriz[][max], float n, float det);
float resultadoF(float matrizT[][max], float det, float n);
int main()
{
	float matriz[max][max];
	float det, n = 4;
	cout << "\n ingrese los valores de la matriz :\n\n";
	for (int f = 0; f < n; f++) {
		for (int c = 0; c < n; c++) {
			cout << "[" << f << "]" << "[" << c << "]" << endl;
			cin >> matriz[f][c];
		}
	}

	cout << "revelando matriz : \n";
	for (int f = 0; f < n; f++) {
		for (int c = 0; c < n; c++) {
			cout << "\t" << matriz[f][c];
		}
		cout << "\n" << endl;
	}

	det = determinante(matriz, n);
	cout << " La determinante es :" << det << endl;
	Transpuesta(matriz, n, det);
	return 0;
}

float determinante(float matriz[][max], float n)
{
	float det = 0.0;
	int f = 0, i = 0;
	if (n == 1)
	{
		det = matriz[0][0];
	}
	else
	{

		for (int c = 0; c < n; c++)
		{
			det = det + matriz[0][c] * cofactor(matriz, n, f, c);
		}
	}
	return det;
}


float cofactor(float matriz[][max], float n, float fil, float colum)
{
	float matriz2[max][max];
	float nw = n - 1;
	int i = 0, nueva;
	int e = 0;
	int s = 0;
	for (int f = 0; f < n; f++)
	{
		for (int c = 0; c < n; c++)
		{
			if (f != fil && c != colum)
			{
				matriz2[e][s] = matriz[f][c];

				s++;
				if (s >= nw)
				{
					e++;
					s = 0;
				}
			}
		}
	}
	return pow(-1.0, fil + colum)* determinante(matriz2, nw);
}


float Transpuesta(float matriz[][max], float n, float det) {
	float matrizC[max][max];
	float matrizT[max][max];
	int f = 0, i = 0;
	if (n == 1)
	{
		det = matriz[0][0];
	}
	else
	{

		cout << endl << "la adjunta es : " << endl;
		for (int f = 0; f < n; f++) {

			for (int c = 0; c < n; c++)
			{
				matrizC[f][c] = cofactor(matriz, n, f, c);

				cout << "\t:" << matrizC[f][c];
				matrizT[c][f] = matrizC[f][c];
			}
			cout << "\n" << endl;
			i += 1;
			if (i < n) {
				i = 0;
			}
			else {
				f -= 1;
			}
		}
	}

	cout << endl << " La matriz transpuesta " << endl;
	for (int f = 0; f < n; f++) {
		for (int c = 0; c < n; c++) {
			cout << "\t:" << matrizT[f][c];
		}
		cout << "\n" << endl;
	}
	resultadoF(matrizT, det, n);
	return 0;
}


float resultadoF(float matrizT[max][max], float det, float n) {
	float matrizb[max][max];
	int ent;
	float dec, veri;
	if (det != 0) {
		cout << "El resultado de la multiplicacion de la matriz ingresada entre la determinante  es : " << endl;
		for (int f = 0; f < n; f++) {
			for (int c = 0; c < n; c++) {
				matrizb[f][c] = matrizT[f][c] / det;
				dec = matrizb[f][c];
				ent = dec;
				veri = dec - ent;
				if (veri != 0) {
					cout << "\t" << matrizT[f][c] << "/" << det;
				}
				else {
					cout << "\t" << matrizb[f][c];
				}
			}
			cout << "\n" << endl;
		}
	}
	else {
		cout << "error no se puede dividir entre cero";
	}
	return 0;
}
