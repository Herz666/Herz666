#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void extractLinesFromEvent(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);

    std::string line;
    std::vector<std::string> eventLines;
    bool inEventBlock = false;

    while (std::getline(fin, line)) {
        if (line.find("<event>") != std::string::npos) {
            inEventBlock = true;
            eventLines.clear(); // Clear previous event lines
        }

        if (inEventBlock) {
            // Add line to eventLines vector
            eventLines.push_back(line);

            // Check if we have reached the end of the event block
            if (line.find("</event>") != std::string::npos) {
                inEventBlock = false;

                // Extract and write lines 5 and 6 (indices 4 and 5 in zero-based indexing)
                if (eventLines.size() >= 5) {
                    // Extract values from the 7th to the 10th column of the 5th line
                    std::istringstream line5(eventLines[4]);
                    double value;
                    int column = 0;

                    while (line5 >> value) {
                        ++column;
                        if (column >= 7 && column <= 10) {
                            fout << value << " ";
                        }
                    }

                    fout << std::endl;

                    // Extract values from the 7th to the 10th column of the 6th line
                    std::istringstream line6(eventLines[5]);
                    column = 0;

                    while (line6 >> value) {
                        ++column;
                        if (column >= 7 && column <= 10) {
                            fout << value << " ";
                        }
                    }

                    fout << std::endl;
                    fout << std::endl; // Separate events with a blank line
                }
            }
        }
    }

    fin.close();
    fout.close();
}

int main() {
    std::string inputFile = "qq.lhe";
    std::string outputFile = "p_qq.dat";

    extractLinesFromEvent(inputFile, outputFile);

    std::cout << "Extraction terminée. Les valeurs ont été écrites dans le fichier " << outputFile << std::endl;

    return 0;
}
