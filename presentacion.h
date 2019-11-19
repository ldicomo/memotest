//####################################################################################
// ARCHIVO             : presentacion.h
// AUTOR/ES            : Luis Antonio Dicomo
// VERSION             : 1.0
// FECHA DE CREACION   : 01/06/2018.
// ULTIMA ACTUALIZACION: 29/06/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//====================================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 16.01
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//====================================================================================
// DESCRIPCION:
// Libreria de presentaciones para interactuar con el usuario.
//
//////////////////////////////////////////////////////////////////////////////////////
#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include <iostream>
#include "CSYSTEM/csystem.h"
#include "procesos.h"

using namespace std;

struct tficha
{
    char ficha;
};

//-------------------------------------------------------------------------------------
// FUNCION   : void memo()
// ACCION    : muestra el nombre del juego.
// PARAMETROS: NADA
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void memo()
{
    cout << "*-----------------------------------------------------------*" << endl;
    cout << "                                                             " << endl;
    cout << "  @@   @@ @@@@@@ @@   @@   @@   @@@@@@ @@@@@@ @@@@@@ @@@@@@  " << endl;
    cout << "  @@@ @@@ @@     @@@ @@@ @@  @@   @@   @@     @@       @@    " << endl;
    cout << "  @@ @ @@ @@@@   @@ @ @@ @@  @@   @@   @@@@   @@@@@@   @@    " << endl;
    cout << "  @@   @@ @@     @@   @@ @@  @@   @@   @@         @@   @@    " << endl;
    cout << "  @@   @@ @@@@@@ @@   @@   @@     @@   @@@@@@ @@@@@@   @@    " << endl;
    cout << "                                                             " << endl;
    cout << "*-----------------------------------------------------------*" << endl;
    cout << endl;
}

//-------------------------------------------------------------------------------------
// FUNCION   : void menu1()
// ACCION    : muestra las distintas opciones.
// PARAMETROS: NADA
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void menu1()
{
    cout << "*-------------------------------------*" << endl;
    cout << "*--------- Ingese una opcion ---------*" << endl;
    cout << "*                                     *" << endl;
    cout << "* 1 - Jugar                           *" << endl;
    cout << "* 2 - Ayuda                           *" << endl;
    cout << "* 3 - Salir                           *" << endl;
    cout << "*-------------------------------------*" << endl;
    cout << endl;
}

//-------------------------------------------------------------------------------------
// FUNCION   : void menu2()
// ACCION    : muestra las distintas opciones de complejidad.
// PARAMETROS: NADA
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void menu2()
{
    cout << "*-------------------------------------*" << endl;
    cout << "*----- Elija la opcion deseada -------*" << endl;
    cout << "*                                     *" << endl;
    cout << "* 1 - Facil:    20 movimientos        *" << endl;
    cout << "* 2 - Moderado: 40 movimientos        *" << endl;
    cout << "* 3 - Dificil:  60 movimientos        *" << endl;
    cout << "* 4 - Volver al menu anterior                           *" << endl;
    cout << "*-------------------------------------*" << endl;
    cout << endl;
}

//-------------------------------------------------------------------------------------
// FUNCION   : void ayuda()
// ACCION    : muestra de que consiste el juego.
// PARAMETROS: NADA
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void ayuda()
{
    cout << "                                                                           " << endl;
    cout << "+------------------------------Menu de Ayuda------------------------------+" << endl;
    cout << "|   Reglas del juego:                                                     |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "| * El objetivo del juego es encontrar las fichas identicas.              |" << endl;
    cout << "|   Por ejemplo: si en el tablero encuentro la letra A debo seleccionar   |" << endl;
    cout << "|   las otras coordenadas donde este la misma A.                          |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "| * Para jugar debemos marcar coordenadas (filas y columnas) utilizando   |" << endl;
    cout << "|   los numeros del teclado. El usuario eligira primero la fila y luego   |" << endl;
    cout << "|   la columna.                                                           |" << endl;
    cout << "|   Ademas posee la opcion flash, que muestra durante 3 segundos como     |" << endl;
    cout << "|   estan las fichas ocultas distribuidas en el tablero.                  |" << endl;
    cout << "|   Para activar esta opcion debe presionar la tecle f durante el juego.  |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "| * Para salir del juego en cualquier momento ingrese la tecla S.         |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "| * El usuario depende de 20, 40 o 60 movimientos dependiendo de la       |" << endl;
    cout << "|   dificultad seleccionada. El juego termina al descubrir todas las      |" << endl;
    cout << "|   fichas, resultando ganador, o al llegar a la cantidad de movimientos, |" << endl;
    cout << "|   acorde a la opcion elegida, lo cual seria la perdida del juego.       |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "| * Esperemos disfrute del juego.                                         |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "|---------------Presione Enter para volver al menu Anterior---------------|" << endl;
    cout << "+-------------------------------------------------------------------------+" << endl;
    cout << endl;
}


//-------------------------------------------------------------------------------------
// FUNCION   : void mostrar(tficha mat[8][8], int nivel, int resta)
// ACCION    : muestra la matriz.
// PARAMETROS: tficha mat[8][8] -> matriz de 8 x 8.
//             int nivel, int resta -> nivel de dificultad y movimientos disponibles.
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void mostrar(tficha mat[8][8], int nivel, int resta)
{
    cout << "Movimientos disponibles: " << resta << endl;
    cout << "Tecla flash: f. " << "Salir del juego: s." << endl << endl;

    cout << " F/C    ";
    for(int x = 0; x < nivel; x++)
    {
        cout << x+1 << "     ";
    }
    cout << endl;
    for(int i = 0; i < nivel; i++)
    {
        if (i < nivel)
        {
            cout << "     +";
            for(int x = 0; x < nivel; x++)
            {
                cout << "-----+";
            }
        }
        cout << endl;
        cout << "  " << i+1 << "  |";
        for(int j = 0; j < nivel; j++)
        {
            cout << "  " << mat[i][j].ficha << "  |";
        }
        cout << endl;
    }
    cout << "     +";
    for(int x = 0; x < nivel; x++)
    {
        cout << "-----+";
    }
    cout << endl << endl;
}

#endif // PRESENTACION_H_INCLUDED
