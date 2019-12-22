#include "CBaseJuegoApp.h"

CBaseJuegoApp::CBaseJuegoApp()
{
    this->finalzarJuego = false;
}

CBaseJuegoApp::~CBaseJuegoApp()
{
    //dtor
}

void CBaseJuegoApp::setFinalizarJuego(bool valor)
{
    this->finalzarJuego = valor;
}

bool CBaseJuegoApp::getFinalizarJuego()
{
    return this->finalzarJuego;
}

// metodo para inciar la ejecucion del juego
void CBaseJuegoApp::iniciarJuego()
{
    // crear un hilo
    thread hilo_principal = thread(&CBaseJuegoApp::bucleDeJuego, this);

    // esperar a que termine el proceso del hilo
    hilo_principal.join();

}

/*
 *  Bucle principal de actualizacion del juego
 */
void CBaseJuegoApp::bucleDeJuego()
{
    comienzo();// se ejecuta la funcion virtual de comienzo una sola vez

    // obteniendo el tiempo actual
    auto tp1 = chrono::system_clock::now();
    auto tp2 = chrono::system_clock::now();

    while(!finalzarJuego)
    {
        tp2 = chrono::system_clock::now();

        //se resta el tiempo para calcular el tiempo transcurrido
        chrono::duration<float> _tiempoTranscurrido = tp2 - tp1;
        tp1 = tp2;

        // se llama la funcion virtual actualizar y se le manda el tiempo transcurrido
        actualizar(_tiempoTranscurrido.count());

    }
}

/*
 *  Se ejecuta una sola vez al iniciar la ejecucion del juego
 */
void CBaseJuegoApp::comienzo()
{

}

/*
 *  Se ejecuta en cada frame que transcurre, contiene un argumento
 *  que es el tiempo transcurrido entre cada frame
 */
void CBaseJuegoApp::actualizar(float tiempoTranscurrido)
{

}

