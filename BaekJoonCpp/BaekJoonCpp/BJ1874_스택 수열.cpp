#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int arrayCount;
	scanf("%d", &arrayCount);

	vector<int> originArray(arrayCount);
	vector<int> sortArray(arrayCount);

	for (int i = 0; i < arrayCount; i++)
	{
		int inputValue;
		scanf("%d", &originArray[i]);
		sortArray[i] = i + 1;
	}

	int originIndex = 0;
	int sortIndex = 0;
	int charIndex = 0;

	vector<char> charArray;
	stack<int> resultStack;

	// 첫번째는 무조건 Push 해줘야함
	resultStack.push(sortArray[sortIndex++]);
	//charArray[charIndex++] = '+';
	charArray.push_back('+');

	bool noCheck = false;

	while (true)
	{
		int peekValue = 0;
		if (resultStack.empty())
			peekValue = INT16_MIN;
		else
			peekValue = resultStack.top();

		int originValue = originArray[originIndex];

		if (peekValue < originValue)
		{
			int sortValue = sortArray[sortIndex++];
			resultStack.push(sortValue);
			charArray.push_back('+');
			//charArray[charIndex++] = '+';
		}
		else if (peekValue == originValue)
		{
			resultStack.pop();
			//charArray[charIndex++] = '-';
			charArray.push_back('-');
			originIndex++;
		}
		else
		{
			noCheck = true;
			break;
		}

		if (originIndex >= arrayCount)
			break;
	}

	if (noCheck)
	{
		printf("NO\n");
		return 0;
	}

	for (int i = 0; i < charArray.size(); i++)
	{
		printf("%c\n", charArray[i]);
	}

}