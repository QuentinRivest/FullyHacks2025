#include "InfoMenu.cpp"
#include <cmath>

void TitleScreen(sf::RenderWindow& window){
    sf::Font space_font;
    space_font.loadFromFile("assets/space-font-italic.ttf");

    sf::Text title("LAST BREATH", space_font, 50);
    auto center = title.getGlobalBounds().width / 2.f;
    auto localBounds = center + title.getLocalBounds().width / 2;
    auto rounded = round(localBounds);
    title.setOrigin(rounded, title.getLocalBounds().height);
    title.setPosition(sf::Vector2f{ window.getSize() / 2u });
    window.draw(title);
    window.display();

}

int main() {
    unsigned int win_width  = 800;
    unsigned int win_length = 600;
    int count = 0;
    sf::RenderWindow window(sf::VideoMode({win_width, win_length}), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
          }
        }
        if (count < 1) {
        window.clear(sf::Color::Black);
        TitleScreen(window);
        count += 1;
        }    
    }
}