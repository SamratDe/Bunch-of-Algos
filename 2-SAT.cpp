
// C++ implementation to find if the given 
// expression is satisfiable using the 
// Kosaraju's Algorithm 
#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100000; 
  
// data structures used to implement Kosaraju's 
// Algorithm. Please refer 
// http://www.geeksforgeeks.org/strongly-connected-components/ 
vector<int> adj[MAX]; 
vector<int> adjInv[MAX]; 
bool visited[MAX]; 
bool visitedInv[MAX]; 
stack<int> s; 
  
// this array will store the SCC that the 
// particular node belongs to 
int scc[MAX]; 
  
// counter maintains the number of the SCC 
int counter = 1; 
  
// adds edges to form the original graph 
void addEdges(int a, int b) 
{ 
    adj[a].push_back(b); 
} 
  
// add edges to form the inverse graph 
void addEdgesInverse(int a, int b) 
{ 
    adjInv[b].push_back(a); 
} 
  
// for STEP 1 of Kosaraju's Algorithm 
void dfsFirst(int u) 
{ 
    if(visited[u]) 
        return; 
  
    visited[u] = 1; 
  
    for (int i=0;i<adj[u].size();i++) 
        dfsFirst(adj[u][i]); 
  
    s.push(u); 
} 
  
// for STEP 2 of Kosaraju's Algorithm 
void dfsSecond(int u) 
{ 
    if(visitedInv[u]) 
        return; 
  
    visitedInv[u] = 1; 
  
    for (int i=0;i<adjInv[u].size();i++) 
        dfsSecond(adjInv[u][i]); 
  
    scc[u] = counter; 
} 
  
// function to check 2-Satisfiability 
void is2Satisfiable(int n, int m, int a[], int b[]) 
{ 
    // adding edges to the graph 
    for(int i=0;i<m;i++) 
    { 
        // variable x is mapped to x 
        // variable -x is mapped to n+x = n-(-x) 
  
        // for a[i] or b[i], addEdges -a[i] -> b[i] 
        // AND -b[i] -> a[i] 
        if (a[i]>0 && b[i]>0) 
        { 
            addEdges(a[i]+n, b[i]); 
            addEdgesInverse(a[i]+n, b[i]); 
            addEdges(b[i]+n, a[i]); 
            addEdgesInverse(b[i]+n, a[i]); 
        } 
  
        else if (a[i]>0 && b[i]<0) 
        { 
            addEdges(a[i]+n, n-b[i]); 
            addEdgesInverse(a[i]+n, n-b[i]); 
            addEdges(-b[i], a[i]); 
            addEdgesInverse(-b[i], a[i]); 
        } 
  
        else if (a[i]<0 && b[i]>0) 
        { 
            addEdges(-a[i], b[i]); 
            addEdgesInverse(-a[i], b[i]); 
            addEdges(b[i]+n, n-a[i]); 
            addEdgesInverse(b[i]+n, n-a[i]); 
        } 
  
        else
        { 
            addEdges(-a[i], n-b[i]); 
            addEdgesInverse(-a[i], n-b[i]); 
            addEdges(-b[i], n-a[i]); 
            addEdgesInverse(-b[i], n-a[i]); 
        } 
    } 
  
    // STEP 1 of Kosaraju's Algorithm which 
    // traverses the original graph 
    for (int i=1;i<=2*n;i++) 
        if (!visited[i]) 
            dfsFirst(i); 
  
    // STEP 2 pf Kosaraju's Algorithm which 
    // traverses the inverse graph. After this, 
    // array scc[] stores the corresponding value 
    while (!s.empty()) 
    { 
        int n = s.top(); 
        s.pop(); 
  
        if (!visitedInv[n]) 
        { 
            dfsSecond(n); 
            counter++; 
        } 
    } 
  
    for (int i=1;i<=n;i++) 
    { 
        // for any 2 vairable x and -x lie in 
        // same SCC 
        if(scc[i]==scc[i+n]) 
        { 
            cout << "The given expression "
                 "is unsatisfiable." << endl; 
            return; 
        } 
    } 
  
    // no such variables x and -x exist which lie 
    // in same SCC 
    cout << "The given expression is satisfiable."
         << endl; 
    return; 
} 
  
//  Driver function to test above functions 
int main() 
{ 
    // n is the number of variables 
    // 2n is the total number of nodes 
    // m is the number of clauses 
    int n = 5, m = 7; 
  
    // each clause is of the form a or b 
    // for m clauses, we have a[m], b[m] 
    // representing a[i] or b[i] 
  
    // Note: 
    // 1 <= x <= N for an uncomplemented variable x 
    // -N <= x <= -1 for a complemented variable x 
    // -x is the complement of a variable x 
  
    // The CNF being handled is: 
    // '+' implies 'OR' and '*' implies 'AND' 
    // (x1+x2)*(x2’+x3)*(x1’+x2’)*(x3+x4)*(x3’+x5)* 
    // (x4’+x5’)*(x3’+x4) 
    int a[] = {1, -2, -1, 3, -3, -4, -3}; 
    int b[] = {2, 3, -2, 4, 5, -5, 4}; 
  
    // We have considered the same example for which 
    // Implication Graph was made 
    is2Satisfiable(n, m, a, b); 
  
    return 0; 
} 
