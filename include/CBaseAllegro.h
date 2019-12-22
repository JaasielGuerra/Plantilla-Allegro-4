/*
 *  Nombre: CBaseAllegro
 *  Autor: Jaasiel Guerra
 *  Fecha: 18 de diciembre 2019
 *  Descripcion: Clase base para la inicializacion de la boblioteca
 *               Allegro version 4.2.2
*/

#ifndef CBASEALLEGRO_H
#define CBASEALLEGRO_H

#include <string>
#include <iostream>
#include <exception>
#include <allegro.h>

using namespace std;

class CBaseAllegro
{
public:
    //constructores
    CBaseAllegro(void);
    CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                 int _profundidadColor);
    CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                 int _profundidadColor, const string &_tituloVentana);
    CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                 int _profundidadColor, const string &_tituloVentana,
                 int _digi_volumen, int _midi_volumen );

    // destructor virtual
    virtual ~CBaseAllegro();

    void iniciarAllegro(void);
    void setPropiedadesVentana(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                               int _profundidadColor);
    void setTituloVentana(const string &_titulo);
    void setVolumenAudio(int _digi_volumen, int _midi_volumen);
    void setTipoCursor(int _tipo);

    int getAnchoPantalla();
    int getAltoPantalla();

protected:
    //todo codigo aca

private:
    int modoGrafico;
    int ancho;
    int alto;
    int profundidadColor;
    string tituloVentana;
    int digi_volumen;
    int midi_volumen;
    int tipoCursorMouse;
    string allegroVersion = ALLEGRO_VERSION_STR;
};

// enumarado de constantes para modo de color
enum
{
    PF_COLOR_8_BITS = 8,
    PF_COLOR_16_BITS = 16,
    PF_COLOR_32_BITS = 32
};

// enumaro de constantes para el tipo de cursor del mouse
enum
{
    MS_OCULTO,
    MS_NORMAL,
    MS_ESPERA = 3,
    MS_DUDA,
    MS_ESCRITURA
};

// enumarado para el modo de video
enum
{
    MD_PANTALLA_COMPLETA = GFX_AUTODETECT_FULLSCREEN,
    MD_VENTANA = GFX_AUTODETECT_WINDOWED,
    MD_AUTOMATICO = GFX_AUTODETECT
};

#endif // CBASEALLEGRO_H
