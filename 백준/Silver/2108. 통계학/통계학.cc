#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;

int main() {
    int num, tmp, range, middle = 0, mean = 0;
    int number[8001] = { 0, };
    int max = 0;
    int flag = 0;

    bool not_first = false;

    int count = 0;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp + 4000]++;

    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < 8001; i++)
    {
        if (number[i] > max)
        {
            max = number[i];
            flag = i;

        } //최댓값 max를 찾아준 것 (number[i]>max이므로, max값이 동일할 때에는 걸러주지 못함. 최빈 값 중에서도 제일 작은 값을 받음
    }

    for (int i = flag + 1; i < 8001; i++)
    {
        if (number[i] == max)
        {
            flag = i;
            break;
        }
        //그렇기에, flag+1이라는 범위에서 (최빈값 중 제일 작은 범위) max와 같다면 flag는 i값이 된다.
    }

 
   
    middle = arr[arr.size() / 2];
    mean = round((float)mean / num);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << flag-4000 << '\n' << range;
}