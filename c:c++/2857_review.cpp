// FBI
#include <iostream>
#include <vector>
using namespace std;
 
string s;
vector<string> v;
vector<int> final;
 
int main()
{
   for(int i=0; i<5; i++){
       cin>>s;
       v.push_back(s);
   }
 
   for(int i=0; i<v.size(); i++){
       for(int j=0; j<=v[i].size()-3; j++){
           string temp;
           for(int k=0; k<3; k++){
               temp += v[i][j+k];
           }
           if(temp=="FBI"){
               final.push_back(i+1);
               break;
           }
       }
   }
 
   for(int i=0; i<final.size(); i++){
       cout<<final[i]<<" ";
   }
   cout<<"\n";
  
   return 0;
}
