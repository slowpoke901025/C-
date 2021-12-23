#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream> // stringstream
#include<iomanip> // setw
#include<algorithm> //sort
using namespace std;

class Info
{
	string name;
	unsigned id;
 
 	public:
 		
		Info(unsigned int id, string name)
		{
		  this->id = id;
		  this->name = name;
		}
		
		friend ostream& operator<<(ostream &output, const Info &v); // 輸出Info物件
		static bool cmp(Info &v1, Info &v2); // 排序函式
	
};

bool Info::cmp(Info &v1, Info &v2) // 排序函式實作
{
 	return v1.id < v2.id; // ascending, descending => v1.id > v2.id
}

ostream& operator<<(ostream &output,const Info &V)  //輸出Info物件
{
	output<<left<<setw(14)<<V.id<<setw(10)<<V.name<<'*'<<endl;
	return output;
}

ostream& operator<<(ostream &output,const vector<Info> &v) // 輸出vector aka 一次輸出所有Info物件
{
	for(int i=0;i<v.size();i++)
	{
		output<<v[i];
	}
 	return output;
}



int main(int argc, char *argv[])
{
	vector<Info> V;
	
	string input;
	getline(cin,input); //一次讀入所有input ，遇到'\n'停止
	stringstream ss(input); //存入 ss
	 
	
	string name;
	unsigned int id;
	while(1)
	{
		ss>>id>>name; //利用ss特性，每次讀入一字串，遇到空格停止
		if(ss.fail())break; //讀完跳出迴圈
		V.push_back(Info(id,name));// push 進 vector
	}
	
	
	sort(V.begin(),V.end(),Info::cmp); //排序
	
	cout<<V;  //印出vector內所有Info物件
	
	fstream file; //建立文件
	file.open("result.txt",ios::out);
	file<<V; //寫入
	file.close();

}
