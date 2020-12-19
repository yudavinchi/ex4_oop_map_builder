#include "Executable.h"
#define ADD_BUTTON_PRESSED 10
#define DELETE_BUTTON_PRESSED 30


void Executable::run()
{

	
	//Intro intro;

	//sf::Vector2i size = intro.run();

	sf::Font font;

	font.loadFromFile("arial.ttf");

	Map map(10, 10, 30,font);
	
	sf::Event event;

	//creates main window
	Window window(1152, 872, "new");

	//sets location of the map based on window
	map.set_location(window);

	//sets ui
	Ui ui(window,font, map);
	
	//renders main window
	sf::RenderWindow main_window(sf::VideoMode(window.get_width(), window.get_height()), window.get_name());
	

	//main window
	while (main_window.isOpen())
	{
		main_window.clear(sf::Color::White);
	

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

				case sf::Event::MouseButtonReleased:
				{
					auto location = main_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });

					switch (event.mouseButton.button)
					{
						case sf::Mouse::Button::Left:
						{
						handle_click_non_pressed(location, ui);
						break;
						}
					break;
					}
				}
			}
		}


	}

}

void Executable::handle_click_non_pressed(sf::Vector2f &location, Ui & ui)
{
	ui.hadle_click(location);
}


