////////////////////////////////////////////////////////////////////////////////
/// File	 Object.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class Object
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include"Link.hpp"
#include <string>
#include <vector>
#include <sstream>

class Link;

class Object {
public:
	Object() = default;
	Object(	const std::string& name, const std::string& description,
			const std::string& action, const std::vector<std::string>& keyWords, bool visible) :
		name_(name),
		description_(description),
		action_(action),
		keyWords_(keyWords),
		visible_(visible)
	{}

	virtual ~Object() = default;

	void displayAction(std::ostream& os) { os << action_ << std::endl; }
	void reveal() { visible_ = true; };
	virtual void use(std::ostream& os) { displayAction(os); };

	const std::string& getName() const { return name_; }
	const std::string& getDescription() const { return description_; }
	const std::string& getAction() const { return action_; }
	const std::vector<std::string>& getKeyWords() const { return keyWords_; }
	bool getVisible() const { return visible_; }

private:
	std::string name_;
	std::string description_;
	std::string action_;
	std::vector<std::string> keyWords_;
	bool visible_ = true;
};