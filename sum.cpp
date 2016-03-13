#include <string>
#include <algorithm>

string sum(string a, string b){
	string res;
	int i = a.length();
	int j = b.length();
	
	if (i > j)
		res.resize(i + 1, '0');
	else
		res.resize(j + 1, '0');

	int loc = 0;
	char carry = '0';


	while (i && j){
		i--;
		j--;

		res[loc] = '0';
		res[loc] = a[i] + b[j] + carry - (2*48);
		if (res[loc] > '9'){
			res[loc] -= 10;
			carry = '1';
		}
		else
			carry = '0';

		loc++;
		
	}

		
	if (i > j){
		while (i){
			i--;
			res[loc] = a[i] + carry - 48;
			if (res[loc] > '9'){
				res[loc] -= 10;
				carry = '1';
			}
			else
				carry = '0';
			loc++;
		}
	}
	else if (j > i){
		while (j){
			j--;
			res[loc] = b[j] + carry - 48;
			if (res[loc] > '9'){
				res[loc] -= 10;
				carry = '1';
			}
			else
				carry = '0';
			loc++;
		}
	}
	
	if (i == j && carry == '1')
		res[loc] = '1';
	

	if (res[res.length() - 1] == '0')
		res.resize(res.length() - 1, 'Q');
	
	
		reverse(res.begin(), res.end());


	
	return res;
}
