#include <iostream>

using namespace std;

// 파티션 함수: 정렬 방향에 따라 오름차순 또는 내림차순으로 작동
int Partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high]; // 마지막 요소를 피벗으로 선택
    int i = low - 1;       // 피벗 기준 작은/큰 요소의 마지막 인덱스

    for (int j = low; j < high; j++) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // 피벗을 제자리에 놓음
    return i + 1;
}

// 퀵 정렬 함수: 정렬 방향에 따라 동작
void QuickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high, ascending);
        QuickSort(arr, low, pivotIndex - 1, ascending);  // 피벗 왼쪽 정렬
        QuickSort(arr, pivotIndex + 1, high, ascending); // 피벗 오른쪽 정렬
    }
}

// 배열을 출력하는 함수
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* Calc(int arr[], int size) {
    static int result[2]; // 합계와 곱셈 결과 저장

    result[0] = 0; // 합 초기화
    result[1] = 1; // 곱 초기화

    for (int i = 0; i < size; i++) {
        result[0] += arr[i]; // 합 계산
        result[1] *= arr[i]; // 곱 계산
    }
    result[1] /= size;

    return result; // 결과 배열 반환
}

int main() {
    int n;
    cout << "입력할 숫자의 개수를 입력하세요: ";
    cin >> n;

    int* array = new int[n]; // 동적 배열 생성

    cout << n << "개의 숫자를 입력하세요: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int sortChoice;
    cout << "정렬 방식을 선택하세요 (1: 오름차순, 2: 내림차순): ";
    cin >> sortChoice;

    if (sortChoice == 1) {
        QuickSort(array, 0, n - 1, true);
        cout << "오름차순 정렬 결과: ";
    }
    else if (sortChoice == 2) {
        QuickSort(array, 0, n - 1, false);
        cout << "내림차순 정렬 결과: ";
    }
    else {
        cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
        delete[] array; // 메모리 해제
        return 1;
    }

    PrintArray(array, n);
    int* result = Calc(array, n);
    cout << "합계: " << result[0] << endl;
    cout << "평균: " << static_cast<double>(result[0]) / n << endl;

    delete[] array; // 동적 메모리 해제
    return 0;
}