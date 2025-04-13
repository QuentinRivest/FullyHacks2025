#include "InfoMenu.cpp"
#include <cmath>
#include "Button.cpp"

void TitleScreen(){
    unsigned int win_width  = 800;
    unsigned int win_length = 600;
    sf::Font space_font;
    space_font.loadFromFile("assets/space-font-italic.ttf");
    sf::RenderWindow window(sf::VideoMode({win_width, win_length}), "SFML works!", sf::Style::Fullscreen);
    
    space_font.loadFromFile("assets/space-font-italic.ttf");
    Button start(window.getSize().x * 0.54, window.getSize().y * 0.73, "assets/Solid_black.png");
    start.setSize(.10 * window.getSize().x, .06 * window.getSize().y);
    sf::Text Start("START", space_font, 40);
    Start.move(window.getSize().x * 0.5, window.getSize().y *0.7);
    sf::Text title("LAST BREATH", space_font, 70);
    title.setPosition(window.getSize().x * 0.1, window.getSize().y * 0.5);
    while (window.isOpen()) {
        while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
            return;
          }
        }
        start.update(window);
        window.clear(sf::Color::Black);
        
        start.render(window);
        window.draw(Start);
        window.draw(title);
        window.display();
        if (start.isPressed()) {
            window.clear(sf::Color::Black);
            return;
            }
        }
    }
}

int main() {
    TitleScreen();
    InfoMenu();
}