#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER x as parameter.
 */

int solve(long x) {
    long long low = 1, high = 1000000; // Akar pangkat tiga dari 10^18 sekitar 10^6
    int ans = 0;
    
    unsigned __int128 total_candies = x;

    while (low <= high) {
        long long n = low + (high - low) / 2;
        
        // Menghitung n * (n + 1) * (2n + 1) / 6
        // Gunakan __int128 untuk mencegah overflow saat perkalian sebelum pembagian
        unsigned __int128 required = (unsigned __int128)n * (n + 1);
        required = (required * (2 * n + 1)) / 6;

        if (required <= total_candies) {
            ans = n;
            low = n + 1;
        } else {
            high = n - 1;
        }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string x_temp;
        getline(cin, x_temp);

        long x = stol(ltrim(rtrim(x_temp)));

        int result = solve(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
