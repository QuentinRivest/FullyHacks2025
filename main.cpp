#include <iostream>
#include <SFML/Graphics.hpp>

#include "Room.hpp"

int main() {

  displayExampleRoom();

  /*unsigned int win_width  = 800;
  unsigned int win_length = 600;
  sf::RenderWindow window(sf::VideoMode(win_width, win_length), "SFML works!");

  sf::Texture texture;
  texture.loadFromFile("assets/button-example.png");
  sf::Sprite sprite(texture);
  sf::Rect<float> sprite_size = sprite.getGlobalBounds();
  sprite.setOrigin(sprite_size.width / 2.0f, sprite_size.height / 2.f);
  sprite.setPosition(win_width / 2.0f, win_length / 2.0f);
  sprite.setColor(sf::Color(160, 160, 160));    // makes image darker

  sf::Font space_font;
  space_font.loadFromFile("assets/space-font-italic.ttf");
  sf::Text title_text("Placeholder Name", space_font, 50);
  sf::Rect<float> title_text_size = title_text.getGlobalBounds();
  title_text.setOrigin(title_text_size.width / 2.0f, 0);
  title_text.setPosition(win_width / 2.0f, 0);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);

    window.draw(sprite);
    window.draw(title_text);

    window.display();
  }*/

  return EXIT_SUCCESS;
}
