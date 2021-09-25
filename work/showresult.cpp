#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
using namespace std;

void Color(int x) {
	/*	7为默认白色
		0 = 黑色                8 = 灰色　　
		1 = 蓝色                9 = 淡蓝色
		2 = 绿色                10 = 淡绿色
		3 = 湖蓝色              11 = 淡浅绿色
		4 = 红色                12 = 淡红色
		5 = 紫色                13 = 淡紫色
		6 = 黄色                14 = 淡黄色
		7 = 白色                15 = 亮白色	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

int main(){
	ifstream fin;
	fin.open("tmp.txt");
	
	Color(7); 
	string s = "", sc;
	while(getline(fin, sc)){
		s += sc;
		s += '\n';
	}

	int num = s.size();
	for(int i=0;i<s.size();i++){
		if(s[i] == ']') Color(7);
		cout << s[i];
		if(s[i] == '['){
			if(s[i+1] == 'A') Color(10);
			else if(s[i+1] == 'W') Color(4);
		}
	}
	
	fin.seekg(0, ios_base::beg);
	fin.close();
    
	return 0;
}
