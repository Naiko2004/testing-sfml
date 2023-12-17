#include <SFML/Graphics.hpp>
#include <thread>


void noFocusThread(sf::Window& window)
{

    window.create({ 400, 300 }, "No Focus", sf::Style::Default);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.display();
    }
}


int main()
{

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    auto window = sf::RenderWindow{ { desktop.width, desktop.height }, "titulo", sf::Style::Default };
    window.setFramerateLimit(144);



    bool onetime = true;

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


        if(window.hasFocus())
        {
            window.setSize({ 800, 600 });
            window.setTitle("Focus");

        }else{
            window.setSize({ 400, 300 });
            window.setTitle("No Focus");

            if(onetime)
            {
                onetime = false;

                sf::Window noFocus;
                std::thread nfT{ noFocusThread, std::ref(noFocus) };
                nfT.detach();

            }
        }

        window.clear();
        window.display();


    }


    return 0;
}