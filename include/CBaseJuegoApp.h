/*
 *  Nombre: JuegoApp.
 *  Autor: Jaasiel Guerra.
 *  Fecha: 18 de Diciembre 2019
 *  Descripcion: Clase para el bucle principal del juego.
 *               Se encarga de la actualizacion del juego en cada Frame.
 */

#ifndef CBASEJUEGOAPP_H
#define CBASEJUEGOAPP_H

#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

class CBaseJuegoApp
{
public:
    CBaseJuegoApp();
    virtual ~CBaseJuegoApp();
    void iniciarJuego();

protected:
    void setFinalizarJuego(bool valor);
    bool getFinalizarJuego();
    virtual void comienzo();
    virtual void actualizar(float tiempoTranscurrido);

private:
    bool finalzarJuego;
    void bucleDeJuego();
};

#endif // CBASEJUEGOAPP_H
