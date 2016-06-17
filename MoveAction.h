#ifndef __MOVEACTION_H__
#define __MOVEACTION_H__

#include "Map.h"
#include "Action.h"

typedef enum _Direction { DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_MAX }enumDirection;

//moveable objects 
class IMovable 
{
public:
	void SetLocation(const MapLocation& NewLocation) { m_curLocation = NewLocation;}
	virtual MapLocation GetCurrentLocation() const {return m_curLocation;}

protected:
	MapLocation m_curLocation;
};

class MoveAction : public IAction
{
public: 
	MoveAction(enumDirection Dir, IMovable &Obj):m_Dir(Dir), m_ObjToMove(Obj) {}
    //from IAction
    virtual void Execute();
protected:
	enumDirection m_Dir;
	IMovable &m_ObjToMove;
private:
	MoveAction(); //can't use this
};


#endif //__MOVEACTION_H__
