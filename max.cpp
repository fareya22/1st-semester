#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        for (int i = 0; i < 5; ++i) {

        (*min_element(v.begin(), v.end()))++;
        }

        // Output the product of the elements in v
        cout << v[0] * v[1] * v[2] << "\n";
    }

    return 0;
}
