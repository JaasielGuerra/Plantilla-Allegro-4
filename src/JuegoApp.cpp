#include "JuegoApp.h"

JuegoApp::JuegoApp(int _ancho, int _alto)
{
    // ancho y alto de ventana
    this->ancho = _ancho;
    this->alto = _alto;

    // dar las propiedades a la ventana de allegro
    setPropiedadesVentana(ancho, alto, MD_VENTANA, PF_COLOR_32_BITS);
    iniciarAllegro();// iniciar allegro antes de comenzar cualquier cosa con allegro

    this->buffer = create_bitmap(ancho, alto);
}

JuegoApp::~JuegoApp()
{

    //destructor
    destroy_bitmap(this->buffer);
}

void JuegoApp::comienzo()
{
    //se ejecuta una sola vez
}

void JuegoApp::actualizar(float delta)
{
    //todo aca se actualiza

    if (key[KEY_ESC])
        setFinalizarJuego(true);

    textout_ex(buffer, font, "I love Allegro <3", ancho/3, alto/2, makecol(224,224,224), makecol(96,125,139));

    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);// dibujar el buffer en pantalla

    clear_to_color(buffer, makecol(96,125,139));// limpiar el buffer con un color

}


