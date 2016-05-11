#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Wilderness.h"

using namespace std;

int main(int argc, char** argv)
{
    //create the outside 
	Environment Outside;
	Outside.LightLevel(100,8);  //100% 6am-8pm
	Plant Flower;
	Flower.Put(Outside);

	for (int i=0; i < 100; ++i)
	{
	  size_t DeltaTime = 864;
	  Outside.Tick(DeltaTime);
	  Flower.Tick(DeltaTime);
      //debug
	  Outside.DebugPrint();
	  Flower.DebugPrint();
	}
	//foreach
    return 0;
}
