
/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 Note
 The result may be very large, so you need to return a string instead of an integer.
 
 Example
 Given [1, 20, 23, 4, 8], the largest formed number is 8423201.
 */

#include "global.h"

class Largest_Number {
public:
	/**
	 *@param num: A list of non negative integers
	 *@return: A string
	 */
	string largestNumber(vector<int> &num) {
		// write your code here
		string res;
		list<string> strnum;
		vector<int>::iterator i;
		char tmpstr[32];
		
		bool all0 = true;
		for (i = num.begin(); i != num.end(); i ++) {
			memset(tmpstr, 0, sizeof(tmpstr));
			sprintf(tmpstr, "%d", *i);
			strnum.push_back(tmpstr);
			if (*i != 0)
				all0 = false;
		}
		if (all0)
			return "0";
		
		while (!strnum.empty()) {
			list<string> big = pickup(strnum);
			list<string>::iterator iter;
			for (iter = big.begin(); iter != big.end(); iter ++) {
				res.append(*iter);
			}
		}
		return res;
	}
private:
	list<string> pickup(list<string> &strnum) {
		char max;
		list<string> l1 = strnum;
		list<string> l2;
		int i = 0;
		string tmp;
		bool shouldbreak;
		
		for (; ; i ++) {
			list<string>::iterator iter;
			max = '0';
			shouldbreak = true;
			for (iter = l1.begin(); iter != l1.end(); iter ++) {
				tmp = *iter;
				if (tmp.length() <= i) {
					if (max < tmp[0]) {
						max = tmp[0];
						l2.clear();
						l2.push_back(tmp);
					} else if (max == tmp[0]) {
						l2.push_back(tmp);
					}
				} else if (tmp[i] > max) {
					max = tmp[i];
					l2.clear();
					l2.push_back(tmp);
					shouldbreak = false;
				} else if (tmp[i] == max) {
					l2.push_back(tmp);
					shouldbreak = false;
				}
			}
			
			if (l2.size() == 1) {
				strnum.remove(l2.front());
				return l2;
			} else {
				bool samelen = true;
				bool allsame = true;
				string first = l2.front();
				for (iter = l2.begin(); iter != l2.end(); iter ++) {
					tmp = *iter;
					if (tmp.length() != first.length()) {
						samelen = false;
						allsame = false;
						break;
					} else if (tmp.compare(first) != 0) {
						allsame = false;
					}
				}
				if (allsame) {
					for (iter = l2.begin(); iter != l2.end(); iter++) {
						strnum.remove(*iter);
					}
					return l2;
				} else if (samelen) {
					list<string> l3;
					for (iter = l2.begin(); iter != l2.end(); iter++) {
						tmp = *iter;
						if (tmp.compare(first) > 0) {
							first = tmp;
							l3.clear();
							l3.push_back(tmp);
						} else if (tmp.compare(first) == 0) {
							l3.push_back(tmp);
						}
					}
					for (iter = l3.begin(); iter != l3.end(); iter ++) {
						strnum.remove(*iter);
					}
					return l3;
				} else if (shouldbreak) {
					for (iter = l2.begin(); iter != l2.end(); iter++) {
						strnum.remove(*iter);
					}
					return l2;
				}
				
				l1 = l2;
				l2.clear();
			}
		}
	}
};

void test_largest_number()
{
	int array[] = {0, 0, 0};
	vector<int> num;
	for (int i = 0; i < sizeof(array)/sizeof(int); i ++) {
		num.push_back(array[i]);
		printf("%d, ", array[i]);
	}
	cout << endl;
	Largest_Number s;
	string str = s.largestNumber(num);
	cout << str << endl;
}

