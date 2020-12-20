#include "Executable.h"


void Executable::run()
{
	sf::Event event;
	sf::Font font;

	//creates main window
	Window window(1200, 900, "Map Builder");

	Intro intro;
	sf::Vector2i size = intro.run();

	float scale = 0;

	if (size.x == size.y && size.x == -1)
		scale = 10;
	else if (size.x > size.y)
		scale = size.x;
	else
		scale = size.y;

	Map map(size.x, size.y, (80 * 10 / scale));
	//sets location of the map based on window
	map.set_location(window);

	std::fstream file;

	file.open("Board.txt", std::ios::out | std::ios::app);
	file.close();
	file.open("Board.txt", std::ios::in | std::ios::out | std::ios::app);

	//sets ui
	Ui ui(window, font, map);
	
	//renders main window
	sf::RenderWindow main_window(sf::VideoMode(window.get_width(), window.get_height()), window.get_name());
	

	//main window
	while (main_window.isOpen())
	{
		main_window.clear(sf::Color::Black);
	

		//--------------------------------------------------------------------------------
		sf::Mouse mouse;
			
		auto location = main_window.mapPixelToCoords(
			{ mouse.getPosition(main_window).x, mouse.getPosition(main_window).y });


		ui.handle_mouse_over(location);

		//--------------------------------------------------------------------------------
		//draws all of the ui
		ui.Draw(main_window);
		
		main_window.display();


		while (main_window.pollEvent(event))
		{	
			switch (event.type)
			{
				case(sf::Event::Closed):
					main_window.close();
					break;

				case sf::Event::MouseButtonPressed:
				{
					auto location = main_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });

					switch (event.mouseButton.button)
					{
						case sf::Mouse::Button::Left:
						{
							hadle_click(location, ui);
						break;
						}
					break;
					}
					break;
				}
				case sf::Event::MouseButtonReleased:
				{
					auto location = main_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });

					switch (event.mouseButton.button)
					{
					case sf::Mouse::Button::Left:
					{
						hadle_release(location, ui);
						break;
					}
					break;
					}
				}
				break;
			}
		}
	}
	file.close();
}

void Executable::hadle_click(sf::Vector2f &location, Ui & ui)
{
	ui.hadle_click(location);
}

void Executable::hadle_release(sf::Vector2f& location, Ui& ui)
{
	ui.handle_relese(location);
}
