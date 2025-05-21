#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_min = stoi(video_len.substr(0, 2));
    int video_sec = stoi(video_len.substr(3, 2));

    int pos_min = stoi(pos.substr(0, 2));
    int pos_sec = stoi(pos.substr(3, 2));

    int op_start_min = stoi(op_start.substr(0, 2));
    int op_start_sec = stoi(op_start.substr(3, 2));

    int op_end_min = stoi(op_end.substr(0, 2));
    int op_end_sec = stoi(op_end.substr(3, 2));

    int op_start_time = op_start_min * 60 + op_start_sec;
    int op_end_time = op_end_min * 60 + op_end_sec;
    int cur_time = pos_min * 60 + pos_sec;

    // operation 시작 지점이면 end로 점프
    if (cur_time >= op_start_time && cur_time <= op_end_time) {
        cur_time = op_end_time;
    }

    for (string cmd : commands) {
        if (cmd == "prev") {
            cur_time -= 10;
            if (cur_time < 0) cur_time = 0;
        } else if (cmd == "next") {
            cur_time += 10;
            int video_time = video_min * 60 + video_sec;
            if (cur_time > video_time) cur_time = video_time;
        }

        // operation 범위면 스킵
        if (cur_time >= op_start_time && cur_time <= op_end_time) {
            cur_time = op_end_time;
        }
    }

    int final_min = cur_time / 60;
    int final_sec = cur_time % 60;

    string result = (final_min < 10 ? "0" : "") + to_string(final_min) + ":" +
                    (final_sec < 10 ? "0" : "") + to_string(final_sec);
    

    return result;
}