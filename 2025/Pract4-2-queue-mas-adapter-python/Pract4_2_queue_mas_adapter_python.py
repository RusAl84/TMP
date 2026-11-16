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

class myQueueAdapter(myQueue):

    def display(self):
        tmpQ = myQueue(30)
        print("Display ____")
        while not self.isEmpty():
            element = self.getFront()
            self.dequeue()
            tmpQ.enqueue(element)
        while not tmpQ.isEmpty():
            element = tmpQ.getFront()
            tmpQ.dequeue()
            self.enqueue(element)
            print(element)
        print("____")

    def getElement(self, index):
        element = -1 
        if 0<=index<q.size:
            tmpQ = myQueue(30)
            ind=0
            while not self.isEmpty():
                element = self.getFront()
                if index==ind:
                    break
                ind+=1 #TO DO 
                self.dequeue()
                tmpQ.enqueue(element)
            while not tmpQ.isEmpty():
                tmpElement = tmpQ.getFront()
                tmpQ.dequeue()
                self.enqueue(tmpElement)
        return element


if __name__ == '__main__':
    q = myQueueAdapter(30)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    q.enqueue(50)

    q.display()
    # print(q.getElement(0))
    # print(q.getElement(1))
    # print(q.getElement(2))
    # print(q.getElement(3))
    # print(q.getElement(4))
    # print(q.getElement(5))
