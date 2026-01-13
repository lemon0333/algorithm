#include <iostream>
#include <vector>

using namespace std;

// 북(0), 동(1), 남(2), 서(3) 순서에 따른 좌표 변화
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int r, c, d;
    cin >> r >> c >> d;

    // 변수명을 contain으로 통일하고 크기를 정확히 할당
    vector<vector<int>> contain(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> contain[i][j];
        }
    }

    int result = 0;

    while (true) {
        // 1. 현재 칸이 청소되지 않은 경우 청소
        if (contain[r][c] == 0) {
            contain[r][c] = 2; // 청소 완료 표시
            result++;
        }

        bool foundEmpty = false;
        // 2. 주변 4칸 중 청소되지 않은 빈 칸 탐색
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (contain[nr][nc] == 0) {
                    foundEmpty = true;
                    break;
                }
            }
        }

        if (!foundEmpty) {
            // 주변에 빈 칸이 없는 경우: 후진 시도
            int backDir = (d + 2) % 4; 
            int br = r + dr[backDir];
            int bc = c + dc[backDir];

            // 뒤쪽 칸이 벽이 아니면 후진
            if (br >= 0 && br < N && bc >= 0 && bc < M && contain[br][bc] != 1) {
                r = br;
                c = bc;
                continue; 
            } else {
                // 후진 불가능하면 종료
                break;
            }
        } else {
            // 주변에 빈 칸이 있는 경우: 회전 후 전진 시도
            for (int i = 0; i < 4; i++) {
                d = (d + 3) % 4; // 반시계 회전
                int fr = r + dr[d];
                int fc = c + dc[d];

                if (fr >= 0 && fr < N && fc >= 0 && fc < M && contain[fr][fc] == 0) {
                    r = fr;
                    c = fc;
                    break; 
                }
            }
        }
    }

    cout << result << "\n";
    return 0;
}