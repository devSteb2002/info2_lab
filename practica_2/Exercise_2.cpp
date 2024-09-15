#include <iostream>
#include "problems.h"

using namespace std;

void fun_c(double *a, int n, double *promedio, double *suma);

void exercise_2(){
    double arr[5] = {2.4,3.2,5.1,7.68,8.99};
    double promedio = 0.0;
    double suma = 0.0;

    fun_c(arr, 5, &promedio, &suma);

    cout << promedio;

}

void fun_c(double *a, int n, double *promedio, double *suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++){
        *suma += *(a + i);
    }
    *promedio = *suma / n;
}

//incorrecta
// void fun_c(double *a, int n, double *promedio, double *suma){
//     int i;
//     suma = 0.0;
//     for (i = 0; i < n; i++)
//         suma += (a + i);
//     promedio = suma / n;
// }
