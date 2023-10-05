#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *solve(int in[], int pre[], int &index, int inorderstart, int inorderend, int n, map<int, int> &nodetoindex)
{
    if (index >= n || (inorderstart > inorderend))
        return NULL;
    int element = pre[index++];
    Node *root = new Node(element);
    int position = nodetoindex[element];
    assert(position != -1);
    root->left = solve(in, pre, index, inorderstart, position - 1, n, nodetoindex);
    root->right = solve(in, pre, index, position + 1, inorderend, n, nodetoindex);
    return root;
}
Node *buildfrominorderandpreorder(int in[], int pre[], int n)
{
    int preorderindex = 0;
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
    {
        nodetoindex[in[i]] = i;
    }
    Node *ans = solve(in, pre, preorderindex, 0, n - 1, n, nodetoindex);
    return ans;
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *solveforpostandin(int in[], int post[], int &index, int inorderstart, int inorderend, int n, map<int, int> &nodetoindex)
{
    if (index < 0 || (inorderstart > inorderend))
        return NULL;
    int element = post[index--];
    Node *root = new Node(element);
    int position = nodetoindex[element];
    // assert(position != -1);
    root->right = solveforpostandin(in, post, index, position + 1, inorderend, n, nodetoindex);
    root->left = solveforpostandin(in, post, index, inorderstart, position - 1, n, nodetoindex);
    return root;
}
Node *buildfrompostandinorder(int in[], int post[], int n)
{
    int postorderindex = n-1;
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
    {
        nodetoindex[in[i]] = i;
    }
    Node* ans=solveforpostandin(in, post, postorderindex, 0, n - 1, n, nodetoindex);
    return ans;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    Node *root = buildfrompostandinorder(in, post, n);
    preorder(root);
}