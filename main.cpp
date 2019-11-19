//####################################################################################
// ARCHIVO             : main.cpp
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
// Archivo principal.
//
//////////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
//-----------------------------------------------------------------------------
#ifndef _WIN32
  # define _WIN32
#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
//  # define _LINUX
//#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "procesos.h"
#include "presentacion.h"
#include "juegoFacil.h"
#include "juegoModerado.h"
#include "juegoDificil.h"

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;

//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main()
{
    sys::randomize();
    memo();
    sys::msleep(3);
    bool salir = false;
    int opcion1;
    int opcion2;
    while(!salir)
    {
        sys::cls();                          //borro la pantalla
        menu1();                             //muestro el menu
        cin >> opcion1;
        if (cin.fail())
        {
            cout << endl <<
            "Opcion incorrecta, abra nuevamente el juego." << endl;
            return -1;
        }
        cin.ignore();
        sys::cls();
        switch(opcion1)
        {
            case 1:
            {
                menu2();
                cin >> opcion2;
                if (cin.fail())
                {
                    cout << endl <<
                    "Opcion incorrecta, abra nuevamente el juego." << endl;
                    return -1;
                }
                cin.ignore();
                sys::cls();
                bool corte = false;
                while(corte != true)
                {
                   switch(opcion2)
                   {
                       case 1:
                       {
                           juego_facil();
                           corte = true;
                       }break;
                       case 2:
                       {
                           juego_moderado();
                           corte = true;
                       }break;
                       case 3:
                       {
                           juego_dificil();
                           corte = true;
                       }break;
                       case 4:
                       {
                           corte = true;
                       }break;
                   }
                }
            }break;
            case 2:
            {
                ayuda();
            }break;
            case 3:
            {
                salir = true;
            }break;
            default:
            {
                cout << "Opcion incorrecta!!!";
            }break;
        }
        cin.get();
    }
    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

