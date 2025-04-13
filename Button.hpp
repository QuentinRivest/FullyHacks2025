/* define a clickable object with OPTIONAL visual aspects
 *    like sprites, text, etc.
 *    but could also want invisible button
 *      (ex.: 10 invisible buttons on a keypad jpeg)
 */
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum class ButtonState { IDLE, HOVERED, PRESSED };

class Button {
public:
  Button(float x, float y, const std::string &tex_filepath);
  Button(sf::Vector2f position, const std::string &tex_filepath);

  bool isPressed() const;
  bool isHovered() const;

  void update(const sf::RenderWindow& window);
  void render(sf::RenderTarget& target);

private:
  sf::Sprite _sprite;
  sf::Texture _texture;
  ButtonState _button_state;

// private helper var.s
  const sf::Color _idle_overlay_color  = sf::Color(255, 255, 255);
  const sf::Color _hover_overlay_color = sf::Color(205, 205, 205);
  const sf::Color _press_overlay_color = sf::Color(155, 155, 155);
};

#endif
