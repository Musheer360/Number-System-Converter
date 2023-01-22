#include <iostream>
using namespace std;

int main() {
  
    char task, repeat;
    string from, to;

    cout << "\n    + -------------------------------- +" << endl;
    cout << "    | NUMBER SYSTEM CONVERSION PROGRAM |" << endl;
    cout << "    + -------------------------------- +" << endl;

    cout << "\nEnter 'C' if you want to perform conversions,\nOr enter 'Q' if you want to find complements." << endl;
    cout << "\nYour input: ";
    cin >> task;

    print:

    if (task == 'c' || task == 'C') {

        cout << "\n    PERFROMING NUMBER SYSTEM CONVERSIONS" << endl;

        cout << "\nGive input as:\n'B' for Binary, 'D' for Decimal, 'O' for Octal,\n'H' for Hexa-decimal and 'G' for Gray Code." << endl;
        
        cout << "\nYou want to convert from: ";
        cin >> from;
        cout << "You want to convert to: ";
        cin >> to;

        
        if((from == "b" || from == "B") && (to == "d" || to == "D")) {
            int decbd = 0, weightbd = 1;
            string binbd;

            cout << "\nConverting from Binary to Decimal:\n";
            cout << "\nEnter Binary number: ";
            cin >> binbd;

            bool validbd = true;

            for(int ibd = 0; ibd < binbd.length(); ibd++) {
                if(binbd[ibd] != '0' && binbd[ibd] != '1') {
                validbd = false;
                break;
                }
            }

            if(validbd == false) {
                cout << "Please enter a valid binary value!" << endl;
            }

            else {
                for(int ibd = binbd.length() - 1; ibd >= 0; ibd--) {
                if(binbd[ibd] == '1') {
                    decbd += weightbd;
                }
        
                weightbd *= 2;
                }
        
                cout << "Decimal value: " << decbd << endl;
            }
        }

        
        else if((from == "d" || from == "D") && (to == "b" || to == "B")) {
            int decdb, testdb, bindb[128], idb = 0;
    
            cout << "\nConverting from Decimal to Binary:\n";
            cout << "\nEnter decimal number: ";
            cin >> decdb;

            testdb = decdb;

            if(cin.fail()) {
                cout << "Please enter a valid integer!" << endl;
                return 0;
            }
    
            while(decdb > 0) {
                bindb[idb] = decdb % 2;
                decdb = decdb / 2;
                idb++;
            }

            if(testdb > 0) {
                cout << "Binary value: ";
        
                for (int jdb = idb - 1; jdb >= 0; jdb--) {
                    cout << bindb[jdb];
                }
            }

            else {
                cout << "Binary value: 0" << endl;
            }
        }

        
        else if((from == "d" || from == "D") && (to == "o" || to == "O")) {
            int decdo, testdo, octdo[128], ido = 0;
    
            cout << "\nConverting from Decimal to Octal:\n";
            cout << "\nEnter decimal number: ";
            cin >> decdo;

            testdo = decdo;

            if(cin.fail()) {
                cout << "Please enter a valid integer!" << endl;
                return 0;
            }
    
            while(decdo > 0) {
                octdo[ido] = decdo % 8;
                decdo = decdo / 8;
                ido++;
            }

            if(testdo > 0) {
                cout << "Octal value: ";
        
                for (int jdo = ido - 1; jdo >= 0; jdo--) {
                    cout << octdo[jdo];
                }
            }

            else {
                cout << "Octal value: 0" << endl;
            }
        }

        
        else if((from == "o" || from == "O") && (to == "d" || to == "D")) {
            int decod = 0, weightod = 1;
            string octod;
            
            cout << "\nConverting from Octal to Decimal:\n";
            cout << "\nEnter octal number: ";
            cin >> octod;

            if(cin.fail()) {
                cout << "Please enter a valid octal value!" << endl;
                return 0;
            }

            for(int iod = octod.length() - 1; iod >= 0; iod--) {
                if(octod[iod] >= '0' && octod[iod] < '8') {
            
                decod += (octod[iod] - '0') * weightod;
                }

                else {
                    cout << "Please enter a valid octal value!" << endl;
                    return 0;
                }
        
                weightod *= 8;
            }
        
            cout << "Decimal value: " << decod << endl;
        }


        else if((from == "d" || from == "D") && (to == "h" || to == "H")) {
            int decdh, testdh, hexdh[128], idh = 0;
    
            cout << "\nConverting from Decimal to Hexa-decimal:\n";
            cout << "Enter decimal number: ";
            cin >> decdh;

            testdh = decdh;

            if(cin.fail()) {
                cout << "Please enter a valid integer!" << endl;
                return 0;
            }
    
            while(decdh > 0) {
                hexdh[idh] = decdh % 16;
                decdh = decdh / 16;
                idh++;
            }

            if(testdh > 0) {
                cout << "Hexa-decimal value: ";
        
                for(int jdh = idh - 1; jdh >= 0; jdh--) {
                    if(hexdh[jdh] < 10) {
                        cout << hexdh[jdh];
                    } 
                
                    else {
                        cout << (char)('A' + hexdh[jdh] - 10);
                    }
                }
            }

            else {
                cout << "Hexa-decimal value: 0" << endl;
            }
        }



        else if((from == "h" || from == "H") && (to == "d" || to == "D")) {
            int dechd = 0, weighthd = 1;
            string hexhd;
            
            cout << "\nConverting from Hexa-decimal to Decimal:\n";
            cout << "\nEnter hexa-decimal number: ";
            cin >> hexhd;

            for(int ihd = hexhd.length() - 1; ihd >= 0; ihd--) {
                char chd = hexhd[ihd];
                int digithd;
            
                if(chd >= '0' && chd <= '9') {
                    digithd = chd - '0';
                }
            
                else if(chd >= 'A' && chd <= 'F') {
                    digithd = chd - 'A' + 10;
                }
            
                else {
                    cout << "Invalid hexadecimal digit: " << chd << endl;
                    return 1;
                }

                dechd += digithd * weighthd;
                weighthd *= 16;
            }

            cout << "Decimal value: " << dechd << endl;
        }
        
        
        else if((from == "b" || from == "B") && (to == "g" || to == "G")) {
            string binbg;

            cout << "\nConverting from Binary to Gray Code:\n";
            cout << "\nEnter binary number: ";
            cin >> binbg;

            bool validbg = true;

            for(int ibg = 0; ibg < binbg.length(); ibg++) {
                if(binbg[ibg] != '0' && binbg[ibg] != '1') {
                validbg = false;
                break;
                }
            }

            if(validbg == false) {
                cout << "Please enter a valid binary value!" << endl;
            }

            else {
                cout << "Gray code value: ";
                cout << binbg[0];

                for(int ibg = 0; ibg < binbg.length() - 1; ibg++) {
                    cout << (binbg[ibg] ^ binbg[ibg + 1]);
                }

                cout << endl;
            }
        }


        else if((from == "g" || from == "G") && (to == "b" || to == "B")) {
            string graygb;
            
            cout << "\nConverting from Gray code to Binary:\n";
            cout << "Enter gray code value: ";
            cin >> graygb;

            bool validgb = true;

            for(int igb = 0; igb < graygb.length(); igb++) {
                if (graygb[igb] != '0' && graygb[igb] != '1') {
                validgb = false;
                break;
                }
            }

            if(validgb == false) {
                cout << "Please enter a valid gray code value!" << endl;
            }

            else {
                cout << "Binary value: ";
                int prevbingb = graygb[0] - '0';
                cout << prevbingb;

                for(int igb = 1; igb < graygb.length(); igb++) {
                int currentgraygb = graygb[igb] - '0';
                int currentbingb = currentgraygb ^ prevbingb;
                cout << currentbingb;
                prevbingb = currentbingb;
                }
                
                cout << endl;
            }
        }
        

        else {
            cout << "\nInvalid conversion!" << endl;
        }
    }


    else if(task == 'q' || task == 'Q') {

        cout << "\n      FINDING 1'S AND 2'S COMPLEMENTS" << endl;;
        string bincp;
        cout << "\nEnter binary number: ";
        cin >> bincp;

        bool validcp = true;

        for(int icp = 0; icp < bincp.length(); icp++) {
            if(bincp[icp] != '0' && bincp[icp] != '1') {
                validcp = false;
                break;
            }
        }

        if(validcp == false) {
            cout << "Please enter a valid binary value!" << endl;
        }
        
        else {
            string onescp = bincp;

            for(int icp = 0; icp < bincp.length(); icp++) {
                if(bincp[icp] == '0') {
                    onescp[icp] = '1';
                }
            
                else if(bincp[icp] == '1') {
                    onescp[icp] = '0';
                }
            }  

            cout << "\n1's complement of " << bincp << " is: " << onescp << endl;

            string twoscp = onescp;
            int carrycp = 1;

            for(int jcp = onescp.length() - 1; jcp >= 0; jcp--) {
                if(onescp[jcp] == '1' && carrycp == 1) {
                    twoscp[jcp] = '0';
                }
                
                else if(onescp[jcp] == '0' && carrycp == 1) {
                    twoscp[jcp] = '1';
                    carrycp = 0;
                }

                else {
                    twoscp[jcp] = onescp[jcp];
                }
            }

            cout << "2's complement of " << bincp << " is: " << twoscp << endl;
        }
    }

    else {
        cout << "Invalid Input!" << endl;
    }
    
    again:
    cout << "\nDo you want to repeat the operation? (Y/N) ";
    cin >> repeat;
    
    if(repeat == 'y' || repeat == 'Y') {
        goto print;
    }

    else if(repeat == 'n' || repeat == 'N') {
        cout << "\nExiting the program..." << endl;;
        cout << "Done!" << endl;;
    }

    else {
        cout << "\nPlease enter Yes or No!" << endl;;
        goto again;
    }

    return 0;
}