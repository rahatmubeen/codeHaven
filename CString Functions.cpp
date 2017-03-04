#include<iostream>
#include<conio.h>
using namespace std;

void stringConcatenate(char *str1, char *str2)
{
	int i;
	for (i = 0; *(str1+i) != '\0'; i++){}

	int j;
	for (j = 0; *(str2+j) != '\0'; j++){}

	j = 0;
	int k;
	for ( k = i; *(str2+j)!='\0'; k++)
	{
		*(str1+k) = *(str2+j);
		j++;
	}

	*(str1+k) = '\0';

	
}

char **stringTokens(char *str)
{
	char **temp = 0;
	int tokenlen = 0;
	for (char *iptr = str; *iptr != '\0'; iptr++)
	{

		if (*iptr == ' ')
		{
			tokenlen++;
		}

	}
	tokenlen++;

	temp = new char*[tokenlen];

	//for (int i = 0; i < tokenlen; i++)
	//{
	//	temp[i] = new char[10];
	//}

	char *xptr = str;
	char *jptr=str;
	int arrlen = 0;
	for (char **iptr = temp; iptr < temp + tokenlen; iptr++)
	{
		for (; *jptr != ' ' && *jptr!='\0'; jptr++)
		{
			arrlen++;
		}

		*(iptr) = new char[arrlen + 1];
		arrlen=0;
		jptr++;
	}

	
	for (char **iptr = temp; iptr < temp + tokenlen; iptr++)
	{
		for (jptr = *iptr; *xptr != ' ' && *xptr != '\0'; jptr++)
		{
			*jptr = *xptr;

			xptr++;
		}

		*jptr = '\0';
		*xptr++;
	}

	return temp;
}

char **reverseStringTokens(char *str)
{
	char **temp = 0,**reverseTemp=0;
	int tokenlen = 0;

	for (char *iptr = str; *iptr != '\0'; iptr++)
	{

		if (*iptr == ' ')
		{
			tokenlen++;
		}

	}
	tokenlen++;

	temp = new char*[tokenlen];
	reverseTemp = new char*[tokenlen];
	int len = 0;

	for (char *iptr = str; *iptr != '\0'; iptr++)
	{
		len++;
	}
	
	char *jptr = str;
	int arrlen = 0;
	for (char **iptr = temp; iptr < temp + tokenlen; iptr++)
	{
		for (; *jptr != ' ' && *jptr != '\0'; jptr++)
		{
			arrlen++;
		}

		*(iptr) = new char[arrlen + 1];
		arrlen = 0;
		jptr++;
	}

	jptr = str + len - 1;
	for (char **iptr = reverseTemp; iptr < reverseTemp + tokenlen; iptr++)
	{
		for (; *jptr != ' ' && jptr>=str; jptr--)
		{
			arrlen++;
		}

		*(iptr) = new char[arrlen + 1];
		arrlen = 0;
		jptr--;
	}

	char *xptr = str;
	for (char **iptr = temp; iptr < temp + tokenlen; iptr++)
	{
		for (jptr = *iptr; *xptr != ' ' && *xptr != '\0'; jptr++)
		{
			*jptr = *xptr;

			xptr++;
		}

		*jptr = '\0';
    	 xptr++;
	}

	for (char **iptr = reverseTemp,**kptr=temp+tokenlen-1; iptr < reverseTemp+tokenlen && kptr>=temp; iptr++,kptr--)
	{
		char *jptr = *iptr;
		for ( char *xptr=*kptr; *xptr!='\0'; jptr++,xptr++)
		{
			*jptr = *xptr;
		}

		*jptr = '\0';
	}

	return reverseTemp;
}

char *reverseSentence(char *arr)
{
	char **temp = reverseStringTokens(arr);


	int tokenlen = 0;
	for (char *iptr = arr; *iptr != '\0'; iptr++)
	{

		if (*iptr == ' ')
		{
			tokenlen++;
		}

	}
	tokenlen++;

	int count = 0;

	for (int i = 0; *(arr + i) != '\0'; i++){ count++; }
	
	char *tempArr = new char[count + 1];
	char *xptr = tempArr;

	for (char *iptr = arr; iptr < arr+count; iptr++)
	{
		*xptr = *iptr;

		xptr++;
	}
	
	
	char *tempPtr=tempArr;
	
	for (char **iptr = temp;iptr<temp+tokenlen; iptr++)
	{
		for (char *jptr=*iptr; *jptr != '\0'; jptr++)
		{
			*tempPtr = *jptr;

			tempPtr++;
		}

		*tempPtr = ' ';

		tempPtr++;
	}

	*(tempPtr-1) = '\0';

	return tempArr;
}

void CompressString(char* str)
{
	int len = 0;

	for (int i = 0; *(str + i) != '\0'; i++){ len++; }


	char*temp;

	for (temp = str; temp<str + len;)
	{
		if (*temp == *(temp + 1))
		{
			for (char*temp2 = temp; temp2<temp + len; temp2++)
			{
				*temp2 = *(temp2 + 1);
			}
		}

		else{ temp++; }

		if (*temp == 0)
		{
			break;
		}
	}

}

void main()
{
	//concatenate strings
	char xStr[100];
	char yStr[100];

	cout << "Enter the first string: ";
	cin.getline(xStr, 99);

	cout << "Enter the second string: ";
	cin.getline(yStr, 99);

	int count = 0, count2 = 0;
	for (int i = 0; xStr[i] != '\0'; i++){ count++; }
	
	for (int i = 0; yStr[i] != '\0'; i++){ count2++;}

	char *str1 = new char[count + count2 + 1];
	char *str2 = new char[count2+1];

	
	int i;
	for ( i =0 ; *(xStr+i) != '\0'; i++)
	{
		*(str1+i) = *(xStr+i);
	}

	*(str1+i) = '\0';

	for (i = 0; *(yStr+i) != '\0'; i++)
	{
		*(str2+i) = *(yStr+i);
	}

	*(str2+i) = '\0';

	stringConcatenate(str1, str2);
	cout << "After Concatenation: \n" << str1<<endl;
	cout << endl;

	delete[] str1;
	str1 = 0;
	
	delete[] str2;                       
	str2 = 0;

	//string tokens

	char temp[100];
	cout << "Enter your string to make tokens: ";
	cin.getline(temp, 99);

	for (i = 0; temp[i] != '\0'; i++){}

	str1 = new char[i + 1];
	i = 0;
	for (char *iptr = str1; temp[i] != '\0';iptr++)
	{
		*iptr = temp[i];

		i++;
	}

	*(str1 + i) = '\0';

	int tokenlen = 0;
	for (char *iptr = str1; *iptr != '\0'; iptr++)
	{

		if (*iptr == ' ')
		{
			tokenlen++;
		}

	}
	tokenlen++;
	char **tokenStrings = stringTokens(str1);

	for (char **iptr = tokenStrings; iptr < tokenStrings + tokenlen; iptr++)
	{
		for (char *jptr = *iptr; *jptr != '\0'; jptr++)
		{
			cout << *jptr;
		}
		cout << endl;
	}
	cout << endl;

	for (char **iptr = tokenStrings; iptr < tokenStrings + tokenlen; iptr++)
	{
		delete[] * iptr;
	}

	delete[] str1;
	delete[] tokenStrings;
	tokenStrings = 0;

	//reverse token string
	cout << "Enter your string to make reverse-tokens: ";
	cin.getline(temp, 99);

	for (i = 0; temp[i] != '\0'; i++){}

	str1 = new char[i + 1];
	i = 0;
	for (char *iptr = str1; temp[i] != '\0'; iptr++)
	{
		*iptr = temp[i];

		i++;
	}

	*(str1 + i) = '\0';

	 tokenlen = 0;
	for (char *iptr = str1; *iptr != '\0'; iptr++)
	{

		if (*iptr == ' ')
		{
			tokenlen++;
		}

	}
	tokenlen++;
	 tokenStrings = reverseStringTokens(str1);

	 cout << "Reverse Token Strings are: \n";

	for (char **iptr = tokenStrings; iptr < tokenStrings + tokenlen; iptr++)
	{
		for (char *jptr = *iptr; *jptr != '\0'; jptr++)
		{
			cout << *jptr;
		}
		cout << endl;
	}

	cout << endl;

	for (char **iptr = tokenStrings; iptr < tokenStrings + tokenlen; iptr++)
	{
		delete[] * iptr;                                           //deleting memory on heap
	}

	delete[] str1;
	delete[] tokenStrings;
	tokenStrings = 0;

	//reverse sentence

	cout << "Enter the string you want to reverse: ";
	cin.getline(temp, 99);

	for (i = 0; temp[i] != '\0'; i++){}

	str1 = new char[i + 1];
	i = 0;

	char *iptr = str1;

	for (iptr = str1; temp[i] != '\0'; iptr++)
	{
		*iptr = temp[i];

		i++;
	}
	
	*iptr = '\0';
	
	char *revSen = reverseSentence(str1);

	cout << "Reverse Sentence is: \n";
	cout  << revSen << endl << endl;

	delete[] str1;
	str1 = 0;

	delete[] revSen;
	str2 = 0;
	
	iptr = 0;

	//Compress String

	cout << "Enter the string you want to compress: ";
	cin.getline(temp, 99);

	for (i = 0; temp[i] != '\0'; i++){}

	str1 = new char[i + 1];
	i = 0;

	iptr = str1;

	for (iptr = str1; temp[i] != '\0'; iptr++)
	{
		*iptr = temp[i];

		i++;
	}

	*iptr = '\0';

	CompressString(str1);

	cout << "Compressed String is: \n" << str1 << endl << endl << endl;

	cout << "*****************KHALLAS****************";

	_getch();
}