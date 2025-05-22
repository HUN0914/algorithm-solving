#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<>());

    for (int i = 0; i < mats.size(); i++) {
        for (int j = 0; j < park.size(); j++) {
            for (int k = 0; k < park[0].size(); k++) {
                if (park[j][k] == "-1" && k + mats[i] <= park[0].size() && j + mats[i] <= park.size()) {
                    bool check = true;

                    for (int l = 0; l < mats[i]; l++) {
                        for (int n = 0; n < mats[i]; n++) {
                            if (park[j + l][k + n] != "-1") {
                                check = false;
                                break;
                            }
                        }
                        if (!check) break;
                    }

                    if (check) return mats[i];
                }
            }
        }
    }

    return -1;
}