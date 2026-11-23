
#https://www.geeksforgeeks.org/dsa/queue-linked-list-implementation/
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
        return self.front is None

    def enqueue(self, new_data):
        new_node = Node(new_data)
        if self.isEmpty():
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

        self.currSize += 1 

    def dequeue(self):
        if self.isEmpty():
            print("Queue Underflow")
            return -1
        removedData = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.rear = None

        self.currSize -= 1 
        return removedData

    def getFront(self):
        if self.isEmpty():
            print("Queue is empty")
            return -1
        return self.front.data

    def size(self):
        return self.currSize

class myQueueAdapter:
    def __init__(self):
        self.q = myQueue()

    def isEmpty(self):
        return self.q.isEmpty()

    def enqueue(self, new_data):
        self.q.enqueue(new_data)

    def dequeue(self):
        return self.q.dequeue()

    def getFront(self):
        return self.q.getFront()

    def size(self):
        return self.q.size()

    def display(self):
        tq = myQueue()
        print("---Display")
        while not self.isEmpty():
            item = self.getFront()
            self.dequeue()
            tq.enqueue(item)
        while not tq.isEmpty():
            item = tq.getFront()
            tq.dequeue()
            self.enqueue(item)
            print(item)
        print("---")

    def setElement(self, index, new_item):
        tq = myQueue()
        ind = 0
        while not self.isEmpty():
            item = self.getFront()
            self.dequeue()
            if index == ind:
                tq.enqueue(new_item)
            else:
                tq.enqueue(item)
            ind+=1
        while not tq.isEmpty():
            item = tq.getFront()
            tq.dequeue()
            self.enqueue(item)

    def getElement(self, index):
        tq = myQueue()
        ind = 0
        while not self.isEmpty():
            item = self.getFront()
            self.dequeue()
            if index == ind:
                new_item=item
            tq.enqueue(item)
            ind+=1
        while not tq.isEmpty():
            item = tq.getFront()
            tq.dequeue()
            self.enqueue(item)
        return new_item




#https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
def bubbleSort(arr):
    # n = len(arr)
    n = arr.size()
    
    for i in range(n):
        swapped = False

        # Last i elements are already in place
        for j in range(0, n-i-1):

            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            # if arr[j] > arr[j+1]:
            #     arr[j], arr[j+1] = arr[j+1], arr[j]
            #     swapped = True
            if arr.getElement(j) > arr.getElement(j+1):
                tmpEl = arr.getElement(j)
                arr.setElement(j, arr.getElement(j+1))
                arr.setElement(j+1, tmpEl)
                swapped = True
        if (swapped == False):
            break

# Driver code to test above
if __name__ == "__main__":

    q = myQueueAdapter()
    
    q.enqueue(10000)
    q.enqueue(20000)
    q.enqueue(30000)
    q.enqueue(40000)
    q.enqueue(50000)

    q.display()
    q.setElement(0,99999)
    q.setElement(4,77777)
    q.display()
    print(q.getElement(1))   

    bubbleSort(q)

    q.display()

    # print("Sorted array:")
    # for i in range(len(arr)):
    #     print("%d" % arr[i], end=" ")
