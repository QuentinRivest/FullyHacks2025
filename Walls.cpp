// file to define all functions to run each wall

/* Walls are gonna be their own functions rather than class just 'cause
 * each wall will be so unique I think a class is more hassle than
 * it's worth.
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Walls.hpp"

void fourDigitNumberWall(sf::RenderWindow& window) {
  unsigned int win_width  = window.getSize().x;
  unsigned int win_height = window.getSize().y;

  bool was_just_pressed = false;    // flag to tell if mouse button was just pressed

  // DECLARE VARIABLES
  const std::string actual_code = "1234";
  std::string guess_code;

  Picture carbon_fiber_background(win_width * 0.5f, win_height * 0.5f, "assets/brick-texture.png");
  carbon_fiber_background.setSize(win_width, win_height);

  Picture btn_backdrop(win_width * 0.5f, win_height * 0.75f, "assets/btn-backdrop.png");
  btn_backdrop.scaleSize(1.8f, 1.8f);

  // Declare Buttons ...
  Button btn1(win_width * 0.5f - 200.0f, win_height * 0.75f, "assets/btn1-idle.png");
  btn1.setSize(80.0f, 80.0f);
  Button btn2(win_width * 0.5f - 65.0f, win_height * 0.75f, "assets/btn2-idle.png");
  btn2.setSize(80.0f, 80.0f);
  Button btn3(win_width * 0.5f + 65.0f, win_height * 0.75f, "assets/btn3-idle.png");
  btn3.setSize(80.0f, 80.0f);
  Button btn4(win_width * 0.5f + 200.0f, win_height * 0.75f, "assets/btn4-idle.png");
  btn4.setSize(80.0f, 80.0f);

  std::vector<Button*> buttons{&btn1, &btn2, &btn3, &btn4};
  // ... End


  // GAME LOOP
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }


    // UPDATE MEMORY TO SCREEN

    // Update Buttons to Screen
    for (const auto& button : buttons) {
      button->update(window);
    }

    if (!was_just_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

      // Do Event Depending on Button...
      if (btn1.isPressed()) {
        guess_code += '1';
        std::cout << "Pressed 1\n";
      } else if (btn2.isPressed()) {
        guess_code += '2';
        std::cout << "Pressed 2\n";
      } else if (btn3.isPressed()) {
        guess_code += '3';
        std::cout << "Pressed 3\n";
      } else if (btn4.isPressed()) {
        guess_code += '4';
        std::cout << "Pressed 4\n";
      }

      if (guess_code.length() > 3) {
        if (guess_code == actual_code) {
          std::cout << "YES\n";
        } else {
          std::cout << "no\n";
        }
        guess_code = "";
      }
      // ... End

      was_just_pressed = true;
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      was_just_pressed = false;
    }


    // RENDER WINDOW

    window.clear(sf::Color::Black);

    carbon_fiber_background.render(window);
    btn_backdrop.render(window);

    // Render Buttons
    for (const auto& button : buttons) {
      button->render(window);
    }

    window.display();
  }
}



/*void <otherWall>(sf::RenderWindow& window) {
  /// ..
}*/



void displayExampleWall(sf::RenderWindow& window) {
  unsigned int win_width  = window.getSize().x;
  unsigned int win_height = window.getSize().y;

  bool was_just_pressed = false;    // flag to tell if mouse button was just pressed

  // CODE HERE: Declare Buttons ...
  Button example_button(win_width / 2.0f, win_height / 2.0f, "assets/button-example.png");
  Button other_button(win_width / 2.0f, 100, "asset/button-example.png");

  std::vector<Button*> buttons{&example_button, &other_button};
  // ... End

  // GAME LOOP
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }


    // UPDATE MEMORY TO SCREEN

    // Update Buttons to Screen
    for (const auto& button : buttons) {
      button->update(window);
    }

    if (!was_just_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

      // CODE HERE: Do Event Depending on Button...
      if (example_button.isPressed()) {
        std::cout << "example_button was pressed.\n";
      } else if (other_button.isPressed()) {
        std::cout << "other_button was pressed.\n";
      }
      // ... End

      was_just_pressed = true;
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      was_just_pressed = false;
    }


    // RENDER WINDOW

    window.clear(sf::Color::Black);

    // Render Buttons
    for (const auto& button : buttons) {
      button->render(window);
    }

    window.display();
  }
}
