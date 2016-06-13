#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "Map.h"

class Surface
{
  public:
  	Surface(int sizeX, int sizeY);
	~Surface();
	void DrawAt(MapLocation loc, char symbol);
  	void DrawAt(int x, int y, char symbol);
	void Refresh();
	void Erase();
	void DrawBorder(Surface& visual);
	int MaxX() {return m_maxX;}
	int MaxY() {return m_maxY;}

  protected:
  	char* m_pBoard;
	const int m_maxX, m_maxY;

  private:
    Surface();

};

#endif //__SURFACE_H__
