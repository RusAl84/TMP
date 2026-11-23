
#https://www.geeksforgeeks.org/dsa/queue-linked-list-implementation/
global nop
nop=0

class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None

class myQueue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.currSize = 0  

    def isEmpty(self):
        global nop
        nop+=1
        return self.front is None

    def enqueue(self, new_data):
        global nop
        nop+=1
        new_node = Node(new_data)
        nop+=1
        if self.isEmpty():
            nop+=2
            self.front = self.rear = new_node
        else:
            nop+=2
            self.rear.next = new_node
            self.rear = new_node
        nop+=1
        self.currSize += 1 


    def dequeue(self):
        global nop
        nop+=1
        if self.isEmpty():
            print("Queue Underflow")
            return -1
        nop+=1
        removedData = self.front.data
        nop+=1
        self.front = self.front.next
        nop+=1
        if self.front is None:
            nop+=1
            self.rear = None
        nop+=1
        self.currSize -= 1 
        nop+=1
        return removedData

    def getFront(self):
        global nop
        nop+=1
        if self.isEmpty():
            nop+=1
            print("Queue is empty")
            return -1
        return self.front.data

    def size(self):
        global nop
        nop+=1
        return self.currSize

class myQueueAdapter:
    def __init__(self):
        self.q = myQueue()

    def isEmpty(self):
        global nop
        nop+=1
        return self.q.isEmpty()

    def enqueue(self, new_data):
        global nop
        nop+=1
        self.q.enqueue(new_data)

    def dequeue(self):
        global nop
        nop+=1
        return self.q.dequeue()

    def getFront(self):
        global nop
        nop+=1
        return self.q.getFront()

    def size(self):
        global nop
        nop+=1
        return self.q.size()

    def display(self):
        global nop
        nop+=1
        tq = myQueue()
        print("---Display")
        nop+=1
        while not self.isEmpty():
            nop+=1
            item = self.getFront()
            nop+=1
            self.dequeue()
            nop+=1
            tq.enqueue(item)
        nop+=1
        while not tq.isEmpty():
            nop+=1
            item = tq.getFront()
            nop+=1
            tq.dequeue()
            nop+=1
            self.enqueue(item)
            nop+=1
            print(item)
        nop+=1
        print("---")

    def setElement(self, index, new_item):
        global nop
        nop+=1
        tq = myQueue()
        nop+=1
        ind = 0
        nop+=1
        while not self.isEmpty():
            nop+=1
            item = self.getFront()
            nop+=1
            self.dequeue()
            nop+=1
            if index == ind:
                nop+=1
                tq.enqueue(new_item)
            else:
                nop+=1
                tq.enqueue(item)
            nop+=1
            ind+=1
        nop+=1
        while not tq.isEmpty():
            nop+=1
            item = tq.getFront()
            nop+=1
            tq.dequeue()
            nop+=1
            self.enqueue(item)

    def getElement(self, index):
        global nop
        nop+=1
        tq = myQueue()
        nop+=1
        ind = 0
        nop+=1
        while not self.isEmpty():
            nop+=1
            item = self.getFront()
            nop+=1
            self.dequeue()
            nop+=1
            if index == ind:
                nop+=1
                new_item=item
            nop+=1
            tq.enqueue(item)
            nop+=1
            ind+=1
        nop+=1
        while not tq.isEmpty():
            nop+=1
            item = tq.getFront()
            nop+=1
            tq.dequeue()
            nop+=1
            self.enqueue(item)
        nop+=1
        return new_item


#https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
def bubbleSort(arr):
    # n = len(arr)
    global nop
    nop+=1
    n = arr.size()
    nop+=1
    for i in range(n):
        nop+=1
        swapped = False

        # Last i elements are already in place
        nop+=1
        for j in range(0, n-i-1):

            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            # if arr[j] > arr[j+1]:
            #     arr[j], arr[j+1] = arr[j+1], arr[j]
            #     swapped = True
            nop+=1
            if arr.getElement(j) > arr.getElement(j+1):
                nop+=4
                tmpEl = arr.getElement(j)
                arr.setElement(j, arr.getElement(j+1))
                arr.setElement(j+1, tmpEl)
                swapped = True
        nop+=1
        if (swapped == False):
            nop+=1
            break

def generate_numbers(count=10):
    import random
    start=0
    end=100
    arr = [random.randint(start, end) for _ in range(count)]
    for i in range(len(arr)):
        q.enqueue(arr[i])
    return q

if __name__ == "__main__":
    q = myQueueAdapter()
    # q.enqueue(10000)
    # q.enqueue(20000)
    # q.enqueue(30000)
    # q.enqueue(40000)
    # q.enqueue(50000)
    # q.display()
    # q.setElement(0,99999)
    # q.setElement(4,77777)
    # q.display()
    # print(q.getElement(1))   

    # q = generate_numbers(20)
    #presets = [10,20,30] #,40,50,60,70,80,90,100
    presets = [10,20,30,40,50,60,70,80,90,100]
    import time

    for i in range(len(presets)):
        nop = 0
        while not q.isEmpty():
            q.dequeue()
        q = generate_numbers(presets[i])
        start_time = time.time()
        bubbleSort(q)
        end_time = time.time()
        # q.display()
        elapsed_time = end_time - start_time
        # print(f"n={presets[i]} elapsed_time={elapsed_time}")
        print(f"n={presets[i]} nop={nop}")
    

    # print("Sorted array:")
    # for i in range(len(arr)):
    #     print("%d" % arr[i], end=" ")
