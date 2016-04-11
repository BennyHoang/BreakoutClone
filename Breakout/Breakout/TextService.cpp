#include "TextService.h"

bool TextService::init()
{
	if(TTF_Init() == 1)
	{
		return false;
	}
	return true;
}
