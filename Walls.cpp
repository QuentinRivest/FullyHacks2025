// file to define all functions to run each wall

/* Walls are gonna be their own functions rather than class just 'cause
 * each wall will be so unique I think a class is more hassle than
 * it's worth.
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Button.hpp"
#include "Walls.hpp"

void displayExampleWall() {
  unsigned int win_width  = 800;
  unsigned int win_length = 600;
  sf::RenderWindow window(sf::VideoMode(win_width, win_length), "SFML works!");

  // Game Loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseButtonPressed) {
        std::cout << "Mouse button pressed.\a\n";
      }
    }

    // Update

    Button button(win_width / 2.0f, win_length / 2.0f, "assets/button-example.png");
    button.update(window);

    // Render
    window.clear(sf::Color::Black);

    button.render(window);

    window.display();
  }
}
