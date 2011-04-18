#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class Disk
{
   public:
	Disk(int size);
	Disk();
	~Disk();
    void createArray();
	void displayArray();
	void display();
    void moveDisk(int location, int pole);
	int getPole();
   private:     
	int diskSize;
	int diskLocation;
	int diskPole;
	static int diskCount;
	static int thePlaces[10][3];
};
