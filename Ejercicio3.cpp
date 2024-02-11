//Ejercicio 3. Desarrolle un programa que lea por teclado 10 numeros enteros y los guarde en un Array. A continuacion, calcula y muestra por separado la media de los valores positivos y la de los valores negativos.
#include <iostream>
using namespace std;

//Prototipo de Funcion

void PedirNumeros(); //Prototipo de la Funcion para pedir los numeros al usuario, es de tipo void.
void MostrarMedia(); //Prototipo para mostrar la media obtenida de los numeros negativos y positivos del aray de numeros obtenido por el usuario.

int ArrayNumeros[10]; //Declaro una variable de tipo global que sera nuestro Array de numeros enteros. Es de tipo global porque sera utilizada en ambas funciones.

//Funcion Principal

int main(){

    PedirNumeros(); //Llamo a mi funcion de tipo void PedirNumeros para solicitar al usuario los 10 numeros enteros.
    MostrarMedia(); //Una vez obtenido los numeros, llamo a la Funcion MostrarMedia que se encargara de calcular y mostrar la media de los numeros positivos y negativos del Array.

    return 0; //Fin del programa.
}

//Declaracion de Funcion

void PedirNumeros(){ //En la declaracion de la funcion PedirNumeros utilizare un ciclo for para rellenar el array.
    for (int i = 0; i < 10; i++){ //Lo inicio en 0 hasta que sea menor a 10, es decir, los 10 numeros requeridos.
        cout<<i+1<<" Digite un numero entero positivo o negativo: "; //Pido al usuario los numeros.
        cin>>ArrayNumeros[i]; //Los almaceno en el Array de Numeros. La variable que cree de tipo global.
    }
}
void MostrarMedia(){ //Ahora calculo y muestro la media de los numeros obtenidos.

    //Para calcular la media, es necesario crear algunas variables.
    int ContPositivos=0, ContNegativos=0; // De tipo entero cree 2. Una para contar los numeros positivos encontrados en el Array y otra para contar los numeros Negativos.
    double SumaPositivos=0, SumaNegativos=0, MediaPositivos, MediaNegativos; // De tipo double cree 4 variables. Dos para almacenar la suma de los numeros negativos y otra para la suma de positivos. Y las otras dos, se encargaran de almacenar la media de cada uno de los valores.

    //Recorriendo el Array en busca de numeros negativos.
    for (int i = 0; i < 10; i++){ //Creo un ciclo for para recorrer el Array de Numeros.
        if (ArrayNumeros[i] < 0){ //Dentro del bucle agrego un condicional if que se encargara de determinar si hay numeros menores que 0 esto quiere decir que son negativos, al encontrarlos itero la variable ContNegativos.
            ContNegativos++; //Iteracion de Negativos
            SumaNegativos += ArrayNumeros[i]; //En la variable de SumaNegativos almacenare la suma de los numeros encontrados en el Array.
        }else if(ArrayNumeros[i] > 0){ //Con el condicional else if determino que si en el Array hay numeros mayores que cero, son positivos por tanto se itera la variable ContPositivos.
            ContPositivos++; //Iteracion de ContPositivos.
            SumaPositivos += ArrayNumeros[i]; //En la variable SumaPositivos almacenara la suma de los positivos encontrados en el Array.
        }
    }

    //Sacando la media de los negativos y positivos
    if (ContNegativos > 0){ //Ahora para la media, utilizo el condicional if. Si el ContNegativos es mayor a 0, es decir, si en el Array hubo numeros negativos, entonces procede a sacar la media.
        MediaNegativos = SumaNegativos / ContNegativos; //Saco la media de los negativos igualando la variable MediaNegativos a la suma de los numeros negativos entre la cantidad de numeros negativos obtenidos del Array.
    }else{ //En caso de que el ContNegativos sea 0 es decir, que no haya encontrado numeros negativos
        MediaNegativos = 0; //Le doy a la variable MediaNegativos un valor de 0;
    }
    if (ContPositivos > 0){ //Realizo lo mismo con los Positivos. Pregunto con el condicional si el ContPositivos es mayor a 0.
        MediaPositivos = SumaPositivos / ContPositivos; //A la variable MediaPositivos le almaceno la suma de los positivos entre la cantidad de positivos encontrados en el Array.
    }else{ //Si no hay numeros positivos encontrados es decir, el contador es 0, entonces la media es 0.
        MediaPositivos = 0; //Le doy el valor de 0 a la variable MediaPositivos.
    }

    //Muestro los resultados en pantalla y llamo a ambas variables: MediaPositivos para mostrar la media calculada y la MediaNegativos para mostrar la media de los negativos.
    cout<<"\n---Mostrando la Media de numeros Positivos y Negativos---"<<endl<<endl;
    cout<<"La media obtenida de los numeros Positivos es de: "<<MediaPositivos<<endl;
    cout<<"La media obtenida de los numeros Negativos es de: "<<MediaNegativos<<endl<<endl;
}

//Alumno: Valeria Sivira.