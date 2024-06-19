#include <iostream>

int StrLength(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

class String
{
private:
	char* mStr;

public:
	String()
	{
		mStr = new char[1];
		mStr[0] = '\0';
	}
	String(const char* str)
	{
		int len = StrLength(str) + 1;
		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = str[i];
		}
	}
	String(const String& str)
	{
		int len = StrLength(str.mStr) + 1;
		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = str.mStr[i];
		}
	}
	~String()
	{
		delete[] mStr;
		mStr = nullptr;
	}
	char* Getter()
	{
		return mStr;
	}
	void Setter(int len)
	{
		delete[] mStr;
		mStr = new char[len];
	}
	String& operator +(const String& str)
	{
		int lLen = StrLength(mStr);
		int rLen = StrLength(str.mStr);
		int j = 0;
		String sum;
		sum.Setter(lLen + rLen + 1);

		for (int i = 0; i < lLen; i++)
		{
			sum.mStr[i] = mStr[i];
		}
		for (int i = lLen; i < lLen + rLen + 1; i++)
		{
			sum.mStr[i] = str.mStr[j++];
		}
		delete[] mStr;

		*this = sum;

		return *this;
	}

	String& operator = (const String& str)
	{
		int len = StrLength(str.mStr) + 1;
		char* temp = new char[len];
		for (int i = 0; i < len; i++)
		{
			temp[i] = str.mStr[i];
		}

		delete[] mStr;

		mStr = new char[len];
		for (int i = 0; i < len; i++)
		{
			mStr[i] = temp[i];
		}

		delete[]temp;
		return *this;
	}
	String& operator +=(String rstr)
	{
		*this = *this + rstr;
		return *this;
	}
	char& operator [] (int i)
	{
		return mStr[i];
	}
};

std::ostream& operator << (std::ostream& os, String& str)
{
	os << str.Getter();
	return os;
}


int main()
{
	String empty;
	std::cout << empty << std::endl;

	String s1("hello");
	std::cout << s1 << std::endl;

	String s2(s1);
	std::cout << s2 << std::endl;

	String s3 = s1 + s2;
	std::cout << s3 << std::endl;

	s3 += s3;
	std::cout << s3 << std::endl;

	std::cout << s3[0] << ", " << s3[1] << std::endl;
	s3[0] = 'H';
	std::cout << s3 << std::endl;

	empty = s3;
	std::cout << empty << std::endl;

	empty = empty;
	std::cout << empty << std::endl;
}