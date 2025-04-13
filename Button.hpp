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
  Button(sf::Vector2f mousePosView);

  bool isPressed() const;
  bool isHovered() const;

  void update(const sf::RenderWindow& window);
  void render(sf::RenderTarget& target);

private:
  sf::Sprite _shape;
  //sf::Color _idle_color;    // Idk if we'll need colors or if all our buttons will be textures
  //sf::Color _hover_color;
  //sf::Color _press_color;
  sf::Texture _idle_tex;
  sf::Texture _hovered_tex;
  sf::Texture _pressed_tex;
  ButtonState buttonState;
};

#endif
