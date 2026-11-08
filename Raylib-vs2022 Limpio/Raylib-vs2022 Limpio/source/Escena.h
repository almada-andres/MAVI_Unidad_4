#ifndef ESCENA_H
#define ESCENA_H

#include "raylib.h"
#include "Personaje.h"

class Escena
{
    private:
            Texture2D textura;
            Sound sonido;
            Personaje* personaje;

            Color fondo;
            bool mensajeVisible;
            const char* mensajeSistema;

            Rectangle boton;

    public:
            Escena();
            ~Escena();

            void Actualizar(float deltaTime);
            void Dibujar() const;
};

#endif