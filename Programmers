https://programmers.co.kr/learn/courses/30/lessons/42748

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;    
    for (int i = 0; i < commands.size(); i++) {
        vector<int> copy = array;
        sort(copy.begin() + commands[i][0] - 1, copy.begin() + commands[i][1]);
        answer.push_back(copy[commands[i][0] + commands[i][2] - 2]);
    }
    return answer;
}

int main() {
    int arr[] = { 1, 5, 2, 6, 3, 7, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> input;
    for (int i = 0; i < size; i++)   input.push_back(arr[i]);

    vector<vector<int>> input2;
    int arr2[][3] = {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}
    };
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        vector<int> tmp;
        for (int j = 0; j < sizeof(arr2[0]) / sizeof(int); j++) {
            tmp.push_back(arr2[i][j]);
        }
        input2.push_back(tmp);
    }
    vector<int> answer = solution(input, input2);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}

//Very impressed code
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct segment_node {
    int begin, end;
    segment_node* left;
    segment_node* right;
    vector<int> segmentation_array;
};

function<void(vector<int> &, vector<vector<int>> &, vector<int> &)> segment_tree = [](vector<int> &array, vector<vector<int>> &command, vector<int> &answer)
{
    function<bool(const int &, const int &)> cmp = [&](const int &a, const int &b) {
        return array[a] <= array[b];
    };
    vector<int> numbering(array.size(), 0);
    for (int i = 0; i < array.size(); i++) numbering[i] = i;

    int range_begin, range_end, obt, cnt, temp;
    function<void(segment_node*)> segment_search = [&](segment_node* node)
    {
        temp = (node->end - node->begin + 1) / 2;

        if (node->begin == node->end) {
            answer.push_back(array[node->segmentation_array[0]]);
            return;
        }
        else if (node->begin <= range_begin && range_end <= node->begin + temp - 1) {
            if (node->left == NULL) {
                segment_node *left_node;

                left_node = new segment_node;
                left_node->begin = node->begin;
                left_node->end = node->begin + temp - 1;
                left_node->left = NULL;
                left_node->right = NULL;
                left_node->segmentation_array.assign(numbering.begin() + left_node->begin, numbering.begin() + left_node->end + 1);
                sort(left_node->segmentation_array.begin(), left_node->segmentation_array.end(), cmp);
                node->left = left_node;
            }
            segment_search(node->left);
        }
        else if (node->begin + temp <= range_begin && range_end <= node->end) {
            if (node->right == NULL) {
                segment_node *right_node;

                right_node = new segment_node;
                right_node->begin = node->begin + temp;
                right_node->end = node->end;
                right_node->left = NULL;
                right_node->right = NULL;
                right_node->segmentation_array.assign(numbering.begin() + right_node->begin, numbering.begin() + right_node->end + 1);
                sort(right_node->segmentation_array.begin(), right_node->segmentation_array.end(), cmp);
                node->right = right_node;
            }

            segment_search(node->right);
        }
        else
        {
            cnt = 0;
            for (auto &x : node->segmentation_array) {
                if (range_begin <= x && x <= range_end) {
                    cnt++;

                    if (cnt == obt) {
                        answer.push_back(array[x]);
                        return;
                    }
                }
            }
        }
    };

    segment_node* root;
    root = new segment_node;
    root->begin = 0;
    root->end = numbering.size() - 1;
    root->left = NULL;
    root->right = NULL;
    root->segmentation_array = numbering;
    sort(root->segmentation_array.begin(), root->segmentation_array.end(), cmp);

    for (auto &x : command) {
        range_begin = x[0] - 1;
        range_end = x[1] - 1;
        obt = x[2];
        segment_search(root);
    }
};

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;//(commands.size(), 0);
    vector<pair<int,int>> arr(array.size(), pair<int,int>());

    for(int i = 0 ; i < array.size() ; i++){
        arr[i].first = array[i];
        arr[i].second = i + 1;
    }

    segment_tree(array, commands, answer);

    return answer;
}
