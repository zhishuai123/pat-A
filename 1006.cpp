#include<iostream>
#include<string>
#include<vector>
using namespace std;
class time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	bool operator< (const time& t)
	{
		if (hours != t.hours)
			return hours < t.hours;
		if (minutes != t.minutes)
			return minutes < t.minutes;
		return seconds < t.seconds;
	}
	bool operator> (const time& t)
	{
		if (hours != t.hours)
			return hours > t.hours;
		if (minutes != t.minutes)
			return minutes > t.minutes;
		return seconds > t.seconds;
	}
	friend istream& operator>>(istream& in, time& t)
	{
		char ch;
		in >> t.hours >> ch >> t.minutes >> ch >> t.seconds;
		return in;
	}
};
int main()
{
	int num;
	cin >> num;
	vector<pair<string, pair<class time, class time>>> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i].first >> input[i].second.first >> input[i].second.second;
	int unlocked = 0, locked = 0;
	for (int i = 0; i < input.size(); i++)
	{
		unlocked = input[i].second.first < input[unlocked].second.first ? i : unlocked;
		locked = input[i].second.second > input[locked].second.second ? i : locked;
	}
	cout << input[unlocked].first << ' ' << input[locked].first;
	return 0;
}