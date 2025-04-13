// file to define all functions to run each wall

/* Walls are gonna be their own functions rather than class just 'cause
 * each wall will be so unique I think a class is more hassle than
 * it's worth.
 */
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>

#include "Walls.hpp"

namespace {
  static std::tuple<int, int, int> three_rand_nums;
  /*for () {
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> distrib(1, 6);
  int random_number = distrib(gen);
  }*/

  // state variables
  static bool fixed_breaker = false;
  static bool got_passcode = false;
}


// ======================== Circuit Breaker Wall ========================

void circuitBreakerWall(sf::RenderWindow& window) {
  unsigned int win_width  = window.getSize().x;
  unsigned int win_height = window.getSize().y;


  // DECLARE/SETUP VARIABLES
  static Picture carbon_fiber_background(win_width * 0.5f, win_height * 0.5f, "assets/brick-texture.png");
  carbon_fiber_background.setSize(win_width, win_height);

  Picture circuit_breaker(win_width * 0.5f, win_height * 0.5f, "assets/circuit-breaker.png");
  //circuit_breaker.scaleSize(1.8f, 1.8f);

  float scale_ratio = 0.19f;
  // Declare Buttons ...
  Button switch1(win_width * 0.5f - 83.0f, win_height * 0.5f - 70.0f, "assets/btn-off.png");
  switch1.scaleSize(scale_ratio, scale_ratio);

  Button switch2(win_width * 0.5f + 90.0f, win_height * 0.5f - 70.0f, "assets/btn-off.png");
  switch2.scaleSize(scale_ratio, scale_ratio);

  Button switch3(win_width * 0.5f - 83.0f, win_height * 0.5f + 35.0f, "assets/btn-off.png");
  switch3.scaleSize(scale_ratio, scale_ratio);

  Button switch4(win_width * 0.5f + 90.0f, win_height * 0.5f + 35.0f, "assets/btn-off.png");
  switch4.scaleSize(scale_ratio, scale_ratio);

  Button switch5(win_width * 0.5f - 83.0f, win_height * 0.5f + 145.0f, "assets/btn-off.png");
  switch5.scaleSize(scale_ratio, scale_ratio);

  Button switch6(win_width * 0.5f + 90.0f, win_height * 0.5f + 145.0f,"assets/btn-off.png");
  switch6.scaleSize(scale_ratio, scale_ratio);

  std::vector<Button*> buttons{&switch1, &switch2, &switch3, &switch4, &switch5, &switch6};
  // ... End

  // randomly fix three breakers before it starts

  bool was_just_pressed = false;    // flag to tell if mouse button was just pressed


  // GAME LOOP
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }


    // Update Buttons to Screen
    for (const auto& button : buttons) {
      button->update(window);
    }

    if (!was_just_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

      for (int i = 0, n = buttons.size(); i < n; ++i) if (buttons[i]->isPressed()) {
        const std::string& curr_tex = buttons[i]->getTextureFilepath();
        buttons[i]->setTexture(curr_tex == "assets/btn-on.png" ? "assets/btn-off.png" : "assets/btn-on.png");

        buttons.erase(buttons.cbegin() + i);
        //--i;
        //--n;
        std::cout << "Counter: " << i << ".\n";
      }

      if (buttons.empty()) {
        fixed_breaker = true;

        std::cout << "Circuit Breaker Fixed\n";
      }
      // ... End

      was_just_pressed = true;
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      was_just_pressed = false;
    }


    // RENDER WINDOW

    window.clear(sf::Color::Black);

    carbon_fiber_background.render(window);
    circuit_breaker.render(window);

    // Render Buttons
    for (const auto& button : buttons) {
      button->render(window);
    }

    window.display();
  }
}


// ======================== Four Digit Code Wall ========================

void fourDigitNumberWall(sf::RenderWindow& window) {
  unsigned int win_width  = window.getSize().x;
  unsigned int win_height = window.getSize().y;


  // DECLARE/SETUP VARIABLES
  static Picture carbon_fiber_background(win_width * 0.5f, win_height * 0.5f, "assets/brick-texture.png");
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

  const std::string actual_code = "1234";
  std::string guess_code;

  bool was_just_pressed = false;    // flag to tell if mouse button was just pressed
  sf::Clock texture_timer;

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

    if (texture_timer.getElapsedTime().asSeconds() >= 0.5f) {
      for (int i = 1; i <= 4; ++i) {
        buttons[i-1]->setTexture("assets/btn" + std::to_string(i) + "-idle.png");
      }
    }

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
          for (int i = 1; i <= 4; ++i) {
            buttons[i-1]->setTexture("assets/btn" + std::to_string(i) + "-correct.png");
          }

          texture_timer.restart();

          got_passcode = true;

          std::cout << "Correct Code\n";
        } else {
          for (int i = 1; i <= 4; ++i) {
            buttons[i-1]->setTexture("assets/btn" + std::to_string(i) + "-incorrect.png");
          }

          texture_timer.restart();
          std::cout << "Incorrect Code\n";
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


// ======================== EXAMPLE Wall ========================

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
