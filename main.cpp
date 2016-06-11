#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Environment.h"
#include "Plant.h"

using namespace std;

int main(int argc, char** argv)
{
    //create the outside 
	Environment Outside;
	Outside.SetLightLevel(100,8);  //100% 6am-8pm
	Plant Flower;
	Flower.Put(Outside);

	for (int i=0; i < 200; ++i)
	{
	  Timespan DeltaTime = Timespan::FromMiliseconds(800000);
	  Outside.Tick(DeltaTime);
	  Flower.Tick(DeltaTime);
      //debug
	  Outside.DebugPrint();
	  Flower.DebugPrint();
	}
	//foreach
    return 0;
}
