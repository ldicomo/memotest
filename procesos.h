//####################################################################################
// ARCHIVO             : procesos.h
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
// Libreria de funciones de procesos.
//
//////////////////////////////////////////////////////////////////////////////////////
#ifndef PROCESOS_H_INCLUDED
#define PROCESOS_H_INCLUDED

#include <iostream>
#include "CSYSTEM/csystem.h"
#include "presentacion.h"

using namespace std;

int  a, b, c, d, fil, col, nivel, ver = 0;
int coincidencias, resta;

//------------------------------------------------------------------------------------
// FUNCION   : int strToInt(char* cadena)
// ACCION    : convierte una cadena de caracteres a un numero entero.
// PARAMETROS: cadena --> cadena para convertir en un numero entero.
// DEVUELVE  : el numero entero.
//------------------------------------------------------------------------------------
int strToInt(char* cadena)
{
    int i = 0;
    int n = 0;
    int num[50];
    int numero = 0;
    while(cadena[i] != '\0')
    {
        switch(cadena[i])
        {
            case '1': {num[i] = 1;} break;
            case '2': {num[i] = 2;} break;
            case '3': {num[i] = 3;} break;
            case '4': {num[i] = 4;} break;
            case '5': {num[i] = 5;} break;
            case '6': {num[i] = 6;} break;
            case '7': {num[i] = 7;} break;
            case '8': {num[i] = 8;} break;
            case '9': {num[i] = 9;} break;
            case '0': {num[i] = 0;} break;
            case 'f': {num[i] = 102;} break;
            case 's': {num[i] = 115;} break;
        }
        i++;
        n++;
    }
    int m = 1;
    for(int i = n-2; i >= 0; i--)
    {
        m *= 10;
        num[i] *= m;
        numero += num[i];
    }
    numero += num[n-1];
    return numero;
}

//----------------------------------------------------------------------------------------
// FUNCION   : iniMat(tficha mat1[8][8], int nivel, char a)
// ACCION    : mostrar la matriz que corresponda.
// PARAMETROS: tficha mat[8][8] -> la matriz de 8 x 8.
//             int nivel --> el nivel de dificultad.
//             char a --> el caracter a insertar en la ficha.
// DEVUELVE  : NADA
//----------------------------------------------------------------------------------------
iniMat(tficha mat[8][8], int nivel, char a)
{
    for(int i = 0; i < nivel; i++)
    {
        for(int j = 0; j < nivel; j++)
        {
            mat[i][j].ficha = a;
        }
    }
}

//----------------------------------------------------------------------------------------
// FUNCION   : void str_int(tficha mat1[8][8], tficha mat2[8][8],
//             int nivel, int n, int &ac, int &ver)
// ACCION    : tocando la f, aparecen por 3 segundos en la matriz, las letras tapadas.
//           : ademas se convierte un caracter que es numero a entero.
// PARAMETROS: tficha mat1[8][8] --> matriz con pares de letras puestas aleatorias.
//           : tficha mat2[8][8] --> matriz de usuario.
//             int n, int &ac, int &ver --> variables de valor y referencia.
// DEVUELVE  : NADA
//----------------------------------------------------------------------------------------
void str_int(tficha mat1[8][8], tficha mat2[8][8],
             int nivel, int n, int &ac, int &ver)
{
    char c[30];
    cin.getline(c, 30);
    ac = strToInt(c);
    if (ac == 102 && ver == 0)
    {
        sys::cls();
        mostrar(mat1, nivel, n);
        cout << "MODO FLASH, DURACION 3S" << endl;
        sys::msleep(3);
        sys::cls();
        mostrar(mat2, nivel, n);
        ver++;
    }
    else if (ac == 102 && ver > 0)
    {
        cout << "EL MODO FLASH YA FUE UTILIZADO" << endl;
        sys::msleep(3);
        sys::cls();
        mostrar(mat2, nivel, n);
    }
}

//----------------------------------------------------------------------------------------
// FUNCION   : void letra(tficha mat1[8][8], tficha mat2[8][8], int nivel,
//             int &ac, int &bd, int resta)
// ACCION    : invita al usuario a ingresar una fila y una columna.
// PARAMETROS: tficha mat1[8][8] --> matriz con pares de letras puestas aleatorias.
//             tficha mat2[8][8] --> matriz de usuario.
//             int &ac, int &bd, resta --> variables de referencia y valor.
// DEVUELVE  : NADA
//----------------------------------------------------------------------------------------
void letra(tficha mat1[8][8], tficha mat2[8][8], int nivel,
            int &ac, int &bd, int resta)
{
    cout << "Ingrese una fila: ";
    str_int(mat1, mat2, nivel, resta, ac, ver);
    while(ac == 102)
    {
        cout << "Ingrese una fila: ";
        str_int(mat1, mat2, nivel, resta, ac, ver);
        if (ac == 115) break;
    }
    while((ac >= nivel+1 || ac < 1) && (ac != 115))
    {
        cout << "Valor incorrecto.";
        sys::msleep(3);
        sys::cls();
        mostrar(mat2, nivel, resta);
        cout << "Ingrese una fila: ";
        str_int(mat1, mat2, nivel, resta, ac, ver);
        if (ac == 115) break;
        while(ac == 102)
        {
            cout << "Ingrese una fila: ";
            str_int(mat1, mat2, nivel, resta, ac, ver);
            if (ac == 115) break;
        }
    }
    cout << endl << "Ingrese una columna: ";
    str_int(mat1, mat2, nivel, resta, bd, ver);
    while(bd == 102)
    {
        cout << "Ingrese una fila: " << ac << endl << endl;
        cout << "Ingrese una columna: ";
        str_int(mat1, mat2, nivel, resta, bd, ver);
        if (bd == 115) break;
    }
    while((bd >= nivel+1 || bd < 1) && (bd != 115))
    {
        cout << "Valor incorrecto." << endl << endl;
        sys::msleep(3);
        sys::cls();
        mostrar(mat2, nivel, resta);
        cout << "Ingrese una fila: " << ac << endl << endl;
        cout << "Ingrese una columna: ";
        str_int(mat1, mat2, nivel, resta, bd, ver);
        if (bd == 115) break;
        while(bd == 102)
        {
            cout << "Ingrese una fila: " << ac << endl << endl;
            cout << "Ingrese una columna: ";
            str_int(mat1, mat2, nivel, resta, bd, ver);
            if (bd == 115) break;
        }
    }
    ac -= 1;
    bd -= 1;
    sys::cls();
}

//---------------------------------------------------------------------------
// FUNCION   : void coincidencia(int &coincidencias, int n, int dato1, int dato2)
// ACCION    : avisa cuando hay una coincidencia entre 2 letras.
// PARAMETROS: int n -> total de coincidencias a lograr.
//             int dato1, int dato2 -> datos a comparar.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void coincidencia(int &coincidencias, int n, int dato1, int dato2)
{
    if (dato1 == dato2)
    {
        cout << "Hay coincidencia!!!" << endl;
        sys::msleep(3);
        sys::cls();
        coincidencias ++;
        if (coincidencias == n / 2)
        {
            cout <<  "Felicitaciones, total de coincidencias!!!" << endl;
        }
    }
}

#endif // PROCESOS_H_INCLUDED
