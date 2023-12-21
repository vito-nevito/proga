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

        void delAll ()                                    // удаление всех потомков
        {
            node* p = this;
            if ( p != NULL )
            {
                (p -> left) -> delAll();
                (p -> right) -> delAll();
                free(p);
            }
        }

        void inOrder ()                 // симметричный обход потомков
        {
            node* p = this;
            if ( p != NULL )
            {
                ( p -> left ) -> inOrder();
                printf( "%3d", p -> key );
                ( p -> right ) -> inOrder();
            }
        }
    };

protected:
    node* root_m;
    T key_m;
public:

    CBinTree()
    {
        root_m = NULL;
    };

    CBinTree(std::initializer_list<T> a)
    {
        root_m = NULL;
        for(T i : a)
        {
            (*this).insert_(i);
        }
    };

    void insert_(T a)
    {
        if(root_m != NULL)
        {
            node* p = (node*) malloc(sizeof(node));
            p->key = a;
            p->left = NULL;
            p->right = NULL;
            node* t = root_m;
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
            root_m = (node*) malloc(sizeof(node));
            root_m->key = a;
            root_m->left = NULL;
            root_m->right = NULL;
        }
    };

    void delete_(T a)
    {
        node* p = root_m;
        node* last = root_m;
        node* spar;
        node* s;
        int c = 1;
        while ( p != NULL && c )
        {
            if ( p -> key > a )
            {
                last = p;
                p = p -> left;
            }
            else if ( p -> key < a )
            {
                last = p;
                p = p -> right;
            }
            else
                c = 0;
        }

        if ( ( p -> left != NULL ) && ( p -> right != NULL ) )
        {
            spar = p;
            s = p -> right;
            while ( s -> left != NULL )
            {
                spar = s;
                s = s -> left;
            }
            p -> key = s -> key;
            last = spar;
            p = s;
        }
        if ( p -> left == NULL && p -> right == NULL )
        {
            if ( last -> left == p )
                last -> left = NULL;
            else
                last -> right = NULL;
            free(p);
        }
        else if ( p -> left == NULL && p -> right != NULL )
        {
            if ( last -> left == p )
                last -> left = p -> right;
            else
                last -> right = p -> right;
            free(p);
        }
        else if ( p -> left != NULL && p -> right == NULL )
        {
            if ( last -> left == p )
                last -> left = p -> left;
            else
                last -> right = p -> left;
            free(p);
        }
    };

    node* poisk (T x )              // поиск значения х в дереве
    {
        node* p = root_m;
        while ( p != NULL )
        {
            if ( p -> key > x )
                p = p -> left;
            else if ( p -> key < x )
                p = p -> right;
            else
                return p;
        }
        return NULL;
    };

    ~CBinTree()
    {
        root_m -> delAll();
    };

    void print_()
    {
        root_m -> inOrder();
    }
};

int main()
{
    CBinTree<int> S{2, 1, 3};
    S.insert_(3);
    S.delete_(3);
    S.print_();
    int a;
    std::cin << a;
}
