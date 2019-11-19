//####################################################################################
// ARCHIVO             : juegoModerado.h
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
// Libreria del nivel de juego moderado.
//
//////////////////////////////////////////////////////////////////////////////////////
#ifndef JUEGOMODERADO_H_INCLUDED
#define JUEGOMODERADO_H_INCLUDED

#include <iostream>
#include "CSYSTEM/csystem.h"
#include "procesos.h"

using namespace std;

//-------------------------------------------------------------------------------------
// FUNCION   : void juego_moderado()
// ACCION    : juego de dificultad moderada.
// PARAMETROS: NADA
// DEVUELVE  : NADA
//-------------------------------------------------------------------------------------
void juego_moderado()
{
    const int M = 6;
    const int VM = 36;
    const int MMAX = 8;
    int n = 0, x = 0;
    int dato1, dato2;
    coincidencias = 0;
    resta = 40, ver = 0;
    tficha mat1[MMAX][MMAX];
    tficha mat2[MMAX][MMAX];
    iniMat(mat1, M, '?');
    iniMat(mat2, M, '?');
    char moderado[VM] = {'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I',
                         'J','J','K','K','L','L','M','M','N','N','O','O','P','P','Q','Q','R','R'};
    while(n != VM)
    {
        fil = sys::random(M);
        col = sys::random(M);
        if (mat1[fil][col].ficha == '?')
        {
            mat1[fil][col].ficha = moderado[x];
            n++;
            x++;
        }
    }
    while(resta != 0 && coincidencias != VM/2)
    {
        mostrar(mat2, M, resta);
        letra(mat1, mat2, M, a, b, resta);
        if ((a == 114) || (b == 114)) break;
        while(mat2[a][b].ficha != '?')
        {
            mostrar(mat2, M, resta);
            cout << "Ficha ocupada." << endl;
            sys::msleep(3);
            sys::cls();
            mostrar(mat2, M, resta);
            letra(mat1, mat2, M, a, b, resta);
            if ((a == 114) || (b == 114)) break;
        }
        if ((a == 114) || (b == 114)) break;
        dato1 = mat1[a][b].ficha;
        mat2[a][b].ficha = mat1[a][b].ficha;
        mostrar(mat2, M, resta);
        letra(mat1, mat2, M, c, d, resta);
        if ((c == 114) || (d == 114)) break;
        while(mat2[c][d].ficha != '?')
        {
            mostrar(mat2, M, resta);
            cout << "Ficha ocupada." << endl;
            sys::msleep(3);
            sys::cls();
            mostrar(mat2, M, resta);
            letra(mat1, mat2, M, c, d, resta);
            if ((c == 114) || (d == 114)) break;
        }
        if ((c == 114) || (d == 114)) break;
        dato2 = mat1[c][d].ficha;
        mat2[c][d].ficha = mat1[c][d].ficha;
        mostrar(mat2, M, resta);
        coincidencia(coincidencias, VM, dato1, dato2);
        if (dato1 != dato2)
        {
            cout << "No hay coincidencia." << endl;
            sys::msleep(3);
            sys::cls();
            mat2[a][b].ficha = '?';
            mat2[c][d].ficha = '?';
        }
        resta--;
        if (resta == 0)
        {
            cout <<  "Ha perdido, se acabaron los movimientos disponibles." << endl;
        }
    }
}

#endif // JUEGOMODERADO_H_INCLUDED
