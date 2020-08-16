## 1.冒泡排序

```
void bubble_sort(int arr[], int len)
{
    int i = 0, j = 0;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
```
## 2.选择排序

```
void select_sort(int arr[], int len)
{
    int i = 0, j = 0, tmp = 0;
    int min = 0;

    for (i = 0; i < len; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
```
## 3.插入排序

```
void insert_sort(int arr[], int len)
{
    int i = 0, j = 0;
    int preIdx = 0, cur = 0;
    for (i = 1; i < len; i++)
    {
        preIdx = i - 1;
        cur    = arr[i];
        while (preIdx >= 0 && arr[preIdx] > cur)
        {
            arr[preIdx+1] = arr[preIdx];
            preIdx--;
        }
        arr[preIdx+1] = cur;
    }
}
```
## 4.归并排序

```
void sort(int arr[], int len)
{
    vector<int> tmp(len, 0);
    mergeSort(arr, 0, len-1, tmp);
}

void mergeSort(int arr[], int l, int r, vector<int> &tmp)
{
    if (l >= r) return;

    int mid = (l + r) >> 1;

    mergeSort(arr, l, mid, tmp);
    mergeSort(arr, mid+1, r, tmp);

    merge(arr, l, mid, r, tmp);
}

void merge(int arr[], int l, int mid, int r, vector<int> &tmp)
{
    int i = l;
    int j = mid+1;
    int t = 0;

    while (i <= mid && j <= r)
    {
        arr[i] > arr[j] ? tmp[t++] = tmp[j++] : tmp[t++] = tmp[i++];
    }

    while (i <= mid) tmp[t++] = tmp[i++];
    while (j <= r)   tmp[t++] = tmp[j++];

    t = 0;
    while (l < r) arr[l++] = tmp[t++];
}
```

## 5.快速排序
### 1>基本思想
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。
### 2>算法描述
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
- 从数列中挑出一个元素，称为 “基准”（pivot）；
- 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
- 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

```
void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = arr[l];
        while (l < r && arr[j] >= x)
        {
            j--;
        }
        if (l < r)
        {
            arr[i++] = arr[j];
        }
        while (l < r && arr[i] < x)
        {
            i++;
        }
        if (l < r)
        {
            arr[j--] = arr[i];
        }
        arr[i] = x;
        quick_sort(arr, l, i-1);
        quick_sort(arr, i+1, r);
    }
}
```

