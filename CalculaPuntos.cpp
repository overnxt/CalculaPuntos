/* **************************** */
/*  Edward Calderon Rios        */
/*  Cedula 1-1060-0067          */
/*  UNED Costa Rica             */
/*  Tarea 2                     */
/*  Calculo de puntos           */
/*  Juego de Dardos version 1.0 */
/*  La Sanguijuela Testaruda    */
/*  Segundo Cuatrimestre 2017   */
/* **************************** */


/*
Faltantes

    Generar la salida de la tabla de castigos
    Generar reportes en juego grupal
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::system;

#include <string>
using std::string;

//Variables Globales
int const tamanoArreglo2 = 8;

//Prototipos
void menu( );//Para el menu de inicio
void mensajesError( const int );//Para el menejo de los errores
void centraPantalla( const int );//Para el centrado en pantalla
void juegoIndividual( int &, int &, int &, int & );//Para la opcion del juego individual
void ingresoPuntos( int &, const int &, const string & );//Para el ingreso de puntos por el cliente
void validaRegaliasIndividual( const int & );//Para la verificacion si se gano regalias
void juegoGrupal( string [ ] [ tamanoArreglo2 ], int &, int [ ][ tamanoArreglo2 ] );//Para la opcion del juego grupal
void validaContinuar( char & );//Para procesar si se desea continuar ingresando juegos
void estadisticasGenerales( const int &, const int & );//Para presentar las estadisticas de juego
void ingresaNombresJugadoresGrupal( const int &, string [ ][ tamanoArreglo2 ], const int & );//Para ingresar los nombres de los jugadores al arreglo
void ingresoPuntosArreglo( const int &, const int &, int [ ][ tamanoArreglo2 ], string [ ][ tamanoArreglo2 ] );//Para ingresar el puntaje al arreglo
void ordenaArreglos( const int &, const int &, string [ ][ tamanoArreglo2 ], int [ ][ tamanoArreglo2 ] );//Para ordenar el arreglo

int main()
{
    centraPantalla( 0 );
    centraPantalla( 1 );
	cout << "Bienvenido al programa \"Conteo de Puntos en el Juego de Dardos\"";
	cin.get();

    menu( );

	return 0;
}

//Funciones

//Para desplegar el menu de inicio
void menu( )
{
    //Variables para el juego individual
    int contadorJugadoresIndividual = 0;//Contador de jugadores del día
	int puntosTotalesJugadorIndividual = 0; //Contador de puntos obtenidos por jugador
	int puntosTotalesIndividual = 0; //Contador de puntos totales por todos los jugadores del día
	int puntosTurnoJugadorIndividual = 0; //Variable de puntos obtenidos en el turno y validar el numero

    //Variables para el juego grupal
	int const tamanoArreglo1 = 10;
	string arregloNombresJugadores[ tamanoArreglo1 ][ tamanoArreglo2 ] = { "\0" };//Arreglo para los nombres
    int arregloPuntosJugadores[ tamanoArreglo1 ][ tamanoArreglo2 ] = { 0 };//Arreglo para el puntaje
    int rondasJugadas = 0;//cuenta las rodas que se hayan jugado

    int opcionMenu = 0;

    while (opcionMenu != 4)
    {
            centraPantalla( 10 );
            centraPantalla( 0 );
            centraPantalla( 3 );
            cout << "Seleccione la opcion:\n\n";
            centraPantalla( 2 );
            cout << "1. Juego Individual\n\n";
            centraPantalla( 2 );
            cout << "2. Juego Grupal\n\n";
            centraPantalla( 2 );
            cout << "3. Estadisticas Generales\n\n";
            centraPantalla( 2 );
            cout << "4. Salir\n\n";
            centraPantalla( 3 );
            cout << "OPCION: ";
            cin >> opcionMenu;

            if ( opcionMenu < 1 || opcionMenu > 4 )
                mensajesError( 3 );
            else
                switch ( opcionMenu )
                {
                case 1:
                    juegoIndividual( contadorJugadoresIndividual, puntosTotalesJugadorIndividual, puntosTurnoJugadorIndividual, puntosTotalesIndividual );
                    break;
                case 2:
                    juegoGrupal( arregloNombresJugadores, rondasJugadas, arregloPuntosJugadores );
                    break;
                case 3:
                    estadisticasGenerales( contadorJugadoresIndividual, puntosTotalesIndividual );
                    break;
                case 4:
                    estadisticasGenerales( contadorJugadoresIndividual, puntosTotalesIndividual );
                    break;
        }
    }
}

//Para la presentacion de las estadisticas del juego
void estadisticasGenerales( const int &contJugIndi, const int &punTotIndi )
{
    centraPantalla( 10 );
    centraPantalla( 0 );
    centraPantalla( 2 );

    //Salida de cantidad de jugadores y promedio del dia
    if ( contJugIndi > 0 )
    {
        cout << "Cantidad de jugadores en juego individual: " << contJugIndi << endl;
        centraPantalla( 2 );
        cout << "Promedio de puntos en juego individual: " << ( punTotIndi / contJugIndi ) << endl;//Calculo del promedio de puntos
    }

    else
    {
        cout << "No hubieron juegos individuales";
    }

    cin.get();
    cin.get();
}

//Para manejar las salidas de error
void mensajesError( const int codError )
{
    centraPantalla( 0 );
    centraPantalla( 1 );
    switch ( codError )
    {
        case 1://Mensaje de error para el juego individual al validad los valores que se pueden ingresar
            cout << "Solo puede usar los valores 10, 5, 4, 3, 2, 1, 0" << endl;
            break;

        case 2://Mensaje de error para poder validar las salidas con S o N
            cout << "Solo puede usar las letras \"s\" para continuar y \"n\" para salir" << endl;
            break;

        case 3://Mensaje de error para el menu principal donde solo puede usar numeros del 1 al 3
            cout << "Solo puede usar numeros del 1 al 3";
            break;

        case 4://Mensaje de error para el juego grupal con la cantidad de jugadores que se pueden ingresar
            cout << "Solo pueden jugar de 2 a 8 jugadores por ronda";
            break;
    }

    cin.get();
    cin.get();
}

//Para controlar la posicion de las salidas en la pantalla
void centraPantalla( const int codPantalla )
{
    int a = 0;

    switch( codPantalla )
    {
        case 0:
                for ( ; a <= 5; a++ )//Para bajar la salida 5 lineas
                    cout << "\n";
                break;

        case 1:
        case 2:
        case 3:
        case 4:
                for ( ; a <= codPantalla; a++ )//Para tabular a la derecha
                    cout << "\t";
                break;

        case 10:
                system( "cls" );//para limpiar la pantalla
                break;
    }
}

//Para el juego individual
void juegoIndividual( int &ctJugDia, int &ptTotJugador, int &ptTurJugador, int &ptTotDia )
{
    char rondas = 's';
    string name = "Individual";

	while ( rondas == 's' )
	{
		ctJugDia += 1;
		ptTotJugador = 0;

        ingresoPuntos( ptTotJugador, ctJugDia, name );

        validaRegaliasIndividual( ptTotJugador );

		ptTotDia += ptTotJugador;

        validaContinuar( rondas );
	}
}

//Para ingresar los puntos en el juego ganadas por jugador
void ingresoPuntos( int &punToJu, const int &rondasJ, const string &nombre )
{
    int contadorTurnosJugador = 1; //Contador de turnos en juego
    int puntosTurnoJugador = 0;

    while ( contadorTurnosJugador <= 6 )
    {
        centraPantalla( 10 );
        cout << "RONDA #" << rondasJ;
        cout << "\nJugador: " << nombre;
        centraPantalla( 0 );
        centraPantalla( 3 );
		cout << "Conteo actual: " << punToJu;
        centraPantalla( 0 );
        centraPantalla( 3 );

        if ( contadorTurnosJugador == 6)
        {
            contadorTurnosJugador = 7;
            cout << "RONDA TERMINADA\n";
            centraPantalla( 3 );
            cout << "ENTER PARA CONTINUAR";
            cin.get();
            cin.get();
        }
        else
        {
            cout << "Digite el puntaje: " ;
            cin >> puntosTurnoJugador;
            // Valida valores en los puntos, se agrega 0 por si no se obtienen puntos en el juego
            if ( ( ( puntosTurnoJugador > 5 ) || ( puntosTurnoJugador < 0 ) )&& ( puntosTurnoJugador != 10 ) )
			    mensajesError( 1 );
            else
            {
                contadorTurnosJugador++;
                punToJu += puntosTurnoJugador;
            }
        }
    }
}

//Para verificar si se gano la regalia en el juego individual
void validaRegaliasIndividual( const int &ptJugador )
{
    centraPantalla( 10 );
    centraPantalla( 0 );
    centraPantalla( 3 );
    cout << ( ptJugador >= 30 ? "GANA " : "NO Gana " ) << "una cortesia\n\n";
    centraPantalla( 3 );
    cout << "Puntos obtenidos: " << ptJugador;
    cin.get();
}

//Para seleccionar si desea continuar jugando
void validaContinuar( char &jContinua )
{
    do
    {
        centraPantalla( 10 );
        centraPantalla( 0 );
        centraPantalla( 1 );
        cout << "Desea ingresar mas rondas \"s\" (continua) \"n\" (salir): ";
        cin >> jContinua;
        jContinua = tolower( jContinua );

        if ( jContinua != 's' && jContinua != 'n' )
        {
            mensajesError( 2 );
        }
    }while ( jContinua != 's' && jContinua != 'n');
}

//Para el juego grupal
void juegoGrupal( string arrgNombJugadores[ ][ tamanoArreglo2 ], int &cuentaRondas, int arrgPuntJugadores[ ][ tamanoArreglo2 ] )
{
    int cantJugadores = 0;
    char juegos = 's';

	while ( juegos == 's' )
	{
        cuentaRondas++;

        if ( cuentaRondas < 10 )
        {
            do
            {
                centraPantalla( 10 );
                cout << "RONDA #" << cuentaRondas;
                centraPantalla( 0 );
                centraPantalla( 1 );
                cout << "Cuantos personas van a jugar en esta ronda: ";
                cin >> cantJugadores;

                if ( cantJugadores < 2 || cantJugadores > 8 )
                    mensajesError( 4 );
                else
                {
                    ingresaNombresJugadoresGrupal( cantJugadores, arrgNombJugadores, cuentaRondas );
                    ingresoPuntosArreglo( cuentaRondas, cantJugadores, arrgPuntJugadores, arrgNombJugadores );
                    ordenaArreglos( cuentaRondas, cantJugadores, arrgNombJugadores, arrgPuntJugadores );
                }

            }while ( cantJugadores < 2 || cantJugadores > 8);

            validaContinuar( juegos );
        }
        else
        {
            centraPantalla( 10 );
            centraPantalla( 0 );
            centraPantalla( 1 );

            cout << "Ha alcanzado el numero máximo de rondas (10)";
            cin.get();
            cin.get();

            juegos = 'n';
        }
	}
}

//Para ingresar los nombres de los jugadores
void ingresaNombresJugadoresGrupal( const int &cantJug, string arrayNombres[ ][ tamanoArreglo2 ], const int &ronda )
{
    for ( int i = 0; i < cantJug; i ++ )
    {
        centraPantalla( 10 );
        cout << "RONDA #" << ronda;
        centraPantalla( 0 );
        centraPantalla( 1 );
        cout << "Digite el nombre del jugador " << ( i + 1 ) << ": ";
        cin >> arrayNombres[ ( ronda - 1 ) ][ i ];
    }
}

//Para ingresar los puntos al arreglo
void ingresoPuntosArreglo( const int &nRonda, const int &cantJugadores, int arrayPuntos[ ][ tamanoArreglo2 ], string arrayNombres[ ][ tamanoArreglo2 ] )
{
    for ( int i = 0; i < cantJugadores; i++ )
    {
       ingresoPuntos( arrayPuntos[ ( nRonda - 1 ) ][ i ], nRonda, arrayNombres[ ( nRonda - 1 ) ][ i ]);
    }
}

//Para conocer la bebida que debe tomar como castigo
void tablaCastigos( const string &nombreCastigado )
{
    int puntajeCastigo = 0;
    int continua = 0;

    while ( continua == 0 )
    {
        centraPantalla( 10 );
        centraPantalla( 0 );
        centraPantalla( 3 );
        cout << "El jugador castigado es: " << nombreCastigado << endl;
        centraPantalla( 0 );
        cout << "Digite el puntaje para conocer el castigo: " ;
        cin >> puntajeCastigo;

        if ( ( ( puntajeCastigo > 5 ) || ( puntajeCastigo < 0 ) )&& ( puntajeCastigo != 10 ) )
            mensajesError( 1 );
        else
        {
            continua = 1;
            centraPantalla( 0 );
            cout << "La bebida que debe tomar es: ";
        }
    }

    switch( puntajeCastigo )
    {
        case 1:
            cout << "Martin en las Rocas";
            break;
        case 2:
            cout << "María Sangrienta";
            break;
        case 3:
            cout << "Miguelino";
            break;
        case 4:
            cout << "Polaco Blanco";
            break;
        case 5:
            cout << "Jugo de Ganso";
            break;
        case 10:
            cout << "Caldo de Sapo";
            break;
    }
}

void ordenaArreglos( const int &rondaNumero, const int &cantiJuga, string arrayName[ ][ tamanoArreglo2 ], int arrayPoints[ ][ tamanoArreglo2 ] )
{
    string pasaNombre = " ";
    int pasaPuntos = 0;
    int pasadas = ( cantiJuga - 1 );
    int filas = ( rondaNumero - 1 );

    for ( int a = 1; a < ( cantiJuga ); a++ )
        for ( int b = 0; b <= ( cantiJuga - 2 ); b++ )
        {
            if ( arrayPoints[ filas ][ b ] > arrayPoints[ filas ][ b + 1 ] )
            {
                pasaNombre = arrayName[ filas ][ b ];
                arrayName[ filas ][ ( b ) ] = arrayName[ filas ][ ( b + 1) ];
                arrayName[ filas ][ ( b + 1) ] = pasaNombre;

                pasaPuntos = arrayPoints[ filas ][ b ];
                arrayPoints[ filas ][ ( b ) ] = arrayPoints[ filas ][ ( b + 1) ];
                arrayPoints[ filas ][ ( b + 1) ] = pasaPuntos;
            }
        }
}
