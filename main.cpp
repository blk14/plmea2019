#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Photo {
public:
	int nr_tags;
	int id;
	char type;
	vector<string> tags;

	Photo(int nr_tags, int id, char type) {
		this->nr_tags = nr_tags;
		tags.resize(nr_tags);
		this->id = id;
		this->type = type;
	}

	~Photo() {}

	void add_tag(string tag) {
		tags.push_back(tag);
	}

	void print() {
		cout << id << " " << nr_tags << " " << type << " [";
		for (int i = 0; i < nr_tags; ++i) 
		{
			cout << tags[i] << " ";
		}
		cout << "]\n";
	}
}



std::vector<Photo>* parse_input(string filename) {
	int N, M;
	char type;
	string current_tag;
	vector<Photo>* input;
	
	ifstream in(filename);
	
	in >> N;
	for (int i = 0; i < N; ++i) {
		in >> type;
		in >> M;
		Photo current_photo(M, i, type);
		for (int j = 0; j < M; ++j) {
			in >> current_tag;
			current_photo.add_tag(current_tag);
		}
		input.push_back(current_photo);
	}

	in.close();
	return input;
}

int main() {
	vector<Photo> photos = parse_input("a_example.txt");
	for (int i = 0; i < photos.size(); ++i)
	{
		photos[i].print();
	}
}