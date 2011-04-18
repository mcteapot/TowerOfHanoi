#include "Disk.h"


int Disk::diskCount = 0;
int Disk::thePlaces[10][3];
Disk::Disk() {
	diskLocation = diskSize = ++diskCount;
	diskPole = 1;
	//cout<<"Disk "<<diskSize<<" born"<<endl;
}
Disk::Disk(int size) {
	diskSize = size;
	diskLocation = ++diskCount;
	diskPole = 1;
	//cout<<"Disk "<<diskSize<<" born"<<endl;

}
Disk::~Disk() {
	//cout<<"Disk "<<diskSize<<" just died"<<endl;
}

void Disk::createArray() {
	//diskCount = 0;
	//diskPole = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			thePlaces[i][j] = 0;
		}
	}


}

void Disk::resetData() {
	diskCount = 0;
	diskPole = 1;
}

void Disk::displayArray() {
	for (int i = 9; i >= 0; i--) {
		for (int j =0; j < 3; j++) {
			cout << thePlaces[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void Disk::display() {
	switch (diskPole) {
		case 1:
			cout << "  " << "< " << diskSize << " >" << endl;
			break;
		case 2:
			cout << "test";
			break;
		case 3:
			cout << "test";
			break;
		default:
			break;
	}
	//cout<<"I am disk "<<diskSize<<endl;
}

void Disk::moveDisk(int location, int pole) {
	thePlaces[(diskLocation-1)][(diskPole-1)] = 0;
	thePlaces[(location-1)][(pole-1)] = diskSize;
	diskLocation = location;
	diskPole = pole;
}  

int Disk::getPole() {
	return diskPole;

}
int Disk::getLocation() {
	return diskLocation;
}