#include<iostream>

//class CopyBan
//{
//public:
//	CopyBan() {}
//	CopyBan(const CopyBan& self) = delete;
//	CopyBan& operator=(const CopyBan& self) = delete;
//};

class CopyBan
{
public:
	CopyBan() {}
private:
	CopyBan(const CopyBan& self);
	CopyBan& operator=(const CopyBan& self);
};



int main()
{
	CopyBan cb1;
	//CopyBan cb2 = cb1;
	//CopyBan cb3(cb1);
	return 0;
}