
#include "base.h"
#include "StackLL.h"
class Item
{
	tree<std::string> content;
	int x;
	int y;
	int depth;
public:
	item(std::string a, int offsetX, int offsetY )
	~item();
	void addFrame(std::string frame);//to add a new frame in the case of a ascii sprite
	void move(int moveX, int moveY); //move from relitive position
	void absM(int moveX, int moveY); //move to position absolutly.
	void draw();//draw this item to the screen
	void step();//if It is a sprite this will step through it 
	void event(std::string e)//move to sprite/frame upon an event

}