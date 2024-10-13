#include <iostream>
using namespace std;
int main() {
  
    int n;
    cin>>n;
    if (n <= 1) {
        cout << "False";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "True";
        return 0;
    }
    for(int i= 5;i<n;i+=6){
        if (n % i == 0 || n % (i + 2) == 0){
            cout << "False";
            return 0;
        }
    }
    cout<<"True";
    return 0;
}
