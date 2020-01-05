#include <vector>
#include  "BoardObjectH.h"
#include  "PlayerH.h"
#include  "CookieH.h"
#ifndef H_LIST_OF_OBJECTS
#define H_LIST_OF_OBJECTS
typedef BoardObject* p_BoardObject;


class  ListBoardObjects
{
	std::vector <p_BoardObject> list;
	std::vector < p_BoardObject>::iterator internalIterator;
public:
	ListBoardObjects(p_BoardObject theFirstObject);

	p_BoardObject theFirstObject();
	p_BoardObject theNextObject();
	void addObject(p_BoardObject newObject);
	void removeOnePlayer();
	bool isThereAWall();
	int isCookieValue();
};
#endif
