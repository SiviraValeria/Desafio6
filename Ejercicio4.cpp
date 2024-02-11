//Ejercicio 4. Desarrolle un programa que permita ingresar en un arreglo de tipo string los nombres de 10 estudiantes, en otros 3 arreglos las tres notas correspondientes a los 3 cortes cursados en la asignatura programacion 1 y en el ultimo arreglo debe calcular la nota final de cada estudiante procesado. Organice la informacion mostrada en forma de tabla. Al final debe mostrar el nombre del estudiante, las 3 notas y la nota final. Identifique cada item (Estudiantes, Nota 1er Corte, Nota 2do Corte, Nota 3er Corte, Nota Final) para reconocer visualmente el resultado presentado.
#include <iostream>
#include <string.h> //La libreria string para utilizar cadena de texto.
using namespace std;

//Prototipo de Funcion

void PedirDatosEstudiantes(); //Prototipo de funcion void para pedir los datos de los estudiantes.
void MostrarDatos(); //Prototipo void para mostrar los datos de los estudiantes.

//Los Arrays los declaro de tipo global porque los usare en ambas funciones.
string Nombre[10]; //El primer array de tipo cadena llamado nombre que contiene los 10 espacios de los estudiantes.
float Notas1erCorte[10],Notas2doCorte[10],Notas3erCorte[10],NotaFinal[10]; //Los otros 4 Arrays son de tipo float para obtener las notas de los 3 cortes y la nota final cada Array con 10 espacios para los 10 estudiantes.

//Funcion Principal

int main(){

    PedirDatosEstudiantes(); //Llamo la funcion PedirDatosEstudiantes para solicitar la informacion requerida de cada uno.
    MostrarDatos(); //Llamo a la funcion MostrarDatos para mostrar la informacion obtenida de cada uno en forma de tabla.

    return 0; //Fin del programa.
}

//Declaracion de Funcion

void PedirDatosEstudiantes(){ //Declaracion de Funcion para pedir los datos.
    for (int i = 0; i < 10; i++){ //Creo un bucle for para almacenar el primer array que es de tipo cadena donde almacenare los nombres de cada estudiante. Lo inicializo en 0 hasta 10.
        cout<<"Digite el nombre del estudiante "<<i+1<<" sin espacios: "; cin>>Nombre[i]; //Solicito el nombre y lo guardo en su respectivo array Nombre[i].
    }
    for (int i = 0; i < 10; i++){ //Para las notas, hago lo mismo. Es decir, otro ciclo for para introducir en los Arays de las notas cada una de los 10 estudiantes. Una vez solicitadas las 3 notas de los 10 estudiantes, se termina el ciclo.
        cout<<"Ingrese la nota del 1er Corte para "<<Nombre[i]<<": "; cin>>Notas1erCorte[i]; //Solicito la nota del primer corte y la almaceno en su respectivo Array.
        cout<<"Ingrese la nota del 2do Corte para "<<Nombre[i]<<": "; cin>>Notas2doCorte[i]; //Solicito la nota del segundo corte y la almaceno en su respectivo Array.
        cout<<"Ingrese la nota del 3er Corte para "<<Nombre[i]<<": "; cin>>Notas3erCorte[i]; //Solicito la nota del tercer corte y la almaceno en su respectivo Array.
    }
    for (int i = 0; i < 10; i++){ //Por ultimo, creo otro bucle for que generara la nota final de cada estudiante.
        //Calculo la Nota Final
        NotaFinal[i] = (Notas1erCorte[i] + Notas2doCorte[i] + Notas3erCorte[i]) / 3; //Para la nota final, almaceno en el Array NotaFinal[i] la suma de las 3 notas guardadas en cada Array y lo divido en 3. Esto dentro del bucle for para que genere la NotaFinal de los 10 estudiantes.
    }
}
void MostrarDatos(){ //Declaracion de funcion para mostrar los datos.
    cout<<"\n\n\tMostrando resultados de los Estudiantes"<<endl<<endl; //Titulo.
    cout<<"---------------------------------------------------------------"<<endl; 
    cout<<"Estudiantes|Notas1erCorte|Notas2doCorte|Notas3erCorte|NotaFinal"<<endl; //Todo este texto es para visualizarlo en forma de tabla de acuerdo a lo solicitado.
    cout<<"-----------|-------------|-------------|-------------|---------"<<endl;
    for (int i = 0; i < 10; i++){ //Para mostrar el contenido de los Arrays utilizo nuevamente otro ciclo for. Donde voy mostrando en pantalla un espacio entre cada uno y por supuesto llamando a cada Array con su respectivo nombre. Esto mostrara los resultados de los Arrays que contienen los datos de los 10 estudiantes.
        cout<<Nombre[i]<<"    |      "<<Notas1erCorte[i]<<"     |      "<<Notas2doCorte[i]<<"      |     "<<Notas3erCorte[i]<<"      |     "<<NotaFinal[i]<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }    
}

//Alumno: Valeria Sivira.