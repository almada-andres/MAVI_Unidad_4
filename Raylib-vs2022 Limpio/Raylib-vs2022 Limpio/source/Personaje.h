#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "raylib.h"

class Personaje
{
    private:
            Texture2D* textura;
            Vector2 posicion;
            float velocidad;
            float escala;
            float tiempoSalto;
            bool saltando;

    public:
            Personaje(Texture2D* texturaCompartida);

            void Actualizar(float deltaTime);
            void Saltar();
            void Reiniciar();
            void Dibujar() const;

            Vector2 ObtenerPosicion() const;
};

#endif