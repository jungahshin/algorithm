// 트리(벡터이용 -> 시간초과)
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
 
int testcase, n, node;
vector<int> preorder;
vector<int> inorder;
 
vector<int> slice(const vector<int> &v, int a, int b){
   return vector<int>(v.begin()+a, v.begin()+b);
}
 
void postorder(const vector<int> &preorder, const vector<int> &inorder)
{
   if(preorder.empty()){
       return;
   }
 
   int N = preorder.size();
 
   int root = preorder[0];
 
   int L;
   for(int i=0; i<N; i++){
       if(root==inorder[i]){
           L = i;
           break;
       }
   }
 
   postorder(slice(preorder, 1, L+1), slice(inorder, 0, L)); // left
   postorder(slice(preorder, L+1, N), slice(inorder, L+1, N)); // right
 
   printf("%d ", root); // root
}
 
int main()
{
   scanf("%d", &testcase);
   for(int i=0; i<testcase; i++){
       inorder.clear();
       preorder.clear();
       scanf("%d", &n);
       // 전위순회(preorder)
       for(int j=0; j<n; j++){
           scanf("%d", &node);
           preorder.push_back(node);
       }
 
       // 중위순회(inorder)
       for(int j=0; j<n; j++){
           scanf("%d", &node);
           inorder.push_back(node);
       }
 
       postorder(preorder, inorder);
       printf("\n");
   }
 
   return 0;
}
