
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
        while(not self.empty()):
            x = self.get()
            print(x)
            mq1.put(x)
        while(not mq1.empty()):
            x = mq1.get()
            self.put(x)


if __name__ == "__main__":
    q = myQueue(maxsize=3000)
    print(q.empty())      # True
    q.put(1)
    q.put(2)
    q.put(3)
    q.put(4)
    q.put(5)
    q.put(6)
    q.put(7)
    q.display()
    print(q.empty())      # False
    q.put(7)
    print(q.full())       # True
    print(q.qsize())      # 3
    print(q.get())        # 1
    print(q.empty())      # False