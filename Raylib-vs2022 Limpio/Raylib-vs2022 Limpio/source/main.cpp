#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "Escena.h"

int main(void)
{
    // Inicializamos una ventana de 800x450 píxeles con un título personalizado
    InitWindow(800, 450, "Unidad 4 - Almada Andres");

    InitAudioDevice();

    // Configuramos el framerate deseado (opcional, pero recomendado)
    SetTargetFPS(60);
    {
        Escena escena;
        // Bucle principal del juego (se repite hasta que se cierre la ventana)
        while (!WindowShouldClose())
        {
            float deltaTime = GetFrameTime();

            escena.Actualizar(deltaTime);

            // Iniciamos la etapa de dibujo
            BeginDrawing();

            escena.Dibujar();

            // Finalizamos el dibujo
            EndDrawing();
        }
    }
    CloseAudioDevice();

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

