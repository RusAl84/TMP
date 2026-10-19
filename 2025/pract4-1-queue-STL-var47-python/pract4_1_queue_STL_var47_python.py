from queue import Queue


class myQueue:
    """Обёртка над queue.Queue с пробросом основных методов."""

    def __init__(self, maxsize: int = 0):
        self._queue = Queue(maxsize=maxsize)

    def put(self, item, block: bool = True, timeout=None) -> None:
        """Кладёт элемент в очередь."""
        self._queue.put(item, block=block, timeout=timeout)

    def get(self, block: bool = True, timeout=None):
        """Извлекает элемент из очереди."""
        return self._queue.get(block=block, timeout=timeout)

    def empty(self) -> bool:
        """True, если очередь пуста."""
        return self._queue.empty()

    def full(self) -> bool:
        """True, если очередь заполнена (для maxsize > 0)."""
        return self._queue.full()

    def qsize(self) -> int:
        """Приблизительный размер очереди."""
        return self._queue.qsize()

    # Небольшие удобства (необязательно)
    def __len__(self) -> int:
        return self.qsize()

    def __repr__(self) -> str:
        return f"myQueue(size={self.qsize()}, full={self.full()})"

    def display(self):
        mq1 = myQueue()
        print("Display: ")
        while (not self.empty()):
            x = self.get()
            print(x)
            mq1.put(x)
        while (not mq1.empty()):
            x = mq1.get()
            self.put(x)


class myAdapterQueue(myQueue):
    """
    Наследник myQueue с индексным доступом к элементам.
    Все методы родителя (put, get, empty, full, qsize, display)
    доступны через наследование.
    """

    def setElement(self, index: int, element: int) -> None:
        if (index>0 and index<self.qsize()-1):
            mq1 = myQueue()
            ind=0
            x=0
            while (not self.empty()):
                x = self.get()
                if (ind==index):
                    break;
                mq1.put(x)
                ind+=1
            mq1.put(element)
            while (not self.empty()):
                x = self.get()
                mq1.put(x)
            while (not mq1.empty()):
                x = mq1.get()
                self.put(x)

    def getElement(self, index: int) -> int:
        if (index>0 and index<self.qsize()-1):
            mq1 = myQueue()
            ind=0
            x=0
            while (not self.empty()):
                x = self.get()
                if (ind==index):
                    break;
                mq1.put(x)
                ind+=1
            element = x
            mq1.put(x)
            while (not self.empty()):
                x = self.get()
                mq1.put(x)
            while (not mq1.empty()):
                x = mq1.get()
                self.put(x)
            return x
        else:
            return -1


if __name__ == "__main__":
    # --- проверка исходного myQueue ---
    # print("=== myQueue ===")
    # q = myQueue(maxsize=3000)
    # print(q.empty())      # True
    # q.put(1)
    # q.put(2)
    # q.put(3)
    # q.put(4)
    # q.put(5)
    # q.put(6)
    # q.put(7)
    # q.display()
    # print(q.empty())      # False
    # q.put(777)
    # q.display()
    # print(q.full())       # False (maxsize=3000, а элементов 8)
    # print(q.qsize())      # 8
    # print(q.get())        # 1
    # print(q.empty())      # False

    # --- проверка myAdapterQueue ---
    print("\n=== myAdapterQueue ===")
    aq = myAdapterQueue(maxsize=10)

    # наследованные методы
    for v in (10, 20, 30, 40, 50):
        aq.put(v)
    print("qsize:", aq.qsize())        # 5
    print("empty:", aq.empty())        # False
    print("full:", aq.full())          # False

    # новые методы
    print("getElement(0):", aq.getElement(0))    # 10
    print("getElement(2):", aq.getElement(2))    # 30
    print("getElement(-1):", aq.getElement(-1))  # 50
    aq.display()
    aq.setElement(5, 999)
    aq.display()
