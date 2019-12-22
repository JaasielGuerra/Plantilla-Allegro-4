#include "CBaseAllegro.h"

CBaseAllegro::CBaseAllegro(void)
{
    // incializa los atributos por defecto
    this->modoGrafico = GFX_AUTODETECT_WINDOWED;
    this->ancho = 480;
    this->alto = 360;
    this->profundidadColor = PF_COLOR_32_BITS;
    this->tituloVentana = "Allegro " + allegroVersion + " - Jaasiel Guerra";
    this->digi_volumen = 70;
    this->midi_volumen = 70;
    this->tipoCursorMouse = MS_NORMAL;
}

CBaseAllegro::CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                           int _profundidadColor)
{
    this->modoGrafico = _modoGrafico;
    this->ancho = _anchoPantalla;
    this->alto = _altoPantalla;
    this->profundidadColor = _profundidadColor;
    this->tituloVentana = "Allegro " + allegroVersion + " - Jaasiel Guerra";
    this->digi_volumen = 70;
    this->midi_volumen = 70;
    this->tipoCursorMouse = MS_NORMAL;
}


CBaseAllegro::CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                           int _profundidadColor,const string &_tituloVentana)
{
    this->modoGrafico = _modoGrafico;
    this->ancho = _anchoPantalla;
    this->alto = _altoPantalla;
    this->profundidadColor = _profundidadColor;
    this->tituloVentana = _tituloVentana;
    this->digi_volumen = 70;
    this->midi_volumen = 70;
    this->tipoCursorMouse = MS_NORMAL;
}

CBaseAllegro::CBaseAllegro(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
                           int _profundidadColor, const string &_tituloVentana,
                           int _digi_volumen, int _midi_volumen )
{
    this->modoGrafico = _modoGrafico;
    this->ancho = _anchoPantalla;
    this->alto = _altoPantalla;
    this->profundidadColor = _profundidadColor;
    this->tituloVentana = _tituloVentana;
    this->digi_volumen = _digi_volumen;
    this->midi_volumen = _midi_volumen;
    this->tipoCursorMouse = MS_NORMAL;
}

CBaseAllegro::~CBaseAllegro()
{
    allegro_exit();// cerrando la biblioca
}

// para iniciar el volumen del audio
void CBaseAllegro::setVolumenAudio(int _digi_volumen, int _midi_volumen)
{
    this->digi_volumen = _digi_volumen;
    this->midi_volumen = _midi_volumen;
}

// poner titulo a la ventana
void CBaseAllegro::setTituloVentana(const string& _titulo)
{
    this->tituloVentana = _titulo;
}

//metodo para dar las propiedades a la ventana
void CBaseAllegro::setPropiedadesVentana(int _anchoPantalla, int _altoPantalla, int _modoGrafico,
        int _profundidadColor)
{
    this->modoGrafico = _modoGrafico;
    this->ancho = _anchoPantalla;
    this->alto = _altoPantalla;
    this->profundidadColor = _profundidadColor;
}

//establece el tipo de cursor del mouse en la ventana
void CBaseAllegro::setTipoCursor(int _tipo)
{
    this->tipoCursorMouse = _tipo;
}

// devolver el alto de pantalla configurado
int CBaseAllegro::getAltoPantalla()
{
    return this->alto;
}

// devolver el ancho de pantalla configurado
int CBaseAllegro::getAnchoPantalla()
{
    return this->ancho;
}

/** @brief
 *  Inicia la biblioteca Allegro.
 *  Esta funcion debe llamarse justo despues de inicializar cualquier
 *  configuracion para Allegro.
 *  \param  Ninguno.
 *  \return Ninguno
 */
void CBaseAllegro::iniciarAllegro(void)
{
    try
    {
        allegro_init();// llamando a la biblioteca
        install_keyboard();// instalar el teclado
        install_timer();// instalar temporizadores
        install_mouse();// instalar el mouse

        //especificar la profundidad de color
        set_color_depth(this->profundidadColor);

        //iniciar el modo grafico
        set_gfx_mode(this->modoGrafico, this->ancho, this->alto, 0, 0);

        //titulo de la ventana
        set_window_title(this->tituloVentana.c_str());// titulo de la ventana

        // habilita el cursor del sistema para mostrarla en la ventana
        show_os_cursor(this->tipoCursorMouse);

        //iniciar el audio
        install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

        //volumen de los altavoces
        set_volume(this->digi_volumen, this->midi_volumen);

    }
    catch(std::exception& e)
    {
        cout << "Error en la inicializacion de allegro: " << e.what() << endl;
    }
}



