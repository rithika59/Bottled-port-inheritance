#include<iostream>
using namespace std;
#include<string.h>

#include "port.h"


Port::Port(const char *br,const char *st,int b)
{
	if(br == 0)
	{
		cout<<"enter valid brand name \n";
	}
	else
	{
//		cout<<"Size of br"<<strlen(br);
		brand = new char[strlen(br)];
		strcpy(brand,br);
	}
	if(st == 0)
	{
		cout<<"enter valid style \n";
	}
	else
	{
		style = new char[strlen(st)];
		strcpy(style,st);
	}
	if(b>0)
	{
		bottle = b;
	}
	else
	{
		cout<<"enter valid bottles number \n";
	}
}

Port::Port(const Port &p)
{
	if(sizeof(brand)!= sizeof(p.brand))
	{
		delete[] brand;
		int m = sizeof(p.brand);
		brand = new char[m+1];
	}
	for(int i=0;i<sizeof(p.brand);i++)
	{
		brand[i] = p.brand[i];
	//	brand[i+1] = 0;
	}
	if(sizeof(style)!= sizeof(p.style))
	{
		delete[] style;
		int m = sizeof(p.style);
		style = new char[m];
	}
	for(int i=0;i<sizeof(p.style);i++)
	{
		style[i] = p.style[i];
		//style[i+1] = 0;
	}
	bottle = p.bottle;
//	p.brand[sizeof(brand)+1] = 0;
}

Port::~Port()
{
	cout<<"calling destructor for"<<this->brand;
	delete[] brand;
	delete[] style;
}

Port& Port::operator=(const Port &p)
{
	if(sizeof(brand)!=sizeof(p.brand))
	{
		delete[] brand;
		brand = new char[sizeof(p.brand)];
	}
	for(int i=0;i<sizeof(p.brand);i++)
	{
		brand[i] = p.brand[i];
		//brand[i+1] = 0;
	}
	if(sizeof(style)!= sizeof(p.style))
	{
		delete[] style;
		int m = sizeof(p.style);
		style = new char[m+1];
	}
	for(int i=0;i<sizeof(p.style);i++)
	{
		style[i] = p.style[i];
		//style[i+1] = 0;
	}
	bottle = p.bottle;
	return *this;
	
}

Port& Port::operator+=(int b)
{
	if(b>0)
	{
		bottle += b;
	}
	else
	{
		cout<<"Enter valid number to add\n";

	}
	return *this;
}
Port& Port::operator-=(int b)
{
	if((bottle-b)>0)
	{
		bottle -= b;
	}
	else
	{
		cout<<"Enter valid number to subtract\n";
	}
	return *this;
	
}
int Port::BottleCount() const
{
	return bottle;
}
void Port::Show() const
{
	cout<<"Brand: "<<brand<<endl;
	cout<<"Kind: "<<style<<endl;
	cout<<"Bottles: "<<bottle<<endl;
}
ostream &operator<<(ostream &os, const Port &p)
{
	os<<p.brand;
	os<<", ";
	os<<p.style;
	os<<", ";
	os<<p.bottle;
	
	return os;
}

VintagePort::VintagePort():Port("None","vintage",0)
{
	nickname = new char[4];
	strcpy(nickname,"none");
	year = 0;
}

VintagePort::VintagePort(const char * br , int b , const char * nn, int y):Port(br,"vintage",b)
{
	nickname = new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year = y;

}

VintagePort::VintagePort(const VintagePort & vp)
{
	if(strlen(nickname)!=strlen(vp.nickname))
	{
		delete[] nickname;
		nickname = new char[strlen(vp.nickname)];
	//	strcpy(nickname,vp.nickname);
	}

		strcpy(nickname,vp.nickname);
		year = vp.year;

}

VintagePort::~VintagePort()
{
	delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort & vp)
{
	if(strlen(nickname) != strlen(vp.nickname))
	{
		delete[] nickname;
		nickname = new char[strlen(vp.nickname)];
	}

	strcpy(nickname,vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	cout<<"Nickname:"<<nickname<<endl;
	cout<<"year:"<<year<<endl;
	Port::Show();

}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os<<vp.nickname;
	os<<", ";
	os<<vp.year;
	os<<".";
	
	
	return os;
}
















































