#include<iostream>
#include<vector>
using namespace std;

//class Solution{// ռ�ø��ഢ��ռ�
//public:
//	string reverseWords(string s) {
//		vector<string> words;
//		string word;
//		string result;
//		// �������е���
//		for (char t : s) {
//			if (t != ' ') {
//				word.push_back(t);
//			}
//			else {//�����ո񱣴浥�ʣ������word
//				if (word.empty()) { //��ǰ���ո�
//					continue;
//				}
//				words.push_back(word);
//				word.erase(word.begin(), word.end());
//			}			
//		}
//		if (!word.empty()) {
//			words.push_back(word); //�������һ������
//		}		
//		
//		// ��ת����
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
//		result.pop_back(); // ɾ�����һ���ո�
//
//		return result;
//	}
//};

class Solution { // ֱ�����ڷ�ת
public:
	string reverseWords(string s) {
		// ����ָ��ȥ������ո�
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
		// ȫ����ת
		for (int i = 0; i < s.size() / 2; i++) {
			swap(s[i], s[s.size() - i - 1]);
		}
		
		//��תÿ������
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