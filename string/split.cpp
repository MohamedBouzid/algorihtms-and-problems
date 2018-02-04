#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the function below.
 */

/*
 * Complete the function below.
 */
vector <string> findViolations(vector <string> datafeed) {

    vector<string> array;
    unordered_map<string,int> sub, start;
    int mi= 0 ;
    int line = 1;
    for(auto & s : datafeed){
        string s1 = s.substr(0, s.find(";"));
        string s2 = s.substr(s.find(";")+1);
				cout<<"s1 = "<<s1<<" s2 = "<<s2<<endl;

        if(s2=="START"){
        	start[s1] = mi;
					//cout<<"start "<<s1<<" : "<<mi<<endl;
        }else{
          mi = max(atoi(s2.c_str()) + 1,mi);
          sub[s1] = atoi(s2.c_str());
				//	cout<<"subs "<<s1<<" : "<<sub[s1]<<endl;
        }
				line++;

    }
    vector<string> fraud;
		for(auto & p : start){
			//cout<<p.first<<":"<<p.second<<"*****"<<sub[p.first]<<endl;
		  if(p.second > sub[p.first]){
					cout<<p.first<<":"<<p.second<<endl;
		      ostringstream st;
		      st << line;
		      string num = st.str();
		      string output = num + p.first + "SHORTENED_JOB";
					cout<<output<<endl;
		      fraud.push_back(output);
		  }
			
		}
		//cout<<fraud.at(0);    
		return fraud;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector <string> res;
    int datafeed_size = 0;
    cin >> datafeed_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> datafeed;
    for(int i = 0; i < datafeed_size; i++) {
        string datafeed_item;
        getline(cin, datafeed_item);
        datafeed.push_back(datafeed_item);
    }

    res = findViolations(datafeed);

		cout<<"fraud detected !"<<endl;
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	cout << res.at(res_i) << endl;;
    }

    fout.close();
    return 0;
}
