class Spreadsheet {
private:
    unordered_map<std::string, int> umap;
public:
    Spreadsheet(int rows) {
       /* for (char c = 'A'; c <= 'Z'; c++) {
            for (int i = 1; i <= rows; i++) {
                string key = string(1, c) + to_string(i);
                umap[key]=0;
            }
        }*/
    }

    void setCell(string cell, int value) {
        umap[cell] = value;
    }

    void resetCell(string cell) {
        umap[cell] = 0;
    }

    int getValue(string formula) {
        bool string1exit = false;
        string string1="";
        string string2 = "";

        for (int i = 1; i < formula.size(); i++)
        {

            if (formula[i] != '+' && string1exit == false) {
                string1 += formula[i];
            }
            else if (formula[i] == '+')
            {
                string1exit = true;
                continue;
            }
            else
            {
                string2 += formula[i];
            }
        }int num1;
        int num2;
        if (string1[0] >= 'A'&&string1[0]<='Z')
        {
            if (umap.find(string1) == umap.end()) {
                num1 = 0;
            }
            else
            {
                num1 = umap[string1];
            }
        }
        else
        {
            num1 = stoi(string1);
        }
        if (string2[0] >= 'A' && string2[0] <= 'Z')
        {
            if (umap.find(string2) == umap.end()) {
                num2 = 0;
            }
            else
            {
                num2 = umap[string2];
            }
        }
        else
        {
            num2 = stoi(string2);
        }
        return num1 + num2;
    }
};