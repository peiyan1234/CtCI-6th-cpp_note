#include <string>
#include <bitset>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

bool is_unique_unordered_map_solution(const string &inputstr)
{
	if (inputstr.size() > 1 &&  
	   inputstr.size() <= 256)
	{
		char c;
		size_t index = 0;

		unordered_map<char, bool> str_hashT;
		
		while (index < inputstr.size())
		{
	            c = inputstr[index];

                    if (str_hashT.find(c) == str_hashT.end()) 
		    {
			    str_hashT[c] = true;
		    }		    
		    else
			    return false;

		    index++;
		}

		return true;
	}

	if (inputstr.size() == 0)
		return true;

	return false;
}

int main()
{
	vector<string> testwords = {"abcde",
                                       "hello",
	                               "apple",
	                               "kite",
	                               "padle"};

	printf("Test words and answers\n%s: true\n%s: false\n%s: false\n%s: true\n%s: true", 
	       testwords[0].c_str(), testwords[1].c_str(), 
	       testwords[2].c_str(), testwords[3].c_str(), testwords[4].c_str());

	printf("\n\nTesting the version of unordered_map solution ...\n\n");
	
	bool answer;
	
	time_t start, end;
	time(&start);

	for (auto inputstr: testwords)
	{
		answer = is_unique_unordered_map_solution(inputstr);
		printf("%s\t", answer ? "true" : "false");
	}

	time(&end);
	double avg_runtime = (end - start) / 5.0;

	printf("\nAvg. runtime: %lf\n\n", avg_runtime);

	return 0;
}

