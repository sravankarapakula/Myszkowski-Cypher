#include <bits/stdc++.h>
using namespace std;

// DJB2 HASH
string djb2(string msg) {
    unsigned long long h = 5381;
    for (char c : msg)
        h = ((h << 5) + h) + c;
    return to_string(h);
}

vector<int> getOrd(string key) {
    set<char> s(key.begin(), key.end());
    vector<char> v(s.begin(), s.end());
    map<char, int> mp;

    for (int i = 0; i < v.size(); i++)
        mp[v[i]] = i;

    vector<int> ord;
    for (char c : key)
        ord.push_back(mp[c]);

    return ord;
}

// ENCRYPT
string enc(string txt, string key) {
    int m = key.size();
    int n = txt.size();
    int r = ceil((double)n / m);

    while (txt.size() < r * m) txt += 'X';

    vector<vector<char>> g(r, vector<char>(m));
    int k = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = txt[k++];

    vector<int> ord = getOrd(key);
    set<int> u(ord.begin(), ord.end());

    string c = "";

    for (int x : u)
        for (int j = 0; j < m; j++)
            if (ord[j] == x)
                for (int i = 0; i < r; i++)
                    c += g[i][j];

    return c;
}

// DECRYPT
string dec(string c, string key) {
    int m = key.size();
    int n = c.size();
    int r = n / m;

    vector<vector<char>> g(r, vector<char>(m));
    vector<int> ord = getOrd(key);
    set<int> u(ord.begin(), ord.end());

    int k = 0;

    for (int x : u)
        for (int j = 0; j < m; j++)
            if (ord[j] == x)
                for (int i = 0; i < r; i++)
                    g[i][j] = c[k++];

    string txt = "";

    for (int i = 0; i < r; i++)
        for (int j = 0; j < m; j++)
            txt += g[i][j];

    return txt;
}

int main() {
    string msg, key;

    cout << "Enter message: ";
    getline(cin, msg);

    cout << "Enter key: ";
    cin >> key;

    string h = djb2(msg);
    string c = enc(h, key);

    cout << "\nCiphertext: " << c << endl;

    string rh = dec(c, key);
    cout << "Recovered Hash: " << rh << endl;

    return 0;
}
