//Ejercicio 2. Escribe un programa que genere al azar 20 numeros enteros comprendidos entre 0 y 9. Estos numeros se deben introducir en un array de 4 filas por 5 columnas. El programa mostrara las sumas parciales de filas y columnas igual que si de una hoja de calculo se tratara. La suma total debe aparecer en la esquina inferior derecha.
#include <iostream>
#include <stdlib.h> //Libreria para utilizar la funcion srand de la generacion de numeros aleatorios.
#include <time.h> //Libreria para generar la semilla en tiempo real.
using namespace std;

//Prototipo de Funcion
int GenerarNumsAleatorios(int,int); //Prototipo de funcion que generara los numeros aleatorios. Le doy como parametros dos enteros que seran los limites superior e inferior.
void Tabla(); //Prototipo de tipo void que mostrara en pantalla la matriz.

int limInferior = 0, limSuperior = 9; //Para generar los numeros aleatorios cree dos variables de tipo global, pues las necesitare llamar en ambas funciones. Por tanto, las declaro de manera global dandoles el valor solicitado. El limite inferior de numeros sera de 0 y el limite superior el numero 9.

//Funcion Principal

int main(){

    srand(time(NULL)); //La funcion srand(time(NULL)) generara los numeros aleatorios en tiempo real.

    Tabla(); //Llamo a mi funcion de tipo void llamada Tabla que contiene toda mi matriz.

    system("pause");
    return 0; //Fin del programa.
}

//Declaracion de Funcion
int GenerarNumsAleatorios(int limInferior,int limSuperior){ //Para la declaracion de esta funcion, le di como parametros los dos enteros que seran los limites inferior y superior del generador de numeros aleatorios.
    return limInferior + rand() % (limInferior + 1 - limSuperior); //Retorno la funcion predeterminada rand() que me genere los numeros aleatorios dandole los parametros de 0 a 9.
}
void Tabla(){ //En la declaracion de la funcion Tabla de tipo void, viene todo el proceso de la matriz.

    int matriz[4][5], sumaTotal = 0, sumasFilas[4], sumasColumnas[5]; //Comienzo creando las variables de tipo local. Primero mi vector o array principal el cual contiene los valores de mi matriz de 4 filas por 5 columnas. Luego creo otras 3 variables, una para la suma parcial de filas de la matriz, otra para la suma parcial de columnas y una ultima para la suma total de filas y columnas.

    for (int i = 0; i < 4; i++){ //Para rellenar mi matriz de numeros enteros aleatorios, es necesario crear un ciclo for que inicie en 0 hasta que sea menor al numero de filas de la matriz, en este caso, 4.
        for (int j = 0; j < 5; j++){ //Como se trata de una matriz, se requiere un for anidado es decir, dentro del for, creo otro ciclo for que permitira la creacion de las columnas. En este caso la variable de iteracion sera la "j". La inicio en 0 hasta el numero de columnas de la matriz, es decir, 5.
            matriz[i][j] = GenerarNumsAleatorios(limInferior,limSuperior); //Para rellenarla utilizo la variable de mi matriz con las iteraciones y almaceno los numeros aleatorios. Para esto llamo a mi funcion GenerarNumsAleatorios y le doy como parametros los limites inferior y superior.
        }
    }

    cout<<"\n ____Mostrando Matriz____\n\n"; //Una vez rellenada la matriz, se muestra.

    for (int i = 0; i < 4; i++) { //Creo un ciclo for para las filas que inicie en 0 hasta que sea menor a 4. Estos ciclos anidados son para recorrer la matriz y hacer la suma parcial de las filas.
    // Calcular la suma de la fila actual utilizando mi variable de sumasFilas.
    sumasFilas[i] = 0; //La inicio en 0
    for (int j = 0; j < 5; j++) { //Utilizo el for anidado para las columnas. 
      sumasFilas[i] += matriz[i][j]; //Luego, en la variable de sumasFilas voy a almacenar la suma de los valores de la matriz(filas).
      sumaTotal += matriz[i][j]; //Y a la variable de suma total, le almaceno los valores de la suma de las filas.
    }

    // Imprimir la fila actual
    for (int j = 0; j < 5; j++) { //Utilizo el ciclo for para mostrar las filas.
      cout<<matriz[i][j]<<"    "; //Muestro las filas de mi matriz y dejo un espacio en cada una de ellas.
    }

    // Imprimir la suma de la fila actual
    cout<<" "<< sumasFilas[i]<<endl; //Ahora imprimo la suma de las filas. Utilizando la variable sumasFilas[i] que contiene la suma de cada una y un salto de linea para la siguiente fila. Por eso, todo este proceso va dentro de un solo for, pues se realizara el mismo proceso hasta que haya recorrido todas las filas de la matriz.
  }

  // Recorrer las columnas
  for (int j = 0; j < 5; j++) { //Utilizo otro bucle for pero ahora para las columnas es decir, hasta 5.
    // Calcular la suma de la columna actual
    sumasColumnas[j] = 0; //Inicio mi variable de sumasColumnas en 0.
    for (int i = 0; i < 4; i++) { //El for anidado ahora para las filas, es decir, hasta que sea menor a 4.
      sumasColumnas[j] += matriz[i][j]; //Ahora el mismo proceso que realice con las filas. En mi variable sumasColumnas[j] almacenare los valores de las columnas de mi matriz.
      sumaTotal += matriz[i][j]; //A la variable sumaTotal que ya contiene la suma de las filas, ahora le almacenare la suma de las Columnas de la matriz.
    }
    // Imprimir la suma de la columna actual
    cout<<sumasColumnas[j]<<"   "; //Ahora muestro la suma parcial de las columnas y un espacio en cada una.
  } //Cierro mi ciclo for que terminara hasta que se acaben las columnas de la matriz.

  // Imprimir la suma total
  cout<<" "<<sumaTotal<<endl<<endl;  //Una vez terminada la matriz y la sumas parciales de filas y columnas, imprimo la suma total. Con un cout, un espacio y llamo a mi variable sumaTotal.
}

//Alumno: Valeria Sivira.