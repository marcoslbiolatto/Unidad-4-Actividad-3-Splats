#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

int main() {
    // Crear la ventana
    RenderWindow window(VideoMode(800, 600), "Splats");

    // Cargar las texturas
    Texture textureRed, textureBlue;
    if (!textureRed.loadFromFile("red/rcircle.png")) {
        return -1;  // Error al cargar la textura
    }
    if (!textureBlue.loadFromFile("blue/rcircleb.png")) {
        return -1;  // Error al cargar la textura
    }

    // Contenedor para los sprites
    std::vector<Sprite> splats;

    // Bucle principal
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // Detectar clic izquierdo o derecho
            if (event.type == Event::MouseButtonPressed) {
                Sprite splat;
                if (event.mouseButton.button == Mouse::Left) {
                    splat.setTexture(textureRed);
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    splat.setTexture(textureBlue);
                }

                // Establecer posición del splat
                splat.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                // Agregar el splat al contenedor
                splats.push_back(splat);
            }
        }

        // Limpiar la ventana
        window.clear(Color::White);

        // Dibujar todos los splats
        for (const auto& splat : splats) {
            window.draw(splat);
        }

        // Mostrar la ventana
        window.display();
    }

    return 0;
}