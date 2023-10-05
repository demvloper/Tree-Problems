#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the data for node:(-1 for NULL) " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter data for insering in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildfrom_levelorder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

pair<int, int> diameterfast(node *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);
    int ans = max(op1, max(op2, op3));
    return ans;
}

bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && diff)
        return true;
    else
        return false;
}

pair<bool, int> isbalancedfast(node *root)
{
    if (root == NULL)
        return {true, 0};
    pair<bool, int> left = isbalancedfast(root->left);
    pair<bool, int> right = isbalancedfast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    ans.first = leftans && rightans && diff;
    return ans;
}

pair<bool, int> issumtreeFast(node *root)
{
    if (root == NULL)
        return {true, 0};
    if (root->left == NULL && root->right == NULL)
        return {true, root->data};
    pair<bool, int> left = issumtreeFast(root->left);
    pair<bool, int> right = issumtreeFast(root->right);
    bool sum = root->data == left.second + right.second;
    pair<bool, int> ans;
    ans.first = left.first && right.first && sum;
    ans.second = root->data + left.second + right.second;
    return ans;
}
bool isSumTree(node *root)
{
    issumtreeFast(root).first;
}

bool isIdentical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL && r2 != NULL)
        return false;
    if (r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    return left && right && value;
}

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    queue<node *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();
            int index = lefttoright ? i : size - i - 1;
            ans[index] = frontnode->data;
            if (frontnode->left)
                q.push(frontnode->left);
            if (frontnode->right)
                q.push(frontnode->right);
        }
        lefttoright = !lefttoright;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> zigzagusinglevelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> t2;
    vector<vector<int>> res;
    bool ltr = true;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        { 
            if (ltr)
            {
                for (int i = 0; i < t2.size(); i++)
                {
                    res.push_back(t2);
                }
                t2.clear();
                ltr = !ltr;
            }
            else if (ltr == false)
            {
                for (int j = t2.size() - 1; j >= 0; j--)
                {
                    res.push_back(t2[j]);
                }
                ltr = !ltr;
                t2.clear();
            }

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            t2.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void traverseleft(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        traverseleft(root->left, ans);
    else if (root->right)
        traverseleft(root->right, ans);
}
void traverseleaf(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);
}
void traverseright(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    if (root->right)
        traverseright(root->right, ans);
    else if (root->left)
        traverseright(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundarytraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    traverseleft(root->left, ans);
    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);
    traverseright(root->right, ans);
}

vector<int> verticalorder(node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
        return ans;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        if (frontnode->left)
            q.push({frontnode->left, {hd - 1, lvl + 1}});
        if (frontnode->right)
            q.push({frontnode->right, {hd + 1, lvl + 1}});
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

vector<int> topview(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;
        if (topnode.find(hd) == topnode.end())
        {
            topnode[hd] = frontnode->data;
        }
        if (frontnode->left)
            q.push({frontnode->left, hd - 1});
        if (frontnode->right)
            q.push({frontnode->right, hd + 1});
    }
    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> leftView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int lvl = temp.second;
        if (topnode.find(lvl) == topnode.end())
        {
            topnode[lvl] = frontnode->data;
        }
        if (frontnode->left)
            q.push({frontnode->left, lvl + 1});
        if (frontnode->right)
            q.push({frontnode->right, lvl + 1});
    }
    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomview(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;
        topnode[hd] = frontnode->data; // only difference here we don't check that entry is present or not we just insert and uodate the entry correspondinf to distance
        if (frontnode->left)
            q.push({frontnode->left, hd - 1});
        if (frontnode->right)
            q.push({frontnode->right, hd + 1});
    }
    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

void solveforleftviewrecursive(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solveforleftviewrecursive(root->left, ans, level + 1);
    solveforleftviewrecursive(root->right, ans, level + 1);
}
vector<int> leftviewrecursive(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    solveforleftviewrecursive(root, ans, 0);
    return ans;
}

void solveforrightviewrecursive(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solveforrightviewrecursive(root->right, ans, level + 1);
    solveforrightviewrecursive(root->left, ans, level + 1);
}
vector<int> rightView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    solveforrightviewrecursive(root, ans, 0);
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);

    // cout << "Printing the level order traversal" << endl;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelordertraversal(root);
    // inorder(root);
    // preorder(root);
    // postorder(root);

    // buildfrom_levelorder(root);
    // levelordertraversal(root);
    // cout << height(root) << endl;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 - 1 -1
}