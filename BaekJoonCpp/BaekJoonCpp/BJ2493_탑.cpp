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

	// originArray�� �Է� �� Ÿ�� ���� ����
	for (int i = 0; i < inputString.size(); i++)
	{
		if (i % 2 != 0)
			continue;

		int inputValue = inputString.at(i) - '0';

		originArray.push_back(inputValue);

		steram.putback('0');

		// ��� �־��� inputValue�� �����ϰ� for�� ���ư���
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
