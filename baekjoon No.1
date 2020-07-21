https://www.acmicpc.net/problem/10816

#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

int countCmp;

void calc(int* have, int index) {
    int standard = have[index];
    for (int i = index; have[i] == standard; i++)
        countCmp++;
    for (int i = index - 1; have[i] == standard; i--)
        countCmp++;
}

void search(int* have, int compare, int start, int end) {
    int mid = (start + end) / 2;
       
    if (start == mid)    return;
    if (have[mid] == compare)
    {
        calc(have, mid);
        return;
    }
    if (have[mid] > compare) search(have, compare, start, mid);
    else search(have, compare, mid, end);
}

int main() {
    //input part
    int first, second;
    scanf("%d", &first);
    int* have = new int[first];
    for (int i = 0; i < first; i++)   scanf("%d", &have[i]);
    scanf("%d", &second);
    int* compare = new int[second];
    for (int i = 0; i < second; i++) scanf("%d", &compare[i]);

    sort(have, have + first);

    for (int i = 0; i < second; i++) {
        countCmp = 0;
        search(have, compare[i], 0, first);
        cout << countCmp << " ";
    }
}
