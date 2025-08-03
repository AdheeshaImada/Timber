// Include important libraries

#include <SFML/Graphics.hpp>


// Make code easier to type with "using namespace"

using namespace sf;


//This is where game starts

int main() {

	// Create video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Game loop
	while (window.isOpen()) {

		//handle the player inputs

		// Exit
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Update the scene

		// Draw the scene

		//clear everything from last frame
		window.clear();

		//Draw game scene here

		// Show everything we just draw
		window.display();

	}

	return 0;
}