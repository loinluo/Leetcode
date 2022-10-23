#include<iostream>
#include<vector>
using namespace std;

//class Solution{// 占用更多储存空间
//public:
//	string reverseWords(string s) {
//		vector<string> words;
//		string word;
//		string result;
//		// 保存所有单词
//		for (char t : s) {
//			if (t != ' ') {
//				word.push_back(t);
//			}
//			else {//遇到空格保存单词，并清空word
//				if (word.empty()) { //有前导空格
//					continue;
//				}
//				words.push_back(word);
//				word.erase(word.begin(), word.end());
//			}			
//		}
//		if (!word.empty()) {
//			words.push_back(word); //保存最后一个单词
//		}		
//		
//		// 反转单词
//
//		for (int i = 0; i < words.size() / 2; i++) {
//			string temp = words[i];
//			words[i] = words[words.size() - i - 1];
//			words[words.size() - i - 1] = temp;
//		}
//
//		for (string& w : words) {
//			for (char t : w) {
//				result.push_back(t);
//			}
//			result.push_back(' ');
//		}
//		result.pop_back(); // 删除最后一个空格
//
//		return result;
//	}
//};

class Solution { // 直接组内反转
public:
	string reverseWords(string s) {
		// 快慢指针去除冗余空格
		int fast = 0, slow = 0;
		while (s[fast] == ' ') {
			fast++;
		}
		
		for (; fast < s.size(); fast++) {
			if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
				continue;
			}
			else {
				s[slow] = s[fast];
				slow++;
			}			
		}
		if (slow > 0 && s[slow - 1] == ' ') {
			s.resize(slow - 1);
		}
		else {
			s.resize(slow);
		}
		// 全部反转
		for (int i = 0; i < s.size() / 2; i++) {
			swap(s[i], s[s.size() - i - 1]);
		}
		
		//反转每个单词
		for (int i = 0; i < s.size(); i++) {
			int j = i;
			while (s[j] != ' ' && j < s.size()) {
				j++;
			}
			for (int k = i; k < (i + j) / 2; k++) {
				swap(s[k], s[i + j - 1 - k]);
			}
			i = j;
		}
		return s;
	}
};

//int main() {
//	string s = " the  sky is  blue ";
//	Solution solution;
//	string result = solution.reverseWords(s);
//	cout << result << endl;
//}