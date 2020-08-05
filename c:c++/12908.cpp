// 텔레포트 3
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
 
int start_x, start_y, end_x, end_y, a, b, c, d;
struct subin { int x1, y1, x2, y2;};
vector<subin> V;
vector<int> seq; // 방문할 순서(idx)
long long final = INT_MAX;
 
long long cal(int x, int y, int z, int w)
{
   return abs(z-x) + abs(w-y);
}
 
int main()
{
   cin>>start_x>>start_y;
   cin>>end_x>>end_y;
 
   for(int i=0; i<3; i++){
       cin>>a>>b>>c>>d;
 
       V.push_back({a, b, c, d});
       V.push_back({c, d, a, b});
   }
   V.push_back({end_x, end_y, end_x, end_y});
 
   for(int i=0; i<7; i++){
       seq.push_back(i);
   }
 
   do{
       long long dist = 0;
       int nx = start_x;
       int ny = start_y;
       for(int i=0; i<seq.size(); i++){
           dist += cal(nx, ny, V[seq[i]].x1, V[seq[i]].y1); // 전의 좌표에서 지금 좌표까지의 거리
           if(V[seq[i]].x2==end_x && V[seq[i]].y2==end_y){ // 도착
               break;
           }
           dist += 10; // 텔레포트해서 (x1, y1) -> (x2, y2)로 이동했다.
           // (nx, ny)값 갱신
           nx = V[seq[i]].x2;
           ny = V[seq[i]].y2;
       }
       final = min(final, dist); 
 
   }while(next_permutation(seq.begin(), seq.end()));
 
   cout<<final<<"\n";
   return 0;
}
