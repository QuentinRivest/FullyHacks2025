#include "InfoMenu.cpp"
#include <cmath>
#include "Button.cpp"

void TitleScreen(sf::RenderWindow& window){
    sf::Font space_font;
    space_font.loadFromFile("assets/space-font-italic.ttf");
    Button start(600, 520, "assets/Solid_black.png");
    sf::Text Start("START", space_font, 40);
    Start.move(550, 500);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
          }
        }
        start.update(window);
        window.clear(sf::Color::Black);

        sf::Text title("LAST BREATH", space_font, 50);
        auto center = title.getGlobalBounds().width / 2.f;
        auto localBounds = center + title.getLocalBounds().width / 2;
        auto rounded = round(localBounds);
        title.setOrigin(rounded, title.getLocalBounds().height);
        title.setPosition(sf::Vector2f{ window.getSize() / 2u });
        start.render(window);
        window.draw(Start);
        window.draw(title);
        window.display();
    if (start.isPressed()) {
        std::cout << "Click";
        window.clear(sf::Color::Black);
        InfoMenu(window);
    }
    }

    
    

}

int main() {
    unsigned int win_width  = 800;
    unsigned int win_length = 600;
    sf::Font space_font;
    space_font.loadFromFile("assets/space-font-italic.ttf");
    sf::RenderWindow window(sf::VideoMode({win_width, win_length}), "SFML works!");
    TitleScreen(window);
    
}