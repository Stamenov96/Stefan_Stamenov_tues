#include <iostream>
#include <string.h>

using namespace std;

class String{

	int capacity_;
	int size_;
	char* buffer_;
	friend ostream& operator<<(ostream&,const String&);
public: 
		
	String(int capacity)
	:	capacity_(capacity),
		size_(0),
		buffer_(new char[capacity_])
	{
		buffer_[0]='\0';
	}

	~String(){
		delete [] buffer_;
	}
	
	String(const char* str)
	:	capacity_(0),
		size_(0),
		buffer_(0)
	{
		size_=strlen(str);
		capacity_=size_+1;
		buffer_=new char[capacity_];
		strcpy(buffer_,str);
	}
	

};


ostream& operator<<(ostream& out,const String& s){
	
	out<<s.buffer_;
	return out;

}



int main(){

	String s1("Hello");
	String s2("World!");

	cout<<s1<<endl;
	cout<<s2<<endl;

	return 0;
}
