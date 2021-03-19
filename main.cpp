#include <iostream>
#include <fstream>


using namespace std;


void creator_1(){
	ofstream file_1 ("text_1.txt");
	file_1 << "Let me say this: bein a idiot is no box of chocolates...";
	file_1.close();
	ofstream file_2 ("text_2.txt");
	file_2 << "From Forrest Gump by Winston Groom";
	file_2.close();
}


void creator_2(){
	ofstream file_1 ("text_11.txt");
	file_1 << "Let me say this: bein a idiot is no box of chocolates...gsagsdgaew";
	file_1.close();
	ofstream file_2 ("text_22.txt");
	file_2 << "From Forrest Gump by Winston Groomsdagsdge4gdsrgzs";
	file_2.close();
}


void stapler(){
	
	ifstream file1("text_1.txt");
    ifstream file2("text_2.txt");
	ofstream file3("text_3.txt");
	char *ch_1 = new char[100] {};
	char *ch_2 = new char[100] {};

	file1.read(ch_1, 100);
	file2.read(ch_2, 100);

	file3 << ch_1;

	file3 << '\n';

	file3 << ch_2;
	
	delete []ch_1;
	delete []ch_2;
	file1.close();
	file2.close();
	file3.close();

}

void staplerfromlesson (istream& file1, istream& file2, ostream& file3){
	file1.seekg(0, ios_base::end);
	auto size1 = file1.tellg();
	file1.seekg(0, ios_base::beg);
	
	file2.seekg(0, ios_base::end);
	auto size2 = file2.tellg();
	file2.seekg(0, ios_base::beg);
	
	char *buffer = new char[size1+size2];
	file1.read(buffer, size1);
	file2.read(buffer + size1, size2);
	
	file3.write(buffer, size1 + size2);
	

	
	delete []buffer;
	
}

bool findWord(istream& file, char* word){
	string word_;
	while (file >> word_){
		if(word_ == word) {
			return true;
		}
	}
	return false;
}



int main(int argc, char** argv) {
 	
	creator_1();
	creator_2();
	stapler(); //text_1, text_2, text_3
	
	if(argc != 3){
		cout << argv[0] << " file_name word\n";
		return 1;
	}
	
	ifstream file1("text_11.txt");
    ifstream file2("text_22.txt");
	ofstream file3("text_33.txt");

	staplerfromlesson(file1, file2, file3);
	
	char* file_name = argv[1];
	char* word = argv[2];
	ifstream file_(file_name);
	cout << boolalpha << findWord(file_, word);
	return 0;
}
