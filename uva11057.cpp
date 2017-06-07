#include <bits/stdc++.h>
using namespace std;

int main()
{  
    while (true)
    {
        int N; //qtd de livros
        cin >> N;
        if (cin.eof())
        {
            break;
        }
        vector<int> livros;
        for (int i = 0; i < N; ++i){
            int l;
            cin >> l;
            livros.push_back(l);
        }
    
        int M; //quantia de dinheiro
        cin >> M;

        sort(livros.begin(), livros.end()); //ordenamos o vetor para que possamos usar a busca binária
        int livro1 = livros.front();
        int livro2 = livros.back();
        for (auto pos  = livros.begin(); pos != livros.end(); ++pos)
        {
            int l1 = *pos;
            int l2 = M - l1;
            if (l1 > l2)
                break;
            if (binary_search(pos + 1, livros.end(), l2))
            {
                if (l2 - l1 < livro2 - livro1)
                {
                    livro1 = l1;
                    livro2 = l2;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << livro1 << " and " << livro2 << "."<< endl<< endl;
    }
    return 0;
}