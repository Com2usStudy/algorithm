/*
문제 설명
n명이 입국심사를 위해 줄을 서서 기다리고 있습니다. 각 입국심사대에 있는 심사관마다 심사하는데 걸리는 시간은 다릅니다.

처음에 모든 심사대는 비어있습니다. 한 심사대에서는 동시에 한 명만 심사를 할 수 있습니다. 가장 앞에 서 있는 사람은 비어 있는 심사대로 가서 심사를 받을 수 있습니다. 하지만 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사를 받을 수도 있습니다.

모든 사람이 심사를 받는데 걸리는 시간을 최소로 하고 싶습니다.

입국심사를 기다리는 사람 수 n, 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times가 매개변수로 주어질 때, 모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하도록 solution 함수를 작성해주세요.


제한사항
입국심사를 기다리는 사람은 1명 이상 1,000,000,000명 이하입니다.
각 심사관이 한 명을 심사하는데 걸리는 시간은 1분 이상 1,000,000,000분 이하입니다.
심사관은 1명 이상 100,000명 이하입니다.

 

입출력 예
n 	times 	return
6 	[7, 10] 	28
 

입출력 예 설명
가장 첫 두 사람은 바로 심사를 받으러 갑니다.

7분이 되었을 때, 첫 번째 심사대가 비고 3번째 사람이 심사를 받습니다.

10분이 되었을 때, 두 번째 심사대가 비고 4번째 사람이 심사를 받습니다.

14분이 되었을 때, 첫 번째 심사대가 비고 5번째 사람이 심사를 받습니다.

20분이 되었을 때, 두 번째 심사대가 비지만 6번째 사람이 그곳에서 심사를 받지 않고 1분을 더 기다린 후에 첫 번째 심사대에서 심사를 받으면 28분에 모든 사람의 심사가 끝납니다.
*/

#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = (long long)times.back() * n;
    
    while (min <= max) {
        long long mid = (max + min) / 2;    // 기대치 평균 심사 시간
        long long process = 0;              // 각 심사원의 시간을 확인하는 값
        
        // 각 심사원이 평균 시간 안에 얼마나 처리하는지 확인
        for (int k = 0; k < times.size(); k++) {
            // k번째 심사원이 평균 시간 안에 (평균시간/k)명까지 심사 가능
            process += (mid / (long long)times[k]);
        }
        
        // 모든 심사원이 평균 시간 안에 업무를 처리할 수 있는 경우,
        // 더욱 최소 값을 찾기 위해 범위를 줄인다.
        if (process >= n) {
            max = mid - 1;  // 업무 시간을 줄여 더 빨리 처리 가능한지 확인한다.
            answer = mid;   // 업무 처리가 가능하니 정답에 입력해 놓는다.
        }
        // 모든 심사원이 평균 시간 안에 업무를 처리하지 못하는 경우,
        // 평균 시간을 늘려 업무 처리 가능 시간을 산정한다.
        else {
            min = mid + 1;  // 여유 시간을 주어 업무를 처리하게 만든다.
        }
    }
    
    return answer;
}
