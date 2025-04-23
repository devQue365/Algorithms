import heapq # in-built lib to be used for priority queue

class MinPriorityQueue(object):
    def __init__(self):
        self.heap = []
    def insert(self, element):
        heapq.heappush(self.heap,element)
    def extract_min(self):
        if self.heap:
            return heapq.heappop(self.heap)
        return None
    def show(self):
        print(self.heap)

def max_heapify(arr, n, i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    if(left<n and arr[left]>arr[largest]):
        largest = left
    if(right<n and arr[right]>arr[largest]):
        largest = right
    if(largest != i):
        arr[i],arr[largest] = arr[largest],arr[i]
        max_heapify(arr, n, largest)

def max_heapSort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        max_heapify(arr,n,i)
    for i in range(n-1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        max_heapify(arr,i,0)


''' MIN_HEAPIFY '''
def min_heapify(arr, n, i):
    smallest = i
    left = 2*i + 1
    right = 2*i + 2
    if(left<n and arr[left]<arr[smallest]):
        smallest = left
    if(right<n and arr[right]<arr[smallest]):
        smallest = right
    if(smallest != i):
        arr[i], arr[smallest] = arr[smallest], arr[i]
        min_heapify(arr,n,smallest)

def min_heapSort(arr):
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        min_heapify(arr,n,i)
    for i in range(n-1, 0, -1):
        arr[0],arr[i] = arr[i],arr[0]
        min_heapify(arr,i,0)
        
# __main__ segment
arr = [4, 1, 3, 9, 7]
# min_heapSort(arr)
pq = MinPriorityQueue()
for i in arr:
    pq.insert(i)
pq.show()
# print(arr)
