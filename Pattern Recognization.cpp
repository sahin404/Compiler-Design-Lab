#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> gmailStore, KeywordStore, WebaddresStore, NumberStore;
int cnt1 = 0, cnt2 =0, cnt3=0, cnt4=0;

bool ChkLetterValidation(char chr){
	if((chr>='A' && chr<='Z') || (chr>='a' && chr<='z') || (chr>='0' && chr<='9')) return true;
	return false;
}


//Gmail Checking
bool GmailChecking(){
	
	int flag=0, PartCount = 0;
	string gmail="";
	for(int i=0; i<s.size(); i++){
		if(ChkLetterValidation(s[i])==true && flag==0){
			PartCount=1;
			gmail.push_back(s[i]);
			continue;
		}
		if(s[i]=='@' && PartCount==1 && flag==0){
			PartCount=2;
			flag=1;
			gmail.push_back(s[i]);
			continue;
		}
		if(flag==1 && (s[i]>='a' && s[i]<='z')){
			PartCount = 3;
			gmail.push_back(s[i]);
			continue;
		}
		if(s[i]=='.' && PartCount==3){
			PartCount=4;
			flag=2;
			gmail.push_back(s[i]);
			continue;
		}
		if(flag==2 && (s[i]>='a' && s[i]<='z')){
			PartCount=5;
			gmail.push_back(s[i]);
			continue;
		}
		else{
			break;
		}
	}
	if(PartCount == 5){
		cnt1++; 
		if(cnt1==1) gmailStore.push_back("#Gmail List:");
		gmailStore.push_back(gmail); 
		return true;
	}
	return false;
}

bool NumberChecking(){
	int step = 0;
	for(int i=0; i<s.size(); i++){
		if(s[0]=='+' || s[0]=='-' || (s[0]>='0' && s[0]<='9') && step==0){
		step = 1;
		continue;
		}
		if(step==1 && s[i]=='.'){
			step = 2;
			continue;
		}
		if(step==1 && s[i]>='0' && s[i]<='9'){
			continue;
		}
		if(step==2 && s[i]>='0' && s[i]<='9'){
			continue;
		}
		else{
			return false;
		}
	}


	cnt2++;
	if(cnt2==1)	NumberStore.push_back("#Number List:");
	NumberStore.push_back(s);
	return true;

}


//Keywors Cheking
bool KeywordChecking(){
	vector<string> vecString{"int", "char", "double", "float", "bool", "long long", "continue", "break", "if" };
	for(int i=0; i<9; i++){
		if(s==vecString[i]){
			cnt3++;
			if(cnt3==1) KeywordStore.push_back("#Keyword List: ");
			KeywordStore.push_back(s);
			return true;
		}
	}
	return false;
}

//Webaddres checkking

bool WebaddresChecking(){
	int cnt = 0, PartCount = 0, flag=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='w'){ 
			cnt++;
			continue;
		}
		if(cnt==3 && s[i]=='.' && PartCount==0){
			PartCount = 2;
			continue;
		}
		if(PartCount==2 && ChkLetterValidation(s[i])==true){
			flag=1;
			continue;
		}
		if(flag==1 && s[i]=='.'){
			PartCount=3;
			continue;
		}
		if(PartCount==3 && ChkLetterValidation(s[i])==true){
			PartCount=4;
			continue;
		}
		else{
			break;
		}
	}

	if(PartCount==4){
		cnt4++;
		if(cnt4==1) WebaddresStore.push_back("#Webaddres List: ");
		WebaddresStore.push_back(s);
		return true;
	}
	return false;
}

int main()
{	
	int check=0;
	ifstream inputFile("C:/Users/SAHIN/Desktop/test.txt"); 
    while (inputFile >> s) {
    	check=1;
    	KeywordChecking();
		NumberChecking();
		GmailChecking();
		WebaddresChecking();
    }
    inputFile.close();

	
	//printing Section
	if(!check){
		cout<<"NOT FOUND ANY TEXT"<<endl;
	}
	check = 0;
	for(auto i: KeywordStore){
		check++;
		if(check>1) cout<<" "<<check-1<<". ";
		cout<<i<<endl;
	}
	check = 0;
	for(auto i: NumberStore){
		check++;
		if(check>1) cout<<" "<<check-1<<". ";
		cout<<i<<endl;
	}
	check = 0;
	for(auto i: gmailStore){
		check++;
		if(check>1) cout<<" "<<check-1<<". ";
		cout<<i<<endl;
	}
	check = 0;
	for(auto i: WebaddresStore){
		check++;
		if(check>1) cout<<" "<<check-1<<". ";
		cout<<i<<endl;
	}	
	
}