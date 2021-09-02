#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int a, b, n, m;
bool visited[100001] = {false, };
int stone[100001] = {0, };

int main()
{
    scanf("%d %d %d %d", &a, &b, &n, &m);    
    
    const int dist[8] = {1, -1, a, b, -a, -b, a, b};
    queue<int> q;
    visited[n] = true;
    stone[n] = 0;
    q.push(n);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(curr == m)
        {
            printf("%d", stone[m]);
            break;
        }

        // 일반 점프
        for(int i=0; i<6; i++)
        {
            int next = curr+dist[i];

            if(next<0 || 100000<next) continue;

            if(!visited[next])
            {
                visited[next] = true;
                stone[next] = stone[curr]+1;
                q.push(next);
            }
        }


        // 힘 모아서 점프
        for(int i=6; i<8; i++)
        {
            int next = curr*dist[i];
            
            if(next<0 || 100000<next) continue;

            if(!visited[next])
            {
                visited[next] = true;
                stone[next] = stone[curr]+1;
                q.push(next);
            }
        }

    }

    return 0;
}