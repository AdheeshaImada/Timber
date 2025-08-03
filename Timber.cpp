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

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Attach the texture to the sprite
	spriteBackground.setPosition(0, 0);

	// Game loop
	while (window.isOpen()) {

		//handle the player inputs

		// Exit
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Update the scene

		//clear everything from last frame
		window.clear();

		//Draw game scene here
		window.draw(spriteBackground);

		// Show everything we just draw
		window.display();

	}

	return 0;
}