#include <iostream>
#define N 100000

struct union_find
{
    int sets[N];
    void init(int n)
    {
        for (int i = 0; i < n; ++i)
            sets[i] = i;
    }
    
    int find(int x)  // O(n)
    {
        if (sets[x] == x)
            return x;
        return sets[x] = find(sets[x]); 
    }

    bool join(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        sets[x] = y;
        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    union_find uf;
    uf.init(10);
    uf.join(1, 2);
    uf.join(2, 3);
    uf.join(4, 5);
    uf.join(5, 6);
    uf.join(7, 8);
    uf.join(8, 9);
    uf.join(1, 9);
    std::cout << uf.same(1, 9) << std::endl;
    std::cout << uf.same(1, 4) << std::endl;
    return 0;
}
