#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int number;
	scanf("%d", &number);
	getchar();

	string inputString;
	//getline(cin,  inputString);
	scanf("%s", inputString);

	vector<int> originArray;

	stringstream steram;

	// originArray에 입력 된 타워 높이 정리
	for (int i = 0; i < inputString.size(); i++)
	{
		if (i % 2 != 0)
			continue;

		int inputValue = inputString.at(i) - '0';

		originArray.push_back(inputValue);

		steram.putback('0');

		// 방금 넣어준 inputValue는 제외하고 for문 돌아가게
		for (int j = originArray.size() - 2; j >= 0; j--)
		{
			if (steram.str().back() != ' ')
				steram.putback(' ');

			if (inputValue <= originArray[j])
			{
				steram.putback(j);
			}

		}
	}

	printf("%%s", steram.str());

	return 0;
}
