#include "utils.h"

void delay(int msec)
{
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents , 100);
}

vector<string> parseLine(string aString)
{
    stringstream lineStream(aString);
    string cell;

    vector<string> keys;

    // parse line
    while(getline(lineStream, cell, ',')) {
        keys.push_back(cell);
    }

    return keys;
}



const vector<map<string, string>> extract_fileData(string fileName)
{
    vector<map<string, string>> data;

    // open file
    ifstream file(fileName);

    if(!file) {
        cout << "Unable to open the file named: " << fileName;
    }
    else {
        string tmp;
        // prepare keys for map
        getline(file, tmp);
        vector<string> keys = parseLine(tmp);
        // end prepare keys for map

        while(!file.eof()) {

            // parse every line of the file remaning
            getline(file, tmp);
            vector<string> values = parseLine(tmp);

            map<string, string> map_tmp;
            for (unsigned long long i = 0; i < keys.size(); i++) {
                map_tmp.insert({keys[i], values[i]});
            }

            // put the map in the vector data
            data.push_back(map_tmp);
        }
    }

    // close file to avoid trouble
    file.close();

    return data;
}


void print_data(vector<map<string, string> > aData)
{
    for (unsigned long long i = 0; i < aData.size(); i++) {
        map<string, string> line = aData[i];
        string toCout = "";

        for (map<string, string>::iterator it = line.begin(); it != line.end(); it++) {
            toCout += it->first + ": " + it->second + ",";
        }

        cout << i << "(" << toCout << ")" << std::endl;
    }
}


