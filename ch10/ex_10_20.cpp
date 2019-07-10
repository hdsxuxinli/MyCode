#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	std::stable_sort(words.begin(), words.end(), isShorter);
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	auto count = std::count_if(words.begin(), words.end(), [sz](const string &s) {
		return s.size() >= sz;
	} );	
	cout << count << " " << make_plural(count, "word") << " of length " << sz << " or longer" << endl;

	std::for_each(words.end() - count, words.end(), [](const string &s) {cout << s << " ";});
	cout << endl;
}

int main()
{
	vector<string> vec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "thurtle"};
	biggies(vec, 6);
	return 0;
}
