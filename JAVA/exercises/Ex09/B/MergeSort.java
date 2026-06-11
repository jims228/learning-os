class MergeSort implements Strategy {
    public void sort(int[] data) {
        if (data.length <= 1) return;
        int[] buf = new int[data.length];
        mergeSort(data, buf, 0, data.length - 1);
    }

    private void mergeSort(int[] data, int[] buf, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(data, buf, left, mid);
        mergeSort(data, buf, mid + 1, right);
        merge(data, buf, left, mid, right);
    }

    private void merge(int[] data, int[] buf, int left, int mid, int right) {
        for (int i = left; i <= right; i++) buf[i] = data[i];
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (buf[i] <= buf[j]) {
                data[k++] = buf[i++];
            } else {
                data[k++] = buf[j++];
            }
        }
        while (i <= mid) data[k++] = buf[i++];
        while (j <= right) data[k++] = buf[j++];
    }
}
