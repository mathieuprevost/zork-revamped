////////////////////////////////////////////////////////////////////////////////
/// File	 Game.cpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the methods of the class Game
////////////////////////////////////////////////////////////////////////////////

#include"Game.hpp"

Game::Game() {
	world_ = std::make_unique<World>(World());
}

void Game::start()
{
	//Setting initial room
	position_ = world_->getRoom(Rooms::entrance);

	//Begin display
	std::cout	<< ">>>> " + name_ + " 2021 <<<<"
				<< std::endl
				<< std::endl;
	position_->display(std::cout);

	do  {
		std::cout << "\n> ";
		std::getline(std::cin, input_);
		processInput(input_);
	} while (input_ != "exit");
}

void Game::changeRoom(char direction)
 {
	 if (position_->checkDirection(direction)) {
		 position_ = position_->getRoom(direction);
		 std::cout	<<	"Going " + position_->charToString(direction)
					<<	std::endl 
					<<	std::endl
					<<	"==== " + position_->getName()
					<<	" ====" << std::endl;
		 position_->display(std::cout);
	 }
	 else
		 std::cout << "Can't go there" << std::endl;
}

void Game::processInput(std::string& input)
{
	lowerInput(input);
	sliceInput(input);
	if (inputDictionary_.find(input) != inputDictionary_.end())
		inputDictionary_[input]();
	else
		std::cout << "I don't know that." << std::endl;
	inputExtension_ = "";
}

void Game::sliceInput(std::string& input)
{
	std::size_t spacePosition = input.find(" ");
	if (spacePosition != std::string::npos) {
		inputExtension_ =
			input.substr(spacePosition + 1, input.size());
		input.erase(spacePosition, input.size());
	}
}

void Game::lowerInput(std::string& input) 
{
	transform(	input.begin(), input.end(), input.begin(),
				[](unsigned char c) { return (char)tolower(c); });
}