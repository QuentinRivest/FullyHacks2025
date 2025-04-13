#include <iostream>

#include "Button.hpp"

Button::Button(float x, float y, const std::string& tex_filepath)
    : _button_state{ButtonState::IDLE}, _tex_filepath(tex_filepath) {
  if (_texture.loadFromFile(tex_filepath)) {
    _sprite.setTexture(_texture);
  } else {
    std::cout << "Textures didn't load. :(\n";
  }


  sf::Rect<float> sprite_size = _sprite.getGlobalBounds();
  _sprite.setOrigin(sprite_size.width / 2.0f, sprite_size.height / 2.0f);
  _sprite.setPosition(x, y);
}

bool Button::isPressed() const {
  return this->_button_state == ButtonState::PRESSED;
}

bool Button::isHovered() const{
  return this->_button_state == ButtonState::HOVERED;
}

void Button::scaleSize(float x, float y) {
  _sprite.setScale(x, y);
}

void Button::setSize(float target_x, float target_y) {
  sf::Vector2u texSize = _texture.getSize();
  if (texSize.x == 0 || texSize.y == 0) return;

  float scale_x = target_x / static_cast<float>(texSize.x);
  float scale_y = target_y / static_cast<float>(texSize.y);
  _sprite.setScale(scale_x, scale_y);
}


void Button::setTexture(const std::string &tex_filepath) {
  if (_texture.loadFromFile(tex_filepath)) {
    _sprite.setTexture(_texture);
  } else {
    std::cout << "Textures didn't load. :(\n";
  }
}

const std::string& Button::getTextureFilepath() const {
  return _tex_filepath;
}

void Button::update(const sf::RenderWindow &window) {
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
  auto hit_box = this->_sprite.getGlobalBounds();

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
