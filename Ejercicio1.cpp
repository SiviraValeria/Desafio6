//Ejercicio 1. Escribe un programa que genere 20 numeros enteros aleatorios entre 0 y 99 y los almacene en un array. El programa debe crear un nuevo array con los numeros primos que haya en esos 20 numeros. Luego debe mostrar los dos arrays.
#include <iostream>
#include <stdlib.h> //Libreria necesaria para la funcion srand de la generacion de numeros aleatorios.
#include <time.h> // La libreria time.h permite la generacion de la semilla de la funcion srand().
using namespace std;

//Prototipo de Funcion

int GenerarNumAleatorios(int,int); //Prototipo de la funcion que se encargara de generar los numeros aleatorios.
void ArrayNumsAleatorios(); //Prototipo de la funcion que se encargara de almacenar los numeros aleatorios generados y mostrar el array que los contiene.
bool NumeroPrimo(int); //Funcion que ayudara a determinar que numeros del array de numeros aleatorios es o no primo.
void ArrayPrimos(); //Funcion que se encargara de introducir y mostrar el array con los numeros primos extraidos.

int limInferior=0,limSuperior=99; //Estas dos variables se presentan en tipo global porque se necesitaran en otras funciones del programa para obtener los limites de los numeros aleatorios.
int NumsAleatorios[20]; //Esta es la variable que contiene el array de los 20 espacios donde se almacenaran los numeros aleatorios. Se declara de tipo global porque se utilizara en otras funciones.

//Funcion Principal
int main(){

    srand(time(NULL)); //Inicializamos el proceso de numeros aleatorios con la funcion predeterminada srand(time(NULL)) pues se basa en generar una semilla en tiempo actual.

    cout<<"\n\t---Mostrando Arrays---\n"; //Este es un texto para mostrar los Arrays y se vea de manera mas ordenada.
    ArrayNumsAleatorios(); //Llamamos a nuestra funcion ArrayNumsAleatorios que se encargara de almacenar y mostrar el array con los numeros aleatorios generados comprendidos entre 0 y 99.
    ArrayPrimos(); //Finalmente se llama a la funcion ArrayPrimos que almacenara y mostrara los numeros primos extraidos del primer array.
    
    system("pause");
    return 0; //Fin del programa
}
//Declaracion de funcion
int GenerarNumAleatorios(int limInferior=0,int limSuperior=99){ //Tenemos dos parametros en la declaracion de esta funcion. Los limites inferior y superior que tendran los numeros aleatorios generados. La funcion es de tipo Int porque retornara los numeros enteros obtenidos con esos parametros.
    return limInferior + rand() % (limSuperior + 1 - limInferior); //Retorno los numeros generados.
}
void ArrayNumsAleatorios(){ //En esta funcion de tipo void, vamos a almacenar los numeros en su respectivo array y mostrarlos.
    cout<<"\t\nArray de Numeros enteros aleatorios: \n{ "; //Texto mostrativo del array 
    for (int i = 0; i < 20; i++){ //Con este ciclo for muestro el array de los numeros. Lo inicio en el indice 0 hasta el 20 luego en la variable NumsAleatorios[i] (array) almaceno los numeros aleatorios llamando a la funcion GenerarNumsAleatorios.
        NumsAleatorios[i] = GenerarNumAleatorios(limInferior,limSuperior);
        cout<<NumsAleatorios[i]<<" "; //Muestro los numeros con una separacion en cada uno.
    }
    cout<<"}"<<endl; //Esta linea de texto es para cerrar el array, es simplemente para que se vea mejor a la vista.
}
bool NumeroPrimo(int numero){ //En esta declaracion de funcion, coloco como parametro un entero llamado numero en el que va a operar la funcion para saber si es primo.
    if (numero <= 1){
        return false; //Con este condicional pregunto al programa si el numero introducido es menor o igual a uno, pues de ser asi, no es primo. Por tanto, retorno false.
    }
    for (int i = 2; i * i <= numero; i++){ //Con este bucle se comprueba si el numero es primo. Se ejecuta desde i = 2 hasta que i * i sea menor o igual a numero. Esto significa que el bucle itera desde el numero 2 hasta la raiz cuadrada del numero dado.
        if (numero % i == 0){ //Dentro del bucle esta el condicional if pues se comprueba si "numero" es divisible por el valor actual de i. Si "numero" es divisible por i, significa que tiene un divisor distinto de 1 y sí mismo, por lo que no es primo.
            return false; //Asi que retorno false.
        } 
    }
    return true; //Una vez que el programa pase por ambos condicionales y no se cumplan, esto quiere decir que el numero es primo por tanto retorno true.
}
void ArrayPrimos(){ //Una vez obtenido los numeros primos, deben almacenarse y mostrarse en su respectivo array. Por tanto esta es la declaracion de la funcion ArrayPrimos de tipo void.
    int numerosPrimos[20], ContPrimos = 0; //Creo dos variables. Una que sera el Array que almacenara los numeros primos denominada numerosPrimos con 20 espacios por si los numeros generados llegan a ser todos primos. Luego creo otra variable que se llama ContPrimos, esta se encargara de contar los numeros primos encontrados, por tanto la inicializo en 0.

    for (int i = 0; i < 20; i++){ //Para contar los primos, inicio un bucle for en 0 hasta que sea menor a 20 y que vaya aumentando(i++) de esta manera hago un recorrido por el array. 
        if (NumeroPrimo(NumsAleatorios[i])){ //Aca hago un condicional que va a determinar que numeros son primos para poder almacernarlos en su array. Por tanto, llamo a la funcion NumeroPrimo(Declarada anteriormente de tipo bool) y le doy como parametro el array que contiene los numeros aleatorios. (Por esta razon, el array de numeros aleatorios lo coloque de manera global para poder usarlo en otras funciones)
            numerosPrimos[ContPrimos++] = NumsAleatorios[i]; //En este fragmento estoy almacenando en mi Array de numeros primos, el contador que me inicializo en 0, le doy la opcion de iterar bajo la condicional if para que vaya aumentando cuando consiga un primo. Luego igualo la variable a NumsAleatorios[i] para guardarlos en el array de numeros primos.
        }    
    }
    cout<<"\t\nArray de numeros primos: \n{ "; //Finalmente muestro el array de numeros primos.
    for (int i = 0; i < ContPrimos; i++){ //Para mostrarlo nuevamente utilizo un ciclo for hasta que sea menor al ContPrimos que es la cantidad de primos encontrados.
        cout<<numerosPrimos[i]<<" ";  // Los muestro dejando un espacio en cada uno.
    }
    cout<<"}"<<endl<<endl; //Finalizo con una linea de texto para que sea mas agradable a la vista.
}

//Alumno: Valeria Sivira.