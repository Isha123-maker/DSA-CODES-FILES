#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxWater(vector<int>& area){
    int maxWater = 0 , left = 0 , right = area.size() - 1;

    while(left < right){
        int width = right - left;
        int height = min(area[right] , area[left]);
        int currentWater = width * height;
        maxWater = max(maxWater , currentWater);

        area[left] < area[right] ? left++ : right--;
    }
    return maxWater;

}

int main(){
    vector<int> area = {1,8,6,2,5,4,8,3,7};
    cout << "Area of Container with most water is: " << maxWater(area) << endl;
    return 0;
}