#include <string>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
//userid , nickname
map<string, string> list;
string result_list[100000][3];
vector<string> solution(vector<string> record) {
    vector<string> answer;

    //분리하기해서 배열에 저장
    for(int i = 0; i < record.size(); i++){
        char s[11];
        strcpy(s, record[i].c_str());
        char *ptr = strtok(s, " ");
        int j = 0;
        while(ptr != NULL){   
         //   cout << ptr << endl;
            result_list[i][j++] = ptr;
          //  cout << j << endl;
            ptr = strtok(NULL, " ");
        }
    }
    //map에 userid와 nickname만 저장
    for(int i = 0; i < record.size(); i++){
        if(result_list[i][0]=="Enter"){
            list[result_list[i][1]] = result_list[i][2];
            list.insert(make_pair(result_list[i][1],result_list[i][2]));
        }
        //이름 변경
        if(result_list[i][0]=="Change"){
            list[result_list[i][1]] = result_list[i][2];
        }
    }
      //출력
       for(int i = 0; i < record.size(); i++){
        if(result_list[i][0]=="Enter"){
            string name = list[result_list[i][1]];
            answer.push_back(name+"님이 들어왔습니다.");

        }
        //이름 변경
        if(result_list[i][0]=="Leave"){
            string name = list[result_list[i][1]];
            answer.push_back(name+"님이 나갔습니다.");
        }
    }

    return answer;
}