#https://www.geeksforgeeks.org/dsa/implementation-deque-using-circular-array/
class myDeque:
    
    # Constructor to initialize the deque with a given capacity
    def __init__(self, c):
        self.l = [None] * c
        self.cap = c
        self.size = 0
        self.front = 0

    # Delete element from the front
    def deleteFront(self):
        
        # Return None if deque is empty
        if self.size == 0:
            return None
        else:
            res = self.l[self.front]

            # Move front index circularly
            self.front = (self.front + 1) % self.cap
            self.size -= 1
            return res

    # Insert element at the front
    def insertFront(self, x):
        # Return if deque is full
        if self.size == self.cap:
            return
        else:
            # Move front index circularly
            self.front = (self.front - 1 + self.cap) % self.cap
            self.l[self.front] = x
            self.size += 1

    # Insert element at the rear
    def insertRear(self, x):
      
        # Return if deque is full
        if self.size == self.cap:
            return
      
        # Calculate rear index
        new_rear = (self.front + self.size) % self.cap
        self.l[new_rear] = x
        self.size += 1

    # Delete element from the rear
    def deleteRear(self):
        sz = self.size
        # Return None if deque is empty
        if sz == 0:
            return None
        else:
            # Calculate rear index
            rear = (self.front + sz - 1) % self.cap
            self.size -= 1
            return self.l[rear]

    # Get the front element
    def frontEle(self):
        return self.l[self.front]

    # Get the rear element
    def rearEle(self):
        # Calculate rear index
        rear = (self.front + self.size - 1) % self.cap
        return self.l[rear]

    def isEmpty(self):
        if self.size==0:
            return True
        else:
            return False

    def display(self):
        tmpQ = myDeque(20)
        while not self.isEmpty():
            x = self.frontEle()
            self.deleteFront()
            tmpQ.insertFront(x)
            print(x)
        while not tmpQ.isEmpty():
            x = tmpQ.frontEle()
            tmpQ.deleteFront()
            self.insertFront(x)

class myDequeAdapter(myDeque):    
     
     def getElement(self, index):

            return False


if __name__ == "__main__":
    dq = myDeque(20)
    dq.insertRear(1000)
    dq.insertFront(2000)
    dq.insertRear(4000)
    dq.insertRear(5000)
    dq.insertRear(6000)

    dq.display()

    
    # print(dq.front())
    # print(dq.rear())
    # dq.deleteFront()
    # print(dq.front())
    # print(dq.rear())
    # dq.deleteRear()
    # print(dq.front())
    # print(dq.rear())