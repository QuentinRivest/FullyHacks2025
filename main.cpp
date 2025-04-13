#include <iostream>
#include <SFML/Graphics.hpp>

#include "Room.hpp"

int main() {
  unsigned int win_width  = 1200;
  unsigned int win_height = 800;
  sf::RenderWindow window(sf::VideoMode(win_width, win_height), "SFML works!");

  displayRoom(window);

  return EXIT_SUCCESS;
}
