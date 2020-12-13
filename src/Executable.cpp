#include "Executable.h"


void Executable::run()
{

	// Declare and load a font
	sf::Font font;
	font.loadFromFile("arial.ttf");

	// Create a text
	sf::Text text("button", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	text.setPosition(20, 10);
	
	Window window(2000, 1200, "new");

	sf::RenderWindow main_window(sf::VideoMode(window.get_width(), window.get_height()), window.get_name());

	sf::RectangleShape rectangle(sf::Vector2f(300, 1200));

	// ~~~ button 1 ~~~

	sf::RectangleShape button_1(sf::Vector2f(250, 50));

	button_1.setPosition(20, 10);

	button_1.setFillColor(sf::Color::Yellow);

	// ~~~ button 2 ~~~

	sf::RectangleShape button_2(sf::Vector2f(250, 50));

	button_2.setPosition(20, 80);

	button_2.setFillColor(sf::Color::White);

	// ~~~ button 3 ~~~

	sf::RectangleShape button_3(sf::Vector2f(250, 50));

	button_3.setPosition(20, 150);

	button_3.setFillColor(sf::Color::Green);

	rectangle.setFillColor(sf::Color::Blue);

	//sf::Text::getLocalBounds()


	while (main_window.isOpen())
	{
		main_window.clear();
		main_window.draw(rectangle);
		main_window.draw(button_1);
		main_window.draw(button_2);
		main_window.draw(button_3);
		main_window.draw(text);
		main_window.display();

		sf::Event event;
		
		while (main_window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				main_window.close();
				break;
			
			case(sf::Event::MouseButtonPressed):
				std::cout << "Click\n" << sf::Event::;
				break;
			}
		}
	}
}
