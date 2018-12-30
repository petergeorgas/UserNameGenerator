#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;
int main() {
    srand((unsigned)time(nullptr));
    vector<string> adjectives;
    vector<string> nouns;
    vector<string> usernames;
    string noun;
    string ADJ;
    string users;
    fstream in_stream;
    int adj_size = 0;
    int noun_size = 0;
    in_stream.open("/Users/Peter/Downloads/UserNameGenerator/adjective.txt"); // Open the file
    //in_stream.open("/Users/Peter/Downloads/UserNameGenerator/nouns.txt");
    while (getline(in_stream, ADJ, '\n')) {
        if (!ADJ.empty()) {
            adjectives.push_back(ADJ);
        }
    }
    in_stream.close();
    in_stream.open("/Users/Peter/Downloads/UserNameGenerator/nouns.txt");
    while (getline(in_stream, noun, '\n')) { // Store each line of the text file into a vector.
        if (!noun.empty()) {
            nouns.push_back(noun);
        }
    }
    in_stream.close();

    // randomize the indicies of the vectors.
    bool length = true;
    bool containment = true;
    while(length = true) {
        int rand_adj = rand() % adjectives.size();
        int rand_noun = rand() % nouns.size();
        int rand_num = rand() % 999 + 100;
        string adj_out = adjectives[rand_adj];
        string noun_out = nouns[rand_noun];
        adj_out[0] = toupper(adj_out[0]);
        noun_out[0] = toupper(noun_out[0]);
        stringstream final_out;
        final_out << adj_out << noun_out << rand_num << endl; // Create 1 String Stream
        string final_string = final_out.str(); //Convert to String
        if (final_string.length() <= 15) { // If the size of the username is <= 15, write it to the usernames file and output the name.

            ofstream out_stream;
            out_stream.open("/Users/Peter/Downloads/UserNameGenerator/usernames.txt", ios_base::app);

            in_stream.open("/Users/Peter/Downloads/UserNameGenerator/usernames.txt"); // Load usernames file into an array
            while(getline(in_stream, users, '\n')){
                if(!usernames.empty()){
                    usernames.push_back(users);
                }
            }
            in_stream.close();
            if(find(usernames.begin(), usernames.end(), final_string) != usernames.end()) { //CURRENTLY DOESN'T WORK

                out_stream << final_string;
                out_stream.close();

                cout << final_string;
                length = false;
                break;
            }
        }
    }
}
