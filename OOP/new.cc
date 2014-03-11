#include <iostream>
#include <string.h>

using namespace std;

class StringError{};
class String{

	int capacity_;
	int size_;
	char* buffer_;

	void ensure_capacity(int cap){
	
		if(capacity_>=cap){
			return;
		}
		char* tmp=buffer_;
		capacity_=cap;
		buffer_=new char[capacity_];
		strcpy(buffer_,tmp);
		delete [] tmp;
	}

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
	
	int size() const {
		return size_;
	}
	
	int length() {
		return size_;
	}
	
	bool empty() const {
		return size_==0;
	}
	
	void clear() {
		size_=0;
		buffer_[0]='\0';
	}
	
	char& operator[](int index) {
		return buffer_[index];
	}
	
	char& at(int index) {
		if(index<=size_) {
			return buffer_[index];
		}
		throw StringError();
	}
	
	bool operator==(const String& other) {
		return strcmp(buffer_, other.buffer_);//==0;
	}
	
	bool operator!=(const String& other) {
		return strcmp(buffer_, other.buffer_)!=0;
	}
	
	bool operator<(const String& other) {
		return strcmp(buffer_, other.buffer_)<0;
	}
	
	bool operator>(const String& other) {
		return strcmp(buffer_, other.buffer_)>0;
	}
	
	bool operator<=(const String& other) {
		bool res=strcmp(buffer_, other.buffer_);
		return (res==0 || res<0);
	}
	
	bool operator>=(const String& other) {
		bool res=strcmp(buffer_, other.buffer_);
		return (res==0 || res>0);
	}
	
	String& operator+=(const String& s){
		ensure_capacity(size_+s.size_+1);
		strcat(buffer_,s.buffer_);
		return *this;
	}
	
	//	String(const String& other) {
		//size_=size
	//}
};


ostream& operator<<(ostream& out,const String& s){
	
	out<<s.buffer_;
	return out;

}



int main(){

	String s1("Hello ");
	String s2("World!");
	String s3("");

	cout<<s1<<endl;
	cout<<s2<<endl;
	s1+=s2;
	cout<<s1<<endl;
	cout<<s3.empty()<<endl;	
	//cout<<s1.size()<<endl;	
	cout<<s1.length()<<endl;	
	cout<<s2.length()<<endl;	
	cout<<(s1==s2)<<endl;
	
	return 0;
}

