#https://www.geeksforgeeks.org/dsa/array-implementation-of-queue-simple/

class myQueue:
    def __init__(self, capacity):
         #Maximum number of elements the queue can hold.
        self.capacity = capacity
        #  Array to store queue elements.
        self.arr = [0] * capacity
        #  Current number of elements in the queue.
        self.size = 0

    # Check if queue is empty
    def isEmpty(self):
        return self.size == 0

    # Check if queue is full
    def isFull(self):
        return self.size == self.capacity

    # Enqueue
    def enqueue(self, x):
        if self.isFull():
            print("Queue is full!")
            return
        self.arr[self.size] = x
        self.size += 1

    # Dequeue
    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty!")
            return
        for i in range(1, self.size):
            self.arr[i - 1] = self.arr[i]
        self.size -= 1

    # Get front element
    def getFront(self):
        if self.isEmpty():
            print("Queue is empty!")
            return -1
        return self.arr[0]
        
    def getRear(self):
        if self.isEmpty():
           print("Queue is empty!")
           return -1
        return self.arr[self.size - 1]

class myQueueAdapter:
    def __init__(self, capacity):
        self.q = myQueue(capacity)
    
    def getRear(self):
        return self.q.getRear()

    def getFront(self):
        return self.q.getFront()

    def dequeue(self):   
        self.q.dequeue()

    def enqueue(self, x):
        self.q.enqueue(x)

    def isFull(self):
        return self.q.isFull()

    def isEmpty(self):
        return self.q.isEmpty()

    def display(self):
        tq = myQueue(30)
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
        tq = myQueue(30)
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
        tq = myQueue(30)
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

if __name__ == '__main__':
    q = myQueueAdapter(30)

    q.enqueue(10000)
    q.enqueue(20000)
    q.enqueue(30000)
    q.enqueue(40000)
    q.enqueue(50000)

    q.display()
    q.setElement(4,7777777)
    q.display()
    print(q.getElement(0))



