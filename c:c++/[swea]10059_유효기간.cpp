// 10059. 유효기간
#include <iostream>
#include <vector>
using namespace std;
 
int testcase;
string s;
vector<string> validation;
string month[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
vector<string> final;
 
int main()
{
   cin>>testcase;
   for(int i=0; i<testcase; i++){
       cin>>s;
       validation.push_back(s);
   }
 
   for(int i=0; i<validation.size(); i++){
       // 앞 두 글자 01~12인지 확인
       string first;
       first += validation[i][0];
       first += validation[i][1];
 
       bool check_first = false;
       for(int j=0; j<12; j++){
           if(first==month[j]){
               check_first = true;
               break;
           }
       }
      
       string second;
       second += validation[i][2];
       second += validation[i][3];
 
       bool check_second = false;
       for(int j=0; j<12; j++){
           if(second==month[j]){
               check_second = true;
               break;
           }
       }
      
       if(check_first==true && check_second==true){ // 애매한 경우
           final.push_back("AMBIGUOUS");
       }else if(check_first==true && check_second==false){ // MMYY인 경우
           final.push_back("MMYY");
       }else if(check_first==false && check_second==true){ // YYMM인 경우
           final.push_back("YYMM");
       }else{ // NA인 경우
           final.push_back("NA");
       }
   }
 
   for(int i=0; i<final.size(); i++){
       cout<<"#"<<i+1<<" "<<final[i]<<"\n";
   }
  
   return 0;
}
