#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MAVI - Unidad 6");
    window.setFramerateLimit(60);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(100, 100);

    sf::Vector2f tempPosition(400.0f, 100.0f);
    sf::Vector2f velocity(0.0f, 0.0f);

    float deltaTime = 1.0f / 60.0f;

    const float gravity = 100.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
                window.close();
        }

        velocity.y += gravity * deltaTime;

        tempPosition += velocity * deltaTime;

        if (tempPosition.y > 500.0f) {
            tempPosition.y = 500.0f;
            velocity.y = -(velocity.y * 0.75f);
        }

        shape.setPosition(tempPosition);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}