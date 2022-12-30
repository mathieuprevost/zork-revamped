////////////////////////////////////////////////////////////////////////////////
/// File	 Game.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class Game
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "World.hpp"
#include "Room.hpp"
#include "Link.hpp"
#include "Object.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>

class Game {
public:
	Game();

	void start();
	void changeRoom(char direction);
	void processInput(std::string& input);
	void sliceInput(std::string& input);
	void lowerInput(std::string& input);

private:
	std::unique_ptr<World> world_;
	std::string name_ = "THE QUEST OF THE LOST PROJECT";
	std::string input_;
	std::string inputExtension_ = "";
	Room* position_ = nullptr;

	std::unordered_map<std::string, std::function<void()>> inputDictionary_ = {
		{"n",		[this]() { return changeRoom(Directions::North); }},
		{"north",	[this]() { return changeRoom(Directions::North); }},
		{"s",		[this]() { return changeRoom(Directions::South); }},
		{"south",	[this]() { return changeRoom(Directions::South); }},
		{"e",		[this]() { return changeRoom(Directions::East);	 }},
		{"east",	[this]() { return changeRoom(Directions::East);  }},
		{"w", 		[this]() { return changeRoom(Directions::West);  }},
		{"west",	[this]() { return changeRoom(Directions::West);  }},
		{"exit",
		[]() { std::cout << "\nGoodbye! Please leave a review if you enjoyed!\n"; }},
		{"look",
		[this]() { 
			if (!inputExtension_.empty()) {
				Object* object = position_->findObject(inputExtension_);
				if (object != nullptr)
					std::cout << object->getDescription() << std::endl;
				else {
					std::cout	<<	"Could not find this object in this room."
								<<	" Try different key words." << std::endl;
				}					
			}
			else
				return position_->display(std::cout);
			}
		},
		{"use",
		[this]() { 
			if (!inputExtension_.empty()) {
				Object* object = position_->findObject(inputExtension_);
				if (object != nullptr) 
					object->use(std::cout);
				else {
					std::cout	<<	"Could not find this object in this room."
								<<	" Try different key words." << std::endl;
				}
			}
			else
				std::cout << "You must specify an object to use it." << std::endl;  
			}
		}		
	};
};