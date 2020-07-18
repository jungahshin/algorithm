// 트리(idx이용)
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
 
int testcase, n, node;
int preorder[1001] = {0, };
int inorder[1001] = {0, };
map<int, int> m;
 
void postorder(int x, int y, int w, int z)
{
   if(x>y || w>z){
       return;
   }
 
   int root = preorder[x];
   int L = m[root];
 
   postorder(x+1, x+(L-w), w, L-1); // left
   postorder(x+(L-w)+1, y, L+1, z); // right
 
   printf("%d ", root); // root
}
 
int main()
{
   scanf("%d", &testcase);
   for(int i=0; i<testcase; i++){
       scanf("%d", &n);
       // 전위순회(preorder)
       for(int j=0; j<n; j++){
           scanf("%d", &node);
           preorder[j] = node;
       }
 
       // 중위순회(inorder)
       for(int j=0; j<n; j++){
           scanf("%d", &node);
           inorder[j] = node;
           m[node] = j;
       }
 
       postorder(0, n-1, 0, n-1);
       printf("\n");
   }
 
   return 0;
}
