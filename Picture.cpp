#include <iostream>

#include "Picture.hpp"

Picture::Picture(float x, float y, const std::string& tex_filepath) {
  if (_texture.loadFromFile(tex_filepath)) {
    _sprite.setTexture(_texture);
  } else {
    std::cout << "Textures didn't load. :(\n";
  }

  sf::Rect<float> sprite_size = _sprite.getGlobalBounds();
  _sprite.setOrigin(sprite_size.width / 2.0f, sprite_size.height / 2.0f);
  _sprite.setPosition(x, y);
}

void Picture::scaleSize(float x, float y) {
  _sprite.setScale(x, y);
}

void Picture::setSize(float target_x, float target_y) {
  sf::Vector2u texSize = _texture.getSize();
  if (texSize.x == 0 || texSize.y == 0) return;

  float scale_x = target_x / static_cast<float>(texSize.x);
  float scale_y = target_y / static_cast<float>(texSize.y);
  _sprite.setScale(scale_x, scale_y);
}

void Picture::render(sf::RenderTarget &target) {
  target.draw(this->_sprite);
}
