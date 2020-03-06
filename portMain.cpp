#include<iostream>
using namespace std;
#include<string.h>
#include"port.h"

int main()
{
	char brr[1024];
	char st[20];
	int bt=0;
	cout<<"Enter name of a brand \n";
	cin>>brr;
	cout<<"Enter the style of the brand\n";
	cin>>st;
	cout<<"Enter number of bottles \n";
	cin>>bt;
	char *br = NULL;
	char *stt = NULL;
	br = new char[strlen(brr)];
	stt = new char[strlen(st)];
	strcpy(br,brr);
	strcpy(stt,st);
	Port p1((const char*)br,(const char*)stt,bt);
	p1.Show();
	Port p2("Galleo", "tawny",20);
//	Port p2;
	p1.Show();
	cout<<p1.BottleCount();
	cout<<"After reducing"<<(p1-=(1));
	cout<<"After Increasing by 2"<<(p1+=(2));
	p2.Show();
	cout<<p1;
	delete[] br;
	delete[] stt;

	VintagePort v1("Some brand",20,"frost",1900);
	v1.Show();
	cout<<v1;
	return 0;
}
