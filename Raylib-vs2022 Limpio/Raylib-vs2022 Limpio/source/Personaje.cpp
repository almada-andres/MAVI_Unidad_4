#include "Personaje.h"
#include <math.h>

Personaje::Personaje(Texture2D* texturaCompartida)
{
    textura = texturaCompartida;
    posicion = { 350.0f, 280.0f };
    velocidad = 250.0f;
    escala = 0.20f;
    tiempoSalto = 0.0f;
    saltando = false;
}

void Personaje::Actualizar(float deltaTime)
{
    if (IsKeyDown(KEY_RIGHT))
    {
        posicion.x += velocidad * deltaTime;
    }

    if (IsKeyDown(KEY_LEFT))
    {
        posicion.x -= velocidad * deltaTime;
    }

    float ancho = textura->width * escala;

    if (posicion.x < 0.0f)
    {
        posicion.x = 0.0f;
    }

    if (posicion.x + ancho > GetScreenWidth())
    {
        posicion.x = GetScreenWidth() - ancho;
    }

    if (saltando)
    {
        tiempoSalto += deltaTime;

        if (tiempoSalto >= 0.6f)
        {
            tiempoSalto = 0.0f;
            saltando = false;
        }
    }
}

void Personaje::Saltar()
{
    if (!saltando)
    {
        saltando = true;
        tiempoSalto = 0.0f;
    }
}

void Personaje::Reiniciar()
{
    posicion = { 350.0f, 280.0f };
    tiempoSalto = 0.0f;
    saltando = false;
}

void Personaje::Dibujar() const
{
    float desplazamientoY = 0.0f;

    if (saltando)
    {
        desplazamientoY = sinf((tiempoSalto / 0.6f) * PI) * 110.0f;
    }

    DrawTextureEx(*textura, { posicion.x, posicion.y - desplazamientoY }, 0.0f, escala, WHITE);
}

Vector2 Personaje::ObtenerPosicion() const
{
    return posicion;
}