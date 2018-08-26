#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _bitree {
    int data;
    struct _bitree *left;
    struct _bitree *right;
} bitree;

class binary_tree {

public:
//层序构造
    bitree *binary_tree_creat(vector<int> &data)
    {
        int length = data.size();
        bitree *root = new bitree;
        root->left = NULL;
        root->right = NULL;
        bitree *temp = root;
        bitree *temp1;
        root->data = data[0];
        queue<bitree *> que;

        cout<<"length :"<<length<<endl;

        for(int i = 1; i < length; i++)
        {
            temp1 = new bitree;
            temp1->data = data[i];
            temp1->left = NULL;
            temp1->right = NULL;
            cout<<"data["<<i<<"]:  "<<data[i]<<' ';
            if(temp->left == NULL)
            {
                temp->left = temp1;
                que.push(temp->left);
                cout<< "left "<<endl;
                continue;
            }
            if(temp->right == NULL)
            {
                temp->right = temp1;
                que.push(temp->right);
                temp = que.front();
                que.pop();
                cout<<"right "<<endl;
            }
        }
        while(!que.empty())
            que.pop();

        return root;
    }

//删除二叉树
void delete_bitree(bitree *tree)
{
    if(!tree)
        return;
    if(tree->left)
        delete_bitree(tree->left);
    if(tree->right)
        delete_bitree(tree->right);
    delete tree;
}

//查找二叉树中数值为k的节点
virtual bitree *search_node(bitree *tree, int k)
{
    if(!tree)
        return NULL;
    if(tree->data == k)
        return tree;
    bitree *temp = NULL;
    temp = search_node(tree->left, k);
    if(!temp)
        temp = search_node(tree->right, k);
    return temp;
}
//二叉树深度
int get_bitree_depth(bitree *tree)
{
    if(tree == NULL)
    {
         return 0;
    }

    int left = get_bitree_depth(tree->left) + 1;
    int right = get_bitree_depth(tree->right) + 1;
    return (left > right ? left : right);
}

//二叉树中节点个数
int get_bitree_node_count(bitree *tree)
{
    if(!tree)
        return 0;
    int left = get_bitree_node_count(tree->left);
    int right = get_bitree_node_count(tree->right);
    return left + right + 1;
}

//前序遍历
void preorder_traverse(bitree *tree)
{
    if(tree == NULL)
        return;
    int data = tree->data;
    cout<<data<<' ';
    //arr.push_back(data);
    preorder_traverse(tree->left);
    preorder_traverse(tree->right);
}

//中序遍历
void inorder_traverse(bitree *tree)
{
    if(!tree)
        return;

    inorder_traverse(tree->left);
    int data = tree->data;
    cout<<data<<' ';
    //arr.push_back(data);
    inorder_traverse(tree->right);
}

//后序遍历
void post_traverse(bitree *tree)
{
    if(!tree)
        return;

    post_traverse(tree->left);
    post_traverse(tree->right);
    int data = tree->data;
    cout<<data<<' ';
    //arr.push_back(data);
}

//广度优先遍历
void breadth_first_traverse(bitree *tree)
{
    if(!tree)
        return;

    queue<bitree *> que;

    que.push(tree);
    while(!que.empty())
    {
        bitree *temp = que.front();
        que.pop();
       // arr.push_back(temp->data);
       cout<<temp->data<<' ';
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
    }
}
//求k层节点个数
int get_node_num_kth_level(bitree *tree, int k)
{
    if(!tree || k < 1)
        return 0;
    if(k == 1)
        return 1;

    int left_num = get_node_num_kth_level(tree->left, k - 1);
    int right_num = get_node_num_kth_level(tree->left, k - 1);
    return (left_num + right_num);
}

//求二叉树叶子节点个数
int get_leaf_node_num(bitree *tree)
{
    if(!tree)
        return 0;
    if(!tree->left || (!tree->right))
        return 1;
    return (get_leaf_node_num(tree->left) + get_leaf_node_num(tree->right));
}

};

class binary_search_tree : public binary_tree {
public:

    virtual bitree *search_node(bitree *tree, int k)
    {
        if(tree == NULL)
            return NULL;
        if(tree->data == k)
            return tree;

        if(tree->data > k)
            return search_node(tree->left, k);
        else
            return search_node(tree->right, k);
    }

    int get_minmum_data(bitree *tree)
    {
        if(tree == NULL)
            return 0;
        while(tree->left)
           tree = tree->left;
         return tree->data;
    }

    int get_maxmum_data(bitree *tree)
    {
        if(tree == NULL)
            return 0;
        while(tree->right)
           tree = tree->right;
         return tree->data;
    }

    bool is_binary_search_tree(bitree *tree)
    {
        int pre = INT_MIN;
        return is_BST_help(tree, pre);
    }
    bool is_BST_help(bitree *tree, int pre)
    {
        if(!tree)
            return tree;
        if(is_BST_help(tree->left, pre)) {
            if(tree->data > pre) {
                pre = tree->data;
                return is_BST_help(tree->right, pre);
            }
            else
                return false;
        }
        else
            return false;
    }

    bitree* insert_node(bitree *tree, int data)
    {
        if(!tree)
        {
           bitree *node = new bitree;
           node->data = data;
           return node;
        }
        s

    }
};

int main()
{
    vector<int> data = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    binary_tree a;
    bitree *root;
    root = a.binary_tree_creat(data);

   int depth = a.get_bitree_depth(root);
   int node = a.get_bitree_node_count(root);
    cout<<depth<<"    "<<node<<endl;
    a.preorder_traverse(root);
    cout<<endl;
   a.breadth_first_traverse(root);

    a.delete_bitree(root);
 return 0;
}
