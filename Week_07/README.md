**并查集模板**

```
class UF
{
    private:
    //连通分量个数
    int count;

    //存储一棵树
    vector<int> parent;

    //重量
    vector<int> size;

    public:
    UF(int n)
    {
        count  = n;
        parent = vector<int> (n, 0);
        size   = vector<int> (n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void merge(int p, int q)
    {
        int rootp = find(p);
        int rootq = find(q);

        if (rootp == rootq) return;

        //小树接到大树下面，较平衡
        if (size[rootp] < size[rootq])
        {
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        }
        else
        {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        }
        count--;
    }

    bool connect(int p, int q)
    {
        int rootp = find(p);
        int rootq = find(q);

        return rootp == rootq;
    }

    int counts(void)
    {
        return count;
    }

    private:
    int find(int x)
    {
        while (parent[x] != x)
        {
            //路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }
};
```
