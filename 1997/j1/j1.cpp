#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> vs;

void vs_print(vs& v){
	for(const auto& s : v){
		cout << s << endl;
	}
}

int case_insensitive_compare(string a, string b){
	string lower_a = "";
	string lower_b = "";
	for(char c : a){
		lower_a += tolower(c);
	}
	for(char c : b){
		lower_b += tolower(c);
	}
	return lower_a < lower_b;
}

vs do_data_set(vs subjects, vs verbs, vs objects){
	sort(subjects.begin(), subjects.end(), case_insensitive_compare);
	sort(verbs.begin(), verbs.end(), case_insensitive_compare);
	sort(objects.begin(), objects.end(), case_insensitive_compare);

	vs sentences;
	for(auto sub : subjects){
		for(auto verb : verbs){
			for(auto obj : objects){
				string sentence = sub + " " + verb + " " + obj + ".";
				sentences.push_back(sentence);
			}
		}
	}	
	return sentences;
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		vs subjects, verbs, objects;
		int nSub, nVerb, nObj;
		cin >> nSub >> nVerb >> nObj;
		cin.ignore(256, '\n');

		for(int j=0; j<nSub; j++){
			string subject;
			getline(cin, subject);
			subjects.push_back(subject);
		}
		for(int j=0; j<nVerb; j++){
			string verb;
			getline(cin, verb);
			verbs.push_back(verb);
		}
		for(int j=0; j<nObj; j++){
			string obj;
			getline(cin, obj);
			objects.push_back(obj);
		}

		vs sentences = do_data_set(subjects, verbs, objects);
		vs_print(sentences);
		cout << "\n";
	}
	return 0;
}
