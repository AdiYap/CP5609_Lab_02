

#define ROWS 20
#define COLUMNS 20

#include <vector>
#include  "BoardObjectH.h"
#include  "ListBoardObjectsH.h"
#include  "PlayerH.h"
#include  "WallH.h"
#include  "CookieH.h"

typedef  ListBoardObjects* p_ListBoardObjects;

class Board
{

private:

	int the_rows, the_cols;

	bool setOK;
	bool gameOn;
	int lives;
	p_ListBoardObjects   boardSpace[ROWS][COLUMNS];
	int player_id_x;
	int player_id_y;
	Player *startPlayer;
	int currentScore;
	

public:

	Board (int rows, int cols)
	{
	  if ((ROWS >= rows ) && (COLUMNS >= cols)) 
		{ setOK-true; the_rows=rows; the_cols=cols;
                  lives=3000000; gameOn=true;
			for (int i=0;  i<rows; i++)
			  for (int j=0;  j<cols; j++)
			    {
		              BoardObject* aBackground = new BoardObject(i,j);
			      p_ListBoardObjects objectList =new ListBoardObjects(aBackground);
			      boardSpace[i][j]=objectList;
			    }
		    player_id_x =the_rows/2;
		    player_id_y =the_cols/2;
		    startPlayer = new Player(player_id_x,player_id_y);
		    currentScore =0;

                    (boardSpace[player_id_x][player_id_y])->addObject(startPlayer);

	            for	(int i=1; i<the_rows-1; i++)
		       { Wall * aWall = new Wall (i,1);
                         (boardSpace[i][1])->addObject(aWall);
		         aWall = new Wall (i,the_cols-2);
                         (boardSpace[i][the_cols-2])->addObject(aWall);
			}

	            for	(int i=1; i<the_rows-1; i=i+2)
		       { Cookie * aCookie = new Cookie (i,0);
                         (boardSpace[i][0])->addObject(aCookie);
		         aCookie = new Cookie (i,the_cols-1);
                         (boardSpace[i][the_cols-1])->addObject(aCookie);
			}
		}
	  else
		setOK=false;

	};

	bool setBoardOK () {return setOK;};

	void paint();

	void move(char command);

	bool isAlive() {if (0<lives) { lives--; return true;}
                         else return false;}
};
