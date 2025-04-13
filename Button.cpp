#include <iostream>

#include "Button.hpp"

Button::Button(sf::Vector2f mousePosView) {
  if (this->_idle_tex.loadFromFile("assets/button-example.png")) {
    std::cout << "Texture loaded.\n";
    this->_shape.setTexture(this->_idle_tex);
  } else {
    std::cout << "Textures didn't load. :(\n";
  }

  this->buttonState = ButtonState::IDLE;
  this->_shape.setPosition(mousePosView.x - this->_shape.getGlobalBounds().width / 2.f,
                           mousePosView.y - this->_shape.getGlobalBounds().height / 2.f);
}

bool Button::isPressed() const {
  return this->buttonState == ButtonState::PRESSED;
}

bool Button::isHovered() const{
  return this->buttonState == ButtonState::HOVERED;
}

void Button::update(const sf::RenderWindow &window) {
  sf::Vector2f mousePosView = sf::Mouse::getPosition(window);
}

void Button::render(sf::RenderTarget &target) {
  target.draw(this->_shape);
}
