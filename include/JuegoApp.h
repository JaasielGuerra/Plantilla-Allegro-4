/*
 *  Nombre: JuegoApp
 *  Autor: Jaasiel Guerra
 *  Fecha: 18 de diciembre 2019
 *  Descripcion: Clase principal para la ejecucion del juego.
 *
*/

#ifndef JUEGOAPP_H
#define JUEGOAPP_H

#include "CBaseAllegro.h"
#include "CBaseJuegoApp.h"
#include <allegro.h>

/*
 *  Hereda de las clases bases para la inicializacion de allegro
 *  y ejecucion del bucle principal del juego.
 */
class JuegoApp : public CBaseAllegro, public CBaseJuegoApp
{
    public:
        JuegoApp(int _ancho, int _alto);
        virtual ~JuegoApp();

    protected:
        virtual void comienzo();
        virtual void actualizar(float delta);

    private:
        int ancho;
        int alto;
        BITMAP* buffer;
};

#endif // JUEGOAPP_H
