// Finding LCA -----Lowest Common Ancestor
// M-1 : Build path arrays for both the nodes and then find the closest one
// M-2 : Optimized Solution
// Watch the GFG video--------Tricky but good implementation
// My implementation also covers the case when one of the keys is not present in the tree
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define endl "\n"
#define mod 1e9 + 7
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int global_flag;

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

// ********WRONG------THIS WILL WORK FOR BST THOUGH----------------
// node *__lca(node *root, int a, int b)
// {
//     if (!root)
//         return nullptr;
//     if (a > root->key && b > root->key)
//     {
//         if ((root->right && root->right->key == a) || (root->right && root->right->key == b))
//             return root;
//         return __lca(root->right, a, b);
//     }
//     else if (a < root->key && b < root->key)
//     {
//         if ((root->left && root->left->key == a) || (root->left && root->left->key == b))
//             return root;
//         return __lca(root->left, a, b);
//     }
//     else
//         return root;
// }

node *__lca(node *root, int a, int b)
{
    int flag = 1;
    if (global_flag == 0)
        flag = 0;
    if (!root)
        return nullptr;
    if (root->key == a || root->key == b)
    {
        if (global_flag == 0)
            global_flag = 1, flag = 1;
        else
            global_flag = 2;
        if (global_flag == 2)
            return nullptr;
    }
    if (global_flag != 2)
    {
        node *temp = __lca(root->left, a, b);
        if (!temp && !flag && global_flag == 2)
            return root;
        if (temp)
            return temp;
    }
    if (global_flag != 2)
    {
        node *temp = __lca(root->right, a, b);
        if (!temp && !flag && global_flag == 2)
            return root;
        if (temp)
            return temp;
    }
    return nullptr;
}

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
    auto ax = __lca(root, 73, 17892);
    if (!ax)
        cout << "No LCA";
    else
        cout << ax->key;
    return 0;
}
