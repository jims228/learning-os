class SelectionSort implements Strategy {
    public void sort(int[] data) {
        int n = data.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (data[j] < data[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                int tmp = data[i];
                data[i] = data[minIdx];
                data[minIdx] = tmp;
            }
        }
    }
}
