#include "Executable.h"


void Executable::run()
{
	//should move it somewhere else?
	int num_of_buttons = 0;
	// Declare and load a font - should be member of window?
	sf::Font font;
	font.loadFromFile("arial.ttf");

	//creaates main window
	Window window(1152, 872, "new");

	//renders main window
	sf::RenderWindow main_window(sf::VideoMode(window.get_width(), window.get_height()), window.get_name());
	
	//creates side pannel
	SidePannel side_pannel(window.get_height(), window.get_width());

	//sets location - just for checking if it works - should be held with the rest inside a member?
	sf::Vector2f location(10,20);
	//should be initialized with window? or atleast after inserting size of board
	Button new_button(location, 50, 200, font, "Delete");
	//-puts it in vector of buttons
	m_button.push_back(new_button);
	//this aswell should be moved out
	++num_of_buttons;


	//main window
	while (main_window.isOpen())
	{
	
		//clears
		main_window.clear();
		
		//prints all
		side_pannel.draw(main_window);

		new_button.Draw(main_window);

		//displays
		main_window.display();

		//to handle events
		sf::Event event;
		
		while (main_window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				main_window.close();
				break;
			
			case(sf::Event::MouseButtonPressed):
				//sets location based on main window and not on the screen
				auto location = main_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				//handles both right and left clicks - should change
				handle_click(location, num_of_buttons);
				break;
			}
		}
	}
}


//handles clicks
void Executable::handle_click(sf::Vector2f location, int number_of_buttons)
{
	//runs on button
	for (int i = 0; i < number_of_buttons; ++i) {
		m_button[i].handle_click_button(location);
	}
}