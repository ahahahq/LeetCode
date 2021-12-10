/**
 * @file 2021-12-10.cpp
 * 
 * @author He Qiang (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// LeetCode 748.最短补全词语  https://leetcode-cn.com/problems/shortest-completing-word/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& vs) {
        vector<int> cnt(26);
        for (char c : s) {
            if (isalpha(c)) ++cnt[tolower(c) - 'a'];
        }
        int idx = -1;
        for (int i = 0; i < vs.size(); i++) {
            vector<int> tmp(26);
            for (char c : vs[i]) ++tmp[c - 'a'];
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                if (tmp[j] < cnt[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag && (idx < 0 || vs[i].size() < vs[idx].size())) idx = i;
        }
        return vs[idx];
    }
};