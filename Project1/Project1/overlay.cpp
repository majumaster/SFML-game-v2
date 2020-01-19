#include "overlay.h"
#include "random.h"
overlay::overlay()
{
	rect.setPosition(500, 400);
	//...

}
void overlay::update()
{

	sprite.setPosition(rect.getPosition());
}