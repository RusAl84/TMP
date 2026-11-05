
#https://www.geeksforgeeks.org/dsa/introduction-to-queue-data-structure-and-algorithm-tutorials/

from collections import deque

class myQueue:

    def __init__(self, items=None):
        self._data = deque(items) if items is not None else deque()

    def enqueue(self, item):
        """Добавить элемент в конец очереди. O(1)."""
        self._data.append(item)

    def dequeue(self):
        """Удалить и вернуть элемент из начала очереди. O(1)."""
        if not self._data:
            raise IndexError("dequeue из пустой очереди")
        return self._data.popleft()

    def front(self):
        """Посмотреть первый элемент, не удаляя его."""
        if not self._data:
            raise IndexError("front из пустой очереди")
        return self._data[0]

    def is_empty(self):
        return not self._data

    def size(self):
        """Количество элементов в очереди."""
        return len(self._data)

    def clear(self):
        """Очистить очередь."""
        self._data.clear()

    def display(self):
        tmp_q = myQueue()
        print('Display ____')
        while not self.is_empty():
            x = self.front()
            tmp_q.enqueue(x)
            self.dequeue()
            print(x)
        while not tmp_q.is_empty():
            x = tmp_q.front()
            self.enqueue(x)
            tmp_q.dequeue()
        print('__________')


class myQueueAdapter(myQueue):

    def getElement(self,index): 
        x=-1
        if 0<=index<self.size():
            tmp_q = myQueue()
            ind = 0 
            while not self.is_empty():
                x = self.front()
                tmp_q.enqueue(x)
                self.dequeue()
                if ind==index:
                    break
                ind+=1
            while not tmp_q.is_empty():
                y = tmp_q.front()
                self.enqueue(y)
                tmp_q.dequeue()
        return x
    
    def setElement(self,  index, element): 
        x=-1
        # index=self.size()-index-1
        if 0<=index<self.size():
            tmp_q = myQueueAdapter()
            ind = 0 
            while not self.is_empty():
                x = self.front()
                self.dequeue()
                if ind==index:
                    tmp_q.enqueue(element)
                else:
                    tmp_q.enqueue(x)
                ind+=1
                
            while not tmp_q.is_empty():
                y = tmp_q.front()
                self.enqueue(y)
                tmp_q.dequeue()


if __name__=='__main__':
    q = myQueueAdapter()
    q.enqueue(1000)  
    q.enqueue(2000)  
    q.enqueue(3000)  
    q.enqueue(4000)  
    q.enqueue(5000)  

    q.display()
    q.setElement(0,777)
    q.display()

    print(q.getElement(0))          
    print(q.getElement(1))          
    print(q.getElement(4))          
    print(q.getElement(5))          
    print(q.getElement(50))          
    # print(q.front())  # 1
    # print(q.dequeue())# 1
    # print(q)          # myQueue([2, 3])
    # print(q.size())   # 2
    # print(bool(q))    # True

    # q.clear()
    # print(q.is_empty())  # True