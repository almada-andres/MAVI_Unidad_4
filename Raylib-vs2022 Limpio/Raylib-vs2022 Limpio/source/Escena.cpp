#include "Escena.h"

Escena::Escena()
{
    textura = { 0 };
    sonido = { 0 };
    personaje = nullptr;

    fondo = { 110, 100, 215, 255 };
    mensajeVisible = true;
    mensajeSistema = " Esperando instrucciones.";

    boton = { 610.0f, 370.0f, 160.0f, 45.0f };

    textura = LoadTexture("Assets/pelota.png");
    sonido = LoadSound("Assets/sonido_input.wav");

    if (textura.id != 0)
    {
        personaje = new Personaje(&textura);
    }
}

Escena::~Escena()
{
    delete personaje;

    if (textura.id != 0)
    {
        UnloadTexture(textura);
    }

    if (sonido.frameCount > 0)
    {
        UnloadSound(sonido);
    }
}

void Escena::Actualizar(float deltaTime)
{
    if (personaje == nullptr)
    {
        return;
    }

    personaje->Actualizar(deltaTime);

    if (IsKeyPressed(KEY_SPACE))
    {
        personaje->Saltar();
        
        if (sonido.frameCount > 0)
        {
            PlaySound(sonido);
        }

        mensajeSistema = "Sistema: salto...";
    }

    if (IsKeyPressed(KEY_R))
    {
        personaje->Reiniciar();
        mensajeSistema = "Sistema: posicion reiniciada.";
    }

    if (IsKeyPressed(KEY_M))
    {
        mensajeVisible = !mensajeVisible;
        mensajeSistema = mensajeVisible ? "Sistema: mensaje activado." : "Sistema: mensaje ocultado.";
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, boton))
        {
            fondo = (fondo.r == 110) ? Color{ 40, 110, 90, 255 } : Color{ 110, 100, 215, 255 };

            mensajeSistema = "Sistema: fondo modificado por el mouse.";
        }
    }
}

void Escena::Dibujar() const
{
    ClearBackground(fondo);

    DrawText("UNIDAD 4", 20, 15, 23, WHITE);

    DrawText("Flechas: mover | ESPACIO: saltar | R: reiniciar | M: mensaje", 20, 55, 16, WHITE);

    if (personaje == nullptr)
    {
        DrawText("ERROR: no se pudo cargar Assets/pelota.png", 20, 110, 20, RED);
        return;
    }

    personaje->Dibujar();

    Vector2 posicion = personaje->ObtenerPosicion();

    DrawText(TextFormat("Posicion X: %.1f | Posicion Y: %.1f", posicion.x, posicion.y), 20, 100, 18, WHITE);

    DrawRectangleRec(boton, DARKGREEN);

    DrawText("CAMBIAR FONDO", 620, 383, 15, WHITE);

    DrawRectangleLinesEx(boton, 2.0f, WHITE);

    if (mensajeVisible)
    {
        DrawRectangle(20, 145, 470, 35, Fade(BLACK, 0.45f));

        DrawText(mensajeSistema, 30, 153, 16, YELLOW);
    }
}