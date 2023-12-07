#include<iostream>

template<class T>
class CBinTree
{
    class node
    {
    public:
        T key;
        node* left;
        node* right;
    };

protected:
    node* root;
    T key_m;
public:

    CBinTree()
    {
        root = NULL;
    };

    CBinTree(std::initializer_list<T> a)
    {
        root = NULL;
        for(T i : a)
        {
            (*this).insert_(i);
        }
    };

    void insert_(T a)
    {
        if(root != NULL)
        {
            node* p = (node*) malloc(sizeof(node));
            p->key = a;
            p->left = NULL;
            p->right = NULL;
            node* t = root;
            while (t != NULL)
            {
                node* tp = t;
                if (p->key < t->key)
                {
                    t = t->left;
                    if (t==NULL)
                        tp->left = p;
                }
                else
                {
                    t = t->right;
                    if (t==NULL)
                        tp->right = p;
                }
            }
        }
        else
        {
            root = (node*) malloc(sizeof(node));
            root->key = a;
            root->left = NULL;
            root->right = NULL;
        }
    };

    void delete_(T a)
    {

    };

    ~CBinTree() {};
};

int main()
{
    CBinTree<int> S{1, 2, 3};
    S.insert_(3);
}
