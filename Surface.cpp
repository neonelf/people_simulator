#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "Surface.h"

Surface::Surface(int sizeX, int sizeY) : m_maxX(sizeX), m_maxY(sizeY)
{
	m_pBoard = (char*)calloc(m_maxX, m_maxY);
	Erase();
}

Surface::~Surface()
{
	free(m_pBoard);
}

void Surface::DrawAt(int x, int y, char symbol)
{
	//TODO bounds checking
	m_pBoard[x+(m_maxX*y)] = symbol;
}
	
void  Surface::DrawBorder(Surface& visual)
{
	for (int x=0; x < m_maxX; ++x)
    {
		visual.DrawAt(x, 0, '-');
	    visual.DrawAt(x, m_maxY-1, '-');
	}

	for (int y=1; y < m_maxY; ++y)
	{
		visual.DrawAt(0, y, '|');
		visual.DrawAt(m_maxX-1, y, '|');
	}
}


void Surface::Refresh()
{
	DrawBorder(*this);
	//draw
	char curLine[m_maxX+1];
	for (int i=0; i < m_maxY; ++i)
	{
		memcpy((void*)curLine, m_pBoard+(i*m_maxX), m_maxX);
		curLine[m_maxX] = '\0';
		printf("%s\n",curLine);
	}
	Erase();
}

void Surface::Erase()
{
	memset((void*)m_pBoard, 32, (m_maxX*m_maxY));
}

void Surface::DrawAt(MapLocation loc, char symbol)
{
	DrawAt(loc.x, loc.y, symbol);
}
