#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


void InfoMenu() {
    using namespace std::chrono;
    unsigned int win_width  = 800;
    unsigned int win_length = 600;
    sf::RenderWindow window(sf::VideoMode({win_width, win_length}), "SFML works!", sf::Style::Fullscreen);
    int count = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
          } else if (event.type == sf::Event::MouseButtonPressed) {
            window.close();
          }
        }
        if (count < 1) {
        window.clear(sf::Color::Black);
        sf::Font code_font;
        if (!code_font.loadFromFile("assets/code_font.ttf")) {
            std::cout << "Error";
        }
        std::string message = "During an inter galactic mission a fleet of aliens has fully hacked your power systems.\nThe oxygen generation systems can only function for another 8 minutes.\nThe aliens have also hacked the door systems on board.\nYou must solve the now puzzling door systems to reach the escape pod or face certain death.\n";
        std::string mess;
        for (int i = 0; i < message.length(); ++i) {
            mess += message[i];
            sf::Text text(mess, code_font, 25);
            text.setOrigin(0, -50);
            window.draw(text);
            window.display();
            std::this_thread::sleep_for(milliseconds(65));
        }
        count += 1;
    } 
    }
    
}

/*int main() {
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
        InfoMenu(window);
        count += 1;
        }    
    }
}*/