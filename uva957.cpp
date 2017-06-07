#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;

int main(){

    while (true){
        int periodo; //qtd de anos
        int papas; //qtd de papas
        cin >> periodo;
        if (cin.eof())
        {
            break;
        }
        cin >> papas;
        vector<int> anos; //anos em que cada papa foi eleito
        for (int i = 0; i < papas; i++){
            int ano;
            cin >> ano;
            anos.push_back(ano);
        }

        int maxi = 0; //ano de eleição do primeiro papa
        int maxf = 0; //ano de eleição do ultimo papa
        int max = 0; //qtd máxima de papas eleitos

        for (vector<int>::iterator inicio = anos.begin(); inicio != anos.end(); inicio++){
            vector<int>::iterator termino = upper_bound(anos.begin(), anos.end(), *inicio + periodo -1);
            if (termino - inicio > max){
                max = termino - inicio;
                maxi = *inicio;
                maxf = *(termino-1);
            }
        }
        cout << max << " " << maxi << " " << maxf << endl; 
    }
    return 1;
}
