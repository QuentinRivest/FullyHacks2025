#include <iostream>

#include "Button.hpp"

Button::Button(float x, float y, const std::string& tex_filepath) {
  if (this->_texture.loadFromFile(tex_filepath)) {
    this->_sprite.setTexture(this->_texture);
  } else {
    std::cout << "Textures didn't load. :(\n";
  }

  this->_button_state = ButtonState::IDLE;

  sf::Rect<float> sprite_size = _sprite.getGlobalBounds();
  this->_sprite.setOrigin(sprite_size.width / 2.0f, sprite_size.height / 2.0f);
  this->_sprite.setPosition(x, y);
}

Button::Button(sf::Vector2f position, const std::string& tex_filepath) {
  Button(position.x, position.y, tex_filepath);
}

bool Button::isPressed() const {
  return this->_button_state == ButtonState::PRESSED;
}

bool Button::isHovered() const{
  return this->_button_state == ButtonState::HOVERED;
}

void Button::update(const sf::RenderWindow &window) {
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
  auto hit_box = this->_sprite.getGlobalBounds();

  this->_sprite.setScale(0.4f, 0.4f);

  if (hit_box.contains(mouse_pos.x, mouse_pos.y)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      this->_sprite.setColor(_press_overlay_color);
      this->_button_state = ButtonState::PRESSED;
    } else {
      this->_sprite.setColor(_hover_overlay_color);
      this->_button_state = ButtonState::HOVERED;
    }
  } else {
    this->_sprite.setColor(_idle_overlay_color);
    this->_button_state = ButtonState::IDLE;
  }

}

void Button::render(sf::RenderTarget &target) {
  target.draw(this->_sprite);
}
