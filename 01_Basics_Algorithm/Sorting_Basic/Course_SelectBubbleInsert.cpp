/**
 * @Title: 选择排序、冒泡排序、插入排序
 * @Author: C1ay
 * @Date: 2025-12-09 22:34
 * @Tag: 排序
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    static void swap(vector<int> &arr,int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void selectionSort(vector<int> &arr){
        if(arr.size() < 2){
            return;
        }
        for(int minIndex,i= 0;i < arr.size();i++){
            minIndex = i;
            for(int j = i+1;j<arr.size();j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }
            swap(arr,i,minIndex);
        }
    }

    static void printSort(vector<int> &arr){
        cout << "Sorted array: ";
        for(int num : arr){
            cout << num << " ";
        }
        cout << endl;
    }



};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> arr = {4, 1, 3, 2, 5};
    cout << "Before Sorted：";

    Solution::printSort(arr);
    Solution::selectionSort(arr);
    cout << "After Sorted：";
    Solution::printSort(arr);

    
    
    return 0;
}