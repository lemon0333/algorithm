#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<cmath>
#include<unordered_map>
#include<stack>
#include<set>
#include<list>
using namespace std;
#define X first
#define Y second
int dist[502][502];
bool vis[502][502];
int n ;
int m ;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int area_count;

long long int result;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
Node* createNode(int v) {
    return new Node(v);
}
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->val;   // Root
    preorder(root->left);   // Left
    preorder(root->right);  // Right
}
void postorder(Node* root){
    if (root == nullptr) return;

    // Root
    postorder(root->left);   // Left
    postorder(root->right);  // Right
    cout << root->val;
}
void inorder(Node* root){
    if (root == nullptr) return;

  // Root
    inorder(root->left);   // Left
    cout << root->val;
    inorder(root->right);  // Right
    
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    
    vector<Node*> nodes(26);
       for (int i = 0; i < 26; i++)
           nodes[i] = new Node('A' + i);

       while (n--) {
           char c, ch1, ch2;
           cin >> c >> ch1 >> ch2;

           Node* parent = nodes[c - 'A'];

           if (ch1 != '.')
               parent->left = nodes[ch1 - 'A'];

           if (ch2 != '.')
               parent->right = nodes[ch2 - 'A'];
       }

  
       Node* cur = nodes[0];
     
           preorder(cur);
    cout<<endl;
    cur=nodes[0];
           inorder(cur);
    cout<<endl;
    cur=nodes[0];
           postorder(cur);
    cout<<endl;
           
        }
