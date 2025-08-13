/* Include important libraries*/

// Graphics
#include <SFML/Graphics.hpp>
// String manipulation
#include <sstream>


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
	bool isCloud1Active = false;
	bool isCloud2Active = false;
	bool isCloud3Active = false;

	// Speed of clouds moving
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;


	/*Time*/

	// Variable to contrall time itself
	Clock clock;

	// Track whether the game is runing
	bool paused = true;

	// Score
	int score = 0;

	/* Text */

	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	// Score Text
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Score : 0");
	scoreText.setCharacterSize(100);
	scoreText.setFillColor(Color::White);

	// Message Text
	Text messageText;
	messageText.setFont(font);
	messageText.setString("Press ENTER to start");
	messageText.setCharacterSize(75);
	messageText.setFillColor(Color::White);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);


	// Game loop
	while (window.isOpen()) {

		//handle the player inputs

		// Exit
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			paused = false;
		}

		/*Update the scene */

		if (!paused) { // Chech whether game paused or not

			// Mesure the time
			Time dt = clock.restart();

			//  Setup the bee
			if (!isBeeActive) {
				// How fast is the Bee
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;
				// How high is the Bee
				srand((int)time(0) * 10);
				float hight = (rand() % 500) + 500;
				spriteBee.setPosition(2000, hight);
				// Set Bee active
				isBeeActive = true;
			}
			else {
				//Move the bee
				spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
				//Bee reached the lest end
				if (spriteBee.getPosition().x < -100) {
					isBeeActive = false;
				}
			}

			//setup the clouds
			// Cloud 1
			if (!isCloud1Active) {
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				// How high is the cloud1
				srand((int)time(0) * 10);
				float hight = (rand() % 150);
				spriteCloud1.setPosition(-200, hight);
				//set cloud active
				isCloud1Active = true;
			}
			else {
				//Move the cloud1
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
				//cloud reach the right end
				if (spriteCloud1.getPosition().x > 1920) {
					isCloud1Active = false;
				}
			}

			// Cloud 2
			if (!isCloud2Active) {
				// How fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				// How high is the cloud1
				srand((int)time(0) * 20);
				float hight = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, hight);
				//set cloud active
				isCloud2Active = true;
			}
			else {
				//Move the cloud1
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
				//cloud reach the right end
				if (spriteCloud2.getPosition().x > 1920) {
					isCloud2Active = false;
				}
			}

			// Cloud 3
			if (!isCloud3Active) {
				// How fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				// How high is the cloud1
				srand((int)time(0) * 30);
				float hight = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, hight);
				//set cloud active
				isCloud3Active = true;
			}
			else {
				//Move the cloud1
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
				//cloud reach the right end
				if (spriteCloud3.getPosition().x > 1920) {
					isCloud3Active = false;
				}
			}

			// Update the Score text
			std::stringstream ss;
			ss << "Score: " << score;
			scoreText.setString(ss.str());

		}


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

		// Score
		window.draw(scoreText);

		// Message
		if (paused) {
			window.draw(messageText);
		}


		// Show everything we just draw
		window.display();

	}

	return 0;
}
