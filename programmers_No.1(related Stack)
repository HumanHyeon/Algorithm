https://programmers.co.kr/learn/courses/30/lessons/42588

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findPosition(stack<int> storage, int compare, int size) {
    if (storage.empty())    return 0;

    int stackSize = storage.size();
    for (int result = 0; result < stackSize; result++) {
        int tmp = storage.top();
        if (tmp > compare)  return size - result;
        storage.pop();
    }
    return 0;
}

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> storage;

    int count = 0;
    for (vector<int>::iterator iter = heights.begin(); iter != heights.end(); iter++) {
        int tmp = findPosition(storage, *iter, count);
        answer.push_back(tmp);
        storage.push(*iter);
        count++;
    }
    return answer;
}

int main()
{
    int input[] = { 5, 3, 1, 2, 3 };
    //int input[] = { 6, 9, 5, 7, 4 };
    //int input[] = {3, 9, 9, 3, 5, 7, 2};
    //int input[] = {1, 5, 3, 6, 7, 6, 5};
    vector<int> para;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
        para.push_back(input[i]);

    vector<int> result;
    result = solution(para);

    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << " ";
    putchar('\n');
}
