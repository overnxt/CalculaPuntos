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

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::system;


//Prototipos
void menu( );//Para el menu de inicio
void mensajesError( const int );//Para el menejo de los errores
void centraPantalla( const int );//Para el centrado en pantalla
void juegoIndividual( int &, int &, int &, int & );//Para la opcion del juego individual
void ingresoPuntosIndividual( int &, int & );//Para el ingreso de puntos por el cliente
void validaRegaliasIndividual( const int & );//Para la verificacion si se gano regalias
void juegoGrupal( );//Para la opcion del juego grupal
void validaContinuar( char & );//Para procesar si se desea continuar ingresando juegos
void estadisticasGenerales( const int &, const int & );//Para presentar las estadisticas de juego

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
	int const tArreglo1 = 10;
	int const tArreglo2 = 8;
    char arregloNombresJugadores[ tArreglo1 ];
    int arregloPuntosJugadores[ tArreglo1 ][ tArreglo2 ];

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
                    juegoGrupal( );
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
            cout << "Solo pueden jugar de 2 a 8 jugadores";
            break;
    }

    cin.get();
    cin.get();
}

//Para controlar la posicion de las salidas en la pantalla
void centraPantalla( const int codPantalla )
{
    int a = 0;

    switch ( codPantalla )
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
                system( "clear" );//para limpiar la pantalla
                break;
    }
}

//Para el juego individual
void juegoIndividual( int &ctJugDia, int &ptTotJugador, int &ptTurJugador, int &ptTotDia )
{
    char rondas = 's';

	while ( rondas == 's' )
	{
		ctJugDia += 1;
		ptTotJugador = 0;

        ingresoPuntosIndividual( ptTotJugador, ptTurJugador );

        validaRegaliasIndividual( ptTotJugador );

		ptTotDia += ptTotJugador;

        validaContinuar( rondas );
	}
}

//Para ingresar los puntos en el juego individual
void ingresoPuntosIndividual( int &punToJu, int &punTurJu )
{
    int contadorTurnosJugador = 0; //Contador de turnos en juego

    while ( contadorTurnosJugador != 5 )
    {
        centraPantalla( 10 );
        centraPantalla( 0 );
        centraPantalla( 3 );
		cout << "Conteo actual: " << punToJu;
        centraPantalla( 0 );
        centraPantalla( 3 );
        cout << "Digite el puntaje: " ;
		cin >> punTurJu;
		// Valida valores en los puntos, se agrega 0 por si no se obtienen puntos en el juego
		if ( ( ( punTurJu > 5 ) || ( punTurJu < 0 ) )&& ( punTurJu != 10 ) )
			    mensajesError( 1 );
        else
		{
            contadorTurnosJugador += 1;
            punToJu += punTurJu;
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
}

//Para seleccionar si desea continuar jugando
void validaContinuar( char &jContinua )
{
    do
    {
        centraPantalla( 0 );
        centraPantalla( 1 );
        cout << "Desea ingresar mas juegos \"s\" (continua) \"n\" (salir): ";
        cin >> jContinua;
        jContinua = tolower( jContinua );

        if ( jContinua != 's' && jContinua != 'n' )
        {
            mensajesError( 2 );

            centraPantalla( 10 );
        }
    }while ( jContinua != 's' && jContinua != 'n');
}

//Para el juego grupal
void juegoGrupal( )
{
    int jugadores = 0;

    char juegos = 's';

	while ( juegos == 's' )
	{
        do
        {
            centraPantalla( 10 );
            centraPantalla( 0 );
            centraPantalla( 1 );
            cout << "Cuantos personas van a jugar: ";
            cin >> jugadores;

            if ( jugadores < 2 || jugadores > 8 )
                mensajesError( 4 );
            //else

        }while ( jugadores < 2 || jugadores > 8);

        validaContinuar( juegos );
	}
}

//Para ingresar los nombres de los jugadores
void ingresaNombresJugadoresGrupal()
{

}


/*
Estado actual de las etapas:

Ingresar nombres para juego grupal
Ingresar los puntos para juego grupal
Generar la tabla de castigos
Generar reportes en juego grupal
*/
