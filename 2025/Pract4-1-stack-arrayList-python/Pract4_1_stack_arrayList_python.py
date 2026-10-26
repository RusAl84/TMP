
class Stack:
    def __init__(self):
        self._items = []

    def push(self, item):
        """Добавить элемент на вершину стека."""
        self._items.append(item)

    def pop(self):
        """Снять и вернуть элемент с вершины стека."""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._items.pop()

    def peek(self):
        """Посмотреть верхний элемент, не снимая его."""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self._items[-1]

    def is_empty(self) -> bool:
        """Проверить, пуст ли стек."""
        return len(self._items) == 0

    def size(self) -> int:
        """Количество элементов в стеке."""
        return len(self._items)

    def clear(self):
        """Очистить стек."""
        self._items.clear()

    def __len__(self):
        return len(self._items)

    def __bool__(self):
        return not self.is_empty()

    def __repr__(self):
        return f"Stack({self._items})"

    def display(self):
        tempStack = Stack()
        print("Display Stack: ")
        while (not self.is_empty()):
            x = self.pop()
            print(x)
            tempStack.push(x)
        while (not tempStack.is_empty()):
            x = tempStack.pop()
            self.push(x)


# Пример использования
if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)

    print(s)          # Stack([1, 2, 3])
    print(s.peek())   # 3
    print(s.pop())    # 3
    print(s.pop())    # 2
    print(s.size())   # 1
    print(s.is_empty())  # False
    s.clear()
    print(s.is_empty())  # True