#include "InfoMenu.cpp"
#include <cmath>
#include "Button.cpp"

void TitleScreen(){
    unsigned int win_width  = 800;
    unsigned int win_length = 600;
    sf::Font space_font;
    space_font.loadFromFile("assets/space-font-italic.ttf");
    sf::RenderWindow window(sf::VideoMode({win_width, win_length}), "SFML works!");
    
    space_font.loadFromFile("assets/space-font-italic.ttf");
    Button start(win_width * 0.58, win_length * 0.74, "assets/Solid_black.png");
    start.setSize(.17 * win_width, .06 * win_length);
    sf::Text Start("START", space_font, 40);
    Start.move(win_width * 0.5, win_length *0.7);
    sf::Text title("LAST BREATH", space_font, 50);
    title.setPosition(win_width * 0.1, win_length * 0.5);
    while (window.isOpen()) {
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
        Start.setFillColor(sf::Color::Red);
        break;
    }
    }
    window.clear(sf::Color::Black);
    InfoMenu();

}

int main() {
    TitleScreen();
}