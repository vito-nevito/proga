#include<iostream>

template<class T>
class CBinTree
{
    class node
    {
        T val;
        node* left;
        node* right;
    };

protected:
    node root;
    T key;
public:


    void insert(T a)
    {
        p = (node*) malloc(sizeof(node));
        p->val = a;
        p->left = NULL;
        p->right = NULL;
    };

    void delete(T a)
    {

    };

    ~CBinTree();
};

int main()
{

}
