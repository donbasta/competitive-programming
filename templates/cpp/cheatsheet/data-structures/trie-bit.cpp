const int BMAX = 20;
struct Trie
{
    struct Node
    {
        Node *child[2];
        int cnt;
        Node()
        {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *head;

    Trie() { head = new Node(); }

    void insert(int val)
    {
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--)
        {
            int v = (val >> i) & 1;
            ++(cur->cnt);
            if (cur->child[v] == NULL)
            {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        ++(cur->cnt);
    }

    void erase(int val)
    {
        Node *cur = head;
        for (int i = BMAX; i >= 0; i--)
        {
            int v = (val >> i) & 1;
            --(cur->cnt);
            cur = cur->child[v];
        }
        --(cur->cnt);
    }
};