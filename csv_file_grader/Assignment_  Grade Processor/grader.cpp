// -----------------------------------------------------------------------
// grader.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// -----------------------------------------------------------------------
// global constants
const string INFILE_PREFIX = "rawgrades-";
const string OUTFILE_PREFIX = "grade-report-";
const string IN_FILE_EXT = ".csv";
const string OUT_FILE_EXT = ".txt";

const size_t LEN_PREFIX = INFILE_PREFIX.length();
const size_t LEN_F_EXT = 3;

///this will be used for extra space between fields in the output file
const string SPACER = "  ";

const double A_GRADE = 90.0;
const double B_GRADE = 80.0;
const double C_GRADE = 70.0;
const double D_GRADE = 60.0;
// anything below D_GRADE is an 'F'

// output field widths
const int FW_NAME = 24;
const int FW_SCORE = 4;
const int FW_LOW = 3;
const int FW_TOTAL = 5;
const int FW_AVG = 7;
const int FW_GRADE = 3;
const int FW_SCORE_X4 = FW_SCORE * 4;

/// -----------------------------------------------------------------------
/// function prototypes

// top-level functions
string getInputFilename();
string deriveOutputFilename(const string &inFname);
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout);
void processGradeFile(ifstream &fin, ofstream &fout);

/// helper functions
// TODO (0): declare function prototypes for the helper functions
bool validInputFilename(const string &fname);
int min(int a, int b);
int min(int a, int b, int c, int d);
char gradeFromScore(double score);
void parseStudentRecord(const string &line, string &name, string &id, int &s1, int &s2, int &s3, int &s4);
char gradeFromScore(double score);
void processLine(ostream &out, const string &line);
void writeReportHeader(ofstream &out);

/// -----------------------------------------------------------------------
// program entry point
int main() {
    // main() has been implemented for you; no need to change anything here
    ifstream fin;
    ofstream fout;

    string inFilename = getInputFilename();
    string outFilename = deriveOutputFilename(inFilename);

    if (!openFiles(inFilename, outFilename, fin, fout)) {
        return EXIT_FAILURE;
    }

    cout << "Processing " << inFilename << " ..." << endl;
    processGradeFile(fin, fout);
    cout << "Report written to " << outFilename << endl;

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}


/// -----------------------------------------------------------------------
/// helper function definitions

// Returns true if `fname` of the form "rawgrades-<className>.csv"
bool validInputFilename(const string &fname) {
    size_t nameLen = fname.length();
    int postFix = nameLen - 4;
    string temp;
    //cout << endl << "**fname length: " << nameLen << endl;

    // TODO (1): implement validation on the given filename
    if (INFILE_PREFIX == fname.substr(0, 10) && nameLen > 14 && IN_FILE_EXT == fname.substr(postFix, 4)) {
        //temp = fname.substr(10, nameLen - 14); //temp is what needs to be kept
        //cout << "**passed " << endl;

       return true;
    }
    else return false;
       ///look for the presence of INFILE_PREFIX
       ///look for the presence of IN_FILE_EXT
       /// ensure the name length is MORE than just the prefix and extension
    return true;
}


// Parses a record, placing the substrings into `name`, `id`, and `s1...s4`
void parseStudentRecord(const string &line, string &name, string &id, int &s1, int &s2, int &s3, int &s4) {
    int index = line.find(",");
    name = line.substr(0, index);
    int index2 = 0;
    //for(int i = 0; i < 7; i++) {}
//    index = line.find(",", index + 1);
//    index2 = line.find(",", index + 1);
//    name = line.substr(index, index2 - index);

    ///index = line.find(",", index + 1);
    index2 = line.find(",", index + 1);
    id = line.substr(index + 1, index2 - index - 1);


    ///index = line.find(",", index + 1);
    ///index2 = line.find(",", index + 1);
    stringstream ss1;
    ss1.str(line.substr(index2));
    char c; //burner for each ','
    ss1 >> c >> s1 >> c >> s2 >> c >> s3 >> c >> s4;


    //cout << endl << "s1: " << s1 << " s2: " << s2 << " s3: " << s3 << " s4: " << s4 << " c: " << c << endl;

}

// Returns the smaller of the two values
int min(int a, int b) {
    if(a < b) return a;
    if(b <= a) return b;
    //TODO (3): return minimum value
}

// Returns the smallest of all the values
int min(int a, int b, int c, int d) {
    // TODO (4): return minimum value
    // HINT: use min(int, int)

    if(min(a, b) < min(c, d)) return min(a, b);
    if(min(c, d) <= min(a, b)) return min(c, d);
}

// Returns a letter grade for the given score
char gradeFromScore(double score) {
    char grade = 'F';

    // TODO (5): adjust grade based on score
    if(score >= 90.0) grade = 'A';
    else if(score >= 80.0) grade = 'B';
    else if(score >= 70.0) grade = 'C';
    else if(score >= 60.0) grade = 'D';
    else grade = 'F';

    return grade;
}

// Processes a line read from the raw-grades input file
void processLine(ostream &out, const string &line) {
    string studentName, studentId, scores;
    int score1, score2, score3, score4;
    int total, lowest;
    double average;
    char letterGrade;

    // TODO (6): process the raw record...
    parseStudentRecord(line, studentName, studentId, score1, score2, score3, score4);
    // - compute total (but subtract the lowest score)
    lowest = min(score1, score2, score3, score4);
    //cout << "**lowest: " << lowest << endl;

    total = score1 + score2 + score3 + score4 - lowest;
    // - compute the average (of 3 scores)
    average = (double)total / 3.0;
    letterGrade = gradeFromScore(average);

    // TODO (7): write the formatted record to the report file
    out << left << setw(FW_NAME) << studentName << SPACER
        << right << setw(FW_SCORE) << score1
        << setw(FW_SCORE) << score2
        << setw(FW_SCORE) << score3
        << setw(FW_SCORE) << score4 << SPACER
        << '(' << setw(FW_LOW) << lowest << ')' << SPACER
        << setw(FW_TOTAL) << total << SPACER
        << setw(FW_AVG) << average << SPACER
        << setw(FW_GRADE) << letterGrade << endl;
}

// Writes the report header to the given output stream
void writeReportHeader(ofstream &out) {
    // Lucky you! I've implemented this one for you. Don't change it! :)
    out << left;

    out << setw(FW_NAME) << "Name" << SPACER
        << setw(FW_SCORE_X4) << "Scores" << SPACER
        << "(" << setw(FW_LOW) << "Low" << ")" << SPACER
        << setw(FW_TOTAL) << "Total" << SPACER
        << setw(FW_AVG) << "Average" << SPACER
        << "Grade"
        << endl;

    out << setfill('-');

    out << setw(FW_NAME) << "" << SPACER
        << setw(FW_SCORE_X4) << "" << SPACER
        << "-" << setw(FW_LOW) << "" << "-" << SPACER
        << setw(FW_TOTAL) << "" << SPACER
        << setw(FW_AVG) << "" << SPACER
        << "-----"
        << endl;

    out << setfill(' ') << fixed << setprecision(2);
}


/// -----------------------------------------------------------------------
/// top-level function definitions

// Returns a validated input filename from the user
string getInputFilename() {
    string fname;

    do{
        cout << "Enter input filename (rawgrades-<className>.csv): ";
        cin >> fname;
        cout << endl;

    } while(!validInputFilename(fname));
    // TODO (8): Repeatedly prompt the user for a filename
    //            until it matches the required form.

    return fname;
}

// Derives the output filename from the given input filename
string deriveOutputFilename(const string &inFname) {

    // TODO (9): Generate the output file name
       ///grade-report-<className>.txt
       ///use .replace to replace the prefix and the extension
       int nameLen = inFname.length();
       string lol = inFname;

       lol.replace(nameLen - 4, 4, OUT_FILE_EXT);
       lol.replace(0, INFILE_PREFIX.size(), OUTFILE_PREFIX);

    return lol;
}

// Returns true only if both files opened without error
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout) {

    // TODO (10): open input and output files, associate with the given streams
    // HINT:
    //   open input;  if fails, write message and return false
    //   open output; if fails, write message and return false
    //   return true
    fin.open(inName);
    fout.open(outName);

    if(!fin.is_open()) {
        cout << "failed" << endl;
        return false;
    }
    else if(!fout.is_open()) {
        cout << "failed" << endl;
        return false;
    }

    return true;
}

// Read input records, process, write formatted output records
void processGradeFile(ifstream &fin, ofstream &fout) {
    // This function, too, has been implemented for you... nothing to do here
    string rawLine;

    writeReportHeader(fout);
    while (getline(fin, rawLine)) {
        processLine(fout, rawLine);
    }
}

// -----------------------------------------------------------------------
