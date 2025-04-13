#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Picture {
public:
  Picture(float x, float y, const std::string &tex_filepath);

  void scaleSize(float x, float y);
  void setSize(float target_x, float target_y);

  void render(sf::RenderTarget &target);

private:
  sf::Sprite  _sprite;
  sf::Texture _texture;
};

#endif
