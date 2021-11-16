#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres),
 infectados(int), recuperados(int) y muertos(int).
Desarrollar una función llamada actualizarRecuperados que reciba el país y los recuperados del dia y que acumule
estos a los que ya tiene el país. La función no devuelve nada. /


/2.Crear una función que se llame invertirCadena que reciba una cadena de caracteres
como parámetro y su responsabilidad es invertir los caracteres de la misma.
Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU/


/3.Crear una función que se llame ordenarCaracteres que reciba una cadena de caracteres
 como parámetro y su responsabilidad es ordenarlos caracteres de manera ascendente dentro de la cadena.
Ejemplo si le pasamos "algoritmo" la deja como "agilmoort"
*/

typedef struct
{
    int id;
    char nombre[20];
    int infectados;
    int recuperados;
    int muertos;
} ePais;

void actualizarRecuperados (ePais* pais, int recuperados);
int invertirCadena (char* cadena);
int ordenarCaracteres(char* cadena);


int main()
{
    ePais argentina;
    char cadena[20] = "UTN-FRA";
    char cadenaBis[20] = "algoritmo";


    argentina.recuperados = 100;
    printf("%d\n", argentina.recuperados);
    actualizarRecuperados(&argentina, 200);
    printf("%d\n", argentina.recuperados);
    actualizarRecuperados(&argentina, 200);
    printf("%d\n", argentina.recuperados);

    invertirCadena(cadena);
    puts(cadena);

    ordenarCaracteres(cadenaBis);
    puts(cadenaBis);

    return 0;
}

void actualizarRecuperados (ePais* pais, int recuperados)
{
    if (pais != NULL && recuperados > 0)
    {
        pais->recuperados += recuperados;
    }
}

int invertirCadena (char* cadena)
{
    int todoOk=0;
    int i = 0;
    int j = strlen(cadena) - 1;
    char auxCad[20];
    strcpy(auxCad, cadena);

    if(cadena != NULL)
    {
        todoOk = 1;
        while(cadena [i] != '\0')
        {
            cadena[i] = auxCad[j];
            i++;
            j--;
        }

    }
    return todoOk;
}


int ordenarCaracteres( char* cadena)
{
    int todoOk=0;
    int tam;
    char aux;
    tam = strlen(cadena);

    if (cadena!= NULL )
    {
        for (int i = 0; i < tam -1; i++)
        {
            for (int j = i+1; j < tam; j++)
            {
                if ( cadena[i]>cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                }
            }
        }
        todoOk = 1;

    }
    return todoOk;
}
