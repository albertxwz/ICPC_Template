struct Treap
{
    struct Node
    {
        Node *ch[2];
        int r, v, cnt;

        Node()
        {
            *this = NULL;
        }

        Node(int v) : v(v)
        {
            r = rand()/10*rand();
            ch[0] = ch[1] = NULL;
            cnt = 1;
        }

        bool operator < (const Node &rhs) const
        {
            return r < rhs.r;
        }

        int cmp(int x) const
        {
            if (x == v) return -1;
            return x > v;
        }

    }*root;

    void rotate(Node *&o, int d)
    {
        Node *k = o->ch[d^1];
        o->ch[d^1] = k->ch[d];
        k->ch[d] = o;
        o = k;
    }

    void insert(Node *&o, int x)
    {
        if (o == NULL)
        {
            o = new Node(x);
            return;
        }
        int k = o->cmp(x);
        if (k == -1) o->cnt++;
        else
        {
            insert(o->ch[k], x);
            if (o->ch[k]->r > o->r) rotate(o, k^1);
        }
    }

    void remove(Node *&o, int x)
    {
        int d = o->cmp(x);
        if (d == -1)
        {
            if (o->cnt == 0 || (--o->cnt) == 0)
            {
                if (o->ch[0] == NULL)
                    o = o->ch[1];
                else if (o->ch[1] == NULL)
                    o = o->ch[0];
                else
                {
                    int d1 = o->ch[0]->r > o->ch[1]->r;
                    rotate(o, d1);
                    remove(o->ch[d1], x);
                }
            }
            return;
        }
        remove(o->ch[d], x);
    }

    int finds(Node *o, int x)
    {
        if (o == NULL) return INF;
        int d = o->cmp(x);
        if (d == -1) return 0;
        if (o->ch[d] == NULL) return abs(x-o->v);
        else return min(abs(x-o->v), finds(o->ch[d], x));
    }

    int findmin()
    {
        Node *k = root;
        while (k->ch[0] != NULL) k = k->ch[0];
        return k->v;
    }

}