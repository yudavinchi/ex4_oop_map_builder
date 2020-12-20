#include "Executable.h"


void Executable::run()
{
	Intro intro;

	sf::Vector2i size = intro.run();
	//sf::Vector2i size(10, 20);
	sf::Font font;

	float scale = 0;

	if (size.x > size.y)
		scale = size.x;
	else
		scale = size.y;

	Map map(size.x,size.y,60 * 10 / scale);

	sf::Event event;

	//creates main window
	Window window(1200, 900, "Map Builder");

	//sets location of the map based on window
	map.set_location(window);

	//sets ui
	Ui ui(window,font, map);
	
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
}

void Executable::hadle_click(sf::Vector2f &location, Ui & ui)
{
	ui.hadle_click(location);
}

void Executable::hadle_release(sf::Vector2f& location, Ui& ui)
{
	ui.handle_relese(location);
}
