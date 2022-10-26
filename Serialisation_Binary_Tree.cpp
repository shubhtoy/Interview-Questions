// Serialize nd de-serialize a Tree
// Using Pre-order Traversal (GFG)
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define endl "\n"
#define mod 1e9 + 7
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

struct node
{
    int key;
    node *left;
    node *right;
    node(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

bool check(queue<node *> q)
{
    while (!q.empty())
    {
        auto x = q.front();
        if (x)
            return false;
        q.pop();
    }
    return true;
}
void serialize(node *root, vi &alpha)
{
    if (!root)
    {
        alpha.push_back(INT_MIN);
        return;
    }
    alpha.push_back(root->key);
    serialize(root->left, alpha);
    serialize(root->right, alpha);
}

node *deserialize(queue<int> &beta)
{
    if (beta.front() == INT_MIN)
    {
        beta.pop();
        return nullptr;
    }
    node *root = new node(beta.front());
    beta.pop();
    root->left = deserialize(beta);
    root->right = deserialize(beta);
    return root;
}

// ****************TREE TRAVERSALS FOR VERIFICATION**************************
void __preorder(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    __preorder(root->left);
    __preorder(root->right);
}
void __postorder(node *root)
{
    if (!root)
        return;
    __postorder(root->left);
    __postorder(root->right);
    cout << root->key << " ";
}
void __inorder(node *root)
{
    if (!root)
        return;
    __inorder(root->left);
    cout << root->key << " ";
    __inorder(root->right);
}
// ****************************************************************************

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ****************************************************
    node *root = nullptr;
    root = new node(41);
    root->left = new node(29);
    root->right = new node(12);
    root->left->left = new node(12);
    root->left->right = new node(17);
    root->right->left = new node(5);
    root->right->right = new node(7);
    root->right->right->left = new node(98);
    root->right->right->right = new node(73);
    root->right->right->left->right = new node(72);
    root->right->right->left->right->left = new node(172);
    root->right->right->left->right->right = new node(162);
    // ****************************************************

    vi alpha;
    serialize(root, alpha);
    for (auto x : alpha)
        cout << x << "  ";

    queue<int> beta;
    for (auto x : alpha)
        beta.push(x);
    node *root2 = deserialize(beta);

    cout << endl;
    __preorder(root2);
    cout << endl;
    __inorder(root2);
    cout << endl;
    __postorder(root2);
    return 0;
}
