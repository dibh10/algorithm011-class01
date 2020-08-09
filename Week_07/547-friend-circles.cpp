
class Solution {
class UF
{
    private:
    //��ͨ��������
    int count;

    //�洢һ����
    vector<int> parent;

    //����
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

        //С���ӵ��������棬��ƽ��
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
            //·��ѹ��
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }
};
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();

        UF un(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (M[i][j] == 1)
                {
                    un.merge(i, j);
                }
            }
        }

        return un.counts();
    }
};

