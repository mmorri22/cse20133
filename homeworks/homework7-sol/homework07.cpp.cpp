#include "palindrome.h"



int main(const int argc, const char* argv[]) {

    // check if valid
    if (argc != 2) {
        COUT << "Must have only 1 test file." << ENDL;
    }

    // initialize ifstream & check a valid open
    std::ifstream fin(argv[1]);
    if (!fin.is_open()) {
        COUT << argv[1] << " is an invalid test file." << ENDL; 
    }
    
    // initialize ofstream & check if output file is valid
    std::string out_file = "output.txt"; // hard coded output
    std::ofstream fout(out_file, std::ofstream::out);
    if (!fout.is_open()) { 
        COUT << out_file << " is an invalid output file." << ENDL; 
    }
    

    // iterate through and read the string & check if a palindrome permutation
    while (1) {
        std::string inputstr;
        std::getline(fin, inputstr);
        if (fin.eof()) break;

        if (is_palindrome( inputstr )) {
            fout << "\"" << inputstr << "\" is a palindrome permutation" << ENDL;
        }
        else {
            fout << "\"" << inputstr << "\" is not a palindrome permutation" << ENDL;
        }
        //del inputstr;
    }

    fin.close(); // close our ifstream
    fout.close(); // close our ofstream
    

    return 0;
}
