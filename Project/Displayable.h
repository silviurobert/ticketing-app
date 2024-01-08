#pragma once
#include <iostream>
class Displayable {
public:
	virtual void display() = 0;


};

/*std::ostream& operator<<(std::ostream& out, Displayable& object)
{
	object.display();
	return out;
}*/

