#include <iostream>
#include <vector>
using namespace std;

void pigeonholeSort(int arr[], int n){

    if (n <= 0) return;

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++){
    
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    vector<int> holes[range];

    for (int i = 0; i < n; i++)
    {
        holes[arr[i] - min].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        for (int val : holes[i])
        {
            arr[index] = val;
            index = index + 1;
        }
    }
}