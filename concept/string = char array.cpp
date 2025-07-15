#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "afaegaegaegaij";
    const char *a = s.c_str();
    for (size_t i = 0; i < s.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}