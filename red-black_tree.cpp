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
    bool color;
    node *left;
    node *right;
    node *parent;

    node(int key, node *parent)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        this->parent = parent;
        color = 1;
    }
};

node *uncle(node *root)
{
    if (root->parent->parent->left == root->parent)
        return root->parent->parent->right;
    else
        return root->parent->parent->left;
}
node *clockwise_rotation(node *root)
{
    node *l = root->left;
    root->left = l->right;
    if (root->left)
        root->left->parent = root;
    l->right = root;
    l->parent = root->parent;
    root->parent = l;

    if (l->parent)
    {
        if (l->key > l->parent->key)
            l->parent->right = l;
        else
            l->parent->left = l;
    }

    return l;
}

node *anti_clockwise_rotation(node *root)
{
    node *r = root->right;
    root->right = r->left;
    if (root->right)
        root->right->parent = root;
    r->left = root;
    r->parent = root->parent;
    root->parent = r;

    if (r->parent)
    {
        if (r->key > r->parent->key)
            r->parent->right = r;
        else
            r->parent->left = r;
    }

    return r;
}

void b_check(node *root)
{
    if (root->parent->color == 0)
        return;
    else if ((uncle(root)) && uncle(root)->color == 1)
    {
        root->parent->color = 0;
        uncle(root)->color = 0;
        if (root->parent->parent->parent)
            root->parent->parent->color = 1;
    }
    else
    {
        if (root->parent->left == root)
        {
            if (root->parent->parent->left == root->parent)
            {
                root = clockwise_rotation(root->parent->parent);
                root->right->color = 1;
                root->color = 0;
            }
            else
            {
                root = clockwise_rotation(root->parent);
                root = anti_clockwise_rotation(root->parent);
                root->left->color = 1;
                root->color = 0;
            }
        }
        else
        {
            if (root->parent->parent->right == root->parent)
            {
                root->color = anti_clockwise_rotation(root->parent->parent);
                root->left->color = 1;
                root->color = 0;
            }
            else
            {
                root = anti_clockwise_rotation(root->parent);
                root = clockwise_rotation(root->parent);
                root->right->color = 1;
                root->color = 0;
            }
        }
    }
}

node *insert_RB(node *root, node *caller, int key)
{
    if (root && root->key == key)
    {
        cout << "Key already present. Duplicates not allowed!!" << endl;
        return root;
    }

    if (root == nullptr)
    {
        root = new node(key, caller);
        if (caller == nullptr)
        {
            root->color = 0;
            return root;
        }
        if (root->key > caller->key)
            caller->right = root;
        else
            caller->left = root;
    }
    else if (root->key > key)
        insert_RB(root->left, root, key);
    else
        insert_RB(root->right, root, key);

    // ***************************************************************
    if (root->color)
        b_check(root);

    if (caller == nullptr)
    {
        if (root->parent == nullptr)
            return root;
        else if (root->parent->parent == nullptr)
            return root->parent;
    }

    return root;
}

// node *rectify(node *root, int stop_key)
// {
//     if (stop_key > root->key)
//         root->right = rectify(root->right, stop_key);
//     else if (stop_key < root->key)
//         root->left = rectify(root->left, stop_key);

//     // ***************************************************************
//     root = b_check(root);

//     return root;
// }

// node *delete_rec(node *root, int key)
// {
//     if (!root)
//         printf("Element not Present!!!!!\n");
//     else if (root->key == key)
//     {
//         if (!(root->left || root->right))
//         {
//             delete root;
//             return nullptr;
//         }
//         else if (!(root->left && root->right))
//         {
//             if (root->left)
//             {
//                 node *temp = root->left;
//                 delete root;
//                 return temp;
//             }
//             if (root->right)
//             {
//                 node *temp = root->right;
//                 delete root;
//                 return temp;
//             }
//         }
//         else
//         {
//             node *temp = root->right, *temp2 = root;
//             while (temp->left)
//             {
//                 temp2 = temp;
//                 temp = temp->left;
//             }
//             if (temp2 == root)
//             {
//                 temp->left = temp2->left;
//                 delete root;
//                 root = temp;
//             }
//             else
//             {
//                 temp2->left = temp->right;
//                 temp->left = root->left;
//                 temp->right = root->right;
//                 delete root;
//                 root = rectify(temp, temp2->key);
//             }
//         }
//     }
//     else if (root->key > key)
//         root->left = delete_rec(root->left, key);
//     else if (root->key < key)
//         root->right = delete_rec(root->right, key);

//     // ***************************************************************
//     root = b_check(root);

//     return root;
// }

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

    node *root = nullptr;

    int key, i = 8;
    while (i--)
    {
        cin >> key;
        root = insert_RB(root, nullptr, key);
        __preorder(root);
        cout << endl;
        __inorder(root);
        cout << endl;
        __postorder(root);
        cout << endl;
        cout << endl;
    }
    // cout << "********************\n";
    // while (cin >> key)
    // {
    //     root = delete_rec(root, key);
    //     __preorder(root);
    //     cout << endl;
    //     __inorder(root);
    //     cout << endl;
    //     __postorder(root);
    //     cout << endl;
    //     cout << endl;
    // }
    return 0;
}
