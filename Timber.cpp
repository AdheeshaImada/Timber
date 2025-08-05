// Include important libraries

#include <SFML/Graphics.hpp>


// Make code easier to type with "using namespace"

using namespace sf;


//This is where game starts

int main() {


	/*Window*/

	// Create video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);


	/*Background*/

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


	/*Tree*/

	// Create tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);


	/*Bee*/

	// Create Bee sprite
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	// Is bee currently mooving
	bool isBeeActive = false;

	// How fast bee can fly
	float beeSpeed = 0.0f;


	/*Clouds*/

	//Create texture for clouds
	Texture textureClouds;
	textureClouds.loadFromFile("graphics/cloud.png");

	//Create 3 cloud sprites
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureClouds);
	spriteCloud2.setTexture(textureClouds);
	spriteCloud3.setTexture(textureClouds);
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	// Is clouds currently moving
	bool isCloudsActive = false;

	// Speed of clouds moving
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;


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


		/*Draw game scene here. drawing order matter*/

		// Background
		window.draw(spriteBackground);
		// Clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		// Tree
		window.draw(spriteTree);
		// Bee
		window.draw(spriteBee);

		// Show everything we just draw
		window.display();

	}

	return 0;
}
