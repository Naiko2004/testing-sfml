#include <SFML/Graphics.hpp>
#include <iostream>



int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    auto window = sf::RenderWindow{ { desktop.width, desktop.height }, "titulo", sf::Style::Default };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed )
            {
                window.close();
            }
        }


        window.clear();
        window.display();

    }


    return 0;
}