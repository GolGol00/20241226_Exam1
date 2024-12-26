#include <iostream>

using namespace std;

// ��Ƽ�� �Լ�: ���� ���⿡ ���� �������� �Ǵ� ������������ �۵�
int Partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high]; // ������ ��Ҹ� �ǹ����� ����
    int i = low - 1;       // �ǹ� ���� ����/ū ����� ������ �ε���

    for (int j = low; j < high; j++) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // �ǹ��� ���ڸ��� ����
    return i + 1;
}

// �� ���� �Լ�: ���� ���⿡ ���� ����
void QuickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high, ascending);
        QuickSort(arr, low, pivotIndex - 1, ascending);  // �ǹ� ���� ����
        QuickSort(arr, pivotIndex + 1, high, ascending); // �ǹ� ������ ����
    }
}

// �迭�� ����ϴ� �Լ�
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* Calc(int arr[], int size) {
    static int result[2]; // �հ�� ���� ��� ����

    result[0] = 0; // �� �ʱ�ȭ
    result[1] = 1; // �� �ʱ�ȭ

    for (int i = 0; i < size; i++) {
        result[0] += arr[i]; // �� ���
        result[1] *= arr[i]; // �� ���
    }
    result[1] /= size;

    return result; // ��� �迭 ��ȯ
}

int main() {
    int n;
    cout << "�Է��� ������ ������ �Է��ϼ���: ";
    cin >> n;

    int* array = new int[n]; // ���� �迭 ����

    cout << n << "���� ���ڸ� �Է��ϼ���: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int sortChoice;
    cout << "���� ����� �����ϼ��� (1: ��������, 2: ��������): ";
    cin >> sortChoice;

    if (sortChoice == 1) {
        QuickSort(array, 0, n - 1, true);
        cout << "�������� ���� ���: ";
    }
    else if (sortChoice == 2) {
        QuickSort(array, 0, n - 1, false);
        cout << "�������� ���� ���: ";
    }
    else {
        cout << "�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�." << endl;
        delete[] array; // �޸� ����
        return 1;
    }

    PrintArray(array, n);
    int* result = Calc(array, n);
    cout << "�հ�: " << result[0] << endl;
    cout << "���: " << static_cast<double>(result[0]) / n << endl;

    delete[] array; // ���� �޸� ����
    return 0;
}