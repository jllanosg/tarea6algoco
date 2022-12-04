#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void alinearSecuencias(string A, string B){
    
    int i,j;
    int m = A.length();
    int n = B.length();

    // matriz para guardar los valores
    int matriz[n+m+1][n+m+1] = {0};

    // rellenando la matriz con los valores iniciales
    // F_0j = -2 * j
    // F_i0 = -2 * i
    for (i = 0; i <= (n+m); i++)
    {
        matriz[i][0] = i * -2;
        matriz[0][i] = i * -2;
    }

    // Aplicamos la recurrencia 

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                matriz[i][j] = matriz[i - 1][j - 1] + 2;
            }
            else
            {
                matriz[i][j] = max({matriz[i - 1][j - 1] - 1,matriz[i - 1][j] - 2,matriz[i][j - 1] - 2});
            }
        }
    }
     
    i = m; j = n;
 
    string A_final, B_final;

    // recorremos la matriz de [m][n] a [0][0], 
    while ( !(i == 0 || j == 0))
    {
        if (A[i - 1] == B[j - 1])
        {
            // Significa que hubo match
            A_final += A[i - 1];
            B_final += B[j - 1];

            // El movimiento fue diagonal por lo que se reducen ambos contadores
            i--; j--;
        }
        else if (matriz[i - 1][j - 1] - 1 == matriz[i][j])
        {
            // Significa que hubo diferente caracter
            A_final += A[i - 1];
            B_final += B[j - 1];

            // El movimiento fue diagonal por lo que se reducen ambos contadores
            i--; j--;
        }
        else if (matriz[i - 1][j] - 2 == matriz[i][j])
        {
            // significa que hubo gap en B
            A_final += A[i - 1];
            B_final += ' ';

            // El movimiento fue hacia arriba
            i--;
        }
        else if (matriz[i][j - 1] - 2 == matriz[i][j])
        {
            // significa que hubo gap en A
            A_final += ' ';
            B_final += B[j - 1];

            // El movimiento fue hacia la derecha
            j--;
        }
    }

    // Revertimos los strings, ya que los fuimos acumulando de manera inversa.

    reverse(A_final.begin(), A_final.end());
    reverse(B_final.begin(), B_final.end());

    // Finalmente mostramos la solución.
    cout<<A_final<<endl<<B_final<<endl<<matriz[m][n]<<endl;
}

int main(int argc, char** argv){
    string A = argv[1];
    string B = argv[2];
    alinearSecuencias(A,B);
    return 0;
}