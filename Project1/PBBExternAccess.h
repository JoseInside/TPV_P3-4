#pragma once
class PBBExternAccess
{
public:

	PBBExternAccess()
	{
	}

	virtual ~PBBExternAccess()
	{
	}
	

	virtual void setDirectionX(int dx) = 0;
	virtual void setDirectionY(int dy) = 0;

	virtual int getDirectionX() = 0;
	virtual int getDirectionY() = 0;
	
	virtual int getTotalClicks() = 0;
	virtual void setPoints(int pointsAssigned) = 0;
	virtual int getPoints() = 0;
	virtual void addGlobalPoints(int globalPoints) = 0;
	virtual void setActive(bool active) = 0;
};

